
#ifndef _JSON_ENCOURAGE_H_
#define _JSON_ENCOURAGE_H_

#include <sdtype.h>
#include <json/json.h>
#include <string.h>
#include <string>
#include "logic/record/recordmgr.h"

using namespace std;
class	CPlayer;
struct	tagDT_RES_ITEM_DATA;
typedef	tagDT_RES_ITEM_DATA DT_RES_ITEM_DATA;

struct	tagDT_RSYNC_RES_ITEM_DATA;
typedef	tagDT_RSYNC_RES_ITEM_DATA DT_RSYNC_RES_ITEM_DATA;

struct	tagDT_RES_NUM_ITEM_DATA;
typedef	tagDT_RES_NUM_ITEM_DATA DT_RES_NUM_ITEM_DATA;

struct tagDT_ATTR_BASE_DATA;
typedef tagDT_ATTR_BASE_DATA DT_ATTR_BASE_DATA;


#define	 BAG_FULL_ERR 1
#define	 HERO_CARRY_FULL 2

enum em_Percent
{
	em_SINGLE	=	1,
	em_All		=	2,
};

//������Ϣ
typedef struct tagJsonResItem
{
    UINT32	dwKindValue;					//��ƷID,�佫ID,���ꡢԪ����ͭǮ��
    UINT8	byKindType;					//��Ʒ����,1���佫
    UINT8	byNum;						//��Ʒ����
    UINT16	wPercent;					//�ٷֱ�
    tagJsonResItem()
    {
        Init();
    }
    void Init()
    {
        memset(this, 0x00, sizeof(tagJsonResItem));
    }
} CJsonResItem;

typedef std::vector<CJsonResItem>		CJsonResItemVector; //keyΪLevel
typedef CJsonResItemVector::iterator	CJsonResItemVectorItr;

typedef struct _tagJsonResItemVectorInfo
{
    em_Percent emPercent;
    CJsonResItemVector vecJsonResItem;
    _tagJsonResItemVectorInfo()
    {
        emPercent = em_SINGLE;
        vecJsonResItem.clear();
    }
} CJsonResItemVectorInfo;





BOOL		JsonParseResItem(CJsonResItemVectorInfo &JsonResItemVectorInfo, string strJson);

BOOL		JsonParseResItem(CJsonResItemVectorInfo &JsonResItemVectorInfo, Json::Value &root);

//�����Դ�б�
//ͬ����Դ�б�
UINT16	JsonGetResItemVec(CJsonResItemVectorInfo &JsonResItemVectorInfo, CPlayer*, DT_RES_ITEM_DATA &stGainResItemData, DT_RSYNC_RES_ITEM_DATA &stRsyncResItemData, DT_RES_NUM_ITEM_DATA &stResNumItemData, CRecordMgr::EAddItemType emOpType);

void		JsonPackResItem(CJsonResItemVectorInfo& JsonResItemVectorInfo, DT_RES_ITEM_DATA &stDT_RES_ITEM_DATA);

UINT16      JsonGetResItem(CJsonResItem &stItem, CPlayer* poPlayer, DT_RES_ITEM_DATA &stGainResItemData, DT_RSYNC_RES_ITEM_DATA &stRsyncResItemData, DT_RES_NUM_ITEM_DATA &stResNumItemData, CRecordMgr::EAddItemType emOpType);

typedef vector<DT_ATTR_BASE_DATA> CVecJsonAttrBase;
typedef CVecJsonAttrBase::const_iterator CVecJsonAttrBaseItr;

BOOL   JsonParseAttrJson(CVecJsonAttrBase &JsonAttrVectorInfo, string strJson);
BOOL   JsonParseAttrJson(CVecJsonAttrBase &JsonAttrVectorInfo, Json::Value &root);
#endif

