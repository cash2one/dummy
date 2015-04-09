#include "loginencouragerecord.h"
#include "loginencouragemgr.h"
#include "onlineencouragemgr.h"
#include <net/db/dbpktbuilder.h>
#include <db/autosqlbuf.h>
#include <logic/player/player.h>
#include <common/client/errdef.h>
#include <logic/other/singleprammgr.h>
#include "logic/record/recordmgr.h"
#include <logic/base/basedefine.h>
#include <logic/other/state.h>
#include <logic/bag/bag.h>
#include <logic/item/itemmgr.h>
#include <sdloggerimpl.h>

IMPLEMENT_CLASS_POOL_MGR(CLoginEncourageRecord)
CLoginEncourageRecord::CLoginEncourageRecord()
{
    memset(&m_stDT_LOGIN_ENCOURAGE_RECORD_DATA, 0 , sizeof(m_stDT_LOGIN_ENCOURAGE_RECORD_DATA));
}

CLoginEncourageRecord::~CLoginEncourageRecord()
{

}

BOOL CLoginEncourageRecord::Init(DT_LOGIN_ENCOURAGE_RECORD_DATA &stDT_ONLINE_ENCOURAGE_RECORD_DATA, CPlayer* poOwner)
{
    if(NULL == poOwner)
    {
        return FALSE;
    }

    memcpy(&m_stDT_LOGIN_ENCOURAGE_RECORD_DATA, &stDT_ONLINE_ENCOURAGE_RECORD_DATA, sizeof(DT_LOGIN_ENCOURAGE_RECORD_DATA));
    m_poOwner = poOwner;

    return TRUE;
}

UINT16 CLoginEncourageRecord::GetEncourageInfo(DT_LOGIN_ENCOURAG_DATA& stLoginEncourageInfo)
{
    CSDDateTime oNow = SDNow();

    //ע���ǳƺ�ڶ���ſ�����ȡ��¼����
    if(0 == m_poOwner->GetDT_PLAYER_BASE_DATA().aszDispName[0])
    {
        stLoginEncourageInfo.byCanRecvNumToday = 0;
        return  ERR_LOGIN_ENCOURAGE::ID_SUCCESS;
    }
    else
    {
            if(IsToday(m_poOwner->GetState().GetDT_STATE_DATA().qwRegisterDispNameTime)) //����ע����ǳƣ�������ȡ
            {
                stLoginEncourageInfo.byCanRecvNumToday = 0;
                return  ERR_LOGIN_ENCOURAGE::ID_SUCCESS;
            }
    }


    UINT8 byLoginEncourageKeepDays = CSinglePramMgr::Instance()->GetLoginEncourageKeepDays();
    //�ж�ʱ��
    CSDDateTime oLastTime(m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.qwLastRecvTime);

    INT32 nGap = 0;
    //��һ�ε�¼����
    if(0 == m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.qwLastRecvTime)
    {
        m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays = 1;
    }
    else if(0 == (nGap = oNow.DiffDateDay(oLastTime))) //�ϴε�¼ʱ���� ����
    {
        //�ϴε�δ���뱳���У�StateFlag״̬(LastSelectIndex��Ϊ0ʱ��Ч)(0���·���1��ѡ��2�����)��
        if((0 != m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastSelectIndex) && (2 != m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byStateFlag))
        {
            //δѡ����ʾ�ͻ���δѡ�񣬶�Ӧ��������˵�ϴδ��Ѿ���taѡ����ˣ������ٴ�ѡ�񣬷������ױ���������ظ�ˢ���õ��߲ŷű�����
            if(0 == m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byStateFlag)
            {
                stLoginEncourageInfo.byHaveSelectFlag = 0;
            }
            //��ѡ����ʾ�ͻ���δѡ��
            if(1 == m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byStateFlag)
            {
                stLoginEncourageInfo.byHaveSelectFlag = 1;//�Ѿ�ѡ����������ٴ����ѡ
            }
            stLoginEncourageInfo.byHitIdx = m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastSelectIndex;
            stLoginEncourageInfo.wKeepDays = m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays;
            stLoginEncourageInfo.byCanRecvNumToday = m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays >  byLoginEncourageKeepDays ?
                    (byLoginEncourageKeepDays - m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum) : (m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays - m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum);
            //ȡ������Ϣ
            CLoginEncourageMgr::Instance()->GetEncourageItem(stLoginEncourageInfo.astItemInfo);

            return ERR_LOGIN_ENCOURAGE::ID_SUCCESS;
        }

        if((m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum >= m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays) ||
                (m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum >= byLoginEncourageKeepDays))
        {
            return ERR_LOGIN_ENCOURAGE::ID_USE_OUT_NUM;
        }
    }
    else if(1 == nGap)//�ϴε�¼ʱ���� ���죬��������¼����++
    {
        m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays++;
        m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum = 0;
    }
    else //����������¼�������ã���1��ʼ
    {
        m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays = 1;
        m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum = 0;
    }

    //��¼
    m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.qwLastRecvTime = SDTimeSecs();
    m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastSelectIndex = CLoginEncourageMgr::Instance()->RateHitItem();
    m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byStateFlag = 0;

    stLoginEncourageInfo.byHitIdx = m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastSelectIndex;
    stLoginEncourageInfo.byHaveSelectFlag = 0;
    stLoginEncourageInfo.wKeepDays = m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays;
    stLoginEncourageInfo.byCanRecvNumToday = m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays >  byLoginEncourageKeepDays ?
            (byLoginEncourageKeepDays - m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum) : (m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays - m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum);

    stLoginEncourageInfo.byHitIdx = CLoginEncourageMgr::Instance()->RateHitItem();

    //ȡ������Ϣ
    CLoginEncourageMgr::Instance()->GetEncourageItem(stLoginEncourageInfo.astItemInfo);

    //SetSaveState(ESS_WANT_SAVE);//��������

    return  ERR_LOGIN_ENCOURAGE::ID_SUCCESS;
}


