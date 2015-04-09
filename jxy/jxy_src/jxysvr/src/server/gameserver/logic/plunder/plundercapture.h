
#ifndef _PLUNDERCAPTURE_H_
#define _PLUNDERCAPTURE_H_

#include <sdtype.h>
#include <logic/base/baseobj.h>
#include <protocol/server/protocommondata.h>

class CPlayer;
class CPlunder;

struct tagDT_CAPTURE_DATA_CLI;
typedef tagDT_CAPTURE_DATA_CLI DT_CAPTURE_DATA_CLI;

struct tagDT_CAPTURE_WORK_DATA_CLI;
typedef tagDT_CAPTURE_WORK_DATA_CLI DT_CAPTURE_WORK_DATA_CLI;


class CPlunderCapture:public CBaseObj
{
public:
	CPlunderCapture();
	~CPlunderCapture();
public:
	BOOL Init(const DT_CAPTURE_DATA* pstDT_CAPTURE_DATA, CPlayer* poOwner, CPlunder* poPlunder);
	DT_CAPTURE_DATA& GetDT_CAPTURE_DATA() { return m_stDT_CAPTURE_DATA; }
	VOID GetDT_CAPTURE_DATA_CLI(DT_CAPTURE_DATA_CLI& stDT_CAPTURE_DATA_CLI); //�жϷ�²�Ƿ����ͷţ�����ȡ��Ϣ���ͻ��ˣ����ͷ��򷵻�FALSE�������·����ͻ���
	
	//BOOL CkNeedRelease();//����Ƿ����ͷ�,����TRUE��ʾ���ͷ�	
	/////////////////////////////////////
	UINT16 SetWorkType(UINT8 byIncomeType,DT_CAPTURE_WORK_DATA_CLI& stWorkInfo);
	UINT16 CollectIncome(UINT32& dwIncomeValue, DT_CAPTURE_WORK_DATA_CLI& stWorkInfo, UINT8 &byHalved);
	UINT16 BleedCapture(UINT8& byIncomeType, UINT32& dwIncomeValue);
protected:
protected:
	VOID GetDT_CAPTURE_WORK_DATA_CLI(DT_CAPTURE_WORK_DATA_CLI& stDT_CAPTURE_WORK_DATA_CLI);
private:
    DT_CAPTURE_DATA	m_stDT_CAPTURE_DATA;
    CPlunder*		m_poPlunder;
    UINT32			m_dwCaptureKeepSecond;		//��²ӵ�б���ʱ��(��λСʱ�����˸�ʱ�����Զ��ͷ�). ���ڻ��棬����ÿ��ȡ
    UINT32			m_dwCaptureWorkSecond;		//��²����ʱ��,���ڻ��棬����ÿ��ȡ
    //UINT32			m_dwWorkCoinPerSec;		//ÿ�빤���ջ�ͭ��,���ڻ��棬����ÿ��ȡ
    //UINT32			m_dwWorkSciencePerSec;		//ÿ�빤���ջ�����,���ڻ��棬����ÿ��ȡ
};


#endif

