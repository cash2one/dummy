#ifndef _ITEM_H_
#define _ITEM_H_


#include <protocol/server/protocligs.h>
#include <logic/base/baseobj.h>
#include <logic/record/recordmgr.h>

using namespace std ;


/*
enum UINT8
{
	EIK_EQUIP = 1, //װ��
	EIK_GOODS = 2, //��Ʒ
	EIK_BOX = 3, //����
};
*/

#define EQUIP_BEGIN_KINDID	1	//װ������ID�� ��ʼ
#define EQUIP_END_KINDID	10000	//װ������ID�� ����

#define JEWELRY_BEGIN_KINDID 10001 //��Ʒ����ID
#define JEWELRY_END_KINDID 19999 //��Ʒ����ID

#define GOODS_BEGIN_KINDID	20000	//��Ʒ����ID�� ��ʼ
#define GOODS_END_KINDID	0XFFFF	//��Ʒ����ID�� ����


class CPlayer;

class CItem:public CBaseObj
{
public:
	CItem();
	virtual ~CItem();
public:
	virtual UINT8		GetItemKind() = 0;//����������(װ��/��Ʒ)
	virtual UINT16	GetItemKindID() = 0;//����������
	virtual UINT16	GetCurPileNum() = 0;//��ǰ������
	virtual VOID		AddPileNum(UINT16 wPileNum, CRecordMgr::EAddItemType emOpType) = 0;//��ӵ�����
	virtual VOID		DecPileNum(UINT16 wPileNum, CRecordMgr::EDecItemType emOpType, UINT64 qwParam2 = 0, UINT64 qwParam3 = 0, UINT64 qwParam4 = 0) = 0;//ɾ��������	
	virtual UINT16&	GetBagPos() = 0;//��ȡ���ߵ��ߴ�ŵı���λ��
	virtual BOOL		Init(VOID* pData, CPlayer* poOwner) = 0;//��������ʱInit
	virtual UINT16	Sell(UINT16 wNum, DT_ITEM_NUM_DATA_LIST_CLI &stRecvItemNumList/*���������ų��ۺ�����õĵ�������*/) = 0;//���۵���
	virtual	void		GetRecoverScience(UINT32 & dwMinScience, UINT32 & dwMaxScience) = 0;//��������

public:
	VOID		SetMemID(UINT64 qwMemID) { m_qwMemID = qwMemID; }
	UINT64	GetMemID() { return m_qwMemID; }
private:
	UINT64	m_qwMemID;//�ڴ�ID�����ڹ�����map����

private:	
	
};



#endif //#ifndef 

