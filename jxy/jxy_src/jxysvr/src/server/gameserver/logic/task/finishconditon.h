#ifndef _FINISHCONDITON_H
#define _FINISHCONDITON_H


#include "taskprop.h"


//��������������ͺ�����������ͬ
typedef ETaskType EFinishConditionType;

//�������������
class CFinishCondition
{
public:
    CFinishCondition() {};
    virtual ~CFinishCondition() {};
public:
    virtual EFinishConditionType GetFinishType() = 0;
};

//�ջ����� ��ɼ������
class CFinishCondition_Crown: public CFinishCondition
{
public:
    CFinishCondition_Crown() {};
    ~CFinishCondition_Crown() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return CROWN;
    }

    UINT16 wCrownTimes;

};


//��ļ�佫���� ��ɼ������
class CFinishCondition_RecruitHero: public CFinishCondition
{
public:
    CFinishCondition_RecruitHero()
    {
        wRecruitHeroKindID1 = 0;
		wRecruitHeroKindID2 = 0;
    };
    ~CFinishCondition_RecruitHero() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return RECRUITHERO;
    }

    UINT16 wRecruitHeroKindID1;
	UINT16 wRecruitHeroKindID2;
};


//�״�ͨ���������� ��ɼ������
class CFinishCondition_FirstPassInstance: public CFinishCondition
{
public:
    CFinishCondition_FirstPassInstance()
    {
        wSceneIdx = 0;
        byTownIdx = 0;
        byInstanceIdx = 0;
    };
    ~CFinishCondition_FirstPassInstance() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return FIRSTPASSINSTANCE;
    }

    UINT16 wSceneIdx;
    UINT8 byTownIdx;
    UINT8 byInstanceIdx;
};

//ָ������ͨ���������� ��ɼ������
class CFinishCondition_ScorePassInstance: public CFinishCondition
{
public:
    CFinishCondition_ScorePassInstance()
    {
        wSceneIdx = 0;
        byTownIdx = 0;
        byInstanceIdx = 0;
        byScore = 0;
    };
    ~CFinishCondition_ScorePassInstance() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return SCOREPASSINSTANCE;
    }

    UINT16 wSceneIdx;
    UINT8 byTownIdx;
    UINT8 byInstanceIdx;
    UINT8 byScore;
};

//ָ������ͨ���������� ��ɼ������
class CFinishCondition_TimesPassInstance: public CFinishCondition
{
public:
    CFinishCondition_TimesPassInstance()
    {
        wSceneIdx = 0;
        byTownIdx = 0;
        byInstanceIdx = 0;
        byTimes = 0;
    };
    ~CFinishCondition_TimesPassInstance() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return TIMESPASSINSTANCE;
    }

    UINT16 wSceneIdx;
    UINT8 byTownIdx;
    UINT8 byInstanceIdx;
    UINT8 byTimes;
};

//ָ������ɱ������ ��ɼ������
class CFinishCondition_KillMonstersInstance: public CFinishCondition
{
public:
    CFinishCondition_KillMonstersInstance()
    {
        wSceneIdx = 0;
        byTownIdx = 0;
        byInstanceIdx = 0;
        wMonsterKindID = 0;
        byKillNum = 0;
    };
    ~CFinishCondition_KillMonstersInstance() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return KILLMONSTERINSTANCE;
    }

    UINT16 wSceneIdx;
    UINT8 byTownIdx;
    UINT8 byInstanceIdx;
    UINT16 wMonsterKindID;
    UINT8 byKillNum;
};

//ǿ��װ����ָ���ȼ����� ��ɼ������
class CFinishCondition_StrengthenEquipLevel: public CFinishCondition
{
public:
    CFinishCondition_StrengthenEquipLevel()
    {
        wEquipKindID = 0;
        wLevel = 0;
    };
    ~CFinishCondition_StrengthenEquipLevel() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return STRENGTHENEQUIPLEVEL;
    }

    UINT16 wEquipKindID;
    UINT16 wLevel;
};

