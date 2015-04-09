
#ifndef _ITEMEXCHANGEMGR_H_
#define _ITEMEXCHANGEMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>
#include <protocol/server/protocligs.h>

class CPlayer;

/**
 * @brief
 */
struct SItemExchangeProp
{
	UINT16	wExchangeIdx;		//�һ���
	TCHAR	aszTitle[MAX_COMMON_TXT_NUM];		//����
	TCHAR	aszDesc[MAX_COMMON_TXT_NUM];		//����
	UINT64	qwStartTime;		//����ʱ��
	UINT64	qwEndTime;		//ʱ��ʱ��
	UINT16	wExchangeItemKindID;//�ɶһ��ĵ���ID
	UINT16	wExchangeItemNum;	//�ɶһ��ĵ�������
	UINT16	awNeedItemKindID[ITEM_EXCHANGE_ITEM_NUM];//�������ID��0Ϊ��Ч
	UINT16	awNeedItemNum[ITEM_EXCHANGE_ITEM_NUM];//0Ϊ��Ч
};


typedef std::map<UINT16, SItemExchangeProp> CItemExchangePropMap; 
typedef CItemExchangePropMap::iterator CItemExchangePropMapItr;

/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CItemExchangeMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CItemExchangeMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_ITEMEXCHANGE ; }
    /**
     * @brief ��ʼ�����Թ�����
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL Init();

    /**
     * @brief �������Թ�����
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    VOID UnInit();

public:
	VOID OpenItemExchange(CPlayer* poPlayer, PKT_CLIGS_OPEN_ITEM_EXCHANGE_ACK& stAck);
	VOID ItemExchange(CPlayer* poPlayer, UINT16 wExchangeIdx, PKT_CLIGS_ITEM_EXCHANGE_ACK& stAck);
	BOOL HaveExchangeActivity(CPlayer* poPlayer);//�Ƿ��жһ��

protected:
	VOID GetItemExchange(CPlayer* poPlayer, UINT8& byExchangeNum, ITEM_EXCHANGE_DATA astExchangeInfo[ITEM_EXCHANGE_ITEM_NUM]);

public:
    CItemExchangeMgr();
    virtual ~CItemExchangeMgr();

private:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL LoadFromDB();

private:
    CItemExchangePropMap	m_mapItemExchangeProp;
};

#endif // #ifndef _MONEYTREEPROPMGR_H_
