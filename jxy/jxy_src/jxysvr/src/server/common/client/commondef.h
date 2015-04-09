#ifndef _COMMONDEF_H_
#define _COMMONDEF_H_


#define  INVALID_MSGID 0 //��Ч��Э���

///////// װ��ǿ����ʽ
#define EQUIP_STRENGTHEN_COIN 0 //���
#define EQUIP_STRENGTHEN_GOID 1 //Ԫ��

#define NULL_FACTION_ICON_ID 255 // ��ʾû������ͼ�꣨ͼ��0�ѱ�ռ�ã�����Ĭ��ͼ�꣩
#define FLY_LEVEL 120 // ��ҷ����ȼ������������ȼ���1תxx����ʾ����130�� = 1ת10��


enum AttackTarget
{
	EAT_MYSELF = 1,//����
	EAT_ENEMY = 2,//�з�
};

enum EWU_XING
{
	EWX_GOLD = 1,//��
	EWX_WOOD = 2,//ľ
	EWX_WATER = 3,//ˮ
	EWX_FIRE = 4,//��
	EWX_SOIL = 5,//��
};

//��ɫ
enum EColor
{
	EC_BLUE = 1,//��ɫ
	EC_PURPLE = 2,//��ɫ
	EC_RED = 3,//��ɫ
	EC_ORANGE = 4,//��ɫ
	EC_DOUBLE_COLOR = 5,//˫����
};

enum COLOR_TYPE
{
	ECT_NONE = 0,//��
	ECT_BULE = 1,//��ɫ
	ECT_PURPLE = 2,//��ɫ
	ECT_RED = 3,//��ɫ
	ECT_ORANGE = 4,//��ɫ
	ECT_YELLOW = 5,//��ɫ
	ECT_GREEN = 6,//��ɫ
	ECT_CYAN = 7,//��ɫ
};

//��Դ����
enum ACTE_KIND_TYPE
{
	ACTE_GOOD				= 0,//��Ʒ
	ACTE_HERO				= 1,	//�佫
	ACTE_COIN				= 2,	//ͭǮ
	ACTE_GOLD				= 3,	//Ԫ��
	ACTE_PHYSTRENGTH		= 4,	//����
	ACTE_SCIENCE			= 5,	//�����
	ACTE_STORY				= 6,	//����
	ACTE_BLUEGAS			= 7,	//��¶
	ACTE_PRUPLEGAS			= 8,	//����
	ACTE_JINGJIE			= 9,	//����
	ACTE_DoorsTribute		= 10,	//�Ź�
	ACTE_FactionFunds		= 11,	//�����ʽ�
	ACTE_FactionTaskIntegral = 12,	//�����������
	ACTE_StudyClip			= 13,	//Ǭ����Ƭ
	ACTE_SOUL				= 14,	//ս��
	ACTE_STUDYEXP			= 15,	//������
	ACTE_HERO_EXP			= 16,	//���ﾭ��
	ACTE_PETSCORE			,	// �������
};


//ս����������
enum EBattleAttributeKind
{
    EBAK_INVALID = 0,	//��Ч
    EBAK_HP = 1,		//HP
    EBAK_ATTACK = 2,	//������
    EBAK_HITRATE = 3,		//�ƻ���
    EBAK_DODGERATE = 4,		//����
    EBAK_CRITRATE = 5,		//������
    EBAK_DECRITRATE = 6,	//������
    EBAK_INCHURTRATE = 7,	//������(���ӵ��˺��ٷֱ�)
    EBAK_DECHURTRATE = 8,	//������(���ٵ��˺��ٷֱ�)
    EBAK_ANGRY = 9,			//ŭ��ֵ
    EBAK_ODDANGRY = 10,		//ʣ��ŭ��ֵ
    EBAK_FIRSTATTACK = 11,	//�ȹ�
    EBAK_COACHTALENT = 12,	//����
    EBAK_HP2 = 13, //HP2(ֻ�пƼ�������)
    EBAK_ATTACK2 = 14, //������2(ֻ�пƼ�������)
	EBAK_DEFEND = 15,//����
    EBAK_MAX, //���
};

//ս����Ч
enum EBattleSpecialEffects
{
	EBSE_NONE = 0,//��
	EBSE_CONTINUE_ATTACK = 1,//����1
	EBSE_SUCK_BLOOD = 2,//��Ѫ1
	EBSE_PHYSICAL_IMMUNITY = 3,//����
	EBSE_MAGIC_IMMUNITY = 4,//ħ��
	EBSE_ADD_BLOOD = 5,//����
	EBSE_REBOUND = 6,//����
	EBSE_BEAT_BACK = 7,//����
	EBSE_DODGE = 8,//����
	EBSE_PROTECT_BODY = 9,//��������
	EBSE_IRRESISTIBLE_FORCE = 10,//��������
	EBSE_NARROW_ESCAPE = 11,//��������
	EBSE_BAGUS_FLYER = 12,//�����п�
	EBSE_TIGER = 13,//��������
	EBSE_AVALANCHE = 14,//��ɽ����
	EBSE_BURN_BOATS = 15,//�Ƹ�����
	EBSE_LAST_STAND = 16,//��ˮһս

	EBSE_MAX, //��Ч
};

enum EBattleSpecialEffectUpgradeCase
{
	EBSEUC_PROBABILITY = 1,//��������
	EBSEUC_EFFECT = 2,//Ч���ٷֱ�
	EBSEUC_LIMIT_NUM = 3,//���ƵĴ���
};
/**
 * @brief
 * ������Ʒ����
 */
enum EBurstKind
{
    EBKIND_INVALID = 0, //��Ч
    EBKIND_COIN = 1, //Ǯ��
    EBKIND_GOLD = 2, //Ԫ��
    EBKIND_EXPERIENCE = 3, //����
    EBKIND_PHYSTRENGTH = 4, //����
    EBKIND_ITEM = 5, //����
    EBKIND_ATTRIBUTE = 6, //����
    EBKIND_SCIENCE = 7, //�Ƽ���
    EBKIND_STORY = 8, //������
};


//��������
enum EBuildKind
{
    EBK_MAINTOWN = 1, //����
    //EBK_PRODUCE = 2, //��������
    EBK_SCIENCE = 3, //�Ƽ�����
    EBK_SMITHY = 4, //�����̽���
    EBK_RECRUIT	= 5, //��ļ��
    EBK_PVP = 6, //����
    EBK_GODWEAPON = 9, //��������
    EBK_AWAKEN = 10, //���
    EBK_PLUNDER = 11, //�Ӷ�
    //EBK_TALENT = 12, //��Ϊ��
    EBK_CROP = 13, //��ֲ��
    EBK_ADVENTURE = 15,	//ð��
    //EBK_BOOK = 16, //����
    EBK_JINGJIE = 17, //����
    EBK_FACTION = 18, //����
	EBK_JEWELRY = 19, //����
	EBK_PET			 = 20, // ����ϵͳ

