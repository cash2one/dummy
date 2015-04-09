
#ifndef _PLUNDERGRIDPROPMGR_H_
#define _PLUNDERGRIDPROPMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sdhashmap.h>
#include <logic/base/basepropmgr.h>

typedef map<UINT16, UINT16> CGridUnlockPropMap;  //HashMap��lower_bound������
typedef CGridUnlockPropMap::iterator CGridUnlockPropMapItr;

/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CPlunderGridPropMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CPlunderGridPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_PLUNDER_GRID ; }

    /**
     * @brief ��ʼ�����Թ�����
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL Init();

    /**
     * @brief �������Թ�����
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    VOID UnInit();

    UINT16	GetUnlockLevel(UINT8 byGridIdx);
    UINT8	GetUnlockNum(UINT16 wLevel);
    VOID	GetUnlockGridLevel(UINT16 awUnlockGridLevel[MAX_CAPTURE_NUM])
    {
        memcpy(awUnlockGridLevel, m_awUnlockGridLevel, sizeof(m_awUnlockGridLevel));
    }

public:
    CPlunderGridPropMgr();
    virtual ~CPlunderGridPropMgr();

protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL LoadFromDB();

private:
    CGridUnlockPropMap	m_mapGridIdx2LevelProp;
    CGridUnlockPropMap	m_mapLevel2GridIdxProp;
    UINT8				m_byMaxCaptureNum;
    UINT16				m_wMaxPlayerLevel;
	UINT16				m_wMaxGridUnlockLevel; //���1�����ӽ����ȼ�
    UINT16				m_awUnlockGridLevel[MAX_CAPTURE_NUM];
};

#endif // #ifndef _PLUNDERGRIDPROPMGR_H_
