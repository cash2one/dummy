// DealFrame.h: interface for the CRsDealFrame class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _RSDEALFRAME_H_
#define _RSDEALFRAME_H_

#include <sdtype.h>
#include <map>
#include <vector>
#include <string>
#include "common/server/utility.h"

#define RESOPTYPE_CKNUM		1	//�������
#define RESOPTYPE_DECNUM		2	//��������
#define RESOPTYPE_ADDNUM		3	//��������
#define RESOPTYPE_CK_ADD_LIMIT	4  //�����ӵ������Ƿ񳬹�����

struct tagDT_PLAYER_RES_DATA;
typedef tagDT_PLAYER_RES_DATA DT_PLAYER_RES_DATA;

using namespace std;

class CPlayer;

namespace InterfaceDealBase
{
class CRsManager;
class CRsDealFrame
{
public:

    CRsDealFrame();
    CRsDealFrame(CRsManager * IN_pManager);
    virtual ~CRsDealFrame();
    virtual BOOL Deal(CPlayer* poPlayer, vector<string> vecOpValue, UINT8 byOpType, UINT32 dwNum1 = 0, UINT32 dwNum2 = 0, UINT32 dwNum3 = 0, TCHAR *pszDesc = NULL, DT_PLAYER_RES_DATA* pstResInfo1 = NULL, DT_PLAYER_RES_DATA* pstResInfo2 = NULL) = 0;   //����̨���е�Э������
    virtual string GetFrameType() = 0;          //��ȡ��Э���෵�ص�Э�����ͺ�
    virtual void Release() ;               //�ͷŶ����ṩ�ⲿ
    virtual bool init(CRsManager * IN_pManager);//��ʼ��Э�������
public:
	bool	CkAddLimit(string strKey,UINT32 unAddNum);

public:
    CRsManager * m_pManager;
protected:
    void RegisterDealFrame(CRsDealFrame *v_pDealFrame) ;      //����Э�����ݴ���ת������Э����ע�ắ��
};

//�������ӿ�
class CRsManager
{
    //����
public:
    CRsManager();
    virtual ~CRsManager();
    void RegisterDealFrame(CRsDealFrame * IN_pDealFrame) ;
    CRsDealFrame * GetInstanceByType(string strKey);
    virtual CRsManager* instance();   //��ȡ��ʵ������ָ��
    virtual void Release();
protected:
    map<string, CRsDealFrame*> m_mapTask;                //�洢Э�����ָ������
    typedef map<string, CRsDealFrame*>::iterator   MapTaskIter;   //
    CRsManager*                   m_pInstance;  //��������ָ�룬�洢�Լ�ʵ�������ָ��
public:
    virtual BOOL Deal(string strKey, CPlayer* poPlayer, vector<string> vecOpValue, UINT8 byOpType, UINT32 dwNum1 = 0, UINT32 dwNum2 = 0, UINT32 dwNum3 = 0, TCHAR *pszDesc = NULL, DT_PLAYER_RES_DATA* pstResInfo1 = NULL, DT_PLAYER_RES_DATA* pstResInfo2 = NULL);
	string GetAddLimitMsg(string strKey);
};

}
#endif // !defined(AFX_DEALFRAME_H__03868AAA_9098_4543_9A8C_25E2B88CBD7B__INCLUDED_)