    EBK_SHOP = 101, //�̵�
    EBK_ELITEINSTANCE = 102, //��Ӣ����
    EBK_ONHOOK = 103, //�һ���
    EBK_EQUPUPGRADE = 104, //װ�����׹�
    EBK_MONEYTREE = 105, //�в���
    //EBK_JINGJIE=106, //����
    EBK_EXPRIENCE = 107,	//���鵤
    EBK_UPDATEATTR = 108, //��������
    EBK_LEVY = 109, //���ս���
    EBK_FROMATION = 110, //���ͽ���
    EBK_MELTING = 111,		//��������
    EBK_EATBREAD = 112,		//�԰���
    EBK_XIANGQIAN = 113,		//��Ƕ
    EBK_COLLECTGAS = 114,		//�ռ�����
    EBK_CLIMBTOWER = 115,		//����
    EBK_ACTIVITY = 116, //�����
    EBK_YABIAO = 117, //Ѻ��
    EBK_SKILL = 118,		//����
    EBK_BOSSBATTLE = 119,		//BOSSս
    EBK_RECHARGE = 120,		//��ֵ�
    EBK_SCORE = 121,			//���ֻ����
    EBK_EXPTRAN = 122,		//���鴫�ݽ���
    EBK_RDCHALLENGE = 123,		//�����ս
    EBK_RACEBUILD = 124,	//������
    EBK_ACTIVITY_ENCOURAGE = 125,	//���������
    //EBK_FACTION = 126,	//����
    EBK_EQUIPCOMPOSE = 127,	//װ���ϳ�
    EBK_STUDYEXCHANGE = 128,	//����һ� ����ֽ�
    EBK_SCORERATING = 129,		//����ͨ�ؽ���
    EBK_BEGBLUE = 130,  //����¶
    EBK_OPENLIGHT = 131,    //װ������
    EBK_ITEMEXCHANGE = 132,    //���߶һ�
    EBK_VIEWCHAT = 133,    //�ۿ�����
    EBK_SNDCHAT      = 134, //��������
    EBK_FRIENDS      = 135,	//����ϵͳ
    EBK_COURAGE      = 136, //��������
    EBK_EQUIP_MASTER = 137, // װ����ͨ���˹����ѷ�����
	EBK_GVG			 = 138,//���ս
	EBK_MEDAL        = 139,//ѫ��
	EBK_SOUL         = 140,//ս��
	EBK_PETFEED		 = 142, // ����ι��
	EBK_PETMERGE	 = 143, // �����ں�
	EBK_PETUPSTAR	 = 144, // ��������
	EBK_PETWASH		 = 145, // ����ϴ����
	EBK_PETLIANYAOHU = 146, // ������

    EBK_ENCHANT		 = 147, // װ����ħ
    EBK_EQUIP_MAKE	 = 148, // װ������
    EBK_FLY	         = 149, // ��������
	EBK_NEIDAN_INSTANCE = 150,//ն����
    EBK_OUT_BOUND = 151, // �⴫����
};

//ս�����
enum EBattleResult
{
    EBT_SUCCESS = 0, //�ɹ�
    EBT_FAILED = 1, //ʧ��
    EBT_INSTANCE_PASS = 2,//����ͨ��
    EBT_COURAGE_PASS = 3, //����ͨ��
};


//�佫λ��
enum EHeroPos
{
    EHP_CARRY = 0,//Я��
    EHP_BATTLE = 1,//���󣬰���Я��
    EHP_RECRUIT = 2,//����ļ����
};

//��Ʒ������
enum EGoodsMainKind
{
    EGMK_PHYSTRENGTH = 1, //������
    EGMK_GOLD = 2, //Ԫ��
    EGMK_DOUBLEEXPERIENCE = 3, //˫������
    EGMK_ADDEXPERIENCE = 4, //�Ӿ���,������������
    EGMK_MATERIAL = 5, //����
    EGMK_RATEBOX = 6, //����(���)���
    EGMK_COIN = 7, //ͭǮ
    EGMK_BOX = 8, //����
    EGMK_DRUG = 9, //��ҩ
    EGMK_MAKER = 10, //������
    //EGMK_PLUNDERLOWERLEVEL = 11, //�Ӷ����5����ҵĵ���
    //EGMK_ADDPLUNDERTIMES = 12,//�����Ӷ��������
    //EGMK_AVOIDPLUNDERBATTLE = 13,//�Ӷ���ս����
    //EGMK_GODWEAPONQUALITYUPGRADE = 14,//�������׷�
    EGMK_SCIENCE = 11, //����
    EGMK_INNERBOX = 12, //�ڲ����䣬������Ʒʱϵͳֱ�Ӹ����ʹ��
    EGMK_EXPERIENCE = 13, //��龭�鵤
    EGMK_CROP = 14, //��ֲ����
    EGMK_XIANGQIANGEM = 15, //��Ƕ��ʯ
    EGMK_XIANGQIANCHIP = 16, //��Ƕ��Ƭ
    EGMK_BLUEGAS = 17, //����
    EGMK_PURPLEGAS = 18, //����
    EGMK_JINGJIE = 19, //����
    EGMK_GEMMAKER = 20, //��ʯ������
    EGMK_EQUIP_DEBRIS = 21, //װ����Ƭ
    EGMK_STORY = 22, //����
    EGMK_DOORSTRIBUTE = 23, //�Ź�
	EGMK_JEWELRY_ADVANCED = 24,//��Ʒ����
	EGMK_EQUIP_ADVANCED = 25,//װ������ʯ
	EGMK_ROSE = 26,//õ��
	EGMK_SOUL_METERIAL = 27,//ս�����
	EGMK_NORMAL_PET_BAG = 28, // ��ͨ�����
	EGMK_PET_NORMAL_BABY_EGG = 29, // ������
	EGMK_PET_UNNORMAL_BABY_EGG = 30, // ���챦����
	EGMK_DRAGON_BALL = 31, // ����
    EGMK_JINLIULU = 32,	// ϴ������Ʒ
	EGMK_EQUIP_MAKE_BOOK = 33,	// �⴫װ��������
    EGMK_HERO_MATERIAL = 34,	// ������
    EGMK_EQUIP_MATERIAL = 35,	// װ������

    EGMK_OTHER = 99, //����
};


