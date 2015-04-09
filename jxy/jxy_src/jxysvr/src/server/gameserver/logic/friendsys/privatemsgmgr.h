#ifndef _PRIVATE_MSG_MGR_H_
#define _PRIVATE_MSG_MGR_H_

#include <sdtype.h>
#include <common/server/utility.h>
#include <common/client/commondef.h>
#include <list>
#include <sdsingleton.h>
#include <protocommondata.h>
#include <set>

typedef struct tagDT_PRIVATE_MSG_LIST_CLI DT_PRIVATE_MSG_LIST_CLI;

using namespace SGDP;

// �ӳ�ͬ����˽����Ϣ
struct SPrivateMsg
{
    UINT32	dwSenderID;	// ����ID
    UINT32	dwRecverID;	// �շ�ID
    UINT32	dwMsgIdx;		//��ˮ��
    TCHAR	aszMsgContent[PRIVATE_MSG_CONTENT_LEN]; // ��Ϣ����
    UINT64	qwSendTime;	// ����ʱ��
    INT8		byIsRead;		//�Ƿ��Ѷ�

    SPrivateMsg()
    {
        Init();
    }
    void Init()
    {
        memset(this, 0x00, sizeof(SPrivateMsg));
    }
};

//˽����Ϣ(���շ���ҷ���)
typedef std::list<SPrivateMsg> CPrivateMsgList; // keyΪ�շ����ID
typedef CPrivateMsgList::iterator CPrivateMsgListItr;
typedef CPrivateMsgList::reverse_iterator CPrivateMsgListRItr;

// �ӳ�ͬ����˽����Ϣ
struct SPrivateMsgList
{
    CPrivateMsgList	listPrivateMsg;
    UINT32           dwMaxMsgIdx;
    UINT64			qwLastTime; // ������ʱ��

    SPrivateMsgList()
    {
        dwMaxMsgIdx = 1;
        listPrivateMsg.clear();
        qwLastTime = SDTimeSecs();
    }
};

//˽����Ϣ(���շ���ҷ���)
typedef std::map<UINT64, SPrivateMsgList*> CPrivateMsgMap; // keyΪ�շ����ID
typedef CPrivateMsgMap::iterator CPrivateMsgMapItr;


class CPlayer;

class CPrivateMsgMgr
{
public:
    DECLARE_SINGLETON(CPrivateMsgMgr);

public:

    BOOL Init();

    VOID UnInit();


public:

    // �����ʱͬ����˽����Ϣsql
    UINT16 AddPrivateMsg(SPrivateMsg& stPrivateMsg);

    // �����ҵ�˽����Ϣ
    BOOL	CkPrivateMsg(UINT32 dwSenderID, UINT32 dwRecverID);

    //������Ϣ
    BOOL	SetPrivateMsgVec(UINT32 dwSenderID, UINT32 dwRecverID, SPrivateMsgList listPrivateMsg);

    UINT16 SendPrivateMsg(CPlayer* poPlayer, CPlayer* poTargetPlayer, TCHAR aszMsgContent[PRIVATE_MSG_CONTENT_LEN]);


    // 9��ȡ��ĳ��ҵ�˽�ļ�¼
    UINT16 GetPrivateMsgLogList(UINT32 dwSenderID, UINT32 dwRecverID, UINT32 dwStartIdx, UINT8 byGetMsgNum, UINT32& dwTotalNum, DT_PRIVATE_MSG_LIST_CLI& stPrivateMsgList);

    //��ʱ��������
    BOOL OnSave();

	//����Ѷ���Ϣ
	VOID AddReadMsg(UINT32 dwSendID, UINT32 dwRecvID);
protected:
    CPrivateMsgMgr();
    virtual ~CPrivateMsgMgr();

protected:

private:
	UINT64					m_dbMsgTime;
    CPrivateMsgMap			m_mapPrivateMsg; //
	set<UINT64>					m_setReadID;	//�Ѷ�����б�
    CSDObjectPool<SPrivateMsgList, CSDMutex>	m_oPrivateMsgVecPool;

    //���ݿ�仯Ҫ���������
    UINT64					m_dbLastTime;
    CPrivateMsgList			m_dbPrivateMsgList;
};

#endif // 




