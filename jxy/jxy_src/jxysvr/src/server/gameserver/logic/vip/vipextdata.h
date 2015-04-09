#ifndef VIP_EXT_DATA_H
#define VIP_EXT_DATA_H
#include <logic/base/baseobj.h>
#include <protocol/server/protocommondata.h>
#include <common/server/utility.h>
// #include "logic/vip/vipgiftpropmgr.h"
// #include "logic/base/jsonencourage.h"
class CVipExtData: public CBaseObj
{
public:
	CVipExtData();
	~CVipExtData();
public:
	//��ʼ����ض���
	BOOL Init(DT_VIP_EXT_DATA &stDT_VIP_EXT_DATA, CPlayer* poOwner);
	DT_VIP_EXT_DATA &GetDT_VIP_EXT_DATA();
	VOID Check4ResetExperience();
	VOID Check4ResetEliteInstance();

	UINT16		GetRemainGoldExperienceNum();
	UINT16		GetRemainResetEliteInstanceNum( UINT8 byIndex );
	UINT16		GetResetEliteInstanceNum( UINT8 byIndex );
	BOOL			ResetEliteInstance( UINT8 byIndex ); //���򸱱���1��ʼ
	UINT16		GetResetEliteInstanceNum();
// public:
// 	//��ʼ�����VIP���������
// 	VOID InitGift();
// 
// 	//�����������ʱ�ĳ�ʼ������
// 	UINT8 GetOpenData(UINT32 &dwMaxVipLevel,UINT32 &dwCurVipLevel,DT_VIP_GIFT_DATA astVipGetNum[MAX_VIP_LEVEL]);
// 
// 	//��ý������󣬹�����ӿڵ���
// 	UINT8 GetGiftRes(const UINT8 &byVipLevel,TCHAR aszSeriesNo[MAX_SERIES_NO_NUM],DT_RES_ITEM_DATA &stResItemData,DT_RSYNC_RES_ITEM_DATA &stRsyncResItemData,UINT8 &byIndex, UINT16 &wElseCount);
// 
// 	//�ж��Ƿ��������ȡ
// 	BOOL HaveVipGift();
// protected:
// 	//��ý��������ش�����
// 	UINT8 GetGift(TCHAR aszSeriesNo[MAX_SERIES_NO_NUM],SVipGiftData *pVipGiftItem,DT_RES_ITEM_DATA &stResItemData,DT_RSYNC_RES_ITEM_DATA &stRsyncResItemData,const UINT8 &byIndex,UINT16 &wElseCount,const UINT8 &byVipLevel);
// 
// 	//��֤��ȡ�������Ҫ����Դ�Ƿ��㹻
// 	BOOL ChkRequireSource(UINT8 &byErrorCode,TCHAR aszSeriesNo[MAX_SERIES_NO_NUM],const SVipGiftData *pVipGiftItem);
// 
// 	//��֤��ǰ�Ĳ����Ƿ����ڽ���
// 	BOOL ChkGiftDataIsToday();
// 
// 	//�۳�����Ҫ���ĵ���Դ
// 	VOID DecRequireSource(TCHAR aszSeriesNo[MAX_SERIES_NO_NUM],const SVipGiftData *pVipGiftItem,DT_RSYNC_RES_ITEM_DATA &stRsyncResItemData);
private:
	DT_VIP_EXT_DATA		m_stDT_VIP_EXT_DATA;
};
DECLARE_CLASS_POOL_MGR(CVipExtData);
#endif