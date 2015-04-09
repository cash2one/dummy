
#include "player.h"
#include "playerbasedatacachemgr.h"
#include <sdstring.h>
#include <sdutil.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include <framework/gsapi.h>
#include <framework/gsconfig.h>
#include <logic/race/racemgr.h>
#include <logic/other/singleprammgr.h>
#include <logic/plunder/plunder.h>
#include <logic/player/playermgr.h>
#include <logic/other/commoninfomgr.h>
#include <logic/base/basedefine.h>
#include <db/dbmgr.h>
#include "logic/vip/vippropmgr.h"
#include <db/basedbccmd.h>
using namespace SGDP;

bool sort_flower_sum(const SPlayerBaseData* p1, const SPlayerBaseData* p2)
{
    return p1->dwFlowerSum > p2->dwFlowerSum;
}

bool sort_rank_bylvex(const SPlayerBaseData* p1, const SPlayerBaseData* p2)
{
    if (p1->wLevel == p2->wLevel)
    {
        return p1->dwExperience > p2->dwExperience;
    }
    else return p1->wLevel > p2->wLevel;
}

class Csort_rank_bylvex
{
public:
    BOOL operator()(const SPlayerBaseData* p1, const SPlayerBaseData* p2)
    {
        if (p1->wLevel == p2->wLevel)
        {
            return p1->dwExperience > p2->dwExperience;
        }
        else return p1->wLevel > p2->wLevel;
    }
};
IMPLEMENT_SINGLETON(CPlayerBaseDataCacheMgr)

CPlayerBaseDataCacheMgr::CPlayerBaseDataCacheMgr(): m_oPlayerBaseDataPool(MAX_PLAYER_CACHE_POOL_NUM)
{
    m_wMaxPlayerLevel = CSinglePramMgr::Instance()->GetMaxPlayerLevel();
    m_apmapPlayerLevel = new CPlayerID2PlayerBaseDataMap[m_wMaxPlayerLevel + 1];
    //m_apitrPlayerLevel = new CPlayerID2PlayerBaseDataMapItr[m_wMaxPlayerLevel+1];
}

CPlayerBaseDataCacheMgr::~CPlayerBaseDataCacheMgr()
{

}

