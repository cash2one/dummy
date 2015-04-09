
#ifndef _TASKPROPMGR_H_
#define _TASKPROPMGR_H_

#include "taskprop.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <logic/base/basepropmgr.h>

using namespace SGDP;

typedef HashMap<UINT8, CTaskLineProp*> CTaskLine2TaskLinePropMap;//keyΪ�����ߺ�
typedef CTaskLine2TaskLinePropMap::iterator CTaskLine2TaskLinePropMapItr;

typedef HashMap<string, UINT8> CStr2EnumMap;  //�ַ�����ö�ٵ�ת��
typedef CStr2EnumMap::iterator CStr2EnumMapItr;


/**
* @brief ���������
*/
class CTaskPropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CTaskPropMgr)
public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_TASK ; }
    BOOL Init();
    VOID UnInit();

    STaskProp* GetTaksProp(UINT8 byTaskLine, UINT32 dwTaskIdx);
    inline CTaskLine2TaskLinePropMap& GetTaskLine2TaskLinePropMap()  { return m_mapTaskLine; }
    inline DT_INSTANCE_ID& GetInitUnlockInstanceID() {  return m_stInitUnlockInstanceID;  } //����Ĭ�ϳ�ʼ�����ĸ���
	CTaskLineProp* GetTaskLineProp(UINT8 byTaskLine);
public:
    CTaskPropMgr();
    ~CTaskPropMgr();
protected:
    BOOL	ReadTaskFromXML();
    BOOL	ReadTaskFromData(CTaskLineProp* poTaskLineProp, const CHAR* pszData, const UINT32 dwDataLen);
    BOOL	ReadTaskAcceptCondition(CSDXMLNode rootNode, STaskProp* pstTaskProp);
    BOOL	ReadTaskFinishCondition(CSDXMLNode rootNode, STaskProp* pstTaskProp);
    BOOL	ReadTaskEncourage(CSDXMLNode rootNode, STaskProp* pstTaskProp);
    BOOL	ReadTaskUnlockInstance(CSDXMLNode rootNode, STaskProp* pstTaskProp);
    //BOOL	ReadBranchTask(CSDXMLNode rootNode, STaskProp* pstLineTaskProp);
    //BOOL	ReadDailyTaskFromXML();


    VOID	InitStr2Enum();
    ETaskType GetTaskType(string strTaskType);
    EAcceptConditionType GetAcceptConditionType(string strTaskType);
    VOID	InitNextTaskIdx();
private:
    CTaskLine2TaskLinePropMap	m_mapTaskLine;//��������������
    CStr2EnumMap				m_mapStr2Enum;//�ַ�����ö�ٵ�ת�������ڶ�ȡ����
    DT_INSTANCE_ID			m_stLastInstanceID;//���ڶ�ȡ�����ļ�
    DT_INSTANCE_ID			m_stInitUnlockInstanceID;//��ʼ��������ID
};

#endif //#ifndef _ROLEMGR_H_

