#include "recordmgr.h"
#include "dll/sdu/sdlock.h"
#include "dll/sdframework/sdloggerimpl.h"
#include "dll/sddb/sddb.h"
#include "dll/sdframework/sdutil.h"
#include <db/autosqlbuf.h>
#include "logic/other/singleprammgr.h"
#include "framework/gsconfig.h"
#include "common/server/ngstring.h"
#include <fstream>
#include "common/server/utility.h"
#include "logic/player/player.h"

#include <sstream>

IMPLEMENT_SINGLETON(CRecordMgr);
IMPLEMENT_SINGLETON(CConsumeChartMgr);

// �洢��־�����sql�����ļ���
#define RECORD_ERR_FILE	"record_error"

// �洢��Ϸ���е�Ԫ����¼�����sql�����ļ�����Ԫ����¼��־�������Ϸ�⣬�����Ƿ�����־�⣩
#define GOLD_RECORD_ERR_FILE "goldrecord_error"

namespace recordutil
{
// ���ݿ���и�vip�ȼ���Ӧ���ֶ�
string astrVipField[] =
{
    "vip0",
    "vip1",
    "vip2",
    "vip3",
    "vip4",
    "vip5",
    "vip6",
    "vip7",
    "vip8",
    "vip9",
    "vip10",
    "vip11",
    "vip12",
    "vip12+",
};

// ���ݿ���и���ҵȼ��������Ӧ���ֶ�
string astrLevelField[] =
{
    "level_1_9",
    "level_10",
    "level_20",
    "level_30",
    "level_40",
    "level_50",
    "level_60",
    "level_70",
    "level_80",
    "level_90",
    "level_100",
    "level_110",
    "level_120+",
};

// ��ȡ�����賿0��ʱ����ַ���
string GetTodayZeroTime()
{
    CSDDateTime oDateNow      = SDNow();

    UINT64 qwNow              = oDateNow.GetTimeValue();
    UINT32 dwDayPassSec       = GetDayPassSecond(qwNow);

    // ��ȡ�����賿ʱ��
    CSDDateTime dateTodayZero = oDateNow.DecSecond(dwDayPassSec);

    // תΪ�ַ���
    string strTodayZero = SDTimeToString(dateTodayZero);
    return strTodayZero;
}

TCHAR* GetYear()
{
    CSDDateTime t = SDNow();

    static TCHAR temp[20];
    temp[0] = '\0';

    _SDTsnprintf(temp, 20, _SDT("%4d"), t.GetYear());
    return temp;
}
}

using namespace recordutil;

CRecordMgr::CRecordMgr()
    : m_poGameDBSession(NULL)
    , m_poGameDBModule(NULL)
    , m_dwCachedYear(0)
{
    m_bStop = FALSE;

    m_tLastWriteTime = SDTimeSecs();
    m_pDBRecordModule = NULL;
    m_pDBRecordSession = NULL;
    m_poRecordModule = NULL;
}

CRecordMgr::~CRecordMgr()
{
}

BOOL CRecordMgr::Init()
{
    m_pDBRecordModule = SGDP::SDDBGetModule();
    if( NULL == m_pDBRecordModule )
    {
        SYS_CRITICAL(_SDT("[%s: %d]:SDDBGetModule failed"), MSG_MARK);
        return FALSE;
    }

    SGDP::SDDBAccount recordAccount;
    CGSConfig::Instance()->GetRecordDBAccount(recordAccount);
    m_pDBRecordSession = m_pDBRecordModule->GetDBSession( &recordAccount,
                         CGSConfig::Instance()->GetRecordPoolCoreSize(),
                         CGSConfig::Instance()->GetRecordPoolMaxSize() );

    if( NULL == m_pDBRecordSession )
    {
        SYS_CRITICAL(_SDT("[%s: %d]:GetDBSession failed"), MSG_MARK);
        return FALSE;
    }

    m_poRecordModule = SDNew CRecordModule(m_pDBRecordSession);
    if(NULL == m_poRecordModule)
    {
        SYS_CRITICAL(_SDT("[%s: %d]:new CRecordModule failed"), MSG_MARK);
        return FALSE;
    }

    // ������Ϸ���ݿ��ģ��ӿ�
    m_poGameDBModule = SGDP::SDDBGetModule();
    if( NULL == m_poGameDBModule )
    {
        SYS_CRITICAL(_SDT("[%s: %d]:SDDBGetModule failed"), MSG_MARK);
        return FALSE;
    }

    // ͨ��ģ��ӿڴ�������Ϸ���ݿ�ĻỰ���ӣ�ע�⣺��Ϊ�Ƕ��̣߳�����Ҫר���ٴ���һ�����ӣ���������CDBMgr�е���Ϸ���ݿ�����
    SGDP::SDDBAccount gameDBAccount;
    CGSConfig::Instance()->GetDBAccount(gameDBAccount);
    m_poGameDBSession = m_poGameDBModule->GetDBSession( &gameDBAccount,
        CGSConfig::Instance()->GetPoolCoreSize(),
        CGSConfig::Instance()->GetPoolMaxSize());

    if(NULL == m_poGameDBSession)
    {
        SYS_CRITICAL(_SDT("[%s: %d]:GetDBSession failed"), MSG_MARK);
        return FALSE;
    }

    //��ʼ����Դ����ͳ����
    if( FALSE == CConsumeChartMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CConsumeChartMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CConsumeChartMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CConsumeChartMgr Init failed"), MSG_MARK);
        return FALSE;
    }

    Start();
    return TRUE;
}