BOOL CPlayerBaseDataCacheMgr::Init()
{
    //��ȡ���ݿ�
    if(!InitDataFromDB())
    {
        USR_INFO(_SDT("[%s: %d]: InitDataFromDB failed!"), MSG_MARK);
        return FALSE;
    }

    return TRUE;

}
BOOL CPlayerBaseDataCacheMgr::InitDataFromDB()
{
    SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetDBSession();
    if(NULL == pDBSession)
    {
        return FALSE;
    }

    CHAR		szSql[8196] = {0};
    sprintf(szSql, "select players.PlayerID, NotifyID ,RobotFunc, Power, FirstAttack, DispName, MainHeroKindID, players.Level, \
		VipLevel, LastLoginTime, LastLogoffTime, Rank, CaptureOwnerID, BeCaptureOwnerTime, OpenPlunder, \
		EatBreadNotify, BossBattleNotify,CourageNofity, FlowerSum,  player_heros.Exp \
		from players, player_heros where players.PlayerID = player_heros.PlayerID  and player_heros.Coach = 1 \
		order by Rank asc;"); //����������������
    UINT32	dwErr;
    string	strError;
    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    CRank2PlayerBaseDataVector vecRank2PlayerBaseDataVector;
    INT32 nRet = pDBSession->ExecuteSqlRs(szSql, &pRecordSet, &dwErr, &strError );
    if(SDDB_HAS_RECORDSET == nRet)
    {
        UINT32 dwMaxRank = 0;
        while(pRecordSet->GetRecord())
        {
            SPlayerBaseData* poPlayerBaseData = m_oPlayerBaseDataPool.Alloc();
            if(NULL == poPlayerBaseData)
            {
                return FALSE;
            }

            poPlayerBaseData->Init();
            poPlayerBaseData->dwID = SDAtou(pRecordSet->GetFieldValueByName("PlayerID"));
            poPlayerBaseData->byRobotFunc = SDAtou( pRecordSet->GetFieldValueByName("RobotFunc") );
            poPlayerBaseData->dwPower = SDAtou( pRecordSet->GetFieldValueByName("Power") );
            poPlayerBaseData->dwFirstAttack = SDAtou( pRecordSet->GetFieldValueByName("FirstAttack") );

            //�����Ӷ�Ļ�����
            if(ERFK_PLUNDER == poPlayerBaseData->byRobotFunc)
            {
                m_mapPlunderRobot[poPlayerBaseData->dwID] = poPlayerBaseData;
            }
            _SDTStrcpy( poPlayerBaseData->aszDispName, pRecordSet->GetFieldValueByName( "DispName" ) );
            if(poPlayerBaseData->aszDispName[0] != '\0')
            {
                tstring strTmp(poPlayerBaseData->aszDispName);
                transform(strTmp.begin(), strTmp.end(), strTmp.begin(), ::tolower);
                m_mapDspName[strTmp] = poPlayerBaseData->dwID;
            }

            poPlayerBaseData->wMainHeroKindID = SDAtou( pRecordSet->GetFieldValueByName("MainHeroKindID") );//�����ŵ�һ��λ��
            poPlayerBaseData->wLevel = SDAtou( pRecordSet->GetFieldValueByName("Level") );
            poPlayerBaseData->byVipLevel = SDAtou( pRecordSet->GetFieldValueByName("VipLevel") );

            poPlayerBaseData->dwRank = SDAtou( pRecordSet->GetFieldValueByName("Rank") );
            if((0 != poPlayerBaseData->dwRank) && (0 == poPlayerBaseData->byRobotFunc))
            {
                dwMaxRank++;
                if( poPlayerBaseData->dwRank != dwMaxRank)
                {
                    vecRank2PlayerBaseDataVector.push_back(poPlayerBaseData);
                    USR_INFO(_SDT("[%s: %d]: Rank[%u] new!"), MSG_MARK, dwMaxRank);
                }
                poPlayerBaseData->dwRank = dwMaxRank; //��ȡ����ʱ�Ѿ�������˳����˳����������
                CRaceMgr::Instance()->m_mapRank2PlayerBaseData[poPlayerBaseData->dwRank] = poPlayerBaseData;
            }

            //��ȡ֪ͨ�ŵ�����ռ�
            UINT32 dwLen = pRecordSet->GetFieldLengthByName("NotifyID");
            dwLen = dwLen > MAX_TOKEN_NUM ? MAX_TOKEN_NUM : dwLen;
            memcpy(poPlayerBaseData->abyToken, pRecordSet->GetFieldValueByName("NotifyID"), dwLen);

            //��ȡ����¼�ǳ�ʱ��
            char	szTemp[256] = {0};
            memset(szTemp, 0x00, sizeof(szTemp));
            dwLen = pRecordSet->GetFieldLengthByName("LastLoginTime");
            dwLen = dwLen > sizeof(szTemp) ? sizeof(szTemp) : dwLen;
            memcpy(szTemp, pRecordSet->GetFieldValueByName("LastLoginTime"), dwLen);
            CSDDateTime oLoginTime;
            SDTimeFromString(szTemp, oLoginTime);
            poPlayerBaseData->qwLoginTime = oLoginTime.GetTimeValue();

            memset(szTemp, 0x00, sizeof(szTemp));
            dwLen = pRecordSet->GetFieldLengthByName("LastLogoffTime");
            dwLen = dwLen > sizeof(szTemp) ? sizeof(szTemp) : dwLen;
            memcpy(szTemp, pRecordSet->GetFieldValueByName("LastLogoffTime"), dwLen);
            CSDDateTime oLogofTime;
            SDTimeFromString(szTemp, oLogofTime);
            poPlayerBaseData->qwLogoffTime = oLogofTime.GetTimeValue();

            //////////////////////////////////////////////////////////////////////////
            poPlayerBaseData->dwCaptureOwner = SDAtou( pRecordSet->GetFieldValueByName("CaptureOwnerID") );

            memset(szTemp, 0x00, sizeof(szTemp));
            dwLen = pRecordSet->GetFieldLengthByName("BeCaptureOwnerTime");
            dwLen = dwLen > sizeof(szTemp) ? sizeof(szTemp) : dwLen;
            memcpy(szTemp, pRecordSet->GetFieldValueByName("BeCaptureOwnerTime"), dwLen);
            CSDDateTime oCaptureOwnerTime;
            SDTimeFromString(szTemp, oCaptureOwnerTime);
            poPlayerBaseData->qwCaptureOwnerTime = oCaptureOwnerTime.GetTimeValue();


            poPlayerBaseData->bOpenPlunder = SDAtou( pRecordSet->GetFieldValueByName("OpenPlunder") ) == 0 ? FALSE : TRUE;

            poPlayerBaseData->bEatBreadNotify = SDAtou( pRecordSet->GetFieldValueByName("EatBreadNotify") ) == 0 ? FALSE : TRUE;
            poPlayerBaseData->bBossBattleNotify = SDAtou( pRecordSet->GetFieldValueByName("BossBattleNotify") ) == 0 ? FALSE : TRUE;
            poPlayerBaseData->bCoruageNotify = SDAtou( pRecordSet->GetFieldValueByName("CourageNofity") ) == 0 ? FALSE : TRUE;
            poPlayerBaseData->dwFlowerSum = SDAtou( pRecordSet->GetFieldValueByName("FlowerSum") );

			//����
			poPlayerBaseData->dwExperience = SDAtou( pRecordSet->GetFieldValueByName("Exp") );

            //////////////////////////////////////////////////////////////////////////
            m_mapPlayerID2PlayerBaseData[poPlayerBaseData->dwID] = poPlayerBaseData;
            m_vecPlayerBaseData.push_back(poPlayerBaseData);
            m_vecPlayerBaseData_LvEx.push_back(poPlayerBaseData);
            //�ȼ�����
            if(poPlayerBaseData->wLevel <= m_wMaxPlayerLevel)
            {
                m_apmapPlayerLevel[poPlayerBaseData->wLevel][poPlayerBaseData->dwID] = poPlayerBaseData;
            }
        }

        CRaceMgr::Instance()->m_dwMaxRank = dwMaxRank;
    }
    else if(SDDB_NO_RECORDSET == nRet)
    {
        if(NULL != pRecordSet)
        {
            pRecordSet->Release();
            pRecordSet = NULL;
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    //�����б仯����������
    int		nNum = 0;
    char		szTemp[1024] = {0};
    memset(szSql, 0x00, sizeof(szSql));
    for (CRank2PlayerBaseDataVectorItr itr = vecRank2PlayerBaseDataVector.begin(); itr !=  vecRank2PlayerBaseDataVector.end(); itr++)
    {
        //����û�õ�����
        if (0 == (*itr)->dwRank)
        {
            continue;
        }

        if (0 == nNum)
        {
            memset(szSql, 0x00, sizeof(szSql));
            SDStrcat(szSql, "insert into players (PlayerID, Rank) values ");
        }
        else
        {
            SDStrcat(szSql, ",");
        }

        memset(szTemp, 0x00, sizeof(szTemp));
        sprintf(szTemp, "(%u, %u)", (*itr)->dwID, (*itr)->dwRank);
        SDStrcat(szSql, szTemp);
        nNum++;
        if (nNum >= 100)
        {
            SDStrcat(szSql, " on duplicate key update players.Rank = values(players.Rank);");
            nRet = pDBSession->ExecuteSql(szSql);
            if(nRet < 0)
            {
                USR_INFO(_SDT("[%s: %d]: exec sql failed! SQL:%s"), MSG_MARK, szSql);
                return FALSE;
            }
            nNum = 0;
            memset(szSql, 0x00, sizeof(szSql));
        }
    }
    if (nNum > 0)
    {
        SDStrcat(szSql, " on duplicate key update players.Rank = values(players.Rank);");
        nRet = pDBSession->ExecuteSql(szSql);
        if(nRet < 0)
        {
            USR_INFO(_SDT("[%s: %d]: exec sql failed! SQL:%s"), MSG_MARK, szSql);
            return FALSE;
        }
    }
    //��������
    std::sort(m_vecPlayerBaseData.begin(), m_vecPlayerBaseData.end(), sort_flower_sum);
    std::sort(m_vecPlayerBaseData_LvEx.begin(), m_vecPlayerBaseData_LvEx.end(), Csort_rank_bylvex());
    
    return TRUE;
}

VOID CPlayerBaseDataCacheMgr::UnInit()
{
    for(CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.begin(); itr != m_mapPlayerID2PlayerBaseData.end(); itr++)
    {
        m_oPlayerBaseDataPool.Free(itr->second);
    }
    m_mapPlayerID2PlayerBaseData.clear();
    m_vecPlayerBaseData.clear();
    m_vecPlayerBaseData_LvEx.clear();
}

BOOL CPlayerBaseDataCacheMgr::AddPlayerBaseData(CPlayer* poPlayer)
{
    SPlayerBaseData* poPlayerBaseData = m_oPlayerBaseDataPool.Alloc();
    if(NULL == poPlayerBaseData)
    {
        return FALSE;
    }
    const DT_PLAYER_BASE_DATA& stDT_PLAYER_BASE_DATA = poPlayer->GetDT_PLAYER_BASE_DATA();
    _SDTStrncpy(poPlayerBaseData->aszDispName, stDT_PLAYER_BASE_DATA.aszDispName, USERNAME_LEN - 1);
    poPlayerBaseData->dwID = stDT_PLAYER_BASE_DATA.dwID;
    poPlayerBaseData->wLevel = poPlayer->GetLevel();
    poPlayerBaseData->wMainHeroKindID = poPlayer->GetCoachHeroKindID();
    poPlayerBaseData->dwRank = 0; //���������û��race���ݣ��򿪾�����ʱnew
    poPlayerBaseData->dwCaptureOwner = 0;
    poPlayerBaseData->qwNotifyRankTime = 0;
    poPlayerBaseData->dwNotifyRank = 0;
    poPlayerBaseData->qwLoginTime = 0;
    poPlayerBaseData->qwLogoffTime = 0;
    CRace *poRace = NULL;
    poRace = poPlayer->GetRace();
    if (NULL != poRace)
    {
        poPlayerBaseData->qwNotifyRankTime = poRace->GetDT_RACE_BASE_DATA().qwNotifyRankTime;
        poPlayerBaseData->dwNotifyRank = poRace->GetDT_RACE_BASE_DATA().dwNotifyRank;
    }

    memcpy(poPlayerBaseData->abyToken, poPlayer->GetNoticeID(), MAX_TOKEN_NUM);
    m_mapPlayerID2PlayerBaseData[poPlayerBaseData->dwID] = poPlayerBaseData;
    m_vecPlayerBaseData.push_back(poPlayerBaseData);
    m_vecPlayerBaseData_LvEx.push_back(poPlayerBaseData);
    poPlayerBaseData->qwLoginTime = poPlayer->GetLoginTime();
    poPlayerBaseData->qwLogoffTime = poPlayer->GetLogoffTime();

    //���������û��race���ݣ��򿪾�����ʱnew
    //��������
    std::sort(m_vecPlayerBaseData.begin(), m_vecPlayerBaseData.end(), sort_flower_sum);
    std::sort(m_vecPlayerBaseData_LvEx.begin(), m_vecPlayerBaseData_LvEx.end(), Csort_rank_bylvex());
    return TRUE;
}

const SPlayerBaseData* CPlayerBaseDataCacheMgr::GetPlayerBaseData(UINT32 dwPlayerID)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        return NULL;
    }

    return itr->second;
}

