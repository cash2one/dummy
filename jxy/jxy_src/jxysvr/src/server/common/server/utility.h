

#ifndef _UTILITY_H_
#define _UTILITY_H_

/**
 * @file ʵ�ù��÷����ļ�
 *
 * �ṩһЩ�����Խ�ǿ�Ļ�����ͷ�������������ַ���
 *
 */
#include <sdtype.h>
#include <sdstring.h>
#include <sdrandom.h>
#include <vector>
#include <map>

using namespace std;

using namespace SGDP;

#ifndef MAX
#define MAX(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a,b)            (((a) < (b)) ? (a) : (b))
#endif


#define get_bit(var, n) ((var >> n) & 1)
#define set_bit(var, n) (var |= (1<<n))
#define clr_bit(var, n) (var &= ~(1<<n))


#define  AUTOCYCLE	CAutoCycle oAutoCycle(__FUNCTION__);
//�η�������dwData��byNum�η�
UINT32 power(UINT32 dwData, UINT8 byNum);

inline UINT32 GetCycleCount()
{
#ifdef _WIN32
    __asm _emit 0x0F
    __asm _emit 0x31
#else
    //UINT64 qwRet = 0;
    //__asm__ __volatile__ ("rdtsc" : "=r" (qwRet));
    //return (UINT32)qwRet;
    UINT32 low, high;
    __asm__ __volatile__("rdtsc" : "=a" (low), "=d" (high));
    return low + high;
#endif
}

INT32 RandomReseed(UINT32 dwRange);


typedef vector<UINT32> CRandomVec;
typedef CRandomVec::iterator CRandomVecItr;
typedef map<UINT32, UINT32> CRandomMap;
typedef CRandomMap::const_iterator CRandomMapItr;

#define RANDOM_UNHIT -1		//-1Ϊδ����
INT32 GetRandomIdx(CRandomVec& vecRandom, UINT32 dwTotalCent = 100); //�������еĸ������(vecRandom�е�˳��)��-1Ϊδ����. dwTotalCent��ֵ��Ĭ��100Ϊ�ٷֱ�
INT32 GetRandomIdxMustHit(CRandomVec& vecRandom); //���������㷨���������еĸ������(vecRandom�е�˳��),û�и��ʷ���0���
INT32 GetRandomIdxMustHit(CRandomVec& vecRandom, INT32 dwStart, INT32 dwEnd = 0); //���������㷨���������еĸ������(vecRandom�е�˳��),û�и��ʷ���0���

UINT32 GetRandomIdxMustHit(const CRandomMap& mapRandom);	//KeyΪ����ֵ��VlaueΪ����

//����Ŀ¼�е��ļ�,�ļ���Ϊȫ·��
VOID  ListFile(const CHAR* szDir, const CHAR* szFilePrefixName, const CHAR* szFilePostfixName, BOOL bRecursive, map<INT16, string>& mapFiles);
VOID  ListFile(const CHAR* szDir, const CHAR* szFilePrefixName, const CHAR* szFilePostfixName, BOOL bRecursive, vector<string>& vecFiles);
VOID  ListFile(const CHAR* szDir, const CHAR* szFilePostfixName, BOOL bRecursive, vector<string>& vecFiles);
//����Ŀ¼�е��ļ��У��ļ���������ȫ·����ֻ�ǵ�ǰ����
VOID  ListDir(const CHAR* szDir, const CHAR* szDirPrefixName, vector<string>& vecDirs);

//��ȡ�ַ����е�ָ��ǰ׺��׺�����Ĳ����ַ�
string GetLimitStr(const CHAR* szSrc, const CHAR* szPrefixName, const CHAR* szPostfixName = NULL);

//����Ƿ���sql�����ַ�(��)
BOOL HaveSqlToken(TCHAR* pszSrc);

//����(��)
BOOL MisplacedToken(TCHAR* pszSrc, TCHAR*pszDsc);

