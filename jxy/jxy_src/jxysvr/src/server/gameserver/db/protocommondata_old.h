/*       Version Number: 10          */

#ifndef PLAYER_BASE_DATA_OLD_H_INCLUDE_VERSION_10
#define PLAYER_BASE_DATA_OLD_H_INCLUDE_VERSION_10

#include "netdata.h"
#include "sdtype.h"
#include "sdstring.h"
#include <protocol/server/protocommondata.h>
#pragma pack(push, 1)


typedef struct tagDT_COLLECT_GAS_DATA_OLD{
	UINT8            byCollectState; //�ռ�״̬,0���ɣ�1��ȡ
	DT_GAS_BALL_DATA astGasBollInfo[MAX_GAS_BALL_NUM]; //��������Ϣ
	UINT16           wLastRandomGenNum; //�ϴ������������
	UINT64           qwLastRandomGenTime; //�ϴ��������ʱ��
	UINT16           wLastPurpleGenNum; //�ϴ�������������
	UINT64           qwLastGenPurpleTime; //�ϴ�������������ʱ��
	UINT16           wLastRandomUpNum; //�ϴ������������
	UINT64           qwLastRandomUpTime; //�ϴ��������ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COLLECT_GAS_DATA_OLD;

typedef struct tagDT_JINGJIE_DATA_OLD{
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	DT_JINGJIE_BASE_DATA	stBaseData; //���������Ϣ
	DT_COLLECT_GAS_DATA_OLD stCollectData; //�����ռ���Ϣ
	DT_SKILL_ACTION_DATA_LIST stSkillActionData; //������ʽ��Ϣ�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_JINGJIE_DATA_OLD;


typedef struct tagDT_PLAYER_BASE_DATA_OLD{
	UINT32           dwID; //���ΨһID
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT64           qwCoin; //ͭǮ
	UINT64           qwGold; //Ԫ��
	UINT64           qwStory; //����
	UINT16           wPhyStrength; //��ǰ����
	UINT64           qwScience; //��ǰ�Ƽ���
	UINT8            abyGuideRecordData[MAX_GUIDE_NUM]; //������Ϣ(ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����)
	UINT8            byRobotFunc; //�����˹���,>0��Ϊ�����ˣ���ͬ��ֵΪ��ͬ�Ĺ��ܡ�0Ϊ���
	UINT32           dwPower; //ս��(���initʱ���¸�ֵ)
	UINT32           dwFirstAttack; //�ȹ�ֵ
	UINT64           qwTodayFirstLoginTime; //�����һ�ε�½ʱ��
	UINT8            byBagOpenNum; //�����򿪸�����(��ԭ��������)
	UINT64           qwBlueGas; //����
	UINT64           qwPurpleGas; //����
	UINT8            byVipLevel; //VIP�ȼ�
	UINT32           dwTotalAmount; //�ܹ���ֵԪ����
	UINT64           qwJingJie; //�����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_BASE_DATA_OLD;


typedef struct tagDT_SKILL_DATA_OLD{
	UINT16           wID; //��������ID
	UINT16           wLevel; //���ܵȼ�
	UINT16           wActionID; //ʹ����ʽ
	UINT16           wActionLevel; //ʹ����ʽ�ȼ�
	UINT16           wEffectID; //ʹ��Ч��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SKILL_DATA_OLD;

typedef struct tagDT_HERO_DATA_OLD{
	DT_HERO_BASE_DATA stHeroBaseData; //�佫������Ϣ
	DT_HERO_EQUIP_DATA_LST stEquipDataInfo; //�佫װ����Ϣ
	DT_DRUG_DATA_LST stDrugDataInfo; //��ҩ��Ϣ
	DT_GODWEAPON_DATA stGodweaponInfo; //������Ϣ
	DT_SKILL_DATA_OLD stSkillInfo; //������Ϣ
	DT_STUDY_DATA    astStudyInfo[MAX_HERO_STUDY_GRID_NUM]; //�ĵ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_DATA_OLD;


typedef struct tagDT_HERO_DATA_LIST_OLD{
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_DATA_OLD     astHeroInfoLst[MAX_HERO_NUM]; //�佫��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_DATA_LIST_OLD;

#pragma pack(pop)
#endif