//�Ƽ���������
enum EScienceKind
{
    ESK_INVALID = 0,//��Ч��
    ESK_HP = 1,		//HP
    ESK_ATTACK = 2,	//������
    ESK_MAX			//����
};

//��������
enum EDressType
{
    EEDT_DRESS = 0,  //����
    EEDT_UNDRESS = 1,  //ж��
    EEDT_REPLACE = 2,  //�滻
};



//װ��λ������
enum EEquipPosType
{
    EEPT_HEAD = 1, //ͷ(ͷ��)
    EEPT_BODY = 2, //��(ս��)
    EEPT_HAND = 3, //��(����)
    EEPT_FOOT = 4, //��(սѥ)
};


//��������
enum EEmbattleType
{
    EET_UP = 0,  //����
    EET_DOWN = 1,  //����
    EET_REPLACE = 2,  //�滻
    EET_EXCHANGE = 3,  //����
};

//������������
enum EBuildFunctionType
{
    EBFT_OPEN = 0x1, //��
    EBFT_UPGRADE = 0x1 << 1, //����
    EBFT_CROWN = 0x1 << 2, //�ջ�
};

//��������
enum EGuideFunction
{
    EGF_INVALID = 0x0, //��Ч
    EGF_EQUIP = 1, //װ������
    EGF_RECUIT = 2, //��ļ�佫
    EGF_STRENGTHEN  = 3, //װ��ǿ��
    EGF_EMBATTLE = 4, //����
    EGF_CROWN  = 5, //�ջ�
    EGF_DRUG  = 6, //���õ�ҩ
    EGF_PLUNDER  = 7, //�Ӷ�
    EGF_CAPTUREWORK  = 8, //��²����
    EGF_ELITEINSTANCE  = 9, //��Ӣ����
    EGF_ROCKMONEY  = 10, //ҡǮ
    EGF_GODWEAPON   = 11, //����
    EGF_RACE  = 12, //������
    EGF_SCIENCETREE = 13, //�Ƽ���
    EGF_CROP = 14, //��ֲ
    EGF_EXPRIENCE  = 15, //���þ��鵤
    EGF_UPDATEATTR  = 16, //��������
    EGF_LEVY = 17, //����
    EGF_MELTING = 18, //����
    EGF_SECOND_EMBATTLE = 19, //���β���
    EGF_YABIAO = 20, //Ѻ��
    EGF_CLIMBTOWER  = 21, //����
    EGF_XIANGQIAN  = 22,//��Ƕ
    EGF_JINGJIEUPGRADE = 23,//��������
    EGF_GASCOLLECT = 24,//�������ռ�
    EGF_SKILLUPGRADE = 25,//��������
    EGF_AWAKEN = 26,//���
    EGF_RDC = 27,//�����ս
    EGF_OPENLIGHT = 28,//����
    EGF_FRIENDS = 28,//����
    EGF_FACTION = 29,//����
    EGF_BEGBLUE = 30,//����¶
	EGF_PET = 31,//�����
	EGF_PETFEED	= 32,	
	EGF_PETMERGE = 33,	
	EGF_PETUPSTAR = 34,	
	EGF_PETWASH	= 35,	
	EGF_PETLIANYAOHU = 36,
	EGF_PET_FIGHT = 37,	// �����ս
    EGF_MAX		//����128
};



//��������
enum EMonsterType
{
    EMT_NORMAL = 1, //��ͨ
    EMT_SBOSS = 2, //СBOSS
    EMT_BBOSS = 3, //��BOSS
    EMT_ELITE = 4, //��Ӣ
};

//����Ч�����ͣ����32������
enum ESkillEffectKind
{
    ESEK_HURT = 1, //�˺�������ʱ����
    ESEK_SINGLECUER = 2, //�����Ѫ������ʱ��Ѫ
    ESEK_WHOLECUER = 3, //ȫ���Ѫ������ʱ��Ѫ
    ESEK_DECANGRY = 4, //���ţ�����ʱ���͵з�ŭ��
	ESEK_SECOND_ATTACK = 5,//�����˺�(����)
	ESEK_CRITICAL = 6,//���������䣩
	ESEK_WATER = 7,//ˮ��
	ESEK_SOIL = 8,//����
	ESEK_ICE = 9,//������
	ESEK_SAND = 10,//ɰ����
	ESEK_SPARK = 11,//������
	ESEK_HAUNTING = 12,//���겻ɢ
	ESEK_DERAM = 13,//����þ�
	ESEK_SOUL = 14,//��ǣ����
	ESEK_CHARM = 15,//�Ϲ����

	ESEK_MAX,//��Ч
};


//buff���ͣ����32������
enum EBuffKind
{
	EBK_NONE = 0,//�ޣ�û��BUFF
    EBK_STATIC = 1, //��ֹ,�ݶ�ӵ�и�״̬�߱��غ��ڹ��������ڸ���״̬
    EBK_NO_SKILL = 2, //��Ĭ���ݶ�ӵ�и�״̬�߱��غ���ʹ�ü��ܣ����ڸ���״̬
    EBK_POISONING  = 3, //�ж���ʹ��ӵ�и�״̬�߱��غ��ڵ������ٷֱ�Ѫ�������ڸ���״̬
    EBK_DEC_ATTACK = 4, //�зϣ�ʹ��ӵ�и�״̬�߱��غ��ڹ��������ٷֱȽ��ͣ����ڸ���״̬
    EBK_TEAR  = 5, //˺�ѣ�ʹ��ӵ�и�״̬�߱��غ��ڵ������ٷֱ�Ѫ�������ڸ���״̬
    EBK_BLOODTHIRSTY_S = 11, //��Ѫ(����)�� ʹ��ӵ�и�״̬�߱��غ��ڹ��������ٷֱ���������������״̬
    EBK_BLOODTHIRSTY_A = 12, //��Ѫ(ȫ��)�� ʹ��ӵ�и�״̬�߱��غ��ڹ��������ٷֱ���������������״̬
    EBK_DECHURT_S = 13, //����(����)��ʹ��ӵ�и�״̬���ܻ�����ʱ�����˺�ֵ����������״̬
    EBK_DECHURT_A = 14, //����(ȫ��)��ʹ��ӵ�и�״̬���ܻ�����ʱ�����˺�ֵ����������״̬
	EBK_ADD_BLOOD = 15,//�ش������ظ�����ֵ������״̬
	EBK_DEFEND_PERCENT = 16,//���ӷ������ٷֱȣ�,Ϊǰ�ŵ������ӷ�������������״̬
	EBK_FROST = 17,//���ᣬʹĿ�궳�ᣬ��ͣ��״̬�߻غ��ڹ��������ڸ���״̬
	EBK_CHAOS = 18,//���ң�ʹ��״̬�߲��ֵ���ѡ��Ŀ�깥�������ڸ���״̬
	EBK_FIRING = 19,//���գ�ʹĿ����ʧ���������ڸ���״̬
	EBK_DISTURB = 20,//���ţ����͹����˺������ڸ���״̬
	EBK_NOT_ANGER = 21,//ʧȥ��־��ʹĿ���������ڼ����޷����ŭ�������ڸ���״̬
	EBK_SLEEP = 22,//��˯��ʹĿ���˯�غ����޷����������ڸ���״̬
	EBK_DREAMLAND = 23,//�þ�,�ڼ侫�񽫱��ҷ����Ʋ�����񱩣��޷��ͷż��ܣ��˺�����100%������������Է�����(����Է�ֻʣ1���ڳ�����ֻ�����˯1�غ�)
};