//����Ƿ���Utf8mb4�ַ�
BOOL CkHaveUtf8mb4(TCHAR* pszDspName);

//����Ƿ��������ַ�
BOOL CkHaveSpeCharacter(TCHAR* pszDspName);

//��ȡ��ʼ��
UINT32 GetRdNum();

//��ʼ���������
VOID InitRadomQue(UINT8 byRate, vector<UINT8>& vecRadom);

//��������
INT32 Round( DOUBLE nValue );

UINT32 AddValueByValueType(UINT64 qwSourceValue, UINT32 dwAddValue, UINT8 byAddValueType);

// UINT32ת�ַ���
string dw2str(UINT32 dwNum);

string qw2str(UINT64 qwNum);

string ToLowerByString(const TCHAR* aszString);

//����
BOOL UrlEncode(const string& strSrc, string& strOut);
//����
BOOL UrlDecode(string& str);



class CAutoCycle
{
public:
    CAutoCycle(const CHAR* pszMsg);
    ~CAutoCycle();
public:
    VOID PrintCycle(const CHAR* pszMsg = NULL);
private:
    string		m_strMsg;
    UINT32		m_dwStartCycle;
    UINT8		m_byIdx;
};

/**
 * @brief ��������,������ȡ��
 *
 * @param lDividend [in]
 * @param iDivisor [int]
 * @return int
 * @retval
 */
INT64 DivCeil(INT64 lDividend, INT64 lDivisor);
/**
 * @brief ��������,������ȡ��
 *
 * @param iDividend [in]
 * @param iDivisor [int]
 * @return int
 * @retval
 */
INT64 DivFloor(INT64 lDividend, INT64 lDivisor);


tstring Time_ToString();
tstring Time_ToString(time_t now);

//���õ�ǰ�ַ���
VOID SetLocateCharSet();

//��ȫɾ����
#define SAFE_DELETE( p ) if(p){ delete (p); p=NULL; }

//���ݿ�����ַ�������󳤶�
const INT32 SQL_STATEMENT_MAX_LEN = 1024;

//�ѷ�ת��Ϊë
UINT32 Fen2Mao( UINT32 dwNum );

// [nStart, nEnd]
INT32 Random(INT32 nStart, INT32 nEnd);

//ʮ�������ַ���תASCII
int HexToAscii(unsigned char *to, unsigned char *from, unsigned int len);
int AsciiToHex(unsigned char *to, unsigned char *from, unsigned int len);

bool IsMobile(TCHAR* pszMobile);
//����UTF-8�ַ����ȣ�Ӣ�İ�һ���ֽڣ����İ������ֽڼ���
UINT32 GetUTF8CharWidth( const TCHAR* str );
//UTF-8���ȳ�3���ֽ� return FALSE
BOOL ChkUTF8Char(  TCHAR* str );
//����emoji����
BOOL  CkEmoji(TCHAR* str);
//�����Ƿ���UTF-8
BOOL IsUTF8(TCHAR* pBuffer);


//����Ƿ��������ַ����ҳ��ȺϷ�(�ǳ�����6�������ַ���12��Ӣ��)
UINT16 CkHaveSpeCharacterAndValidLen(TCHAR* pszDspName);

class CGenerateJson
{
	struct SoulData {
		UINT16		usSoulId;
		UINT16		usSoulNum;

