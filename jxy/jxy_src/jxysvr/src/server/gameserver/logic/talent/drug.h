#ifndef _DRUG_H_
#define _DRUG_H_


#include <logic/base/baseobj.h>
#include <protocol/server/protocommondata.h>

using namespace SGDP;

struct tagDrugProp;
typedef tagDrugProp SDrugProp;

struct tagDT_DRUG_DATA_CLI;
typedef tagDT_DRUG_DATA_CLI DT_DRUG_DATA_CLI;

class CPlayer;
class CDrug: public CBaseObj
{
public:
    CDrug();
    ~CDrug();

public:
    //��ʼ����ض���
    BOOL Init(DT_DRUG_DATA* pstDT_DRUG_DATA, CPlayer* poOwner);

    DT_DRUG_DATA& GetDT_DRUG_DATA() { return m_stDT_DRUG_DATA; };
    VOID GetDT_DRUG_DATA_CLI(DT_DRUG_DATA_CLI& stDT_DRUG_DATA_CLI);
    SDrugProp* GetDrugProp();
    BOOL CkFull();//����Ƿ��Ѿ��ﵽʹ�����ޣ��ﵽ���ʹ�����޷���TRUE

    UINT16 GetTalent() { return m_wTotalTalent; } ;//��ȡ�õȼ���ҩ����������

    VOID OnUse();//ʹ�øõȼ���ҩ�ɹ�ʱ�ص������¼�������������

protected:
    VOID CountTalent();//

private:
    DT_DRUG_DATA		m_stDT_DRUG_DATA;//
    UINT16				m_wTotalTalent;//�õȼ���ҩ����������,���ڲ���ÿ�λ�ȡ���¼���.ʹ���µ�ҩʱ���¼���
};

#endif
