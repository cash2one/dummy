
#ifndef _PLUNDERBASEPROPMGR_H_
#define _PLUNDERBASEPROPMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>


/**
 * @brief
 */
typedef struct tagPlunderBaseProp
{
    UINT16	wPlunderOpenLevel;		///< �ӶῪ�ŵȼ�
	UINT32	dwPlunderRobotStartID;	///< �Ӷ��������ʼID
    UINT16	wPlunderLowerLevelItemID;	///< �Ӷ���Լ�5�����ϵĵ���
    UINT16	wPlunderFreeTimesPerDay;	///< ÿ�������Ӷ����
    //UINT16	wPlunderMaxTimesPerDay;	///< ÿ���Ӷ�������(���+�շ�)
    UINT32	dwCaptureWorkSecond;		///< ��²����ʱ��
    UINT8	byBleedPerGoldClrMin;		///< ե��ÿԪ�����������
    UINT8	byMaxCaptureNum;			///< ����²����
    UINT32	dwCaptureKeepSecond;		///< ��²ӵ�б���ʱ��(��λ�룬���˸�ʱ�����Զ��ͷ�)
} SPlunderBaseProp;

//�ȼ�ÿ����������ͭ�Ҹ���MAP��
typedef std::map<UINT16, UINT32> CWorkCoinMap; 
typedef CWorkCoinMap::iterator CWorkCoinMapItr;

//�ȼ�ÿ�����������������MAP��
typedef std::map<UINT16, UINT32> CWorkScienceMap; 
typedef CWorkScienceMap::iterator CWorkScienceMapItr;

/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CPlunderBasePropMgr : public CBasePopMgr
{
public:
    typedef std::map<UINT16, SPlunderBaseProp> CPlunderBasePropPriMap;
    typedef std::map<UINT16, SPlunderBaseProp>::iterator CPlunderBasePropPriMapItr;

    DECLARE_SINGLETON_PROPMGR(CPlunderBasePropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_PLUNDER_BASE ; }

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

    SPlunderBaseProp& GetPlunderBaseProp()
    {
        return m_stPlunderBaseProp;
    }

    UINT16 GetPlunderLowerLevelItemID()
    {
        return m_stPlunderBaseProp.wPlunderLowerLevelItemID;
    }

	UINT64 GetWorkCoin(UINT16 wLevel)
	{
		CWorkCoinMapItr itr = m_mapWorkCoin.find(wLevel);
		if (itr != m_mapWorkCoin.end())
		{
			return itr->second;
		}
		return 0;
	}

	UINT32 GetWorkScience(UINT16 wLevel)
	{
		CWorkScienceMapItr itr = m_mapWorkScience.find(wLevel);
		if (itr != m_mapWorkScience.end())
		{
			return itr->second;
		}
		return 0;
	}
public:
    CPlunderBasePropMgr();
    virtual ~CPlunderBasePropMgr();
protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL LoadFromDB();

private:
    SPlunderBaseProp	m_stPlunderBaseProp;

	//�ȼ�ÿ����������ͭ�Ҹ���MAP��
	CWorkCoinMap		m_mapWorkCoin; 
	//�ȼ�ÿ�����������������MAP��
	CWorkScienceMap		m_mapWorkScience;
};

#endif // #ifndef _PLUNDERBASEPROPMGR_H_
