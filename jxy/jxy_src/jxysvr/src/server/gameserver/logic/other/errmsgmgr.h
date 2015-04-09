
#ifndef _MSGDEFMGR_H_
#define _MSGDEFMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <map>
#include <vector>
#include <logic/base/basepropmgr.h>
#include <logic/base/logicfunc.h>
#include <string>

using namespace std;
using namespace SGDP;

//�����������Դ�����Ϣ
struct SRegionErrMsgProp
{
	UINT8	byCliRegionType;	//�ͻ���ƽ̨�������ͣ�0���ļ��壬1���ķ��壬2Ӣ��. ProtocolIDΪ0Ϊ��ʾ��ǰʹ�õ�CliRegionType
	//UINT16	wProtocolID;		//����Ӧ������Э���
	string	strErrKey;			//������
	string  strMsg;
	//string	strErrMsg;		//������Ϣ,��ʽ��ʹ��{������},��hp={HP},mp={MP}����ʽ������������ճ��һ��({HP}{MP}����),Ҳ�����ڵ�һ���ַ�
	vector<string> vecErrMsg;	//������Ϣ,��ʽ��ʹ��${������},��hp={HP},mp={MP}�����Ѿ�
	//
};

typedef map<string, SRegionErrMsgProp> CID2RegionErrMsgPropMap; //keyΪbyCliRegionType+strErrKey
typedef CID2RegionErrMsgPropMap::iterator CID2RegionErrMsgPropMapItr;

class CMsgDefMgr:public CBasePopMgr
{
	friend class CGSProcessor;
public:

    DECLARE_SINGLETON_PROPMGR(CMsgDefMgr);

	virtual EConfigModule	GetConfigModuleType() { return ECM_ERRMSG ; }
public:

    BOOL Init();

    VOID UnInit();
public:
	string GetErrMsg(string strErrKey, vector<string>* pvecFillMsg = NULL);

public:
    CMsgDefMgr();
    virtual ~CMsgDefMgr();
protected:
	BOOL LoadFromDB();

private:
	UINT8					m_byCliRegionType;
	CID2RegionErrMsgPropMap	m_mapID2RegionErrMsgProp;
};

#endif // 