VOID CLoginEncourageRecord::OnRate()
{
    //StateFlag״̬(LastSelectIndex��Ϊ0ʱ��Ч)(0���·���1��ѡ��2�����)
    if(0 != m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byStateFlag)
    {
        return;
    }

    m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byStateFlag = 1;
    m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum++;
    //SetSaveState(ESS_WANT_SAVE);//��������
}

UINT16 CLoginEncourageRecord::PutIntoBag(UINT8& byHaveEncourageFlag, DT_LOGIN_ENCOURAG_DATA& stLoginEncourageInfo)
{
    if((m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastSelectIndex < 1) || (m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastSelectIndex > MAX_LOGIN_ENCOURAGE_ITEM_NUM))
    {
        RETURN_OTHER_ERR;
    }

    //StateFlag״̬(LastSelectIndex��Ϊ0ʱ��Ч)(0���·���1��ѡ��2�����)
    if(1 != m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byStateFlag)
    {
        return ERR_LOGIN_ENCOURAGE::ID_STATE_INVALID;
    }

    SLoginEncourageProp* pstLoginEncourageProp = CLoginEncourageMgr::Instance()->GetLoginEncourageProp(m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastSelectIndex);
    if(NULL == pstLoginEncourageProp)
    {
        RETURN_OTHER_ERR;
    }
    CBag& oBag = m_poOwner->GetBag();
    if((oBag.GetIdleSize() == 0) && (NULL == oBag.GetGoodsItem(pstLoginEncourageProp->wItemKindID)))
    {
        return ERR_LOGIN_ENCOURAGE::ID_BAG_FULL;
    }

    //��������ֱ��ʹ�õ�����Ʒ������뱳����
    if(!CItemMgr::Instance()->SysUseGoods(m_poOwner, pstLoginEncourageProp->wItemKindID, pstLoginEncourageProp->wPileNum))
    {
        ECreateItemRet eRet;
        if( NULL == CItemMgr::Instance()->CreateItemIntoBag(
                    m_poOwner, pstLoginEncourageProp->wItemKindID, pstLoginEncourageProp->wPileNum, eRet, 0, CRecordMgr::EAIT_LOGINENCOURAGE) )
        {
            //�쳣
            SYS_CRITICAL(_SDT("[%s: %d]: give login encourage record failed: CreateItemIntoBag failed, PlayerID:%u, ItemKindID = %u, pilenum = %u" ), MSG_MARK, 
                m_poOwner->GetID(), pstLoginEncourageProp->wItemKindID, pstLoginEncourageProp->wPileNum);

            return ERR_LOGIN_ENCOURAGE::ID_BAG_FULL;
        }
    }

    m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byStateFlag = 2;//���뱳��״̬

    //��ȡ�¸�������Ϣ
    if(ERR_LOGIN_ENCOURAGE::ID_SUCCESS == GetEncourageInfo(stLoginEncourageInfo))
    {
        byHaveEncourageFlag = 1;
    }

    //SetSaveState(ESS_WANT_SAVE);//��������

    return ERR_LOGIN_ENCOURAGE::ID_SUCCESS;
}

//��¼����״̬(0,������ʾ��1����ʾ��2�赯��)
UINT8 CLoginEncourageRecord::GetLoginEncourageState()
{


    //ע���ǳƺ�ڶ���ſ�����ȡ��¼����
    if(0 == m_poOwner->GetDT_PLAYER_BASE_DATA().aszDispName[0])
    {
        return 0;
    }
    else
    {
        if(IsToday(m_poOwner->GetState().GetDT_STATE_DATA().qwRegisterDispNameTime)) //����ע����ǳƣ�������ȡ
        {
            return 0;
        }
    }

    UINT8 byLoginEncourageKeepDays = CSinglePramMgr::Instance()->GetLoginEncourageKeepDays();
    //�ж�ʱ��
    CSDDateTime oNow = SDNow();
    CSDDateTime oLastTime(m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.qwLastRecvTime);

    INT32 nGap = 0;
    //��һ�ε�¼����
    if(0 == m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.qwLastRecvTime)
    {
        return 2;
    }
    if(0 == (nGap = oNow.DiffDateDay(oLastTime))) //�ϴε�¼ʱ���� ����
    {
        //�ϴε�δ���뱳���У�StateFlag״̬(LastSelectIndex��Ϊ0ʱ��Ч)(0���·���1��ѡ��2�����)��
        if((0 != m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastSelectIndex) && (2 != m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byStateFlag))
        {
            return 1;
        }

        //�Ѿ���ȡ�����д���
        if((m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum >= m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.wKeepDays) ||
                (m_stDT_LOGIN_ENCOURAGE_RECORD_DATA.byLastRecvNum >= byLoginEncourageKeepDays))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else//�ϴε�¼ʱ�䲻�ǽ���,�赯��
    {
        return 2;
    }

    return 0;
}