UINT16 CPlayerBaseDataCacheMgr::GetLevel(UINT32 dwPlayerID)
{
    const SPlayerBaseData* pstPlayerBaseData = GetPlayerBaseData(dwPlayerID);
    if(pstPlayerBaseData)
    {
        return pstPlayerBaseData->wLevel;
    }

    return 1;
}

UINT32 CPlayerBaseDataCacheMgr::FindPlayer(const TCHAR* pszDispName)
{
    CDspNameMapItr itr = m_mapDspName.find(pszDispName);
    if(itr != m_mapDspName.end()) //�ǳƳ�ͻ
    {
        return itr->second;
    }
    else
    {
        return 0;
    }
}


UINT16 CPlayerBaseDataCacheMgr::RegDspName(UINT32 dwPlayerID, const TCHAR* pszDispName)
{
    tstring strTmp(pszDispName);
    transform(strTmp.begin(), strTmp.end(), strTmp.begin(), ::tolower);
    if(NULL == pszDispName)
    {
        return ERR_REGISTER_DSPNAME::ID_INVALID_CHARACTER;
    }
    if(m_mapDspName.find(strTmp) != m_mapDspName.end()) //�ǳƳ�ͻ
    {
        return ERR_REGISTER_DSPNAME::ID_DSPNAME_CONFLICT;
    }
    if(CCommonInfoMgr::Instance()->CkDspnameInCache(pszDispName, dwPlayerID))
    {
        return ERR_REGISTER_DSPNAME::ID_DSPNAME_CONFLICT;
    }

    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        RETURN_OTHER_ERR;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        RETURN_OTHER_ERR;
    }

    _SDTStrncpy(poPlayerBaseData->aszDispName, pszDispName, USERNAME_LEN - 1);
    poPlayerBaseData->aszDispName[USERNAME_LEN - 1] = 0;
    m_mapDspName[strTmp] = dwPlayerID;

    CCommonInfoMgr::Instance()->OnRegDspname(dwPlayerID);

    return ERR_REGISTER_DSPNAME::ID_SUCCESS;
}

