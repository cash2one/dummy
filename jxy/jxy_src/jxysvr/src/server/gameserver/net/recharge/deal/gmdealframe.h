// DealFrame.h: interface for the CRsDealFrame class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _MSDEALFRAME_H_
#define _MSDEALFRAME_H_

#include <sdtype.h>
#include <map>
#include <vector>
#include <string>
#include "common/client/gmdef.h"
#include "common/client/errdef.h"
#include "common/server/utility.h"
using namespace std;



class CRCClient;


namespace InterfaceDealBase
{

class CGmManager;

class CGmDealFrame
{
public:

    CGmDealFrame();
    CGmDealFrame(CGmManager * IN_pManager);
    virtual ~CGmDealFrame();
    virtual void Deal(CRCClient* poClinet, UINT32 dwSerialNumber, UINT8 byAction, UINT32 dwAreaID, UINT32 dwPlayerID, UINT32 dwParam1, UINT64 qwParam2, UINT64 qwParam3, TCHAR* pszParam4, TCHAR* pszParam5, TCHAR *pszDesc) = 0;   //����Э������
	virtual void Deal(CRCClient* poClinet,UINT32 dwSerialNumber,UINT32 dwAreaID,UINT32 dwPlayerID,map<string,string> &mapField) = 0;
	virtual void   Interface(CRCClient* poClinet) = 0;
    virtual UINT16 GetFrameType() = 0;          //��ȡ��Э���෵�ص�Э�����ͺ�
	virtual string GetStrFrameType() = 0;          //��ȡ��Э���෵�ص�Э�����ͺ�
	virtual string GetStrFrameDesc() = 0;
    virtual void Release() ;               //�ͷŶ����ṩ�ⲿ
    virtual bool init(CGmManager * IN_pManager);//��ʼ��Э�������

public:
	typedef map<string,string>::iterator	MapFiledIter;//�������淢�͵��ͻ��˵�������Ϣ 
	MapFiledIter iter;

public:
	void RsponeMsg(CRCClient* poClient,map<string,string> &mapFiled);//��������JSON��ʽ
	//string GetErrorMsgJson(const UINT16 unErrorType, map<string,string> *mapJson = NULL);//��Ϊһ�������ӿڣ�����������ͣ����JSON��ʽ���ַ���

public:
    CGmManager * m_pManager;
protected:
    void RegisterDealFrame(CGmDealFrame *v_pDealFrame) ;      //����Э�����ݴ���ת������Э����ע�ắ��
};

//�������ӿ�
class CGmManager
{
    //����
public:
    CGmManager();
    ~CGmManager();

    void				RegisterDealFrame(CGmDealFrame * IN_pDealFrame) ;
    CGmDealFrame*		GetInstanceByType(UINT16 wProto);
	CGmDealFrame*		GetInstanceByType(string strProto);
    CGmManager*			instance();   //��ȡ��ʵ������ָ��
    void				Release();
	void				Deal(UINT16 wProto, CRCClient* poClinet, UINT32 dwSerialNumber, UINT8 byAction, UINT32 dwAreaID, UINT32 dwPlayerID, UINT32 dwParam1, UINT64 qwParam2, UINT64 qwParam3, TCHAR* pszParam4, TCHAR* pszParam5, TCHAR *pszDesc);
	void				Deal(CRCClient* poClinet,UINT32 dwSerialNumber,UINT32 dwAreaID,UINT32 dwPlayerID,map<string,string> &mapField,string strCmdInfo);
	void				Interface(string strProto, CRCClient* poClinet);
	string				GetGmInterfaceCmd(const string strProto);

private:
    map<UINT16, CGmDealFrame*> m_mapTask;						//�洢Э�����ָ������
	map<string, CGmDealFrame*> m_mapStrTask;						//�洢Э�����ָ������
	typedef map<UINT16, CGmDealFrame*>::iterator   MapTaskIter;   //
	typedef map<string, CGmDealFrame*>::iterator   MapStrTaskIter;   //
    CGmManager*               m_pInstance;						//��������ָ�룬�洢�Լ�ʵ�������ָ��

};

}
#endif // !defined(AFX_DEALFRAME_H__03868AAA_9098_4543_9A8C_25E2B88CBD7B__INCLUDED_)
