
#ifndef _URL_PROP_MGR_H_
#define _URL_PROP_MGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>

//HTTP���ýӿ�
#define HTTP_APPPAY		        1	//APP��ֵ��
#define HTTP_LEVEL		        2	//������ҵȼ�
#define HTTP_NAME			    3	//��������ǳ�
#define HTTP_BUGGOLDINFO	    4	//APP��ֵ��
#define HTTP_CHATENCOURAGE	    5	//APP��ֵ��
#define HTTP_RETREATE		    6	//APP��ֵ��
#define HTTP_PUSH_PLAYER_INFO	7	//ͬ�����������Ϣ
#define HTTP_GET_MAX_PLAYERID   8	//��ȡ���ID


class CUrlPropMgr
{
public:
	DECLARE_SINGLETON(CUrlPropMgr);

public:

	BOOL Init();

	VOID UnInit();
public:
	const char* GetUrlLevel(){ return m_strUrlLevel.c_str(); }
	const char* GetUrlName(){ return m_strUrlName.c_str(); }
	const char* GetUrlApp(){ return m_strUrlApp.c_str(); }
	const char* GetUrlBuyGoldInfo(){ return m_strUrlBuyGoldInfo.c_str(); }
	const char* GetUrlChatEncourage(){ return m_strUrlChatEncourage.c_str(); }
    const char* GetUrlRetreate(){ return m_strUrlRetreate.c_str(); }
	const char* GetUrlPushPlayerInfo(){ return m_strUrlPushPlayerInfo.c_str(); }
	const char* GetUrlGetMaxPlyaerID(){ return m_strUrlGetMaxPlayerID.c_str(); }
protected:
	CUrlPropMgr();
	virtual ~CUrlPropMgr();
protected:
	BOOL LoadFromDB();

private:
	string m_strUrlLevel;
	string m_strUrlName;
	string m_strUrlApp;
	string m_strUrlBuyGoldInfo;
	string m_strUrlChatEncourage;
    string m_strUrlRetreate;
	string m_strUrlPushPlayerInfo;
	string m_strUrlGetMaxPlayerID;
};




#endif //#ifndef _ROLEMGR_H_