VOID CRecordMgr::UnInit()
{
    Stop();
    Wait();
}

VOID CRecordMgr::Stop()
{
    m_bStop = TRUE;
}

BOOL CRecordMgr::WriteDataToSqlServer()
{
    UINT32 dwNextID = 0;
    string strTable = m_poRecordModule->GetRecordModuleName(dwNextID);
    CNGString strSql;
    strSql += "insert into ";
    strSql += strTable;
    strSql += "(ID, PlayerID, ModuleType, OpType, OpValue, OpTime, AfterOpValue, Param1, Param2, Param3, Param4,  PlayerLevel, VipLevel, Comment) values";

    //����
    m_poRecordModule->GetDataMutex().Lock();

    deque<string> &deqData = m_poRecordModule->GetQueue();

    BOOL bHaveData = FALSE;

    if( deqData.size() )
    {
        bHaveData = TRUE;
        strSql += "( ";
        strSql += dwNextID++;
        strSql += ", ";
        strSql += deqData[0];
    }

    for( UINT32 dwIndex = 1; dwIndex < deqData.size(); ++dwIndex )
    {
        strSql += ", ( ";
        strSql += dwNextID++;
        strSql += ", ";
        strSql += deqData[dwIndex];
    }
    deqData.clear();//ֱ����������Ᵽ��ʧ��Խ��Խ��
    m_poRecordModule->SetCurID(dwNextID);
    //����
    m_poRecordModule->GetDataMutex().Unlock();

    if( !bHaveData )
    {
        return FALSE;
    }
    string strError;
    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    INT32 nRet = m_pDBRecordSession->ExecuteSqlRs( strSql.c_str(), &pRecordSet, 0, &strError );
    if( pRecordSet )
    {
        pRecordSet->Release();
    }
    if( nRet < 0 )
    {
        SYS_CRITICAL( _SDT( "[%s %d]exec sql error,error:%s SQL:%s" ), MSG_MARK, strError.c_str(), strSql.c_str() );
        AddSaveErrorSql(strSql.str(), RECORD_ERR_FILE);
        return FALSE;
    }

    return TRUE;
}

BOOL CRecordMgr::SplitNewGoldRecordTable(std::string &strNewTableName)
{
    // ��ִ��һ��洢���̣�ȷ����������ڵĻ��򴴽���
    string strError;
    SGDP::ISDDBRecordSet* pRecordSet = NULL;

    CHAR szSql[256] = {0};
    sprintf(szSql, "call SplitNewGoldRecordTable('%s')", strNewTableName.c_str());
    INT32 nRet = m_poGameDBSession->ExecuteSqlRs(szSql, &pRecordSet, 0, &strError);
    if(SDDB_NO_RECORDSET != nRet)
    {
        if(!strError.empty())
        {
            SYS_CRITICAL(_SDT("[%s: %d]:call SplitNewGoldRecordTable(%s) failed, errstr:%s"), MSG_MARK, strNewTableName.c_str(), strError.c_str());
            return FALSE;
        }
    }
    if( pRecordSet )
    {
        pRecordSet->Release();
    }

    return TRUE;
}

