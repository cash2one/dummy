#ifndef _RECHARGEENCOURAGE_H_
#define _RECHARGEENCOURAGE_H_


#include <logic/base/baseobj.h>
#include <protocol/server/protocommondata.h>
#include <protocol/server/protocligs.h>
#include <common/server/utility.h>


using namespace SGDP;

class CPlayer;
class CActivityEncourage: public CBaseObj
{
public:
    CActivityEncourage();
    ~CActivityEncourage();

public:

    //��ʼ����ض���
    BOOL Init(DT_ACTIVITY_ENCOURAGE_DATA &stDT_ACTIVITY_ENCOURAGE_DATA, CPlayer* poOwner);

    DT_ACTIVITY_ENCOURAGE_DATA& GeDT_ACTIVITY_ENCOURAGE_DATA()
    {
        return m_stDT_ACTIVITY_ENCOURAGE_DATA;
    };

    //���ӻID
    VOID AddActivityEncourageID(UINT64 qwActivityID);

    //���ID�Ƿ����ȡ
    BOOL CkActivityEncourage(UINT64 qwActivityID);

    //����Ƿ����ȡ
    BOOL CkActivityEncourage();

    //��ȡ���ȡ����ȡ����
    UINT8 GetCanActivityEncourageNum();

    UINT16 OpenRechargeEncourage(PKT_CLILS_OPEN_RECHARGE_ENCOURAGE_ACK &stAck);
    UINT16 RecvRechargeEncourage(PKT_CLIGS_RECV_RECHARGE_ENCOURAGE_ACK &stAck);

    UINT16 OpenScoreEncourage(PKT_CLILS_OPEN_SCORE_ENCOURAGE_ACK &stAck);
    UINT16 RecvScoreEncourage(PKT_CLIGS_RECV_SCORE_ENCOURAGE_ACK &stAck);

	UINT16 GetActivityEncourageInfo(PKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK &stAck);
    UINT16 GetActivityEncourageInfo(PKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK2 &stAck);
    UINT8  GetActivityEncourageNum();
    UINT16 RecvActivityEncourage(PKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK &stAck, UINT16 wActivityID, TCHAR aszSeriesNo[MAX_SERIES_NO_NUM], BOOL bCdKeyValid);
	UINT16 RecvActivityEncourage(PKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK2 &stAck, UINT64 qwActivityID, TCHAR aszSeriesNo[MAX_SERIES_NO_NUM], BOOL bCdKeyValid);
    inline UINT8  GetLastActivityEncourageNum()
    {
        return m_byLastActivityEncourageNum;
    }
private:
    UINT8				m_byLastActivityEncourageNum;//�����ж��Ƿ񷢹ر�����
    DT_ACTIVITY_ENCOURAGE_DATA m_stDT_ACTIVITY_ENCOURAGE_DATA;//��ֵ������Ϣ
};

DECLARE_CLASS_POOL_MGR(CActivityEncourage)

#endif
