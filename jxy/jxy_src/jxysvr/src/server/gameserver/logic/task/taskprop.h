#ifndef _TASKPROP_H
#define _TASKPROP_H

#include <map>
#include <sdtype.h>
#include <sdhashmap.h>
#include <sdobjectpool.h>
#include <logic/base/burstprop.h>
#include <logic/instance/instancepropmgr.h>
#include <common/client/commondef.h>

using namespace SGDP;
using namespace std;


class CPlayer;

//��������
typedef  UINT32 ETaskType;


//����������������
enum EAcceptConditionType
{
	EACT_INVALID = 0, //��Ч
	EACT_PLAYER = 1, //��Ҵﵽָ���ȼ�
	EACT_INSTANCE = 2, //���ͨ��ָ������
	EACT_BUILD = 3, //���ӵ��ָ��������ָ���ȼ�
	EACT_MAINTASK = 4, //������ָ����������
	EACT_MAX,		//���
};

class CAcceptCondition;
class CFinishCondition;
typedef HashMap<UINT8, CAcceptCondition*> CAcceptType2CheckMap;
typedef CAcceptType2CheckMap::iterator CAcceptType2CheckMapItr;


//����������
struct STaskEncourageProp
{
public:
	STaskEncourageProp();
	~STaskEncourageProp();
public:
	UINT32				dwCoin;
	UINT32				dwGold;
	UINT16				wPhyStrength;
	UINT32				dwScience;
	UINT32				dwFame;
	UINT32				dwStory;//����,ÿ���佫��һ��
	UINT32				dwExperience;//����,ÿ���佫��һ��
	UINT32				dwBlueGas; //����
	UINT32				dwPurpleGas; //����
	UINT32				dwJingJie; //����
	CItemKindID2NumMap	mapItemNum;//�����ĵ��߼���Ӧ����
};

struct STaskProp;
typedef map<UINT32, STaskProp*> CTaskIdx2TaskPropMap;//keyΪ�������dwTaskIdx,�ð���map
typedef CTaskIdx2TaskPropMap::iterator CTaskIdx2TaskPropMapItr;
//��������
struct STaskProp
{
public:
	STaskProp();
	~STaskProp();
public:
	UINT8		byTaskLineIdx;//���������
	UINT32		dwTaskIdx;//�������,���밴��С˳�򣬵���һ������
	ETaskType	eTaskType;//��������
	tstring		strDispName;//������ʾ����
	tstring		strDesc;//������
	CAcceptType2CheckMap mapAcceptCondition;//�����������,�ɶ��
	CFinishCondition*	 poFinishCondition;//�����������
	STaskEncourageProp	 stTaskEncourageProp; //������ɽ���	
	//CTaskIdx2TaskPropMap mapBranchTask;//֧������,key��1��ʼ������++
	//�������������ֻ������1����
	BOOL				bNewUnlockInstanceID;//�Ƿ��½�������
	DT_INSTANCE_ID		stInstanceID;//��ǰ����������ĸ���(�����������)
	UINT32				dwNextTaskIdx;//��һ��������ţ�0Ϊ��������û����
	
	//��������ȡ����ʱ��ֵ
	UINT16			wAcceptPlayerLevel;//������Ҫ����ҵȼ������ڷ��ظ��ͻ��ˣ����ڲ���
	DT_INSTANCE_ID	stAcceptInstanceID;//������Ҫͨ���ĸ��������ڷ��ظ��ͻ��ˣ����ڲ���
};


//��������������
class CTaskLineProp
{
public:
	CTaskLineProp();
	~CTaskLineProp();
public:
	STaskProp*				GetNextTask(UINT32 dwTaskIdx); //��ȡdwTaskIdx����һ������dwTaskIdx��һ����Ч��û�з���NULL
	STaskProp*				GetLastTask(UINT32 dwTaskIdx); //��ȡdwTaskIdx����һ������dwTaskIdxһ����Ч
	UINT8					byTaskLineIdx;//���������
	UINT32					dwFirstTaskIdx;//�������ߵĵ�һ������
	CTaskIdx2TaskPropMap	mapTaskProp;//�������ߵ�����
};



#endif