BOOL CPlayerBaseDataCacheMgr::OnLevelChange(UINT32 dwPlayerID, UINT16 wLevel)
{
    if (wLevel > m_wMaxPlayerLevel)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] Level[%d] error!"), MSG_MARK, dwPlayerID, wLevel);
        return FALSE;
    }

    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return FALSE;
    }
    if(poPlayerBaseData->wLevel != wLevel)
    {
        //�Ӿɵȼ�map��ɾ��,�������µȼ�map
        m_apmapPlayerLevel[poPlayerBaseData->wLevel].erase(dwPlayerID);
        poPlayerBaseData->wLevel = wLevel;
        m_apmapPlayerLevel[wLevel][dwPlayerID] = poPlayerBaseData;
    }

    std::sort(m_vecPlayerBaseData_LvEx.begin(), m_vecPlayerBaseData_LvEx.end(), Csort_rank_bylvex());

    return TRUE;
}

/*
BOOL CPlayerBaseDataCacheMgr::OnFameChange(UINT32 dwPlayerID, UINT32 dwFame)
{
	CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
	if(itr == m_mapPlayerID2PlayerBaseData.end())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
		return FALSE;
	}
	SPlayerBaseData* poPlayerBaseData = itr->second;
	if(NULL == poPlayerBaseData)
	{
		return FALSE;
	}
	poPlayerBaseData->dwFame = dwFame;

	return TRUE;
}
*/

BOOL CPlayerBaseDataCacheMgr::OnRankNew(UINT32 dwPlayerID, UINT32 dwRank)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return FALSE;
    }

    //����map
    CRank2PlayerBaseDataMapItr itrRank;
    CRank2PlayerBaseDataMap& mapRank = CRaceMgr::Instance()->m_mapRank2PlayerBaseData;
    itrRank = mapRank.find(dwRank);

    //�������
    if (itrRank != mapRank.end())
    {
        //���ڴ��ڵ����������������ID�Ƿ���ȡ�
        if (itrRank->second->dwID != dwPlayerID)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: player[%d] Rank Is Exit!"), MSG_MARK, dwPlayerID);
            return FALSE;
        }
    }

    poPlayerBaseData->dwRank = dwRank;
    mapRank[poPlayerBaseData->dwRank] = poPlayerBaseData;
    return TRUE;
}

//����²/��²�ͷŻص�
BOOL CPlayerBaseDataCacheMgr::OnCapture(UINT32 dwPlayerID, UINT32 dwCaptureOwnerID)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        SYS_CRITICAL(_SDT("[%s: %d] player:%u deal capture:%u error!" ), MSG_MARK, dwPlayerID, dwCaptureOwnerID );
        return FALSE;
    }

    //�����Ӷ�Ļ����˲���¼��²�����ɱ������Ӷ�
    if(ERFK_PLUNDER == poPlayerBaseData->byRobotFunc)
    {
        return TRUE;
    }

    poPlayerBaseData->dwCaptureOwner = dwCaptureOwnerID;

    return TRUE;
}

