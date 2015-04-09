
#include "logicmodel.h"
#include <framework/gsconfig.h>
#include <sdutil.h>
#include <sdfile.h>
#include <logic/base/dbconfig.h>
#include <logic/player/playermgr.h>
#include <logic/hero/heromgr.h>
#include <logic/skill/skillmgr.h>
#include <logic/skill/buffmgr.h>
#include <logic/item/itemmgr.h>
#include <logic/instance/instancemgr.h>
#include <logic/build/buildmgr.h>
#include <logic/monster/monstermgr.h>
#include <logic/battle/battlemgr.h>
#include <logic/event/timereventmgr.h>
#include <logic/task/taskmgr.h>
#include <logic/race/racemgr.h>
#include <logic/shop/shopmgr.h>
#include <logic/formation/formationmgr.h>
#include <logic/talent//drugmgr.h>
#include <logic/onhook//onhookmgr.h>
#include <logic/other/singleprammgr.h>
#include <logic/encourage/encouragemgr.h>
#include <logic/plunder/plundermgr.h>
#include <logic/enemy/enemymgr.h>
#include <logic/godweapon/godweaponmgr.h>
#include <logic/player/playerbasedatacachemgr.h>
#include <logic/other/phystrengthmgr.h>
#include <logic/other/ratemgr.h>
#include <logic/other/robotmgr.h>
#include <logic/other/hpgridmgr.h>
#include <logic/chat/chatmgr.h>
#include <logic/activity/eatbreadpropmgr.h>
#include <logic/yabiao/yabiaomgr.h>
#include <logic/lua/luamgr.h>
#include <logic/other/playerbattledatarecordmgr.h>
#include <logic/other/playerbattledata2recordmgr.h>
#include <logic/other/xiangqianmgr.h>
#include <logic/notice/noticemgr.h>
#include <logic/record/recordmgr.h>
#include <logic/vip/vippropmgr.h>
#include <logic/other/commoninfomgr.h>
#include <framework/gsapi.h>
#include <db/autosqlbuf.h>
#include <logic/player/playermgr.h>
#include <logic/crop/croppropmgr.h>
#include <logic/activity/eatbreadpropmgr.h>
#include <logic/science/scienceupdatepropmgr.h>
#include <logic/updateattr/updateattrpropmgr.h>
#include <logic/other/rdchallengepropmgr.h>
#include <logic/skill/collectgaspropmgr.h>

#include "logic/activity/bossbattlemgr.h"
#include "logic/activityencourage/activityencouragemgr.h"
#include "logic/other/jsonopmgr.h"
#include "logic/faction/factionmgr.h"
#include "logic/other/gsnoticemgr.h"
#include "logic/activityencourage/oprateingactivitymgr.h"
#include "logic/other/errmsgmgr.h"
#include "logic/friendsys/sendflowerpropmgr.h"
#include "logic/friendsys/privatemsgmgr.h"
#include "logic/rareitemroom/rareitemroompropmgr.h"
#include "logic/gymnasium/gymnasiumpropmgr.h"
#include "logic/factionshade/shadepropmgr.h"
#include "logic/hotspring/hotspringpropmgr.h"
#include "db/getplayerconsume.h"

#include "logic/http/httpmgr.h"
#include "logic/http/apppayhttpcmd.h"
#include "logic/http/levelhttpcmd.h"
#include "logic/http/namehttpcmd.h"
#include "logic/http/getconfigshttpcmd.h"
#include "logic/activity/couragemgr.h"
#include "logic/plunder/plunderbasepropmgr.h"
#include "logic/other/worship.h"
#include "logic/jingjie/jingjiepropmgr.h"
#include "logic/awaken/awakenpropmgr.h"
#include "logic/awaken/awakenpropmgr2.h"
#include "logic/moneytree/moneytreepropmgr.h"
#include "logic/moneytree/moneytreepropbasemgr.h"
#include "logic/begbluegas/begbluepropmgr.h"
#include "logic/equipmaster/equipmasterpropmgr.h"
#include "logic/monster/shademonstermgr.h"
//#include "logic/vip/vipgiftpropmgr.h"
#include "logic/other/challengepromgr.h"

