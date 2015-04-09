

#ifndef _BUILD_H_
#define _BUILD_H_

#include <logic/base/baseobj.h>
#include "buildpropmgr.h"

using namespace std ;

class CPlayer;

struct tagDT_BUILD_DATA_CLI;
typedef tagDT_BUILD_DATA_CLI DT_BUILD_DATA_CLI;

class CBuild:public CBaseObj
{
public:
	CBuild();
	~CBuild();
public:	
	EBuildKind GetBuildKind() { return (EBuildKind)(m_stDT_BUILD_BASE_DATA.byKindID); } //	
	BOOL AddFunctionModuleAndGuide(); //����ģ�鼰��������������ֱ�ӷ��أ�����ع��ܵĽ�����ʵ��
public:
	VOID GetDT_BUILD_DATA_CLI(DT_BUILD_DATA_CLI& stDT_BUILD_DATA_CLI);//��ȡ���ͻ��˵Ľ�����Ϣ
	DT_BUILD_BASE_DATA& GetDT_BUILD_BASE_DATA() { return m_stDT_BUILD_BASE_DATA; };
	//��ʼ����ض���
	BOOL Init(DT_BUILD_BASE_DATA* pstDT_BUILD_BASE_DATA, CPlayer* poOwner);
	//CPlayer* GetOwner() { return m_poOwner; }	
	VOID OnOpen(); //�򿪽����ص�
protected:
	BOOL AddFunctionModuleAndGuide_Awaken();//��� ��ӹ���ģ�鼰����	
	BOOL AddFunctionModuleAndGuide_EliteInstance();//��Ӣ���� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Godweapon();//���� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_MoneyTree();//ҡǮ�� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Plunder();//�Ӷ� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Race();//������ ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Talent();//��ҩ�� ��ӹ���ģ�鼰����	
	BOOL AddFunctionModuleAndGuide_Recuit();//��ļ�� ��ӹ���ģ�鼰����	
	BOOL AddFunctionModuleAndGuide_Smithy();//������ ��ӹ���ģ�鼰����	
	BOOL AddFunctionModuleAndGuide_Maintown();//���� ��ӹ���ģ�鼰����	
	//BOOL AddFunctionModuleAndGuide_Skill();//���� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_ScienceTree(); //�Ƽ� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Crop();//��ֲ ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Experience();//���鵤 ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_UpdateAttr();//�������� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Levy();//�������� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Melting();//�������� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_EatBread();//�԰��� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Yabiao();// ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_ClimbTower();//���� ��ӹ���ģ�鼰����	
	BOOL AddFunctionModuleAndGuide_JingJie();//���� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Skill();//���� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_CollectGas();//�����ռ����� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Adventure();//���� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Xiangqian(); //��Ƕ ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_BossB();       //BOSSս ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_RDC();         //�����ս ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_OpenLight();   //װ������ ��ӹ���ģ�鼰����
    BOOL AddFunctionModuleAndGuide_EquipMaster(); //װ����ͨ ��ӹ���ģ�鼰����
    BOOL AddFunctionModuleAndGuide_Courage(); //�������� ��ӹ���ģ�鼰����
	BOOL AddFunctionModuleAndGuide_Friends(); //����ϵͳ
	BOOL AddFunctionModuleAndGuide_BegBlue(); //����ϵͳ
	BOOL AddFunctionModuleAndGuide_Faction();	//����
	BOOL AddFunctionModuleAndGuide_Fromation();	//����
	BOOL AddFunctionModuleAndGuide_GVG();//���ս
	BOOL AddFunctionModuleAndGuide_Soul();//ս��
	BOOL AddFunctionModuleAndGuide_Medal();//ѫ��
	BOOL AddFunctionModuleAndGuide_Pet();//����
	BOOL AddFunctionModuleAndGuide_OnHook();	//�һ�
protected:	
	DT_BUILD_BASE_DATA		m_stDT_BUILD_BASE_DATA; //������Ϣ	
};


#endif //#ifndef 

