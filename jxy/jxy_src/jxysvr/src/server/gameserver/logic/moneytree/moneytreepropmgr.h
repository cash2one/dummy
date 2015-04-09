
#ifndef _MONEYTREEPROPMGR_H_
#define _MONEYTREEPROPMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>


/**
 * @brief
 */
typedef struct tagMoneyTreeProp
{
	tagMoneyTreeProp()
	{
		Init();
	}
	void Init()
	{
		memset(this, 0x00, sizeof(tagMoneyTreeProp));
	}

    //UINT16	wRockNumPerDay;		///< ÿ���ҡ����
    //UINT16	wBaseGold;		///< ��Ҫ�Ļ���Ԫ��
    //UINT16	wIncGold;		///< ÿ��ҡһ�����ӵ�Ԫ��
    //UINT16	wMaxGold;		///< �������Ԫ��
	
	UINT16	wMoodValue;			///< ����ֵ
    UINT16	wIncCoinRate;		///< ������ֵ���ӵ�ͭ�Ұٷֱ�
    UINT8	byGetMoodRate;		///< ÿ��ҡǮ�������ֵ�ĸ���
    UINT16	wMoodKeepTime;		///< ������ֵ����ʱ��(��λ��)
} SMoneyTreeProp;


typedef std::map<UINT16, SMoneyTreeProp> CMoneyTreePropMap; 
typedef CMoneyTreePropMap::iterator CMoneyTreePropMapItr;

/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CMoneyTreePropMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CMoneyTreePropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_MONEY_TREE ; }
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


	UINT8 GetMoneyTreeMoodRate(UINT16 wMoodValue); //ҡǮ�������ֵ�ĸ���

	UINT16 GetMoneyTreeIncMoneyRate(UINT16 wMoodValue); //��ø�����ֵ���ӵ�ͭ�Ұٷֱ�

	UINT16 GetMoodKeepTime()
	{
		CMoneyTreePropMapItr itr = m_MoneyTreePropMap.begin();
		if (itr != m_MoneyTreePropMap.end())
		{
			return itr->second.wMoodKeepTime;
		}
		return 600;
	}

	UINT16 GetMoodKeepTime(UINT16	wMoodValue)
	{
		CMoneyTreePropMapItr itr = m_MoneyTreePropMap.find(wMoodValue);
		if (itr != m_MoneyTreePropMap.end())
		{
			return itr->second.wMoodKeepTime;
		}
		return 0;
	}
	BOOL IsExist(UINT16	wMoodValue)
	{
		CMoneyTreePropMapItr itr = m_MoneyTreePropMap.find(wMoodValue);
		if (itr != m_MoneyTreePropMap.end())
		{
			return TRUE;
		}
		return FALSE;
	}


public:
    CMoneyTreePropMgr();
    virtual ~CMoneyTreePropMgr();

protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL LoadFromDB();

private:
    CMoneyTreePropMap	m_MoneyTreePropMap;
};

#endif // #ifndef _MONEYTREEPROPMGR_H_