BOOL CRecordMgr::SaveGoldRecordToDB()
{
    if(m_vecGoldSql.empty())
    {
        return TRUE;
    }

    CSDDateTime t = SDNow();

    /*
        Ԫ����¼�Ƚ���Ҫ����Ҫ���ñ��ݣ�����������������ӣ�������Ŀǰ��־��û�����ӣ���Ϸ�����У�����־��ĴӵĻ�ÿ̨��������Ҫר�Ŷ��һ��mysqlʵ�����Ƚ��˷���Դ��
        ��ˣ���Ԫ��������־�������Ϸ��������Ƿ�����־�⣨2014_3_15�գ�
    */

    // ��ȡ����ȵı���
    std::string strThisYearTableName = std::string("goldrecord_") + recordutil::GetYear();

    // ����Ƿ������꣨ĿǰԪ����¼ÿ�����Ӧһ�꣬���ԣ�ÿ�����꣬��Ҫͨ���洢���̴����õ����Ԫ����¼��
    UINT32 dwCurYear = t.GetYear();
    BOOL bNewYear = (m_dwCachedYear != dwCurYear);
    if(bNewYear)
    {
        m_dwCachedYear = dwCurYear;
        SplitNewGoldRecordTable(strThisYearTableName);
    }

    // ��ͳ�ƣ�1���е�oprecord����Ԫ�������ļ�¼�����Ϊÿ����60������2014_3_11��ͳ�ƣ���ÿ���Լ720������������д�Ż��ǿ��е�
    std::string strSql = "insert into ";
    strSql += strThisYearTableName.c_str();
    strSql += "(ID,ZoneID,PlayerID,PlayerLevel,VipLevel,ModuleType,OpType,OpTime,OpRMBGold,OpRMBGoldGift,OpGmGold,OpGameGold,AfterRMBGold,AfterRMBGoldGift,AfterGmGold,AfterGameGold,Param1,Param2,Param3,Param4,`comment`) values ";

    for( UINT32 i = 0; i < m_vecGoldSql.size(); ++i )
    {
        std::string &strSqlElem = m_vecGoldSql[i];

        strSql.append("(");
        strSql.append(strSqlElem);
        strSql.append("),");
    }
    
    // ȥ��ĩβ��","
    strSql.erase(strSql.end() - 1);

    string strError;
    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    INT32 nRet = m_poGameDBSession->ExecuteSqlRs(strSql.c_str(), &pRecordSet, 0, &strError );
    if(pRecordSet)
    {
        pRecordSet->Release();
    }

    m_vecGoldSql.clear();
    if( nRet < 0 )
    {
        SYS_CRITICAL( _SDT( "[%s %d] exec sql error,error:%s SQL:%s" ), MSG_MARK, strError.c_str(), strSql.c_str());
        AddSaveErrorSql(strSql, GOLD_RECORD_ERR_FILE);

        return FALSE;
    }

    return TRUE;
}

VOID CRecordMgr::AddSaveErrorSql( const string& strSql, CHAR szErrFileName[], BOOL bTrunc )
{
    if(strSql.empty())
    {
        return;
    }

    CHAR szDir[1024] = {0};
    sprintf( szDir, "%s../%s", (const CHAR*)SDGetModulePath(), szErrFileName);
    CHAR szFile[1024] = {0};
    sprintf( szFile, "%s/%s.err", szDir, szErrFileName);

    if( !SDDirectoryExists( szDir ) )
    {
        if( !SDCreateDirectory( szDir, TRUE ) )
        {
            SYS_CRITICAL(_SDT("[%s: %d]: create directory failed!path:%s"), MSG_MARK, szDir);
            return;
        }
    }

    std::ofstream outFile;
    if(bTrunc)
    {
        outFile.open( szFile, ios::trunc | ios::in);
    }
    else
    {
        outFile.open( szFile, ios::app | ios::in);
    }

    if( !outFile.is_open() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: create file failed!path:%s"), MSG_MARK, szFile);
        return;
    }

    outFile.write( strSql.c_str(), strSql.size() );
    outFile << endl;
}


list<string> CRecordMgr::GetErrorSql(CHAR szErrFileName[])
{
    list<string> lstStrSqlInfo;

    CHAR szDir[1024] = {0};
    sprintf( szDir, "%s/../%s", (const CHAR*)SDGetModulePath(), szErrFileName);
    CHAR szFile[1024] = {0};
    sprintf( szFile, "%s/%s.err", szDir, szErrFileName);

    ifstream inFile( szFile );
    if( !inFile.is_open() )
    {
        return lstStrSqlInfo;
    }

    string strSqlRead;
    strSqlRead.resize( MAX_SQL_LEN );
    while( !inFile.eof() )
    {
        inFile.getline( (char *)strSqlRead.c_str(), strSqlRead.size() );
        if(0 == strSqlRead[0])
        {
            continue;
        }
        lstStrSqlInfo.push_back(strSqlRead);
    }

    return lstStrSqlInfo;
}


