
#ifndef _HEROMGR_H_
#define _HEROMGR_H_

#include "hero.h"
#include <sdsingleton.h>
#include <protogsdb.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>

using namespace SGDP;


typedef HashMap<UINT64, CHero*> CID2HeroMap;
typedef CID2HeroMap::iterator	CID2HeroMapItr;


typedef HashMap<UINT16, CHero*> CKind2HeroMap; //keyΪ�佫����
typedef CKind2HeroMap::iterator CKind2HeroMapItr;

typedef map<UINT8, CHero*> CFormationIdx2HeroMap; //keyΪ����λ��
typedef CFormationIdx2HeroMap::iterator CFormationIdx2HeroMapItr;

#define UNDEFINE_UPGRADE_EXPERIENCE 0xFFFFFFFF //δ������һ�����ȼ�ʱ��һ������������


/**
* @brief �佫������
* ��Һ͹��ﹲ�ã�����Hero����map����
*/
class CHeroMgr
{
public:
    DECLARE_SINGLETON(CHeroMgr)

    /**
    * @brief
    * ��ʼ������,��ȡ�����ļ���
    * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
    */
    BOOL Init();

    /**
    * @brief
    * ж�غ���
    */
    VOID UnInit();

public:

	CHero*		CreateHero(UINT32 dwPlayerID, UINT16 wKindID);

	VOID		RemoveHero(UINT32 dwPlayerID, UINT16 wKindID);

    CHero*		FindHero(UINT32 dwPlayerID, UINT16 wKindID);
	
    // �¾�Ӣ�ۻ��������ڻ����ף�
    BOOL		SwapHero(UINT32 dwPlayerID, UINT16 wHeroID1, UINT16 wHeroID2);

protected:
    CHeroMgr();
    ~CHeroMgr();


private:
    CID2HeroMap						m_mapID2Hero;//ֻ����ҵ�Hero��Ϣ   
	CSDObjectPool<CHero, CSDMutex>	m_oHeroShmemObjMgr;
};



#endif //#ifndef _ROLEMGR_H_

