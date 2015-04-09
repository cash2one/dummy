// DealFrame.cpp: implementation of the CRsDealFrame class.
//
//////////////////////////////////////////////////////////////////////



#include "rsdealframe.h"
#include "common/server/ngstring.h"



/////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//GM����
enum EGMERR
{
    EGMERR_ADD_BLUEGAS = 40,	//��¶
    EGMERR_ADD_COIN = 41,	//ͭǮ
    EGMERR_ADD_EXPERCIENCE = 42,	//����
    EGMERR_ADD_GOLD = 43,//Ԫ��
    EGMERR_ADD_JINGJIE = 44,//����
    EGMERR_ADD_PHYSTRENGTH = 45,//����
    EGMERR_ADD_PURPLEGAS = 46,//����
    EGMERR_ADD_SCIENCE	=	47,//����
    EGMERR_ADD_STORY	=	48,//����
    EGMERR_ADD_STUDY	=	49,//����
    EGMERR_ADD_STUDYCLI = 50,//Ǭ����Ƭ
    EGMERR_ADD_STUDYEXP = 51,//������
    EGMERR_ADD_STUDYNOATTR = 52,//̫������
    EGMERR_ADD_ITEM = 53, //������Ʒ
    EGMERR_ADD_GOLD1 = 54, //Ԫ��1
    EGMERR_ADD_FACTION_FUNDS = 55, //���������ʽ�
    EGMERR_ADD_DOORSTRIBUTE = 56, //���������Ź�
};

//GM����
typedef struct
{
    EGMERR emErr;
    char*  strType;
    char*  strMsg;
    UINT32 uMaxValue;
} FrmTab;

//ͨ����֤���Է���
FrmTab frm_tab[] =
{
    { EGMERR_ADD_BLUEGAS,		"bluegas",		"������¶��������",			1000000},
    { EGMERR_ADD_COIN,		"coin",			"����ͭǮ��������",			2000000000},
    { EGMERR_ADD_EXPERCIENCE,	"experience",		"���Ӿ��鳬������",			1000000},
    { EGMERR_ADD_GOLD,		"gold",			"����Ԫ����������",			200000},
    { EGMERR_ADD_JINGJIE,		"jingjie",		"���Ӿ��糬������",			1000000},
    { EGMERR_ADD_PHYSTRENGTH,	"phystrength",	"����������������",			10000},
    { EGMERR_ADD_PURPLEGAS,	"purplegas",		"���ӹ�����������",			1000000},
    { EGMERR_ADD_SCIENCE,		"science",		"�������곬������",			1000000},
    { EGMERR_ADD_STORY,		"story",			"����������������",			1000000},
    { EGMERR_ADD_STUDY,		"study",			"�������񳬹�����",			1000000},
    { EGMERR_ADD_STUDYCLI,		"studyclip",		"����Ǭ����Ƭ��������",		100},
    { EGMERR_ADD_STUDYEXP,		"studyexp",		"���������鳬������",		1000000},
    { EGMERR_ADD_STUDYNOATTR,	"studynoattr",	"����̫�����񳬹�����",		100},
    { EGMERR_ADD_ITEM,		"item",			"������Ʒ��������",			100},
    { EGMERR_ADD_GOLD1,		"gold1",			"����Ԫ��1��������",			100000},
    { EGMERR_ADD_FACTION_FUNDS,"factionfunds",	"���������ʽ𳬹�����",		100000},
    { EGMERR_ADD_DOORSTRIBUTE,	"doorstribute",	"���������Ź���������",		100000},
	{ EGMERR_ADD_DOORSTRIBUTE,	"soul",	"����ս�곬������",		255},
	{ EGMERR_ADD_DOORSTRIBUTE,	"pet",	"���ӳ��ﳬ������",		250}
};