#include <logic/monster/playergroupmgr.h>

#include "logic/gvg/global/pullgroup.h"
#include "logic/gvg/global/gvgmgr.h"
#include "logic/gvg/local/gvgbuild.h"
#include "logic/gvg/gvgpropmgr.h"
#include "logic/player/playersnapshotmgr.h"
#include "logic/player/playerslogmgr.h"
#include "logic/gvg/gvgvideomgr.h"
#include "logic/specialeffects/specialeffectsmgr.h"
#include "logic/soul/soulpropmgr.h"
#include "logic/medal/medalpropmgr.h"
#include "logic/pet/petpropmng.h"
#include "logic/item/equip/equipmakemgr.h"
#include "logic/fly/flypropmgr.h"
#include "logic/other/exchange.h"
#include "logic/pet/petpropmng.h"
//��ģ���װ����Ϸ�߼������з�������Init��Run�������ⲿ��ܿɼ���
//�ⲿ���ģ�鲻����Logic���ֵľ���ʵ�֣�ֻ��Ҫ��ʱ����Run�������ɡ�




IMPLEMENT_SINGLETON(CLogicModel)
CLogicModel::CLogicModel()
{
    int a;
    a = 0;
}

CLogicModel::~CLogicModel()
{

}

BOOL CLogicModel::Init()
{

    CSDXMLFile oSDXMLFile;
    if (FALSE == oSDXMLFile.Load(_SDTT2A(CGSConfig::Instance()->GetConfigFile().c_str())))
    {
        return FALSE;
    }
    CSDXMLNode oRootNode = oSDXMLFile.GetRootNode();

    // ��ʼ����������������Ϣ
    if(FALSE == CDBConfig::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CDBConfig::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if(FALSE == CDBConfig::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CDBConfig Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CDBConfig Init OK!"), MSG_MARK);
    }

    // ��ʼ��CTimerEventMgr������
    if(FALSE == CTimerEventMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CTimerEventMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CTimerEventMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CTimerEventMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CTimerEventMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CSinglePramMgr������
    if(FALSE == CSinglePramMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CSinglePramMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CSinglePramMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CSinglePramMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CSinglePramMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ�� CMsgDefMgr
    if( FALSE == CMsgDefMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CMsgDefMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CMsgDefMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CMsgDefMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CMsgDefMgr Init OK!"), MSG_MARK);
    }

	//����ս��
	if ( FALSE == CPlayerLogMgr::CreateInstance())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CPlayerLogMgr::CreateInstance failed!"), MSG_MARK);
		return FALSE;
	}
	if( FALSE == CPlayerLogMgr::Instance()->Init() )
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CPlayerLogMgr Init failed!"), MSG_MARK);
		return FALSE;
	}
	else
	{
		USR_INFO(_SDT("[%s: %d]: CPlayerLogMgr Init OK!"), MSG_MARK);
	}
	//ѫ��
	if ( FALSE == CMedalPropMgr::CreateInstance())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CMedalPropMgr::CreateInstance failed!"), MSG_MARK);
		return FALSE;
	}
	if( FALSE == CMedalPropMgr::Instance()->Init() )
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CMedalPropMgr Init failed!"), MSG_MARK);
		return FALSE;
	}
	else
	{
		USR_INFO(_SDT("[%s: %d]: CMedalPropMgr Init OK!"), MSG_MARK);
	}

    // ��ʼ����Ƕ������
    if(FALSE == CXiangqianMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CXiangqianMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CXiangqianMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CXiangqianMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CXiangqianMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CLuamgr������
    if(FALSE == CLuamgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CLuamgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CLuamgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CLuamgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CLuamgr Init OK!"), MSG_MARK);
    }

    // ��ʼ������
    if(FALSE == CPhystrengthMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPhystrengthMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CPhystrengthMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPhystrengthMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CPhystrengthMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CRaceMgr������
    if(FALSE == CRaceMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRaceMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CRaceMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRaceMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CRaceMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CPlayerBaseDataCacheMgr������
    if(FALSE == CPlayerBaseDataCacheMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerBaseDataCacheMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CPlayerBaseDataCacheMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerBaseDataCacheMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CPlayerBaseDataCacheMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CSkillMgr������
    if(FALSE == CSkillMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CSkillMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CSkillMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CSkillMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CSkillMgr Init OK!"), MSG_MARK);
    }

	//��ʼ�����⼼��
	if ( FALSE == CSpecialEffectPropMgr::CreateInstance())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CSpecialEffectPropMgr::CreateInstance failed!"), MSG_MARK);
		return FALSE;
	}
	if(FALSE == CSpecialEffectPropMgr::Instance()->Init())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CSpecialEffectPropMgr Init failed!"), MSG_MARK);
		return FALSE;
	}
	else
	{
		USR_INFO(_SDT("[%s: %d]: CSpecialEffectPropMgr Init OK!"), MSG_MARK);
	}

	//��ʼ��ս��
	if ( FALSE == CSoulPropMgr::CreateInstance())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CSoulPropMgr::CreateInstance failed!"), MSG_MARK);
		return FALSE;
	}

	if(FALSE == CSoulPropMgr::Instance()->Init())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CSoulPropMgr Init failed!"), MSG_MARK);
		return FALSE;
	}
	else
	{
		USR_INFO(_SDT("[%s: %d]: CSoulPropMgr Init OK!"), MSG_MARK);
	}

	if(!CPetPropMng::Instance()->Init()) {
		SYS_CRITICAL(_SDT("[%s: %d]: PetPropMng Init failed!"), MSG_MARK);
		return FALSE;
	} else {
		USR_INFO(_SDT("[%s: %d]: PetPropMng Init OK!"), MSG_MARK);
	}

    // ��ʼ��CHeroMgr������
    if(FALSE == CHeroMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CHeroMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CHeroMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CHeroMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CHeroMgr Init OK!"), MSG_MARK);
    }


    // ��ʼ��CBuffMgr������
    if(FALSE == CBuffMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBuffMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CBuffMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBuffMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CBuffMgr Init OK!"), MSG_MARK);
    }


    // ��ʼ������
    if(FALSE == CBagPropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBagPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CBagPropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBagPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CBagPropMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CMonsterMgr������
    if(FALSE == CMonsterMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CMonsterMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CMonsterMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CMonsterMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CMonsterMgr Init OK!"), MSG_MARK);
    }

    //��ʼ��CMonsterMgr������
    if (FALSE == CShadeMonsterMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CShadeMonsterMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if(FALSE == CShadeMonsterMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CShadeMonsterMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CShadeMonsterMgr Init OK!"), MSG_MARK);
    }
    // ��ʼ��CCropPropMgr������
    if(FALSE == CCropPropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CCropPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CCropPropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CCropPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CCropPropMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CItemMgr����������ʹ�õ������̵�ǿ������������ڽ���CBuildMgr֮���ʼ��
    if(FALSE == CItemMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CItemMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CItemMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CItemMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CItemMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CInstanceMgr������
    if(FALSE == CInstanceMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CInstanceMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CInstanceMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CInstanceMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CInstanceMgr Init OK!"), MSG_MARK);
    }


    // ��ʼ��CBuildMgr������
    if(FALSE == CBuildMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBuildMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CBuildMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBuildMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CBuildMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CBattleMgr������
    if(FALSE == CBattleMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBattleMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CBattleMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBattleMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CBattleMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CTaskMgr������
    if(FALSE == CTaskMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CTaskMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CTaskMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CTaskMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CTaskMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CShopMgr������
    if(FALSE == CShopMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CShopMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CShopMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CShopMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CShopMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CFormatinMgr������
    if(FALSE == CFormationMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CFormatinMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CFormationMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CFormatinMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CFormatinMgr Init OK!"), MSG_MARK);
    }


    // ��ʼ��CDrugMgr������
    if(FALSE == CDrugMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CDrugMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CDrugMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CDrugMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CDrugMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��COnhookMgr������
    if(FALSE == COnhookMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: COnhookMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == COnhookMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: COnhookMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: COnhookMgr Init OK!"), MSG_MARK);
    }


    // ��ʼ��CEncourageMgr������
    if(FALSE == CEncourageMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CEncourageMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CEncourageMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CEncourageMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CEncourageMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CPlunderMgr������
    if(FALSE == CPlunderMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CPlunderMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CPlunderMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ����ҹ�����
    if(FALSE == CPlayerMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CPlayerMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CPlayerMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CRobotMgr������
    if(FALSE == CRobotMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRobotMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CRobotMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRobotMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CRobotMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CEnemyMgr������
    if(FALSE == CEnemyMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CEnemyMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CEnemyMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CEnemyMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CEnemyMgr Init OK!"), MSG_MARK);
    }


    // ��ʼ��CMoneyTreeMgr������
    if(FALSE == CMoneyTreePropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CMoneyTreeMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CMoneyTreePropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CMoneyTreeMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CMoneyTreeMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CMoneyTreeMgr������
    if(FALSE == CMoneyTreeBasePropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CMoneyTreeBasePropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CMoneyTreeBasePropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CMoneyTreeBasePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CMoneyTreeBasePropMgr Init OK!"), MSG_MARK);
    }



    // ��ʼ��CGodweaponMgr������
    if(FALSE == CGodweaponMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGodweaponMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CGodweaponMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGodweaponMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CGodweaponMgr Init OK!"), MSG_MARK);
    }
    // ��ʼ��CAwakenPropMgr������
    if(FALSE == CAwakenPropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CAwakenPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CAwakenPropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CAwakenPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    // ��ʼ��CAwakenPropMgr2������
    if(FALSE == CAwakenPropMgr2::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CAwakenPropMgr2::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CAwakenPropMgr2::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CAwakenPropMgr2 Init failed!"), MSG_MARK);
        return FALSE;
    }

    // ��ʼ��CRateMgr������
    if(FALSE == CRateMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRateMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CRateMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRateMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CRateMgr Init OK!"), MSG_MARK);
    }

    //��ʼ���Ƽ���
    if(FALSE == CScienceUpdatePropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CScienceUpdatePropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CScienceUpdatePropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CScienceUpdatePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CScienceUpdatePropMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��Ѻ�ڹ�����
    if(FALSE == CYabiaoMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CYabiaoMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CYabiaoMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CYabiaoMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CYabiaoMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ����������������
    if( FALSE == CUpdateAttrPropMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CUpdateAttrPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CUpdateAttrPropMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CUpdateAttrPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CUpdateAttrPropMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��HP���ӹ�����
    if( FALSE == CHPGridMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CHPGridMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CHPGridMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CHPGridMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CHPGridMgr Init OK!"), MSG_MARK);
    }

    //��ʼ������
    if( FALSE == CChatMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CChatMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CChatMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CChatMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CChatMgr Init OK!"), MSG_MARK);
    }

    //��ʼ���԰���
    if(FALSE == CEatBreadPropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CEatBreadPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CEatBreadPropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CEatBreadPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }

    //��ʼ��ս���洢��Ϣ
    if( FALSE == CPlayerBattleDataRecordMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerBattleDataRecordMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CPlayerBattleDataRecordMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerBattleDataRecordMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CPlayerBattleDataRecordMgr Init OK!"), MSG_MARK);
    }

    //��ʼ��ս���洢��Ϣ2
    if( FALSE == CPlayerBattleData2RecordMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerBattleData2RecordMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CPlayerBattleData2RecordMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerBattleData2RecordMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CPlayerBattleData2RecordMgr Init OK!"), MSG_MARK);
    }

    //��ʼ�����͹���
    if( FALSE == CNoticeMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CNoticeMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CNoticeMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CNoticeMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CNoticeMgr Init OK!"), MSG_MARK);
    }

    //��ʼ�����͹���
    if( FALSE == CJingJiePropMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CJingJiePropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CJingJiePropMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CJingJiePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CJingJiePropMgr Init OK!"), MSG_MARK);
    }



    //��ʼ�����͹���
    if( FALSE == CRecordMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRecordMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CRecordMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRecordMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CRecordMgr Init OK!"), MSG_MARK);
    }

    //��ʼ��VIP����
    if( FALSE == CVipPropMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CVipPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CVipPropMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CVipPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CVipPropMgr Init OK!"), MSG_MARK);
    }

// 	//��ʼ��VIP����
// 	if( FALSE == CVipGiftPropMgr::CreateInstance() )
// 	{
// 		SYS_CRITICAL(_SDT("[%s: %d]: CVipGiftPropMgr::CreateInstance failed!"), MSG_MARK);
// 		return FALSE;
// 	}
// 	if( FALSE == CVipGiftPropMgr::Instance()->Init() )
// 	{
// 		SYS_CRITICAL(_SDT("[%s: %d]: CVipGiftPropMgr Init failed!"), MSG_MARK);
// 		return FALSE;
// 	}
// 	else
// 	{
// 		USR_INFO(_SDT("[%s: %d]: CVipPropMgr Init OK!"), MSG_MARK);
// 	}

    //��ʼ��CBossBattleMgr
    if( FALSE == CBossBattleMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBossBattleMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CBossBattleMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBossBattleMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CBossBattleMgr Init OK!"), MSG_MARK);
    }


    //��ʼ��CCommonInfoMgr,������CPlayerBaseDataCacheMgr��ʼ����
    if( FALSE == CCommonInfoMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CCommonInfoMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CCommonInfoMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CCommonInfoMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CCommonInfoMgr Init OK!"), MSG_MARK);
    }

    // �����������
    if( FALSE == CActivityEncourageMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRechargeEncourageMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CActivityEncourageMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CActivityEncourageMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CActivityEncourageMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ�������ս
    if( FALSE == CRdChallengePropMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRdChallengePropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CRdChallengePropMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRdChallengePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CRdChallengePropMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��Ĥ��
    if( FALSE == CWorshipPropMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CWorshipPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CWorshipPropMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CWorshipPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CWorshipPropMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ����������
    if( FALSE == CScorePropMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CScorePropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if( FALSE == CScorePropMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CScorePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CScorePropMgr Init OK!"), MSG_MARK);
    }

    //��ʼCJsonOpMgr
    if( FALSE == CJsonOpMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CJsonOpMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if( FALSE == CJsonOpMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CJsonOpMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CJsonOpMgr Init OK!"), MSG_MARK);
    }

    //��ʼCGsNoticeMgr
    if( FALSE == CGsNoticeMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGsNoticeMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if( FALSE == CGsNoticeMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGsNoticeMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CGsNoticeMgr Init OK!"), MSG_MARK);
    }

    //��ʼ���ۻ�
    if( FALSE == CCollectGasPropMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CCollectGasPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if( FALSE == CCollectGasPropMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CCollectGasPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CCollectGasPropMgr Init OK!"), MSG_MARK);
    }

    if(FALSE == CBegBluePropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBegBluePropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CBegBluePropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBegBluePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CBegBlueMgr Init OK!"), MSG_MARK);
    }
    // ��ʼCOprateingActivityMgr
    if( FALSE == COprateingActivityMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: COprateingActivityMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if( FALSE == COprateingActivityMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: COprateingActivityMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: COprateingActivityMgr Init OK!"), MSG_MARK);
    }

    //��ʼ��app��ֵģ��
    if (FALSE == CHttpMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]:Create CHttpMgr failed"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CHttpMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]:init CHttpMgr failed"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CHttpMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ������
    if( FALSE == CSendFlowerMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CSendFlowerMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if( FALSE == CSendFlowerMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CSendFlowerMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CSendFlowerMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CPrivateMsgMgr
    if( FALSE == CPrivateMsgMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPrivateMsgMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if( FALSE == CPrivateMsgMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPrivateMsgMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CPrivateMsgMgr Init OK!"), MSG_MARK);
    }


    //��ʼ����������
    if( FALSE == CCourageMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CCourageMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if( FALSE == CCourageMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CCourageMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CCourageMgr Init OK!"), MSG_MARK);
    }

    //��ʼ��CRareItemRoomMgr
    if ( FALSE == CRareItemRoomPropMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRareItemRoomMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if ( FALSE == CRareItemRoomPropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRareItemRoomMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CRareItemRoomMgr Init OK!"), MSG_MARK);
    }

    //��ʼ��CGymnasiumPropMgr
    if ( FALSE == CGymnasiumPropMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGymnasiumPropMgr::CreateInstance Init failed!"), MSG_MARK);
        return FALSE;
    }

    if ( FALSE == CGymnasiumPropMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGymnasiumPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CGymnasiumPropMgr Init OK!"), MSG_MARK);
    }

    //��ʼ������CShadePropMgr
    if ( FALSE == CShadePropMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]:  CShadePropMgr::CreateInstance Init failed!"), MSG_MARK);
        return FALSE;
    }

	if ( FALSE == CShadePropMgr::Instance()->Init() )
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CShadePropMgr Init failed!"), MSG_MARK);
		return FALSE;
	}
	else
	{
		USR_INFO(_SDT("[%s: %d]: CShadePropMgr Init OK!"), MSG_MARK);
	}

    if ( FALSE == CHotSpringPropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]:  CHotSpringPropMgr::CreateInstance Init failed!"), MSG_MARK);
        return FALSE;
    }

    if ( FALSE == CHotSpringPropMgr::Instance()->Init() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CHotSpringPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CHotSpringPropMgr Init OK!"), MSG_MARK);
    }
	
    // ��ʼ��CFactionMgr������
    if (FALSE == CFactionMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CFactionMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
	if(FALSE == CFactionMgr::Instance()->Init())
	{
        SYS_CRITICAL(_SDT("[%s: %d]: CFactionMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CFactionMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��װ����ͨ
    if (FALSE == CEquipMasterPropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CEquipMasterPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if(FALSE == CEquipMasterPropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CEquipMasterPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CEquipMasterPropMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ�����
    if( FALSE == CPlayerGroupMgr::CreateInstance() )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CCourageMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CPlayerGroupMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerGroupMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CPlayerGroupMgr Init OK!"), MSG_MARK);
    }

    if(FALSE == CChallengePropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CChallengePropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CChallengePropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CChallengePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CChallengePropMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ�����ɿ��ս����
    if (FALSE == CGvGPropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGvGPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CGvGPropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGvGPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CGvGPropMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ��CGvGVideoMgr������
    if (! CGvGVideoMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGvGVideoMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(! CGvGVideoMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGvGVideoMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CGvGVideoMgr Init OK!"), MSG_MARK);
    }

    // ��ʼ�����ɿ��ս����
    if (FALSE == CGvGBuild::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGvGBuild::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if(FALSE == CGvGBuild::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGvGBuild Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CGvGBuild Init OK!"), MSG_MARK);
    }

    // ��ʼ����ҿ���
    if (FALSE == CPlayerSnapShotMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerSnapShotMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }

    if(FALSE == CPlayerSnapShotMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlayerSnapShotMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CPlayerSnapShotMgr Init OK!"), MSG_MARK);
    }

    if(!CEquipMakePropMgr::Instance()->Init()) {
        SYS_CRITICAL(_SDT("[%s: %d]: CEquipMakePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    } else {
        USR_INFO(_SDT("[%s: %d]: CEquipMakePropMgr Init OK!"), MSG_MARK);
    }

	// ��ʼ���̵�
	if (FALSE == CExchangePropMgr::CreateInstance())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CExchangePropMgr::CreateInstance failed!"), MSG_MARK);
		return FALSE;
	}

    if(!CFlyPropMgr::Instance()->Init()) {
        SYS_CRITICAL(_SDT("[%s: %d]: CFlyPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    } else {
        USR_INFO(_SDT("[%s: %d]: CFlyPropMgr Init OK!"), MSG_MARK);
    }

	if(FALSE == CExchangePropMgr::Instance()->Init())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CExchangePropMgr Init failed!"), MSG_MARK);
		return FALSE;
	}
	else
	{
		USR_INFO(_SDT("[%s: %d]: CExchangePropMgr Init OK!"), MSG_MARK);
	}


    UINT32 dwLeftTime = 0;
    UINT32 dwCaptureKeepSecond = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp().dwCaptureKeepSecond;
    CPlayerID2PlayerBaseDataMapConstItr itr;
    const CPlayerID2PlayerBaseDataMap &omapPlayerID2PlayerBaseData =  CPlayerBaseDataCacheMgr::Instance()->GetPlayerID2PlayerBaseDataMap();
    for (itr = omapPlayerID2PlayerBaseData.begin(); itr != omapPlayerID2PlayerBaseData.end(); itr++)
    {
        SPlayerBaseData* poPlayerBaseData = itr->second;
        if (0 == poPlayerBaseData->dwCaptureOwner)
        {
            continue;
        }
        UINT64 qwPassTime = SDTimeSecs() - poPlayerBaseData->qwCaptureOwnerTime;
        if (qwPassTime > dwCaptureKeepSecond)
        {
            dwLeftTime = 1;
        }
        else
        {
            dwLeftTime = dwCaptureKeepSecond - (UINT32)qwPassTime;
        }
        CTimerEventMgr::Instance()->AddReleaseCaptureEvent(poPlayerBaseData->dwCaptureOwner, poPlayerBaseData->dwID, dwLeftTime);
    }

    // ���뾺����ǰ��������Լ�������ս��
    CRaceMgr::Instance()->LoadTopRacerPower();

    //Ͷ��һ�λ�ȡ���ݵ�����
    CGetConfigsHttpCMD oCmd;
    SGetConfigs stGetConfigs;
    //�����ID�Ƿ���ȷ
    CSDServerID	oServerID(gsapi::GetLocalID());
    stGetConfigs.wZoneID = oServerID.GetAreaID();
    oCmd.SetUserData(&stGetConfigs, sizeof(SGetConfigs), 0);
    oCmd.Init();
    oCmd.OnSyncExecute();
    if( FALSE == oCmd.OnExecuted())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGetConfigsHttpCMD Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CGetConfigsHttpCMD Init OK!"), MSG_MARK);
    }

    return TRUE;
}

BOOL CLogicModel::InitGvG()
{
    // ��ʼ��CFactionMgr������
    if (FALSE == CGvGMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGvGMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CGvGMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGvGMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    else
    {
        USR_INFO(_SDT("[%s: %d]: CGvGMgr Init OK!"), MSG_MARK);
    }
    return TRUE;
}

//�˳�ǰ�Ļص����������ݵȵȣ�
BOOL CLogicModel::OnAtExit()
{
    if(CPlayerMgr::Instance() && (gsapi::GetNeedSave2DB()))
    {
        CPlayerMgr::Instance()->SaveAllPlayerData();
    }
    return TRUE;
}

VOID CLogicModel::Destroy()
{
    
}

VOID CLogicModel::Run()
{
	CBossBattleMgr::Instance()->Run();
	CHttpMgr::Instance()->Process();
	CFactionMgr::Instance()->Run();
	CJsonOpMgr::Instance()->Run();
	CGvGBuild::Instance()->Run();
	CPlayerLogMgr::Instance()->Run();

    if(CGvGMgr::Instance())
    {
        CGvGMgr::Instance()->Run();
    }
}