//ǿ��װ��ָ���������� ��ɼ������
class CFinishCondition_StrengthenEquipNum: public CFinishCondition
{
public:
    CFinishCondition_StrengthenEquipNum()
    {
        wEquipKindID = 0;
        wNum = 0;
    };
    ~CFinishCondition_StrengthenEquipNum() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return STRENGTHENEQUIPNUM;
    }

    UINT16 wEquipKindID;
    UINT16 wNum;
};


//�������� ���� ��ɼ������
class CFinishCondition_ActivateGodweapon: public CFinishCondition
{
public:
    CFinishCondition_ActivateGodweapon()
    {
        wHeroKindID = 0;
    };
    ~CFinishCondition_ActivateGodweapon() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return ACTIVATEGODWEAPON;
    }

    UINT16 wHeroKindID;	//0��ʾ����
};


//�������� ���� ��ɼ������
class CFinishCondition_UpgradeGodweapon: public CFinishCondition
{
public:
    CFinishCondition_UpgradeGodweapon()
    {
        wHeroKindID = 0;
        wQuality = 0;
        wLevel = 0;
    };
    ~CFinishCondition_UpgradeGodweapon() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return UPGRADEGODWEAPON;
    }

    UINT16 wHeroKindID;	//0��ʾ����
    UINT16 wQuality;
    UINT16 wLevel;
};

//ʹ�õ�ҩ ���� ��ɼ������
class CFinishCondition_UseExprienceDrug: public CFinishCondition
{
public:
	CFinishCondition_UseExprienceDrug()
	{
		wNum = 0;
	};
	~CFinishCondition_UseExprienceDrug() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return USEEXPRIENCEDRUG;
	}
	UINT16 wNum;
};

//ʹ�õ�ҩ ���� ��ɼ������
class CFinishCondition_MultEquip: public CFinishCondition
{
public:
	CFinishCondition_MultEquip()
	{
		wNum = 0;
	};
	~CFinishCondition_MultEquip() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return MELTEQUIP;
	}
	UINT16 wNum;
};

//ʹ�õ�ҩ ���� ��ɼ������
class CFinishCondition_Study: public CFinishCondition
{
public:
	CFinishCondition_Study()
	{
		byLevel = 0;
	};
	~CFinishCondition_Study() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return STUDY;
	}
	UINT8  byLevel;
};



//��Ʒ�ϳ� ���� ��ɼ������
class CFinishCondition_ComposeGood: public CFinishCondition
{
public:
	CFinishCondition_ComposeGood()
	{
		wMaterialID = 0;
		wMaterialNum = 0;
		wKindID = 0;
		wNum = 0;
	};
	~CFinishCondition_ComposeGood() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return COMPOSEGOOD;
	}
	UINT16		wMaterialID; //ԭ��ID
	UINT16		wMaterialNum; //ԭ��ID
	UINT16		wKindID; //�ϳɵ���ƷID
	UINT32		wNum;
};

//////////////////////////////////////////////////////////////////////////
//ͨ����Ӣ������ ��ɼ������
class CFinishCondition_EliteInstance: public CFinishCondition
{
public:
	CFinishCondition_EliteInstance()
	{
		wSceneIdx = 0;
		byTownIdx = 0;
		byInstanceIdx = 0;
	};
	~CFinishCondition_EliteInstance() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return ELITEINSTANCE;
	}
	UINT16 wSceneIdx;
	UINT8 byTownIdx;
	UINT8 byInstanceIdx;
};

//ͨ�������Ƽ� ��ɼ������
class CFinishCondition_UpgradeScience: public CFinishCondition
{
public:
	CFinishCondition_UpgradeScience()
	{
		wNum = 0;
	};
	~CFinishCondition_UpgradeScience() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return UPGRADSCIENCE;
	}
	UINT16 wNum;
};

//ͨ�������Ƽ� ��ɼ������
class CFinishCondition_StrengthAttack: public CFinishCondition
{
public:
	CFinishCondition_StrengthAttack()
	{
		wNum = 0;
	};
	~CFinishCondition_StrengthAttack() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return STRENGTHATTACK;
	}
	UINT16 wNum;
};

