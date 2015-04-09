
#ifndef _MONEYTREEPROPBASEMGR_H_
#define _MONEYTREEPROPBASEMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>



/**
 * @brief
 */
//typedef struct tagMoneyTreeBaseProp
//{
//    //UINT16	wRockNumPerDay;		///< ÿ���ҡ����
//    //UINT16	wBaseGold;		///< ��Ҫ�Ļ���Ԫ��
//    //UINT16	wIncGold;		///< ÿ��ҡһ�����ӵ�Ԫ��
//    //UINT16	wMaxGold;		///< �������Ԫ��
//} SMoneyTreeBaseProp;

/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CMoneyTreeBasePropMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CMoneyTreeBasePropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_MONEY_TREE_BASE ; }
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


    //SMoneyTreeBaseProp& GetMoneyTreeBaseProp()
    //{
    //    return m_stMoneyTreeBaseProp;
    //}

    UINT32	GetProduceCoin(UINT32 dwPlayerLevel, UINT8 byMoodValue);

    UINT32	GetRockNeedGold(CPlayer* poPlayer, UINT16 wCurRockNum);

public:
    CMoneyTreeBasePropMgr();
    virtual ~CMoneyTreeBasePropMgr();

protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL LoadFromDB();

//private:
//    SMoneyTreeBaseProp	m_stMoneyTreeBaseProp;
};

#endif // #ifndef _MONEYTREEPROPBASEMGR_H_