BOOL CPlayerBaseDataCacheMgr::OnRankExchange(UINT32 dwPlayerID1, UINT32 dwRank1, UINT32 dwPlayerID2, UINT32 dwRank2)
{
    CPlayerID2PlayerBaseDataMapItr itr1 = m_mapPlayerID2PlayerBaseData.find(dwPlayerID1);
    if(itr1 == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID1);
        return FALSE;
    }

    CPlayerID2PlayerBaseDataMapItr itr2 = m_mapPlayerID2PlayerBaseData.find(dwPlayerID2);
    if(itr2 == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID2);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData1 = itr1->second;
    if(NULL == poPlayerBaseData1)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID1);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData2 = itr2->second;
    if(NULL == poPlayerBaseData2)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID2);
        return FALSE;
    }


    CRank2PlayerBaseDataMap& mapRank = CRaceMgr::Instance()->m_mapRank2PlayerBaseData;
    CRank2PlayerBaseDataMapItr itr3 = mapRank.find(dwRank1);
    if (itr3 == mapRank.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: Rank[%d] is not found!"), MSG_MARK, dwRank1);
        return FALSE;
    }

    CRank2PlayerBaseDataMapItr itr4 = mapRank.find(dwRank2);
    if (itr4 == mapRank.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: Rank[%d] is not found!"), MSG_MARK, dwRank2);
        return FALSE;
    }

    SPlayerBaseData* poPlayerBaseData3 = itr3->second;
    if(NULL == poPlayerBaseData3)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: Rank[%d] is not found!"), MSG_MARK, dwRank1);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData4 = itr4->second;
    if(NULL == poPlayerBaseData4)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: Rank[%d] is not found!"), MSG_MARK, dwRank2);
        return FALSE;
    }

    //��������£�ָ���ַ��һ����
    if (poPlayerBaseData1 != poPlayerBaseData3 || poPlayerBaseData2 != poPlayerBaseData4 )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: Address Not Equit !"), MSG_MARK);
        return FALSE;
    }


    //���������������ʱ��
    poPlayerBaseData1->dwRank = dwRank2;
    poPlayerBaseData1->dwNotifyRank = poPlayerBaseData1->dwRank;
    poPlayerBaseData1->qwNotifyRankTime = SDTimeSecs();

    poPlayerBaseData2->dwRank = dwRank1;
    poPlayerBaseData2->dwNotifyRank = poPlayerBaseData1->dwRank;
    poPlayerBaseData2->qwNotifyRankTime = SDTimeSecs();

    //����map
    mapRank[poPlayerBaseData1->dwRank] = poPlayerBaseData1;
    mapRank[poPlayerBaseData2->dwRank] = poPlayerBaseData2;

    return TRUE;
}


//fortest������������ʱ�ص�
//VOID CPlayerBaseDataCacheMgr::OnClrPlayerData(CPlayer* poPlayer)
//{
//    if(NULL == poPlayer)
//    {
//        return ;
//    }
//    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(poPlayer->GetDT_PLAYER_BASE_DATA().dwID);
//    if(itr == m_mapPlayerID2PlayerBaseData.end())
//    {
//        return ;
//    }
//    SPlayerBaseData* poPlayerBaseData = itr->second;
//    if(NULL == poPlayerBaseData)
//    {
//        return;
//    }
//    CRank2PlayerBaseDataMap& mapRank = CRaceMgr::Instance()->m_mapRank2PlayerBaseData;
//
//    //�о�����������������1������������������������(�������׬����)
//    BOOL bHaveDelFlag = FALSE;
//    if(0 != poPlayerBaseData->dwRank)
//    {
//        CRank2PlayerBaseDataMap::reverse_iterator itrRank = mapRank.rbegin();
//        if(itrRank != mapRank.rend())
//        {
//            SPlayerBaseData* poTailRank = itrRank->second;
//            if((poTailRank != poPlayerBaseData) && (NULL != poTailRank))
//            {
//                CRaceMgr::Instance()->ReturnRankID();//�黹�������
//                //�ȸ�����һ��������е�����������������������Ҳ����ڴ棬��ȥdbȡ
//                bHaveDelFlag = OnRankNew(poTailRank->dwID, poPlayerBaseData->dwRank);
//
//                CID2RaceMapItr itrRace = CRaceMgr::Instance()->m_mapID2Race.find(poTailRank->dwID);
//                if (CRaceMgr::Instance()->m_mapID2Race.end() != itrRace)
//                {
//                    CRace* poRace = itrRace->second;
//                    //�û���ǰ�����ڴ��У�ȥDBȡ
//                    if(NULL == poRace)
//                    {
//                        //ȡ�Է�����
//                        CGetPlayerDataMgr::Instance()->GetPlayerData(poTailRank->dwID, GET_PLAYERDATATYPE_SYNCDATA, poTailRank->dwID);
//                    }
//                    else
//                    {
//                        //poRace->SetSaveState(ESS_WANT_SAVE);
//                    }
//                }
//                else
//                {
//                    //ȡ�Է�����
//                    CGetPlayerDataMgr::Instance()->GetPlayerData(poTailRank->dwID, GET_PLAYERDATATYPE_SYNCDATA, poTailRank->dwID);
//                }
//            }
//        }
//    }
//
//    //����������ݻ���
//    if(!bHaveDelFlag)
//    {
//        mapRank.erase(poPlayerBaseData->dwRank);
//    }
//    m_mapPlayerID2PlayerBaseData.erase(itr);
//
//    for (CPlayerBaseDataVecItr itr = m_vecPlayerBaseData.begin(); itr != m_vecPlayerBaseData.end(); itr++)
//    {
//        if (*itr == poPlayerBaseData)
//        {
//            m_vecPlayerBaseData.erase(itr);
//        }
//    }
//    //��������
//    std::sort(m_vecPlayerBaseData.begin(), m_vecPlayerBaseData.end(), sort_flower_sum);
//    m_oPlayerBaseDataPool.Free(poPlayerBaseData);
//}


//ս���仯�ص�
BOOL CPlayerBaseDataCacheMgr::OnPowerChange(UINT32 dwPlayerID, UINT32 dwPower)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        // USR_INFO(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);//�½����Ҳ���,USR_INFO����
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return FALSE;
    }

    poPlayerBaseData->dwPower = dwPower;

    return TRUE;
}

//�ȹ�ֵ�仯�ص�
BOOL CPlayerBaseDataCacheMgr::OnFirstAttackChange(UINT32 dwPlayerID, UINT32 dwFirstAttack)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        // USR_INFO(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);//�½����Ҳ���,USR_INFO����
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return FALSE;
    }

    poPlayerBaseData->dwFirstAttack = dwFirstAttack;

    return TRUE;
}

