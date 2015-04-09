
#ifndef _RDCHALLENGEPROPMGR_H_
#define _RDCHALLENGEPROPMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>



class CPlayer;
class CRdChallengePropMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CRdChallengePropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_RDCHALLENGE ; }

    BOOL Init();

    VOID UnInit();
public:
	UINT16 GetMaxChallengePoint() { return m_wMaxChallengePoint; }
	UINT16 GetRdChallengeRefreshCD() { return  m_wRdChallengeRefreshCD; }
	UINT16 GetRdChallengeCD() { return  m_wRdChallengeCD; }
	UINT32 GetRefreshCoin() { return m_dwRefreshCoin; }
	UINT16 GetClrRdChallengeCDGold() { return m_wClrRdChallengeCDGold; }
public:
    CRdChallengePropMgr();
    virtual ~CRdChallengePropMgr();
protected:

    BOOL LoadFromDB();

private:
	UINT16	m_wMaxChallengePoint; //�����ս��
    UINT16	m_wRdChallengeRefreshCD;//�����ָ�1������ʱ��(��λ��)
	UINT16	m_wRdChallengeCD;//��սCD
	UINT32	m_dwRefreshCoin;//ˢ��ͭǮ
	UINT16	m_wClrRdChallengeCDGold;//�����սCDԪ��
};

#endif // 
