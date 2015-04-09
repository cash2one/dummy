
#ifndef _GODWEAPONBASEPROPMGR_H_
#define _GODWEAPONBASEPROPMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>


/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CGodweaponBasePropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CGodweaponBasePropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_GODWEAPON_BASE ; }
	

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

	UINT32  GetActiveCoin() { return m_dwActiveCoin; }
	UINT8	GetGodWeaponRecoverRate() { return m_byGodWeaponRecoverRate; }
	UINT16	GetUpgradeQualityItemID() { return m_wUpgradeQualityItemID; }
	UINT8	GetQualityUpdateNum() { return m_byQualityUpdateNum; }

public:
    CGodweaponBasePropMgr();
    virtual ~CGodweaponBasePropMgr();

protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
	BOOL LoadFromDB();

private:
	UINT32	m_dwActiveCoin;	///< ������������ͭ��
	UINT8	m_byGodWeaponRecoverRate;//����������հٷֱȱ���
	UINT16	m_wUpgradeQualityItemID;///< ���׷���Ӧ�ľ������ID
	UINT8	m_byQualityUpdateNum;	///< ÿ��Ʒ���ܹ�����������,��0����ʼ
};

#endif // #ifndef _PLUNDERBASEPROPMGR_H_