#define  MAIN_LINE_TASK		1 //��������
//#define  BRANCH_LINE_TASK	2 //֧������

//�Ӷ�ս������
enum EPlunderBattleLogType
{
    EPBLT_PLUNDER = 0,//�Ӷ�
    EPBLT_RESIST = 1,//����
    EPBLT_RAP = 2,//����
    EPBLT_AUTOFREE = 3,//�Զ��ͷŷ�²��ʱ�䵽�Զ��ͷ�
    EPBLT_MANUALFREE = 4,//�ֶ��ͷŷ�²(��²���ֶ��ͷ�)
    EPBLT_DRIVEAWAY = 5,//���Ϸ�²��
    EPBLT_INCOME = 6,//�����������
    EPBLT_BLEED = 7,//ե������
};

//�ӶṤ��������
enum EPlunderWorkLogType
{
    EPWLT_CAPTURE_WORK = 0,//��²����
    EPWLT_FOR_OWNER = 1,//Ϊ��²������
    EPWLT_CAPTURE_HANDIN = 2,//��²���������Ͻ�

};

//����ĵ�����
enum EAwakenLevelKind
{
    EALK_KESHUI = 1, //�˯
    EALK_SHENGYOU = 2, //����
    EALK_MINGSI = 3, //ڤ˼
    EALK_RUDING = 4, //�붨
    EALK_CHEWU = 5, //����
};

//�ĵô�������λ��
enum EStutyDressOpPos
{
    ESDOP_HERO = 0, //�佫�ĵ�
    ESDOP_STORE = 1, //�洢�ĵ�
    ESDOP_EXCHANGE = 2, //�佫�ʹ洢����
};

//���ܼ���
enum ESkillGrade
{
    ESG_NORMAL = 1, //һ��
    ESG_RARE = 2,//ϡ��
};


//�Ӷ��²��������
enum EPlunderWorkType
{
    EPWT_UNSET = 0, //δ����
    EPWT_COIN = 1, //ͭ��
    EPWT_SCIENCE = 2, //����
};


//ְҵ����
enum ECareerKind
{
    ECK_INVALID = 0,//��Ч
    ECK_ATTACK = 1, //����
    ECK_DEFENCE = 2, //����
};


//ǿ����������
enum EAttrStrengthType
{
    EAST_HP = 0, //Ѫ��
    EAST_ATTACK = 1, //����
	EAST_DEFEND = 2,//����
};

//ǿ�����Է�ʽ
enum EUpdateAttrByType
{
    EUABT_COIN = 0, //ͭ��
    EUABT_ITEM = 1, //��Ʒ
};

//�ջ�����
enum ECropKind
{
    ECPK_INVALID = 0,		//��Ч
    ECPK_COIN = 1,		//ͭǮ
    ECPK_SCIENCE = 2,		//����
    ECPK_EXPRIENCE = 3,	//���鵤
    ECPK_STORY = 4,		//����
    ECPK_JINGJIE = 5,		//����
};


//���ܹ�����Χ����
enum EAttackRangKind
{
    EARK_INVALID = 0, //��Ч
    EARK_FRONTONE = 1, //ǰ�ŵ���
    EARK_BACKONE , //= 2, //���ŵ���
    EARK_FRONTALL , //= 3, //ǰ��ȫ��
    EARK_BACKALL, //= 4, //����ȫ��
    EARK_ALL, // = 5, //����
    EARK_BUFF, // = 6, //׷��buff
    EARK_MIXBLOOD, //= 7, //׷������Ѫ��
    EARK_RAMDOM_COMBAT_TWO_ENEMY, // = 8, //��������������
	EARK_RANDOM_BY_PLAYER_LEVEL = 9,//���ݵȼ���ȷ���������(���ѡ��)
    EARK_MAX, //���
};


//�����
enum EActivityKind
{
    EAK_EATBREAD = 1, //�԰���
    EAK_BOSSBATTLE = 2, //BOSSս
    EAK_COURAGE = 3, //��������
    EAK_HUNTING = 4, //׽��
    EAK_GVG     = 5, //���ɿ��ս
};

//��������
enum EChatType
{
    ECT_SYS		 = 0, // ϵͳ��Ϣ
    ECT_USER	 = 1, // �û���Ϣ
    ECT_NOTIFY	 = 2, // ֪ͨ ������������ȼ���ECT_SYS��
    ECT_GM		 = 3, // GM�ͷ�
    ECT_FACTION  = 4, // ����Ƶ��(�ͻ��˰汾��>=301��֧��)
    ECT_ACTIVITY = 5, // �Ƶ��(�ͻ��˰汾��>=301��֧��)
};

//��������
enum EGapType
{
    EGT_BLUE = 0, //����
    EGT_PURPLE = 1, //����
};

//֪ͨ����
enum ENoticeType
{
    ENT_OUTLINE = 0, //��Ҳ�����
    ENT_RACE = 1, //������֪ͨ
    ENT_EATBREAD = 2, //�԰���
    ENT_BOSSBATTLE = 3, //BOSSս
    ENT_COURAGETTLE = 4, //��������
    ENT_OTHER = 5, //����֪ͨ
};