VOID  CRecordMgr::ThrdProc()
{
    while(!m_bStop)
    {
        const UINT64 qwNow = SDTimeSecs();
        if(qwNow - m_tLastWriteTime > CSinglePramMgr::Instance()->GetUpdateRecordDataToSqlInterval() )
        {
            WriteDataToSqlServer();
            SaveGoldRecordToDB();

            m_tLastWriteTime = qwNow;//5��ʱ����һ���Ƿ��д����ļ����������
            SGDP::SDSleep( ms_dwSleepTime );
            //ExeErrFileSql(); //δ�������ܲ�������ʱע��
        }

        // �洢��Դ����ͳ�Ʊ�
        CConsumeChartMgr *poRecordSumUpMgr = CConsumeChartMgr::Instance();
        if(qwNow - poRecordSumUpMgr->GetLastSaveTime() > CSinglePramMgr::Instance()->GetSaveOpHistoryToDBInterval())
        {
            poRecordSumUpMgr->SaveToDB();
            poRecordSumUpMgr->ResetLastSaveTime();
        }

        //ǿ������һ�����ټ��һ��
        SDSleep(ms_dwSleepTime);
    }

    WriteDataToSqlServer();
    SaveGoldRecordToDB();

    CConsumeChartMgr::Instance()->SaveToDB();

    m_pDBRecordModule->Close( m_pDBRecordSession );
    m_pDBRecordModule->Release();
    m_pDBRecordSession = NULL;
    m_pDBRecordModule = NULL;


    m_poGameDBModule->Close( m_poGameDBSession);
    m_poGameDBModule->Release();
    m_poGameDBSession = NULL;
    m_poGameDBModule = NULL;
}

VOID CRecordMgr::ExeErrFileSql()
{
    list<string> lstSql = CRecordMgr::Instance()->GetErrorSql(RECORD_ERR_FILE);
    for(list<string>::iterator itr = lstSql.begin(); itr != lstSql.end(); )
    {
        string strError;
        SGDP::ISDDBRecordSet* pRecordSet = NULL;
        string strSql = *itr;
        if(strSql.empty())
        {
            lstSql.erase(itr++);
            continue;
        }
        INT32 nRet = m_pDBRecordSession->ExecuteSqlRs( strSql.c_str(), &pRecordSet, 0, &strError );
        if( pRecordSet )
        {
            pRecordSet->Release();
        }
        if( nRet < 0 )
        {
            SYS_CRITICAL( _SDT( "[%s %d]exec sql error2,error:%s SQL:%s" ), MSG_MARK, strError.c_str(), strSql.c_str() );
            itr++;
        }
        else
        {
            lstSql.erase(itr++);
        }
    }
    for(list<string>::iterator itr = lstSql.begin(); itr != lstSql.end(); itr++)
    {
        if(itr == lstSql.begin())
        {
            AddSaveErrorSql(*itr, RECORD_ERR_FILE, TRUE);
        }
        else
        {
            AddSaveErrorSql(*itr, RECORD_ERR_FILE);
        }
    }
    if(lstSql.empty())
    {
        AddSaveErrorSql("", RECORD_ERR_FILE, TRUE);
    }
}

VOID CRecordMgr::ExeGoldErrFileSql()
{
    list<string> lstSql = CRecordMgr::Instance()->GetErrorSql(GOLD_RECORD_ERR_FILE);
    for(list<string>::iterator itr = lstSql.begin(); itr != lstSql.end(); )
    {
        string strError;
        SGDP::ISDDBRecordSet* pRecordSet = NULL;
        string strSql = *itr;
        if(strSql.empty())
        {
            lstSql.erase(itr++);
            continue;
        }
        INT32 nRet = m_poGameDBSession->ExecuteSqlRs( strSql.c_str(), &pRecordSet, 0, &strError );
        if( pRecordSet )
        {
            pRecordSet->Release();
        }
        if( nRet < 0 )
        {
            SYS_CRITICAL( _SDT( "[%s %d]exec sql error2,error:%s SQL:%s" ), MSG_MARK, strError.c_str(), strSql.c_str() );
            itr++;
        }
        else
        {
            lstSql.erase(itr++);
        }
    }
    for(list<string>::iterator itr = lstSql.begin(); itr != lstSql.end(); itr++)
    {
        if(itr == lstSql.begin())
        {
            AddSaveErrorSql(*itr, GOLD_RECORD_ERR_FILE, TRUE);
        }
        else
        {
            AddSaveErrorSql(*itr, GOLD_RECORD_ERR_FILE);
        }
    }
    if(lstSql.empty())
    {
        AddSaveErrorSql("", GOLD_RECORD_ERR_FILE, TRUE);
    }
}