namespace InterfaceDealBase
{
CRsDealFrame::CRsDealFrame()
{
    m_pManager = NULL;
}

CRsDealFrame::CRsDealFrame(CRsManager * IN_pManager): m_pManager(IN_pManager)
{

}

CRsDealFrame::~CRsDealFrame()
{
    Release();
}

bool CRsDealFrame::init(CRsManager * IN_pManager)
{
    m_pManager = IN_pManager;
    RegisterDealFrame(this);
    return TRUE;
}
void CRsDealFrame::Release()
{

}

//ע�ᴦ�����������ָ��Ķ�Ӧ��ϵ
void CRsDealFrame::RegisterDealFrame(CRsDealFrame *v_pDealFrame)
{
    if(m_pManager)
        m_pManager->RegisterDealFrame(v_pDealFrame);
}

bool CRsDealFrame::CkAddLimit( string strKey , UINT32 unAddNum)
{
    for (unsigned int i = 0; i < sizeof(frm_tab) / sizeof(FrmTab); i++)
    {
        if (0 == strcmp(frm_tab[i].strType, strKey.c_str()))
        {
            if (frm_tab[i].uMaxValue < unAddNum)
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}


CRsManager::CRsManager()
{
    m_pInstance = this;
}


CRsManager::~CRsManager()
{
    Release();
}


//��ȡ������ʵ��
CRsManager* CRsManager::instance()
{
    return m_pInstance;
}


void CRsManager::Release()
{
    try
    {
        for(MapTaskIter itr = m_mapTask.begin(); itr != m_mapTask.end(); itr++ )
        {
            itr->second->Release();
            delete itr->second;
        }
        m_mapTask.clear();
    }
    catch(...)
    {
        return ;
    }
    return ;
}


//ע�ᴦ�����������ָ��Ķ�Ӧ��ϵ
void CRsManager::RegisterDealFrame(CRsDealFrame * IN_pDealFrame)
{
    m_mapTask.insert(std::make_pair(IN_pDealFrame->GetFrameType(), IN_pDealFrame));
}

//��ȡ����ָ��
CRsDealFrame * CRsManager::GetInstanceByType(string strKey)
{
    MapTaskIter         iter;
    iter = m_mapTask.find(strKey);
    if( m_mapTask.end() == iter )
    {
        return NULL;
    }
    return iter->second;
}


BOOL CRsManager::Deal( string strKey, CPlayer* poPlayer, vector<string> vecOpValue, UINT8 byOpType, UINT32 dwNum1, UINT32 dwNum2, UINT32 dwNum3, TCHAR *pszDesc, DT_PLAYER_RES_DATA* pstResInfo1, DT_PLAYER_RES_DATA* pstResInfo2)
{
    InterfaceDealBase::CRsDealFrame *pDeal = GetInstanceByType(strKey);
    if(NULL != pDeal)
    {
        return pDeal->Deal(poPlayer, vecOpValue, byOpType, dwNum1, dwNum2, dwNum3, pszDesc, pstResInfo1, pstResInfo2);
    }
    //����û�в��ҵ��ģ�ֱ������Ʒ����ӿڡ�
    pDeal = GetInstanceByType("item");
    if (NULL != pDeal)
    {
        return pDeal->Deal(poPlayer, vecOpValue, byOpType, dwNum1, dwNum2, dwNum3, pszDesc, pstResInfo1, pstResInfo2);
    }
    return FALSE;
}

string CRsManager::GetAddLimitMsg( string strKey )
{
    for (unsigned int i = 0; i < sizeof(frm_tab) / sizeof(FrmTab); i++)
    {
        if (0 == strcmp(frm_tab[i].strType, strKey.c_str()))
        {
            CNGString strMsg;
            strMsg += "{\"errno\":";
            strMsg += frm_tab[i].emErr;
            strMsg += ",\"desc\":\"";
            strMsg += SDGBK2UTF8(frm_tab[i].strMsg);
            strMsg += "\"}";

            return strMsg.str();
        }
    }

    return string("");
}

}