//ͨ���������� ��ɼ������
class CFinishCondition_StrengthLife: public CFinishCondition
{
public:
	CFinishCondition_StrengthLife()
	{
		wNum = 0;
	};
	~CFinishCondition_StrengthLife() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return STRENGTHLIFE;
	}
	UINT16 wNum;
};

//��ֲ ��ɼ������
class CFinishCondition_Crop: public CFinishCondition
{
public:
	CFinishCondition_Crop()
	{
		wNum = 0;
	};
	~CFinishCondition_Crop() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return CROP;
	}
	UINT16 wNum;
};


//��������ս ���� ��ɼ������
class CFinishCondition_Challenge: public CFinishCondition
{
public:
    CFinishCondition_Challenge()
    {
        wChallengeNum = 0;
    };
    ~CFinishCondition_Challenge() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return CHALLENGE;
    }

    UINT16 wChallengeNum;
};


//�Ӷ� ���� ��ɼ������
class CFinishCondition_Plunder: public CFinishCondition
{
public:
    CFinishCondition_Plunder()
    {
        wPlunderNum = 0;
    };
    ~CFinishCondition_Plunder() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return PLUNDER;
    }

    UINT16 wPlunderNum;
};


//�������� ���� ��ɼ������
class CFinishCondition_UpgradeSkill: public CFinishCondition
{
public:
    CFinishCondition_UpgradeSkill()
    {
        wUnlockIdx = 0;
        wLevel = 0;
    };
    ~CFinishCondition_UpgradeSkill() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return UPGRADESKILL;
    }

    UINT16 wUnlockIdx;	
    UINT16 wLevel;
};

//�������� ���� ��ɼ������
class CFinishCondition_UpgradeJingJie: public CFinishCondition
{
public:
	CFinishCondition_UpgradeJingJie()
	{
		wLevel = 0;
		wSubLevel = 0;
	};
	~CFinishCondition_UpgradeJingJie() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return UPGRADEJINGJIE;
	}

	UINT16 wLevel;	
	UINT16 wSubLevel;	
};





//��Ƕ��ʯ ���� ��ɼ������
class CFinishCondition_MosaicGem: public CFinishCondition
{
public:
    CFinishCondition_MosaicGem()
    {
        wNum = 0;
    };
    ~CFinishCondition_MosaicGem() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return MOSAICGEM;
    }

    UINT16 wNum;
};


//ե�ɷ�² ���� ��ɼ������
class CFinishCondition_ClimbTower: public CFinishCondition
{
public:
	CFinishCondition_ClimbTower()
	{
		wNum = 0;
	};
	~CFinishCondition_ClimbTower() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return CLIMBTOWER;
	}

	UINT16 wNum;
};

//�������� ���� ��ɼ������
class CFinishCondition_DressEquip: public CFinishCondition
{
public:
    CFinishCondition_DressEquip()
    {
        wEquipID = 0;
        byDressFlag = 0;
    };
    ~CFinishCondition_DressEquip() {};
public:
    virtual EFinishConditionType GetFinishType()
    {
        return DRESSEQUIP;
    }

    UINT16	wEquipID;	//0��ʾ���⴩��
    UINT8	byDressFlag; //���ڼ�¼�ͷ��Ѿ�����
};

//��ļ�佫���� ��ɼ������
class CFinishCondition_RecruitHeroNum: public CFinishCondition
{
public:
	CFinishCondition_RecruitHeroNum()
	{
		wNum = 0;
	};
	~CFinishCondition_RecruitHeroNum() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return RECRUITHERONUM;
	}

	UINT16 wNum;
};

//��ļ�佫���� ��ɼ������
class CFinishCondition_OpenLight :public CFinishCondition
{
public:
	CFinishCondition_OpenLight()
	{
		byExt = 0;
	};
	~CFinishCondition_OpenLight() {};
public:
	virtual EFinishConditionType GetFinishType()
	{
		return OPENLIGHT;
	}

	UINT8 byExt;
};



#endif