//������²�ص�
BOOL CPlayerBaseDataCacheMgr::OnOpenPlunder(UINT32 dwPlayerID)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return FALSE;
    }

    poPlayerBaseData->bOpenPlunder = TRUE;

    return TRUE;
}

/*
//��ȡָ���ȼ���ָ����Ŀ�����
VOID CPlayerBaseDataCacheMgr::GetPlayerByLevel(UINT16 wLevel, UINT8 byGetNum, CPlayerBaseDataVec& vecPlayer, BOOL bNotBecapture)
{
	if(wLevel > m_wMaxPlayerLevel)
	{
		return;
	}

	if(0 == m_apmapPlayerLevel[wLevel].size())
	{
		return ;
	}

	UINT8 byLoopNum = byGetNum;
	UINT8 byMaxLoopNum = 0xFF;
	UINT8 byNum = 0;
	CPlayerID2PlayerBaseDataMapItr itrStart = m_apitrPlayerLevel[wLevel];
	for(UINT byIdx = 0; ((byIdx < byMaxLoopNum) && (byNum < byGetNum)); byIdx++)
	{
		if(m_apitrPlayerLevel[wLevel] == m_apmapPlayerLevel[wLevel].end())
		{
			m_apitrPlayerLevel[wLevel] = m_apmapPlayerLevel[wLevel].begin();
		}
		if((0 != byIdx) && (itrStart == m_apitrPlayerLevel[wLevel]))//�Ѿ���ѯһ��
		{
			break;
		}

		SPlayerBaseData* pstPlayerBaseData =  m_apitrPlayerLevel[wLevel]->second;
		//��Ҫû�б���²�����
		if(bNotBecapture)
		{
			if(!pstPlayerBaseData->bBecapture)
			{
				vecPlayer.push_back(pstPlayerBaseData);
				byNum++;
			}
		}
		else
		{
			vecPlayer.push_back(pstPlayerBaseData);
			byNum++;
		}

		m_apitrPlayerLevel[wLevel]++;
	}
}
*/

//��ȡָ���ȼ���ָ����Ŀ�����
VOID CPlayerBaseDataCacheMgr::GetPlayerByLevel(UINT32 dwMyPlayerID, UINT16 wLevel, UINT8 byGetNum, CPlayerBaseDataVec& vecPlayer,
        UINT32 dwStartPlayerID, CPlunder &oOwnPlunder, BOOL bNotBecapture)
{
    if(wLevel > m_wMaxPlayerLevel)
    {
        return;
    }

    CPlayerID2PlayerBaseDataMap& mapPlayerLevel = m_apmapPlayerLevel[wLevel];
    if(0 == mapPlayerLevel.size())
    {
        return ;
    }

    UINT8 byLoopNum = byGetNum;
    UINT8 byMaxLoopNum = 0xFF;
    UINT8 byNum = 0;
    CPlayerID2PlayerBaseDataMapItr itrStart;
    if(0 == dwStartPlayerID)//���¿�ʼ
    {
        itrStart = mapPlayerLevel.begin();
        //���¿�ʼ��Ҫд����һ�������ID��0���ܲ�������Ƿ��Ѿ�����һ�ֵıȽ�
        dwStartPlayerID = itrStart->second->dwID;
    }
    else
    {
        itrStart = mapPlayerLevel.find(dwStartPlayerID);

        //����֮ǰ���ֵ����һ�����
        if(itrStart == mapPlayerLevel.end())
        {
            itrStart = mapPlayerLevel.begin();
            dwStartPlayerID = itrStart->second->dwID;
        }
        else
        {
            itrStart++;
        }

    }

    for(UINT8 byIdx = 0; ((byIdx < byMaxLoopNum) && (byNum < byGetNum)); byIdx++, itrStart++)
    {
        if(itrStart == mapPlayerLevel.end())
        {
            itrStart = mapPlayerLevel.begin();
        }
        if((0 != byIdx) && (itrStart->second->dwID == dwStartPlayerID))//�Ѿ���ѯһ��
        {
            break;
        }

        //�����Լ�
        SPlayerBaseData* pstPlayerBaseData =  itrStart->second;
        if(dwMyPlayerID == pstPlayerBaseData->dwID)
        {
            continue;
        }

        //�ӶṦ��δ���ţ�����
        if(FALSE == pstPlayerBaseData->bOpenPlunder)
        {
            continue;
        }

        //����������
        if(0 != pstPlayerBaseData->byRobotFunc)
        {
            continue;
        }

        if( NULL != oOwnPlunder.GetCaptureMap().GetData( pstPlayerBaseData->dwID ) )
        {
            //�����Ѿ����Լ��������
            continue;
        }

        //��Ҫû�б���²�����
        if(bNotBecapture)
        {
            if(0 == pstPlayerBaseData->dwCaptureOwner)
            {
                vecPlayer.push_back(pstPlayerBaseData);
                byNum++;
            }
        }
        else
        {
            vecPlayer.push_back(pstPlayerBaseData);
            byNum++;
        }

    }

//#ifdef _DEBUG
//    for( UINT32 dwIndex = 0; dwIndex < vecPlayer.size(); dwIndex++ )
//    {
//        DBG_INFO( _SDT( "Func:%s Line:%d Index:%d get player ID:%d, self ID:%d" ),
//                  __FUNCTION__, __LINE__, dwIndex, vecPlayer[dwIndex]->dwID, dwMyPlayerID );
//    }
//#endif
}

