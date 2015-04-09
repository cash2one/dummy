
#ifndef _BAGPROPMGR_H_
#define _BAGPROPMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>

/**
 * @brief 
 */
typedef struct tagBagProp
{
	UINT16	wMaxOpenNum;		///< ���򿪸�����
	UINT16	wInitOpenNum;		///< ��ʼ���򿪸�����
	UINT32	dwBaseOpenCoin;		///< ��ʼ�򿪸�����Ҫ��ң���ѡ1
	UINT32	dwOpenCoinIncrease;		///< û���1���ӵ������
	UINT32	dwBaseOpenGold;		///< ��ʼ�򿪸�����ҪԪ������ѡ1
	UINT32	dwOpenGoldIncrease;		///< û���1���ӵ���Ԫ��
	UINT16  wTotalBagNum;		//�°汾��󱳰���
	string strGiftName;			//�°汾���������
	string strGiftDesc;			//�°汾��������

	tagBagProp()
	{
		wMaxOpenNum = 0;
		wInitOpenNum = 0;
		dwBaseOpenCoin = 0;
		dwBaseOpenGold = 0;
		dwOpenCoinIncrease = 0;
		dwOpenGoldIncrease = 0;
		wTotalBagNum = 0;
		strGiftDesc = "";
		strGiftName = "";
	}
}SBagProp;


class CBagPropMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CBagPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_BAG ; }

    BOOL Init();

    VOID UnInit();

    SBagProp& GetBagProp() { return  m_stBagProp; }

	UINT32 GetEnourageGold(UINT8 byOpenNum);
public:
    CBagPropMgr();
    virtual ~CBagPropMgr();

	BOOL LoadFromDB();

private:
	SBagProp m_stBagProp;
};

#endif // #ifndef _BAGPROPMGR_H_