CConsumeChartMgr::CConsumeChartMgr()
{
    m_qwLastSaveTime = SDTimeSecs();
}

BOOL CConsumeChartMgr::Init()
{
    return LoadFromDB();
}

// ͳ����һ�û�������Դ�����
VOID CConsumeChartMgr::CountUp(UINT16 wPlayerLevel, BYTE byVipLevel, UINT16 wModuleType, UINT16 wOpType, UINT32 dwOpValue, CSDDateTime &oOpTime)
{
    UINT64 qwTime       = oOpTime.GetTimeValue();
    UINT64 qwTodayZero  = qwTime - GetDayPassSecond(qwTime); // �����賿0��ʱ��
    UINT64 qwOptKey     = CLogicFunc::Get3232Key(wModuleType, wOpType); // ��ֵ = ��Դ���� + ��Ӧ�������磺����Ԫ�� + ��ֵ������Ԫ�� + ǿ��װ��

    wPlayerLevel  = MIN(RECORD_CHART_MAX_LEVEL, wPlayerLevel); // ���������ߵȼ���120��������Ϊ������ȼ����ܻ�Խ��Խ������120�����ϵ�ֱ�ӹ�Ϊ120+��
    byVipLevel    = MIN(RECORD_CHART_MAX_VIP + 1, byVipLevel); // �������vip�ȼ���12����˵֮����ܻ���չ��20��������vip12���Ժ�Ķ���Ϊ12+��
    wPlayerLevel /= 10; // ���ĵ���Դ����ҵȼ�����������,[1 - 9], [10, 19].... ÿ10��Ϊһ������

    // �����Է�ֹSaveToDB��������������
    CSDLock<CSDMutex> lock(m_mutex);

    // ͳ����Դ����
    ConsumeChartMap &mapToDay   = m_mapRecord[qwTodayZero];
    ConsumeRow &recordInfo = mapToDay[qwOptKey];

    recordInfo.wModuleType                  = wModuleType;
    recordInfo.wOpType                      = wOpType;
    recordInfo.vecLevelSumUp[wPlayerLevel] += dwOpValue;
    recordInfo.vecVipSumUp[byVipLevel]     += dwOpValue;
    recordInfo.qwOpTotal                   += dwOpValue;
    recordInfo.dwOpCnt                     += 1;
    recordInfo.dwMaxOpVal                   = MAX(dwOpValue, recordInfo.dwMaxOpVal);
    recordInfo.dwMinOpVal                   = ((recordInfo.dwMinOpVal == 0) ? dwOpValue : MIN(dwOpValue, recordInfo.dwMinOpVal));
    recordInfo.bSavedToDB = FALSE;
}

// �����ݿ���ȡ���������Դ����ͳ������
BOOL CConsumeChartMgr::LoadFromDB()
{
    ISDDBSession *poDBSession = CRecordMgr::Instance()->GetRecordDBSession();
    if(NULL == poDBSession)
    {
        return FALSE;
    }

    UINT64 qwNow = SDNow().GetTimeValue();
    UINT64 qwTodayZero = qwNow - GetDayPassSecond(qwNow); // �����賿0��

    // ȡ���������Դͳ������
    string strQuerySql = "select * from ophistory where Date = '" + recordutil::GetTodayZeroTime() + "'";

    SGDP::ISDDBRecordSet* pRes = NULL;
    INT32 nRet = poDBSession->ExecuteSqlRs(strQuerySql.c_str(), &pRes);
    if(SDDB_HAS_RECORDSET != nRet && SDDB_NO_RECORDSET != nRet)
    {
        return FALSE;
    }

    if(NULL == pRes)
    {
        return TRUE;
    }

    CSDLock<CSDMutex> lock(m_mutex);

    ConsumeChartMap &mapTodayHistory = m_mapRecord[qwTodayZero];
    while(pRes->GetRecord()) // �����н��ʱ
    {
        // �Ѽ�¼�浽�������Դͳ������
        UINT16 wModuleType        = SGDP::SDAtou(pRes->GetFieldValueByName("ModuleType"));
        UINT16 wOpType            = SGDP::SDAtou(pRes->GetFieldValueByName("OpType"));
        UINT64 qwOpKey            = CLogicFunc::Get3232Key(wModuleType, wOpType);

        ConsumeRow &stHistory = mapTodayHistory[qwOpKey];
        stHistory.qwOpTotal       = SGDP::SDAtou(pRes->GetFieldValueByName("OpTotal"));
        stHistory.dwOpCnt         = SGDP::SDAtou(pRes->GetFieldValueByName("OpCnt"));
        stHistory.dwMaxOpVal      = SGDP::SDAtou(pRes->GetFieldValueByName("MaxOpVal"));
        stHistory.dwMinOpVal      = SGDP::SDAtou(pRes->GetFieldValueByName("MinOpVal"));

        // ��ȡvip�ȼ�ͳ��
        for(int i = 0; i < RECORD_CHART_VIP_SECTION_CNT; ++i)
        {
            stHistory.vecVipSumUp[i] = SGDP::SDAtou(pRes->GetFieldValueByName(astrVipField[i].c_str()));
        }

        // ��ȡ��ҵȼ�ͳ��
        for(int i = 0; i < RECORD_CHART_LEVEL_SECTION_CNT; ++i)
        {
            stHistory.vecLevelSumUp[i] = SGDP::SDAtou(pRes->GetFieldValueByName(astrLevelField[i].c_str()));
        }
    }

    pRes->Release();
    return TRUE;
}