//vip���Ӵ�������
enum EVipIncNumFunc
{
    EVINF_INVALID = 0x0, //��Ч
    EVINF_MONEYTREE = 1, //�в�
    EVINF_RACEBUYNUM = 2, //������������ս����
    EVINF_PLUNDERBUYNUM = 3, //�ӶṺ����ս����
    EVINF_PHYSTRENGTHBUYNUM = 4, //������������
    EVINF_CLIMBTOWERRESET = 5,		//����ÿ������ô���
    //EVINF_GENRANDOMGAS=6, //�������
    EVINF_HEROEATJINGYANDAN = 7, //�����þ��鵤
    EVINF_RESETELITEINSTANCE = 8, //���þ�Ӣ����
    //EVINF_GENPURPLEGAS = 9, //��ɫ����
    EVINF_AWAKENCALL = 11 , //����ٻ�
    EVINF_GATHER_SCIENCE_COIN = 12 , //ͭǮ�ۻ�
    EVINF_GATHER_SCIENCE_GOLD = 13 , //Ԫ���ۻ�
    EVINF_BEG_BLUE_GAS = 14 , //����¶
    EVINF_GOLD_DONATE = 15,		//Ԫ�����״���
    EVINF_COURAGE = 16,   //������������
	EVINF_PET_FEED = 17,   //����ι��ҡ����
    EVINF_MAX, //���
};

//vip����
enum EVipFunc
{
    EVF_VISITGOLD = 1, //��ļ�ݳ�ǧ����
    EVF_ONHOOKETELITEINSTANCE = 2, //ɨ����Ӣ����
    EVF_GODWEAPONPERFECTRELEASE = 3, //���������ͷ�
    EVF_AUTOCLIMBTOWER = 5, //�Զ�����
    EVF_BOSSBGOLDINSPIREPOWER = 6, //bossսԪ������ս��
    EVF_GOLDMELTEQUIP = 7, //Ԫ������������ֵ����
    EVF_QUJINGCALLTANGSENG = 8, //ȡ���ٻ���ɮ
    EVF_BOSSBAUTOBATTLE = 9, //BOSSս�Զ�ս��
    EVF_GENGASFULL = 10, //һ������
    EVF_GENGAS = 11, //Ԫ������
    EVF_FINDMONSTER = 12,  //���
    EVF_OPENGOLDMODE = 13, //�����ƽ�ģʽ
};

//��������
enum ECostFunc
{
    EGCF_INVALID = 0x0, //��Ч
    EGCF_MONEYTREE = 1, //�в�
    EGCF_RACEBUYNUM = 2, //������������ս����
    EGCF_PLUNDERBUYNUM = 3, //�ӶṺ����ս����
    EGCF_PHYSTRENGTHBUYNUM = 4, //������������
    EGCF_CLIMBTOWERRESET = 5,		//����ÿ���������ô���
    //EGCF_GENRANDOMGAS=6, //�������
    //EGCF_HEROEATJINGYANDAN = 7, //�����þ��鵤
    EGCF_RESETELITEINSTANCE = 8, //���þ�Ӣ����
    //EGCF_GENPURPLEGAS = 9, //��ɫ����
    //EGCF_AWAKENCALL = 11 , //����ٻ�
    EGCF_GATHER_SCIENCE_COIN = 12 , //ͭǮ�ۻ�
    EGCF_GATHER_SCIENCE_GOLD = 13 , //Ԫ���ۻ�
    EGCF_BEG_BLUE_IMPRV_LUCK = 14,  //����¶��������
    EGCF_SHADE_CHANGE_MONSTER = 15,		//��������
    EGCF_BUY_ENCOURAGE_TIMES = 16, //����������������
    EGCF_FACTION_OPEN_GOLD = 17, //�����ƽ�ģʽ
    EGCF_FACTION_CLOSE_MONSTER = 18,//����
    EGCF_FACTION_CREATE_BY_COIN = 19,//ͭǮ��������
    EGCF_FACTION_CREATE_BY_GOLD = 20,//Ԫ����������
	EGCF_FACTION_CHANGE_ICON = 21, //��������ͷ��

    EGCF_NOTVIP	=	100,
    //С��100�ĸ�VIP�����޹�
    EGCF_PLUNDERDRIVEAWAY = 101, //����
    EGCF_GENCOIN = 102, //�ۻ�ͭǮ
    EGCF_GENGOLD = 103, //�ۻ�Ԫ��
    EGCF_GENUPGOLD = 104, //�ۻ�Ԫ�����
    EGCF_GENUPGOLDFULL = 105, //�ۻ�Ԫ������
    EGCF_MAX,//���
};


//���ܻ�ȡ
enum EObtainFunc
{
    EOF_GATHER_SCIENCE_COIN = 1 , //ͭǮ�ۻ�
    EOF_GATHER_SCIENCE_GOLD = 2 , //Ԫ���ۻ�
    //EOF_BLUE = 3, //����
    //EOF_PURPLE = 4, //����
    EOF_MAX,//���
};

enum ERSType
{
    ERS_COIN = 1,//ͭǮ
    ERS_STORY = 2,//����
    ERS_SCIENCE = 3, //����
    ERS_JINGJIE = 4,//����
};


enum ERS_COIN_Type
{
    ERS_COIN_MAIN = 1,	//��������
    ERS_COIN_CROP = 2,	//��ֲ
    ERS_COIN_MONEYTREE = 3,//�в�
    ERS_COIN_SELL = 4,//����Ʒ
    ERS_COIN_MONSTER = 5,//ɱ��
    ERS_COIN_BUDDHISTSUTRAS = 6,//����ȡ��
};

enum ERS_STORY_Type
{
    ERS_STORY_INSTANCE = 1,	//��������
    ERS_STORY_CROP = 2,	//��ֲ
};

enum ERS_SCIENCE_Type
{
    ERS_SCIENCE_MELT = 1,	//����
    ERS_SCIENCE_CROP = 2,	//��ֲ
};

enum ERS_JINGJIE_Type
{
    ERS_JINGJIE_BOSS = 1,			//��սBOSS���
    ERS_JINGJIE_XTQJ = 2,			//ȡ�����
    ERS_JINGJIE_RACE = 3,			//�������ɻ��
    ERS_JINGJIE_CROP = 4,			//��ֲ����
    ERS_JINGJIE_BAISHEN = 5,		//����
    ERS_JINGJIE_SHAGNXIAN = 6,		//����
};

//ս������
enum EBattleLogType
{
    EBLT_RACE = 1,		//������
    EBLT_PLUNDER = 2,	//С����
    EBLT_YABIAO = 3,	//Ѻ��
    EBLT_BOSSB = 4,		//bossս
    EBLT_FACTION = 5,	//����
	EBLT_GVG = 6, //���ս

	EBLT_MAX,//���
};

enum EEnterGSPARAMType
{
    EEGSPT_MAX_PLAYER_LEVEL = 1,//���ȼ���ʹ��wParam2
	EEGSPT_RECHARGE = 2,//��ֵ����
	EEGSPT_ADVERTISEMENT = 3,//���
};