VOID CPlayerBaseDataCacheMgr::GetPlayerByLevel(UINT32 dwMyPlayerID, UINT16 wLevel, UINT8 byGetNum, CPlayerBaseDataVec& vecPlayer,
        UINT32 dwStartPlayerID, BOOL bHaveRobot)
{
    if(wLevel > m_wMaxPlayerLevel)
    {
        return;
    }

    CPlayerID2PlayerBaseDataMap& mapPlayerLevel = m_apmapPlayerLevel[wLevel];
    if(0 == mapPlayerLevel.size())
    {
        return ;
    }

    UINT8 byLoopNum = byGetNum;
    UINT8 byMaxLoopNum = 0xFF;
    UINT8 byNum = 0;
    CPlayerID2PlayerBaseDataMapItr itrStart;
    if(0 == dwStartPlayerID)//���¿�ʼ
    {
        itrStart = mapPlayerLevel.begin();
        //���¿�ʼ��Ҫд����һ�������ID��0���ܲ�������Ƿ��Ѿ�����һ�ֵıȽ�
        dwStartPlayerID = itrStart->second->dwID;
    }
    else
    {
        itrStart = mapPlayerLevel.find(dwStartPlayerID);

        //����֮ǰ���ֵ����һ�����
        if(itrStart == mapPlayerLevel.end())
        {
            itrStart = mapPlayerLevel.begin();
            dwStartPlayerID = itrStart->second->dwID;
        }
        else
        {
            itrStart++;
        }

    }

    for(UINT8 byIdx = 0; ((byIdx < byMaxLoopNum) && (byNum < byGetNum)); byIdx++, itrStart++)
    {
        if(itrStart == mapPlayerLevel.end())
        {
            itrStart = mapPlayerLevel.begin();
        }
        if((0 != byIdx) && (itrStart->second->dwID == dwStartPlayerID))//�Ѿ���ѯһ��
        {
            break;
        }

        //�����Լ�
        SPlayerBaseData* pstPlayerBaseData =  itrStart->second;
        if(dwMyPlayerID == pstPlayerBaseData->dwID)
        {
            continue;
        }

        //����������
        if((!bHaveRobot) && (0 != pstPlayerBaseData->byRobotFunc))
        {
            continue;
        }

        vecPlayer.push_back(pstPlayerBaseData);
        byNum++;
    }

}

VOID CPlayerBaseDataCacheMgr::ReSetLoginTime(UINT32 dwPlayerID)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        USR_INFO(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);//�½����Ҳ���,USR_INFO����
        return;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return ;
    }
    poPlayerBaseData->qwLoginTime = SDTimeSecs();
}

VOID CPlayerBaseDataCacheMgr::ReSetLogoffTime(UINT32 dwPlayerID)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return ;
    }
    poPlayerBaseData->qwLogoffTime = SDTimeSecs();
}

BOOL CPlayerBaseDataCacheMgr::CkHaveDspName(const TCHAR* pszDispName)
{
    if(m_mapDspName.find(pszDispName) != m_mapDspName.end())
    {
        return TRUE;
    }

    return FALSE;
}

CPlayerIDVec CPlayerBaseDataCacheMgr::FindContainDspName(const TCHAR* pszDispName)
{
    CPlayerIDVec vecPlayerID;
    for(CDspNameMap::iterator itr = m_mapDspName.begin(); itr != m_mapDspName.end(); ++itr)
    {
        tstring strPlayerDspName = itr->first;
        UINT32 dwPlayerID = itr->second;

        if(string::npos != strPlayerDspName.find(pszDispName))
        {
            vecPlayerID.push_back(dwPlayerID);
        }
    }

    return vecPlayerID;
}


BOOL	CPlayerBaseDataCacheMgr::GetEatBreadNotify(UINT32 dwPlayerID)//�԰���֪ͨ
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return FALSE;
    }
    return poPlayerBaseData->bEatBreadNotify;
}

BOOL	CPlayerBaseDataCacheMgr::GetBossBattleNotify(UINT32 dwPlayerID)//BOSSս֪ͨ
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return FALSE;
    }
    return poPlayerBaseData->bBossBattleNotify;
}

VOID	CPlayerBaseDataCacheMgr::SetEatBreadNotify(UINT32 dwPlayerID, BOOL bValue)//�԰���֪ͨ
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return;
    }
    poPlayerBaseData->bEatBreadNotify = bValue;
}

VOID	CPlayerBaseDataCacheMgr::SetBossBattleNotify(UINT32 dwPlayerID, BOOL bValue)//BOSSս֪ͨ
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return ;
    }
    poPlayerBaseData->bBossBattleNotify = bValue;
}

BOOL	CPlayerBaseDataCacheMgr::AddFlower(UINT32 dwPlayerID, UINT32 dwFlower)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return FALSE;
    }
    poPlayerBaseData->dwFlowerSum += dwFlower;
    //��������
    std::sort(m_vecPlayerBaseData.begin(), m_vecPlayerBaseData.end(), sort_flower_sum);
    return TRUE;
}

BOOL	CPlayerBaseDataCacheMgr::SetFlower(UINT32 dwPlayerID, UINT32 dwFlower)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return FALSE;
    }
    poPlayerBaseData->dwFlowerSum = dwFlower;
    //��������
    std::sort(m_vecPlayerBaseData.begin(), m_vecPlayerBaseData.end(), sort_flower_sum);
    return TRUE;
}

UINT32	CPlayerBaseDataCacheMgr::GetFlower(UINT32 dwPlayerID)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return 0;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return 0;
    }
    return poPlayerBaseData->dwFlowerSum;
}