// ���صĽ�����磺replace into ophistory(Date, ModuleType, OpType, OpValue....., vip0, vip1, vip2, ......, level_1_9, level_10, .......) values
string& CConsumeChartMgr::BuildInsertFieldSql()
{
    static string strSql;
    if(strSql != "")
    {
        return strSql;
    }

    strSql += "replace into ophistory(Date,ModuleType,OpType,OpTotal,OpCnt,MaxOpVal,MinOpVal,";

    // ƴ�ӳ�vip�ȼ�ͳ������
    for(BYTE i = 0; i < RECORD_CHART_VIP_SECTION_CNT; ++i)
    {
        string& strVipField = astrVipField[i];

        strSql += "`";
        strSql += strVipField;
        strSql += "`,";
    }

    // ƴ�ӳ�level�ȼ�ͳ������
    for(BYTE i = 0; i < RECORD_CHART_LEVEL_SECTION_CNT; ++i)
    {
        string& strLevelField = astrLevelField[i];

        strSql += "`";
        strSql += strLevelField;
        strSql += "`,";
    }

    strSql.erase(strSql.end() - 1);

    strSql += ") values ";
    return strSql;
}

// ���ص��ַ���������磺("2013/12/10 00:00:00", 4, 5, 0, 0, 0.......), ("2013/12/10 00:00:00", 4, 5, 0, 0, 0.......) .....
string CConsumeChartMgr::BuildInsertValueSql()
{
    // std::stringstream strSql;
    CNGString strSql;

    // ����һ�ַ�������������ʱ�䣬����ǰ��������һ�ݿ��գ���Կ��ղ������У�ֻ������һ���ĸ���Դ���ĸ��٣�����
    CSDLock<CSDMutex> lock(m_mutex);

    // ȡ���������Դ���Ļ������ݣ���ʵҲ��ֻ�н��졢���죩
    for(Day2ConsumeChartMap::iterator itr = m_mapRecord.begin(); itr != m_mapRecord.end(); ++itr)
    {
        // ȡ����������
        ConsumeChartMap &mapHistory = itr->second;
        if(mapHistory.empty())
        {
            continue;
        }

        strSql.m_strData.reserve(1024);

        // ��ȡ�����賿ʱ��
        UINT64 qwDayZero = itr->first;

        CSDDateTime dateDayZero(qwDayZero);
        string strDayZero = SDTimeToString(dateDayZero);

        // ��Ե���������sqlƴ��
        for(ConsumeChartMap::iterator itr = mapHistory.begin(); itr != mapHistory.end(); ++itr)
        {
            ConsumeRow &stHistory = itr->second;
            if(stHistory.bSavedToDB)
            {
                continue;
            }

            strSql += "('";
            strSql += strDayZero;
            strSql += "',";
            strSql += stHistory.wModuleType;
            strSql += ",";
            strSql += stHistory.wOpType;
            strSql += ",";
            strSql += stHistory.qwOpTotal;
            strSql += ",";
            strSql += stHistory.dwOpCnt;
            strSql += ",";
            strSql += stHistory.dwMaxOpVal;
            strSql += ",";
            strSql += stHistory.dwMinOpVal;
            strSql += ",";

            // ����vip��������
            for(BYTE i = 0; i < RECORD_CHART_VIP_SECTION_CNT; ++i)
            {
                strSql += stHistory.vecVipSumUp[i];
                strSql += ",";
            }

            // ������ҵȼ������������
            for(BYTE i = 0; i < RECORD_CHART_LEVEL_SECTION_CNT; ++i)
            {
                strSql += stHistory.vecLevelSumUp[i];
                strSql += ",";
            }

            // ȥ��ĩβ��", "
            string &strInnerSql = strSql.m_strData;
            if(!strInnerSql.empty())
            {
                strInnerSql.erase(strInnerSql.end() - 1);
            }

            strSql += "),";
        }
    }

    // ȥ��ĩβ��","
    string &strInnerSql = strSql.m_strData;
    if(!strInnerSql.empty())
    {
        strInnerSql.erase(strInnerSql.end() - 1);
    }

    return strSql.str();
}