//Ĥ������
enum EWorshipType
{
    EWT_RACE = 1,		//������
    EWT_RDC = 2,		//�����ս
};

//������ʾ����
enum EPvpPrompt
{
    EPP_RECVENC = 1, //���콱
    EPP_WORSHIP = 2, //��Ĥ��
    EPP_LIGHTING = 3, //������
    EPP_CHALLENGE = 4, //����ս
    EPP_RDC = 5, //�������ս
};

//����彨����Ϣ
enum EPDFB
{
    EPDFB_RACE = 1, //����
    EPDFB_ADVENTURE = 2, //ð��
    EPDFB_SMITHY = 3,    // ������
};

enum em_Faction_Job
{
    em_Faction_MartialHead			=	1,//��������
    em_Faction_ProxyMartialHead		=	2,//����
    em_Faction_Elder				=	3,//����
    em_Faction_Custodian			=	4,//����
    em_Faction_Elite				=	5,//������ӳ�Ա
    em_Faction_Normal				=	6,//��ͨ���ӳ�Ա
    em_Faction_Other				=	7,//�Ǳ�����Ա
};

enum em_Faction_Authority
{
    EFA_KickedNormal		=	1,	//�߳���ͨ����
    EFA_KickedElite		=	2,	//�߳���Ӣ����
    EFA_Promotion			=	3,	//��ְ
    EFA_Demotion			=	4,	//��ְ
    EFA_Build			=	5,	//�������ɽ���
    EFA_Activity			=	6,	//������������
    EFA_SignUp			=	7,	//��������ս
    EFA_Audit			=	8,	//���
    EFA_EditSetting		=	9,	//�޸���������
    EFA_ShowLog			=	10,	//�鿴��־
    EFA_ChangeOther     =   11, //��λ����
    EFA_BecomeHead		=   12,	//��λ����
	EFA_ChangeIcon      =   13, //����ͷ��
};

enum em_Faction_Shade_Upgrade_Type
{
    EFSUT_UnlockTask     = 1,		//��������
    EFSUT_TaskSchedule   = 2, 		//������
    EFSUT_TaskTimes	    =	3,		//�������
};

enum em_Faction_Task_Type
{
    EFTT_HUNTING = 1,			//׽��
};

// ����ϵͳ����ҹ�ϵ����
enum EFriendSysRelationType
{
    EFSRT_FRIEND = 0, // ����
    EFSRT_STRANGER = 1, // İ����
    EFSRT_BLACKLIST = 2, // ������
    EFSRT_OTHER = 3, // ·�˼�
    EFSRT_FINALLYCONTACT = 4,//��������û�
    EFSRT_BEEN_ADD_FRIEND_NOTICE = 100, // �����Ϊ����֪ͨ����
    EFSRT_BEEN_SEND_FLOWER_NOTICE = 101, // ���ͻ�֪ͨ����
};


enum em_State_Mark
{
    ESM_NO = 0,		//����״̬
    ESM_YES = 1,	//��״̬
};

enum em_Faction_Log_ID
{
    EFLID_ChangeOther = 1,		//��λ����
    EFLID_Promotion = 2 ,		//��ְ
    EFLID_Demotion = 3 ,		//��ְ
    EFLID_Kicked = 4,			//����
    EFLID_LeaveFaction = 5,		//�˳�����
    EFLID_JoinFaction = 6,		//��������
    EFLID_DonateCoin = 7,		//����ͭǮ
    EFLID_DonateGold = 8,		//����Ԫ��
    EFLID_UpgradeFaction = 9,	//��������
    EFLID_UpgradeFactionAndBuild = 10,	//�������ɣ���������
    EFLID_UpgradeBuild = 11,		//�������ɽ���
    EFLID_OpenActivity = 12,	//�������ɻ
    EFLID_ShadeActivity = 13,	//���������
    EFLID_CatchOrange = 14,		//׽����ɫ��
    EFLID_ChangeSchedule = 15,	//��������
    EFLID_OpenGoldMode = 16,	//�����ƽ�ģʽ
};


enum em_Faction_Build
{
    EFB_Faction   = 1,  //����
    EFB_Rareitem  = 2,  //��Ʒ��
    EFB_Gymnasium = 3,	//����
    EFB_Shade     = 4,  //����
    EFB_HotSpring = 5,	//��Ȫ
    EFB_ColdPrison = 6,	//����
    EFB_FactionTower = 7,//�����
};

enum em_Faction_Upgrade_Type
{
    EFUT_PlayerNum = 1,	//��������
    EFUT_Build_Delock = 2, //��������
};

enum em_Faction_BattleLog_Type
{
    EFBT_Kicked = 1,	//����ս��
    EFBT_AddFaction = 2,//��������
    EFBT_FactionUpgrade = 3, //��������ս��
};

enum em_Gymnasium_Skill_Flag
{
    EGSF_Learn = 1,	//1��ѧϰ
    EGSF_CurMax = 2,//�ﵽ��ǰ����
    EGSF_SumMax = 3,//�ﵽ������
    EGSF_DoorsTribute = 4,//�Ź�����
    EGSF_Unlock = 5,//δ����
    EGSF_SumDoorsTribute = 6,//�ۻ��Ź�����
};


// ָ������״̬��ͨ����ʲô״̬
enum EEquipMasterDetailState
{
    EQUIP_MASTER_UPGRADABLE            = 0, // ������
    EQUIP_MASTER_ACTIVATABLE           = 1, // �ɼ���
    EQUIP_MASTER_BREAKABLE             = 2, // ��ͻ��
    EQUIP_MASTER_TOP                   = 3, // �޷���������
    EQUIP_MASTER_PLAYER_LVL_NOT_ENOUGH = 4, // ��ͻ�Ƶ���ҵȼ�����
};

// ������֮ͨ�����״̬
enum EMasterBookPanelState
{
    MASTER_BOOK_PANEL_UN_OPEN                 = 0, // ��δ�򿪹ο����
    MASTER_BOOK_PANEL_GET_BUT_NOT_WIPED       = 1, // �Ѵ򿪵�δ�ο�
    MASTER_BOOK_PANEL_WIPED_BUT_NOT_CONFIRMED = 2, // �ѹο���δȷ��
};

// ��ͨ������Ĵ�С
enum EEquipMasterExpBookType
{
    MASTER_EXP_BOOK_SMALL = 1, // С��ͨ������
    MASTER_EXP_BOOK_BIG   = 2, // ��ͨ������
};