UINT32	CPlayerBaseDataCacheMgr::GetFlowerRanking(UINT32 dwPlayerID)
{

    UINT32 dwFlowerRanking = 1;
    //��������
    //std::sort(m_vecPlayerBaseData.begin(), m_vecPlayerBaseData.end(), sort_flower_sum);
    for (CPlayerBaseDataVecItr itr = m_vecPlayerBaseData.begin(); itr != m_vecPlayerBaseData.end(); itr++)
    {
        if ((*itr)->dwID == dwPlayerID)
        {
            break;
        }
        if (0 == (*itr)->dwFlowerSum)
        {
            dwFlowerRanking = 0;
            break;
        }
        dwFlowerRanking++;
    }
    return dwFlowerRanking;
}


// ��ȡ�ʻ���
UINT16 CPlayerBaseDataCacheMgr::GetFlowerRankingList(DT_FLOWER_RANKING_LIST_CLI& stFlowerRankingList)
{
    UINT32 dwFlowerRanking = 1;
    //��������
    //std::sort(m_vecPlayerBaseData.begin(), m_vecPlayerBaseData.end(), sort_flower_sum);
    memset(&stFlowerRankingList, 0, sizeof(DT_FLOWER_RANKING_LIST_CLI));
    for (CPlayerBaseDataVecItr itr = m_vecPlayerBaseData.begin(); itr != m_vecPlayerBaseData.end() &&
            stFlowerRankingList.dwRankingNum < MAX_FLOWER_RANKING_LIST_ELEM_NUM; itr++)
    {
        //���һ�������Ƿ����0
        if (0 == (*itr)->dwFlowerSum)
        {
            break;
        }
        DT_FLOWER_RANKING_INFO &stDT_FLOWER_RANKING_INFO = stFlowerRankingList.astListData[stFlowerRankingList.dwRankingNum++];
        stDT_FLOWER_RANKING_INFO.dwPlayerID     =	(*itr)->dwID;
        stDT_FLOWER_RANKING_INFO.qwFlowerSum    =	(*itr)->dwFlowerSum;
        stDT_FLOWER_RANKING_INFO.dwFlowerRanking	=	dwFlowerRanking++;
        // ��ȡ�����
        const SPlayerBaseData* pstPlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(stDT_FLOWER_RANKING_INFO.dwPlayerID);
        if (NULL != pstPlayerBaseData)
        {
            memcpy(stDT_FLOWER_RANKING_INFO.aszPlayerName, pstPlayerBaseData->aszDispName, USERNAME_LEN);
        }
    }
    return ERR_GET_FLOWER_RANKING::ID_SUCCESS;
}

VOID CPlayerBaseDataCacheMgr::SetCourageNotify( UINT32 dwPlayerID, BOOL bValue )
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return ;
    }
    poPlayerBaseData->bCoruageNotify = bValue;
}

BOOL CPlayerBaseDataCacheMgr::GetCourageNotify( UINT32 dwPlayerID )
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return FALSE;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return FALSE;
    }
    return poPlayerBaseData->bCoruageNotify;
}

VOID CPlayerBaseDataCacheMgr::SetVipLevel(UINT32 dwPlayerID, UINT8 byVIPLevel)
{
    CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
    if(itr == m_mapPlayerID2PlayerBaseData.end())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
        return ;
    }
    SPlayerBaseData* poPlayerBaseData = itr->second;
    if(NULL == poPlayerBaseData)
    {
        return ;
    }
    //���������ֵ
    if (byVIPLevel > CVipPropMgr::Instance()->GetMaxVipLevel())
    {
        byVIPLevel = CVipPropMgr::Instance()->GetMaxVipLevel();
    }
    poPlayerBaseData->byVipLevel = byVIPLevel;
}

VOID CPlayerBaseDataCacheMgr::SetExperience(UINT32 dwPlayerID, UINT32 dwExperience)
{
	CPlayerID2PlayerBaseDataMapItr itr = m_mapPlayerID2PlayerBaseData.find(dwPlayerID);
	if(itr == m_mapPlayerID2PlayerBaseData.end())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: player[%d] is not found!"), MSG_MARK, dwPlayerID);
		return ;
	}
	SPlayerBaseData* poPlayerBaseData = itr->second;
	if(NULL == poPlayerBaseData)
	{
		return ;
	}
	poPlayerBaseData->dwExperience = dwExperience;

    std::sort(m_vecPlayerBaseData_LvEx.begin(), m_vecPlayerBaseData_LvEx.end(), Csort_rank_bylvex());
}

VOID CPlayerBaseDataCacheMgr::GetRankByLvEx(UINT32 dwNum, CPlayerRankDataVec &m_vecPlayerRankData)
{
    CPlayerBaseDataVecConstItr itrVec = m_vecPlayerBaseData_LvEx.begin();
    UINT32 dwIndex = 0;
    for (itrVec,dwIndex; itrVec!=m_vecPlayerBaseData_LvEx.end() && dwIndex < dwNum; ++itrVec,dwIndex++)
    {
		if ( SAVE_USER_DATA <= (*itrVec)->dwID )
		{
			SPlayerRankData  stPlayerRankData;
			SDStrncpy(stPlayerRankData.aszDispName,(*itrVec)->aszDispName,USERNAME_LEN-1);
			stPlayerRankData.wLevel = (*itrVec)->wLevel;
			stPlayerRankData.dwPlayerID = (*itrVec)->dwID;
			stPlayerRankData.dwExperience = (*itrVec)->dwExperience;
			m_vecPlayerRankData.push_back(stPlayerRankData);
		}
    }
}

const CPlayerBaseDataVec& CPlayerBaseDataCacheMgr::GetPlayerBaseDatas() const {
	return m_vecPlayerBaseData;
}