void CConsumeChartMgr::ResetLastSaveTime()
{
    m_qwLastSaveTime = SDTimeSecs();
}

// �ɹ�������е�δͬ����־��Ϊ��ͬ��������������ͳ�Ƽ�¼
void CConsumeChartMgr::OnSaveDBSuccess()
{
    // ����������ʷ����
    ClearYesterday();

    CSDLock<CSDMutex> lock(m_mutex);

    // ȡ���������Դ���Ļ������ݣ�Ҳ�ͽ��졢�����ˣ�
    for(Day2ConsumeChartMap::iterator itr = m_mapRecord.begin(); itr != m_mapRecord.end(); ++itr)
    {
        // ȡ����������
        ConsumeChartMap &mapHistory = itr->second;
        if(mapHistory.empty())
        {
            continue;
        }

        // ��Ե���������sqlƴ��
        for(ConsumeChartMap::iterator itr = mapHistory.begin(); itr != mapHistory.end(); ++itr)
        {
            ConsumeRow &stHistory = itr->second;
            stHistory.bSavedToDB = TRUE;
        }
    }
}

// ������ͳ�ƴ������ݿ�������±䶯�������ݣ�
BOOL CConsumeChartMgr::SaveToDB()
{
    // ͳ����һ�£���ֹĿǰ2013_12_10�����ڶ���Դ�Ĳ������͹���276�֣�����֮��ÿ��������276����Դ����ͳ�Ƽ�¼������ÿ��300����һ����������Ҳ��10���������Բ��ò��
    ISDDBSession *poDBSession = CRecordMgr::Instance()->GetRecordDBSession();
    if(NULL == poDBSession)
    {
        return FALSE;
    }

    // ���ɸ�����䣬��ʽΪ("2013/12/10 00:00:00", 4, 5, 0, 0, 0.......), ("2013/12/10 00:00:00", 4, 5, 0, 0, 0.......), ......
    string strValueSql = BuildInsertValueSql();
    if(strValueSql.empty())
    {
        // ��ǰû����Ҫ���������
        return TRUE;
    }

    // ���ɲ����ֶ���䣬��ʽΪreplace into ophistory(Date, ModuleType, OpType, OpValue, vip0, vip1, vip2, ......, level_1_9, level_10, .......) values
    string &strFieldSql = BuildInsertFieldSql();
    string strSql = strFieldSql + strValueSql;

    string strError;
    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    INT32 nRet = poDBSession->ExecuteSqlRs(strSql.c_str(), &pRecordSet, 0, &strError);
    if(pRecordSet)
    {
        pRecordSet->Release();
    }

    if(nRet < 0)
    {
        SYS_CRITICAL( _SDT( "[%s %d] CResourceChartMgr SaveToDB error,error:%s SQL:%s" ), MSG_MARK, strError.c_str(), strSql.c_str());
        return FALSE;
    }

    // �ɹ�������е�δͬ����־��Ϊ��ͬ�������������ļ�¼
    OnSaveDBSuccess();
    return TRUE;
}

// ��������ͳ�Ƽ�¼
void CConsumeChartMgr::ClearYesterday()
{
    CSDLock<CSDMutex> lock(m_mutex);

    // ����������ʷ��¼�ڲ��ڣ�map��ֻ������2�������1. ����������ͳ��һ�����  2. ֻ�н����ͳ�Ƽ�¼
    if(m_mapRecord.size() <= 1)
    {
        return;
    }

    UINT64 qwNow             = SDNow().GetTimeValue();
    const UINT64 qwTodayZero = qwNow - GetDayPassSecond(qwNow);

    // ֱ�ӰѲ��ǽ��������ͳ�Ƹ�����������Ѿ����浽���ݿ���
    for(Day2ConsumeChartMap::iterator itr = m_mapRecord.begin(); itr != m_mapRecord.end();)
    {
        const UINT64 qwDayZero = itr->first;
        if(qwTodayZero != qwDayZero)
        {
            m_mapRecord.erase(itr++);
            continue;
        }

        ++itr;
    }
}