		SoulData() : usSoulId(0), usSoulNum(0) {
		}
	};

public:
	CGenerateJson();
	~CGenerateJson();
	string GetJson();
	VOID SetGold(UINT32 dwValue);
	VOID SetCoin(UINT32 dwValue);
	VOID SetPhystrength(UINT32 dwValue);
	VOID SetStory(UINT32 dwValue);
	VOID SetScience(UINT32 dwValue);
	VOID SetJingJie(UINT32 dwValue);
	VOID SetDoorsTribute(UINT32 dwValue);
	VOID SetBlueGas(UINT32 dwValue);
	VOID SetFactionFunds(UINT32 dwValue);
	VOID SetPurpleGas(UINT32 dwValue);
	VOID AddItem(UINT16 wKindID, UINT32 dwNum);
	VOID SetResByGm(string strKey, string strValue, vector<string>& rParam);
	VOID SetStudyExp(UINT32 dwValue);
private:
	UINT32 m_dwGold;
	UINT32 m_dwCoin;
	UINT32 m_dwPhystrength;
	UINT32 m_dwScience;
	UINT32 m_dwStory;
	UINT32 m_dwBluegas;
	UINT32 m_dwPruplegas;
	UINT32 m_dwJingjie;
	UINT32 m_dwDoorstribute;
	UINT32 m_dwFactionFunds;
	UINT32 m_dwStudyExp;
	vector<SoulData> m_vSoulData;

	map<UINT32, UINT32> m_mapItem;
};
#define CC_LOOP_DO					do{
#define CC_LOOP_WHILE(condition)		}while(condition);

#define CC_LOOP_WHILE_START(condition)	while(condition){
#define CC_LOOP_WHILE_END				};

#define CC_LOOP_FOR_START(condition)	for(condition){
#define CC_LOOP_FOR_END				};

#define CC_LOOP_BREAK(condition)		if(condition)break;
#define CC_LOOP_CONTINUE(condition)		if(condition)continue;



#define RETURN_OTHER_ERR SYS_CRITICAL(_SDT("[%s: %d]: ERR_COMMON::ID_OTHER_ERR!"), MSG_MARK); \
	return ERR_COMMON::ID_OTHER_ERR;

#define SET_OTHER_ERR(ErrCode) SYS_CRITICAL(_SDT("[%s: %d]: ERR_COMMON::ID_OTHER_ERR!"), MSG_MARK); \
	ErrCode = ERR_COMMON::ID_OTHER_ERR;



#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdmutex.h>