enum MonsterFuncType
{
    EMFT_NORMAL = 1,	//��ͨ�뾫Ӣ��
    EMFT_TOWER = 2,		//����
    EMFT_BOSS = 3,		//BOSSս
    EMFT_HUNTING = 4,	//׽��
    EMFT_ACTIVITY = 5,	//�
    EMFT_COURAGE = 6,	//��������
};
// װ����ͨ�׼�
enum EEquipMasterRank
{
    EMG_GRADE_0 = 0, // δ����
    EMG_GRADE_1 = 1, // ����
    EMG_GRADE_2 = 2, // �м�
    EMG_GRADE_3 = 3, // �߼�
    EMG_GRADE_4 = 4, // ��
};

//��߻������ʾID
enum ActiviSidePromptID
{
    EASPID_HotSpring = 1,		//��Ȫ
    EASPID_Hunting = 2,			//׽��
};

//������ʾ���
enum FactionPromptID
{
    EFPID_Activi = 1,	//�л
    EFPID_HaveApply = 2,	//������
    EFPID_Donate = 3,  //�ɾ���
    EFPID_Get	= 4,	//���콱
    EFPID_CanApply = 5, //������
    EFPID_HaveNewRareItem = 6,//�»���
    EFPID_CanBuy = 7,//�ɹ���
    EFPID_NewSkill = 8,//�¼���
    EFPID_CanLearn = 9,//��ѧϰ
    EFPID_CanHunting = 10,//��׽��
    EFPID_InActivi = 11,//���
    EFPID_FindBack = 12,//���һ�
};

//��������ʾ����
enum SmithyPromptID
{
    ESPID_STRENGTHEN = 1, // ��ǿ��
    ESPID_ENCHANT = 2,	  // �ɸ�ħ
    ESPID_EQUIP_MAKE = 3, // ������
};

//�ƹ���ʾ����
enum RecruitPromptID
{
    RPID_RECRUIT = 1, // ����ļ
    RPID_UPGRADE = 2,	 // �ɽ���
};

// ���ɲ������
enum EGvGMatrixType
{
    GVG_MATRIX_NONE    = 0,
    GVG_MATRIX_ATTACK  = 1,
    GVG_MATRIX_DEFEND  = 2,
    GVG_MATRIX_BALANCE = 3,
};

//��չ��Ϣλ������˼
enum emExtBit
{
	em_VIP = 0,	//��vip�����ʾ��Ϣ
	em_EDIT_NAME = 1, //�Ƿ���޸�����
};
enum FormationType
{
	EBAK_BAIHU = 1, //�׻�+����
	EBAK_QINGLONG = 2, //����+����
	EBAK_ZHUQUE = 3, //��ȸ+�ȹ�
	EBAK_XUANWU = 4,//����+����
};

// ˽���жԷ��Ľ�ɫ
enum PrivateChatRoleType
{
    PCRT_NORMAL = 0, // ��ͨ���
    PCRT_GM     = 1, // GM
};

enum JewelryDressPos
{
	EJDP_NECKLACE = 1,  //����
	EJDP_RING = 2,//��ָ
	EJDP_BELT = 3, //����
	EJDP_Jade = 4,//����
};

enum JewelryExtAttr
{
	EJEA_ARMS = 1,//����
	EJEA_CLOTHING = 2,//�·�
	EJEA_HELM = 3,//ͷ��
	EJEA_SHOE = 4,//Ь��
	EJEA_NORMAL_ATTACK = 5,//��ͨ����shanghai
	EJEA_SKILL_ATTACK = 6,//���ܹ���
	EJEA_WEAPON_ATTACK = 7,//��������
	EJEA_WEAPON_DEFEND = 8,//��������
	EJEA_INSTANCE_STORY = 9,//��������
	EJEA_INSTANCE_COIN = 10,//����ͭǮ
	EJEA_FIRST_STUDY = 11,//��һ����
	EJEA_SECOND_STUDY = 12,//�ڶ�����
	EJEA_THIRD_STUDY = 13,//��������
	EJEA_FOURTH_STUDY = 14,//��������


	EJEA_ALL_EQUIP = 15,//����װ��
	EJEA_ALL_NORMAL_ATTACK = 16,//������ͨ����
	EJEA_ALL_SKILL_ATTACK = 17,//���鼼�ܹ���
	EJEA_ALL_WEAPON_ATTACK = 18,//������������
	EJEA_ALL_WEAPON_DEFEND = 19,//������������
	EJEA_INSTANCE_EXPERIENCE = 20,//��������
	EJEA_ALL_SCIENCE_LEVEL = 21,//�Ƽ��ȼ�
	EJEA_ALL_STUDY = 22,//��������
	EJEA_HP = 23,	//����+XXXX
	EJEA_ATTACK = 24,//����+XXXX
	EJEA_DEFENG = 25,//����+XXXX
	EJEA_HITRATE = 26,//�ƻ���+XXXX
	EJEA_DODGERATE = 27,//����+XXXX
	EJEA_CRITRATE = 28,//������+XXXX
    EJEA_DECRITRATE = 29,//������+XXXX
	
    EJEA_MAX
};

enum ValueType
{
	EVT_FIX = 1,//�̶�ֵ
	EVT_PERCENT = 2,//�ٷ���
};

enum JewelryPrompt
{
	EJP_CAN_EXT_UPGRADE = 1,//��������������
	EJP_CAN_BASE_UPGRADE = 2,//�ɾ���
};

// ���ɿ��ս�ִ�
enum GvGRound
{
    GVG_SLEEPING         = 0, // �δ����
	GVG_APPLY            = 1, // ����
	GVG_MONEY_WAR        = 2, // ������һ�֣��������ƴ��
	GVG_CHAOS_WAR        = 3, // �����ڶ��֣����ɴ��Ҷ���������Ѻע��
	GVG_16_TO_8          = 4, // ˫��16��8
	GVG_8_TO_4           = 5, // ˫��8��4
	GVG_FINAL_WAR        = 6, // �ķ��ܾ���
    GVG_END              = 7, // �ѽ���

    GVG_MAX // ���ֵ
};

// gvgս�����
enum GvGLogResult
{
    EGLR_NOT_START  = 0, // δ��ʼ
    EGLR_WIN        = 1, // �ɹ�
    EGLR_LOSE       = 2, // ʧ��
    EGLR_NO_ENEMY   = 3  // �ֿ�
};

enum GvGGambleResult
{
	EGGR_LOST = 0,//ʧ��
	EGGR_WIN = 1,//�ɹ�
	EGGR_NOT_DONE = 2,//δ��ʼ
	EGGR_NOT_GAMBLE = 3,//δѺע
};

enum GvGReward
{
	EGR_NONE = 0,//��Ч���

	EGR_BATTLE_CHAOS_WIN = 1,//���Ҷ�ǰ��ս������
	EGR_BATTLE_16_TO_8_WIN = 2,//16��8����
	EGR_BATTLE_8_TO_4_WIN = 3,//8��4ս������
	EGR_BATTLE_FINAL_WAR_WIN = 4,//�ܾ���
	EGR_BATTLE_CHAOS_LOST = 5,//���Ҷ�ʧ�ܽ���
	EGR_BATTLE_16_TO_4_LOST = 6,//˫��16��4ʧ�ܽ���
	EGR_BATTLE_FINAL_WAR_LOST = 7,//4��ս��ʧ�ܽ���

	EGR_RANK_MONEY = 10,//������ƴǰ�Ľ���
	EGR_RANK_CHAOS_WIN = 11,//���Ҷ�ǰ����������
	EGR_RANK_8_TO_4_WIN = 12,//������ǿ���
	EGR_RANK_FINAL_CHAMPION = 13,//�ھ�����
	EGR_RANK_FINAL_SECOND = 14,//�Ǿ�����
	EGR_RANK_FINAL_THIRD = 15,//��������
	EGR_RANK_FINAL_4_8 = 16,//4-8���ν���

	EGR_ZONE_HONOR = 20,//ȫ����������

    EGR_RANK_MONEY_NO_1 = 21,// ������ƴ�ھ�����
    EGR_RANK_MONEY_NO_2,// ������ƴ�Ǿ�����
    EGR_RANK_MONEY_NO_3 // ������ƴ��������
};

enum GvGiftType
{
	EGGT_BATTLE = 1,//ս�����
	EGGT_RANK = 2,//�������
	EGGT_HONOR = 3,//�������
};
//����������� 
enum em_Join_Type
{
	EJT_ALL = 0,   //ȫ��
	EJT_FACTION = 1, //����
	EJT_FRIEND = 2, //����
};

enum em_GvG_Log_Type
{
	EGLT_CONTINUE_KILL = 1,//��նս��
	EGLT_GVG_FACTION_BATTLE = 2,//����ս��ս��
	EGLT_GVG_GAMBLE = 3,//Ѻע
	EGLT_GVG_ALL_HONOUR = 4,//ȫ������
};

enum ATTACK_TYPE
{
	EAT_NONE = 0,//��
	EAT_ATTACK = 1,//������
	EAT_DEFEND = 2,//������
};

enum EATTACK_TYPE
{
	ET_NORMAL = 1,//��ͨ����
	ET_SKILL = 2,//���ܹ���
	ET_BUFF = 3,//BUFF����
	ET_SPECIAL_EFFECT = 4,//���⹥��
	ET_PET_NORMAL = 5,//������ͨ����
	ET_PET_SKILL = 6,//���＼�ܹ���
};

enum MEDAL_BIG_TYPE
{
	EMBT_LIMIT_TIME = 1,//��ʱѫ��
	EMBT_NONE_TIME = 2,//����ʱѫ��
};

enum MEDAL_SMALL_TYPE
{
	EMST_RACE = 1,//������ѫ��
	EMST_BOSS_KILL = 2,//BOSS��ɱ��
	EMST_BOSS_HURT = 3,//BOSS�˺�����1%
	EMST_PHYSTRENGTH = 4,//����ѫ��
	EMST_ESCORT = 5,//����ѫ��
	EMST_ROCK_MONEY = 6,//ҡǮ��
	EMST_GATHER_SCIENCE_GOLD = 7,//Ԫ���ۻ�
//	EMST_GATHER_SCIENCE_COIN = 8,//ͭǮ�ۻ�
	EMST_WORSHIP_PLAYER = 9,//Ĥ��
//	EMST_WORSHIP_GOD = 10,//����
	EMST_AWAKEN_ZTS = 11,//����
	EMST_SMILE = 12,//Ц��
	EMST_RESET_TOWER = 13,//��������
	EMST_CLIMB_TOWER = 14,//��������
	EMST_PLAYER_LEVEL = 15,//��ҵȼ��ﵽָ���ȼ�
	EMST_PLAYER_POWER = 16,//���ս��
	EMST_PLAYER_VIP_LEVEL = 17,//VIP�ȼ�
	EMST_LOGIN_DAY = 18,//��½����
	EMST_INTERCEPT = 19,//����
	EMST_RESET_ELITEINSTANCE = 20,//���þ�Ӣ����
	EMST_ARREST_BLACK = 21,//С����ץ��
	EMST_DRIVE_BLACK = 22,//С��������
	EMST_RACE_CONTINUE_KILL = 23,//��������ն
	EMST_GVG_MEDAL = 24,//GVG���ѫ��
	EMST_GVE_COURAGE = 25,//GVE���ѫ��
};

enum HP_CHANGE_REASON
{
	EHPCR_NORMAL_SKILL = 1,//���ܻ���ͨ����
	EHPCR_BUFF = 2,//BUFF
	EHPCR_SPECIAL_SUCK_BLOOD = 3,//��Ѫ
	EHPCR_SPECIAL_ADD_BLOOD = 4,//����
	EHPCR_SPECIAL_REBOUND = 5,//����
};

enum ePetState {
	ePS_Normal		= 0,	// ��ͨ
	ePS_FOLLOW		,		// ����
	ePS_FIGHT		,		// ��ս
};

enum ePetSkillType
{
	EPST_FIX = 0,//�̶�
	EPST_RANDOM = 1,//���
};

enum ePetStoreItemType {
	ePSIT_CanBuy				= 1,	// �ɶһ�
	ePSIT_NormalProduct			,		// ͨ��С�ٻ����
	ePSIT_GoodProduct			,		// ͨ�����ٻ����
};

// �⴫װ��Ʒ��
enum FlyEquipQuality
{
    FEQ_TIAN  = 1, // ��
    FEQ_DI    = 2, // ��
    FEQ_XUAN  = 3, // ��
    FEQ_HUANG = 4, // ��
};

enum eSoulPotency
{
	ESP_HP = 1,		//HP
	ESP_ATTACK = 2,	//������
	ESP_HITRATE = 3,		//�ƻ���
	ESP_DODGERATE = 4,		//����
	ESP_CRITRATE = 5,		//������
	ESP_DECRITRATE = 6,	//������
	ESP_DEFEND = 7,//����
	ESP_SKILL_PROBABILITY = 8,//��������
	ESP_SKILL_EFFECT = 9,//����Ч��
	ESP_SKILL_ROUND = 10,//�غ���
};
#endif //#ifndef _COMMONDEF_H_