BOOL CRecordMgr::RecordGold(UINT16 wZoneID, UINT32 dwPlayerID, UINT16 wPlayerLevel, UINT16 wVipLevel, ERecordModule wModuleType, UINT16 wOpType,
    UINT32 dwOpRMBGold, UINT32 dwOpRMBGoldGift, UINT32 dwOpGmGold, UINT32 dwOpGameGold, 
    UINT32 dwAfterRMBGold, UINT32 dwAfterRMBGoldGift, UINT32 dwAfterGmGold, UINT64 qwAfterGameGold, 
    UINT64 qwParam1/* = 0 */, UINT64 qwParam2/* = 0 */, UINT64 qwParam3/* = 0 */, UINT64 qwParam4/* = 0 */, string strComment/* = "" */)
{
    if(0 == (dwOpRMBGold | dwOpRMBGoldGift | dwOpGmGold | dwOpGameGold))
    {
        return FALSE;
    }

    CSDDateTime oNow = SDNow();
    string strOpTime = SDTimeToString(oNow);

    CNGString ss;
    //����Ҫ�����ݿ���ж��룬������ݿ�ṹ�޸ģ�����ҲҪ�����޸�
    ss += "NULL,"; // ��Ӧ��ID�ֶΣ�ID��auto increment�ֶ�
    ss += wZoneID;
    ss += ",";
    ss += dwPlayerID;
    ss += ",";
    ss += wPlayerLevel;
    ss += ",";
    ss += wVipLevel;
    ss += ",";
    ss += wModuleType;
    ss += ",";
    ss += wOpType;
    ss += ",'";
    ss += strOpTime;
    ss += "',";
    ss += dwOpRMBGold;
    ss += ",";
    ss += dwOpRMBGoldGift;
    ss += ",";
    ss += dwOpGmGold;
    ss += ",";
    ss += dwOpGameGold;
    ss += ",";
    ss += dwAfterRMBGold;
    ss += ",";
    ss += dwAfterRMBGoldGift;
    ss += ",";
    ss += dwAfterGmGold;
    ss += ",";
    ss += qwAfterGameGold;
    ss += ",";
    ss += qwParam1;
    ss += ",";
    ss += qwParam2;
    ss += ",";
    ss += qwParam3;
    ss += ",";
    ss += qwParam4;
    ss += ",'";
    //�����Ƿ����������ݿ�ؼ���
    if(FALSE == HaveSqlToken((CHAR*)strComment.c_str()))
    {
        ss += strComment;
    }
    ss += "'";
    m_vecGoldSql.push_back(ss.str());

    UINT32 dwOpGold = dwOpRMBGold + dwOpRMBGoldGift + dwOpGmGold + dwOpGameGold;
    CConsumeChartMgr::Instance()->CountUp(wPlayerLevel, (BYTE)wVipLevel, wModuleType, wOpType, dwOpGold, oNow);
    return TRUE;
}

BOOL CRecordMgr::RecordInfo(UINT32 dwPlayerID, UINT16 wModuleType, UINT16 wOpType, UINT32 dwOpValue, UINT64 qwAfterOpValue,
                            UINT16 wPlayerLevel, UINT16 wVipLevel, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
	if ( ERM_DECFACTIONFUNDS != wModuleType && ERM_GVG_ACTIVITY != wModuleType)
	{
		if(0 == dwOpValue)
		{
			return FALSE;
		}
	}

    CSDDateTime oNow = SDNow();
    string strOpTime = SDTimeToString(oNow);

    CNGString ss;
    //����Ҫ�����ݿ���ж��룬������ݿ�ṹ�޸ģ�����ҲҪ�����޸�
    //CSDDateTime dt(SDTimeSecs());
    ss += dwPlayerID;
    ss += ",";
    ss += wModuleType;
    ss += ",";
    ss += wOpType;
    ss += ",";
    ss += dwOpValue;
    ss += ",'";
    ss += strOpTime;
    ss += "',";
    ss += qwAfterOpValue;
    ss += ",";
    ss += qwParam1;
    ss += ",";
    ss += qwParam2;
    ss += ",";
    ss += qwParam3;
    ss += ",";
    ss += qwParam4;
    ss += ",";
    ss += wPlayerLevel;
    ss += ",";
    ss += wVipLevel;
    ss += ",'";
	//�����Ƿ����������ݿ�ؼ���
	if(HaveSqlToken((CHAR*)strComment.c_str()))
	{
		ss += "";
	}
	else
	{
		ss += strComment;
	}
    ss += "')";
    m_poRecordModule->AddData( ss.str() );

    CConsumeChartMgr::Instance()->CountUp(wPlayerLevel, (BYTE)wVipLevel, wModuleType, wOpType, dwOpValue, oNow);
    return TRUE;
}