//�����
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#define DECLARE_CLASS_POOL_MGR( ObjType )	\
class ObjType##PoolMgr \
	{\
	public:\
		DECLARE_AUTO_SINGLETON(ObjType##PoolMgr)\
	public:\
		ObjType* Create();\
		VOID  Remove(ObjType*);\
	private:\
		CSDObjectPool<ObjType, CSDMutex>  m_objectPool;\
	};

#define IMPLEMENT_CLASS_POOL_MGR( ObjType )	\
	IMPLEMENT_AUTO_SINGLETON(ObjType##PoolMgr)\
	ObjType* ObjType##PoolMgr::Create()\
	{\
        ObjType *po##ObjType = m_objectPool.Alloc();\
        if(NULL == po##ObjType)\
        {\
            SYS_CRITICAL(_SDT("[%s: %d]: "#ObjType"PoolMgr::alloc "#ObjType" failed!"), MSG_MARK);\
        }\
        return po##ObjType;\
	}\
	VOID ObjType##PoolMgr::Remove(ObjType *pobject)\
	{\
		if(NULL == pobject)\
		{\
			return;\
		}\
		m_objectPool.Free(pobject);\
	}


//���������޹س�ʼ��
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#define DECLARE_INIT_DESTORY( ObjName, ObjType, ObjArg)	\
	public:\
		ObjType& Get##ObjName() { return *m_po##ObjName; }\
	protected:\
		BOOL		Init##ObjName(ObjArg& stData);	\
		VOID		Destory##ObjName();\
	private:\
		ObjType*	m_po##ObjName;

#define IMPLEMENT_INIT_DESTORY( ObjName, ObjType, ObjArg)	\
	BOOL	CPlayer::Init##ObjName(ObjArg& stData)\
	{\
		m_po##ObjName = NULL;\
		m_vecDestory.push_back(&CPlayer::Destory##ObjName);\
		m_po##ObjName = ObjType##PoolMgr::Instance()->Create();\
		if(NULL == m_po##ObjName)\
		{\
			SYS_CRITICAL(_SDT("[%s: %d]: Init"#ObjName"  Create  PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
			return FALSE;\
		}\
		if(!m_po##ObjName->Init(stData, this))\
		{\
			ObjType##PoolMgr::Instance()->Remove(m_po##ObjName);\
			m_po##ObjName = NULL; \
			SYS_CRITICAL(_SDT("[%s: %d]: Init"#ObjName"  Init  PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
			return FALSE;\
		}\
		return TRUE;\
	}\
	VOID CPlayer::Destory##ObjName()\
	{\
		if (NULL != m_po##ObjName) \
		{\
			ObjType##PoolMgr::Instance()->Remove(m_po##ObjName);\
			m_po##ObjName = NULL;\
		}\
	}

//�������ܳ�ʼ��
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#define DECLARE_BUILD_INIT_DESTORY( ObjName, ObjType, ObjArg)	\
	public:\
	ObjType* Get##ObjName() { return m_po##ObjName; }\
	ObjType*	New##ObjName(ObjArg& stData);\
	protected:\
	BOOL		Init##ObjName(ObjArg& stData);	\
	VOID		Destory##ObjName();\
	private:\
	ObjType*	m_po##ObjName;

//�ð汾�������жϴ��ݵĲ����Ƿ�Ϊ0�����ڼ��ݾɰ汾��
#define IMPLEMENT_BUILD_INIT_DESTORY( ObjName, ObjType, ObjArg)	\
	BOOL	CPlayer::Init##ObjName(ObjArg& stData)\
	{\
		m_po##ObjName = NULL;\
		m_vecDestory.push_back(&CPlayer::Destory##ObjName);\
		CHAR *pstData = (CHAR*)&stData;\
		BOOL byHaveDataFlag = 0;\
		for (UINT32 idx = 0; idx < sizeof(ObjArg); idx++)\
		{\
			if (0x00 != pstData[idx])\
			{\
				byHaveDataFlag = 1;\
				break;;\
			}\
		}\
		if(0 == byHaveDataFlag)\
		{\
		return TRUE;\
		}\
		stData.byHaveDataFlag = 1;\
		m_po##ObjName = ObjType##PoolMgr::Instance()->Create();\
		if(NULL == m_po##ObjName)\
		{\
		SYS_CRITICAL(_SDT("[%s: %d]: Init"#ObjName" Create  PlayID:%u"), MSG_MARK, m_dwPlayerID);\
		return FALSE;\
		}\
		if(!m_po##ObjName->Init(stData, this))\
		{\
		ObjType##PoolMgr::Instance()->Remove(m_po##ObjName);\
		m_po##ObjName = NULL;		\
		SYS_CRITICAL(_SDT("[%s: %d]: Init"#ObjName" Init  PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
		return FALSE;\
		}\
		return TRUE;\
	}\
	VOID CPlayer::Destory##ObjName()\
	{\
	if (NULL != m_po##ObjName) \
		{\
		ObjType##PoolMgr::Instance()->Remove(m_po##ObjName);\
		m_po##ObjName = NULL;\
		}\
	}\
	ObjType* CPlayer::New##ObjName(ObjArg& stData)\
	{\
		if (NULL != m_po##ObjName)\
		{\
		USR_INFO(_SDT("[%s: %d]: New"#ObjName" Error PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
		return m_po##ObjName;\
		}\
		m_vecDestory.push_back(&CPlayer::Destory##ObjName);\
		m_po##ObjName = ObjType##PoolMgr::Instance()->Create();\
		if(NULL == m_po##ObjName)\
		{\
		SYS_CRITICAL(_SDT("[%s: %d]: New"#ObjName" Create  PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
		return NULL;\
		}\
		if(!m_po##ObjName->Init(stData, this))\
		{\
		ObjType##PoolMgr::Instance()->Remove(m_po##ObjName);\
		m_po##ObjName = NULL;\
		SYS_CRITICAL(_SDT("[%s: %d]: New"#ObjName" Init  PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
		return NULL;\
		}\
		return m_po##ObjName;\
	}

//�ð汾�������жϴ��ݵĲ����Ƿ�Ϊ0�����ڼ��ݾɰ汾��
#define IMPLEMENT_BUILD_INIT_DESTORY_EX( ObjName, ObjType, ObjArg, HaveDataFlag)	\
	BOOL	CPlayer::Init##ObjName(ObjArg& stData)\
	{\
		m_po##ObjName = NULL;\
		m_vecDestory.push_back(&CPlayer::Destory##ObjName);\
		CHAR *pstData = (CHAR*)&stData;\
		BOOL byHaveDataFlag = 0;\
		for (UINT32 idx = 0; idx < sizeof(ObjArg); idx++)\
		{\
			if (0x00 != pstData[idx])\
			{\
				byHaveDataFlag = 1;\
				break;;\
			}\
		}\
		if(0 == byHaveDataFlag)\
		{\
		return TRUE;\
		}\
		stData.HaveDataFlag.byHaveDataFlag = 1;\
		m_po##ObjName = ObjType##PoolMgr::Instance()->Create();\
		if(NULL == m_po##ObjName)\
		{\
		SYS_CRITICAL(_SDT("[%s: %d]: Init"#ObjName"  Create  PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
		return FALSE;\
		}\
		if(!m_po##ObjName->Init(stData, this))\
		{\
		ObjType##PoolMgr::Instance()->Remove(m_po##ObjName);\
		SYS_CRITICAL(_SDT("[%s: %d]: Init"#ObjName"  Init  PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
		return FALSE;\
		}\
		return TRUE;\
	}\
	VOID CPlayer::Destory##ObjName()\
	{\
	if (NULL != m_po##ObjName) \
		{\
		ObjType##PoolMgr::Instance()->Remove(m_po##ObjName);\
		m_po##ObjName = NULL;\
		}\
	}\
	ObjType* CPlayer::New##ObjName(ObjArg& stData)\
	{\
		if (NULL != m_po##ObjName)\
		{\
		USR_INFO(_SDT("[%s: %d]: New"#ObjName" Creat PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
		return m_po##ObjName;\
		}\
		m_vecDestory.push_back(&CPlayer::Destory##ObjName);\
		m_po##ObjName = ObjType##PoolMgr::Instance()->Create();\
		if(NULL == m_po##ObjName)\
		{\
		SYS_CRITICAL(_SDT("[%s: %d]: New"#ObjName" Create faild PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
		return NULL;\
		}\
		if(!m_po##ObjName->Init(stData, this))\
		{\
		ObjType##PoolMgr::Instance()->Remove(m_po##ObjName);\
		m_po##ObjName = NULL;\
		SYS_CRITICAL(_SDT("[%s: %d]: New"#ObjName" Init  faild PlayerID:%u"), MSG_MARK, m_dwPlayerID);\
		return NULL;\
		}\
		return m_po##ObjName;\
	}

#define MG_NET_ERRMSG(_errns_ ,_errno_) ((sizeof(_errns_::ErrMsg) / sizeof(_errns_::ErrMsg[0])) > _errno_ ? _errns_::ErrMsg[_errno_] : ERR_COMMON::STR_OTHER_ERR)

string GetRsponeResult(UINT16 _errno_);
string GetRsponeResult(UINT16 _errno_, map<string, string> *pstrMap);
string GetRsponeResult(UINT16 _errno_, map<string, UINT32> *pstrMap);
string GetRsponeResult(UINT16 _errno_, map<string, UINT64> *pstrMap);
string GetRsponeResult(UINT16 _errno_, vector<string> *pstrVec);

// ������־��
#define	PRINT_ERR_INFO		if(CSDLoggerImpl::NeedLog(LOGLVL_SYS_CRITICAL))CSDLoggerImpl::SysCritical(_SDT("[%s: %d]: "), MSG_MARK);

#endif // #ifndef _UTILITY_H_

