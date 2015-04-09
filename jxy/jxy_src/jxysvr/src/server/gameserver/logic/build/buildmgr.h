
#ifndef _BUILDMGR_H_
#define _BUILDMGR_H_

#include "buildpropmgr.h"
#include <sdsingleton.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <sdobjectpool.h>

using namespace SGDP;

class CBuild;

typedef HashMap<UINT64, CBuild*> CID2BuildMap;//keyΪ�ڴ�ΨһID
typedef CID2BuildMap::iterator	CID2BuildMapItr;

typedef HashMap<UINT8, CBuild*> CKind2BuildMap; //keyΪ��������
typedef CKind2BuildMap::iterator CKind2BuildMapItr;


class CPlayer;
/**
* @brief ����������
*/
class CBuildMgr
{
public:
    DECLARE_SINGLETON(CBuildMgr)

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

	CBuild*		CreateBuild(UINT32 dwPlayerID, UINT16 wKindID);
	VOID        RemoveBuild(UINT32 dwPlayerID, UINT16 wKindID);
 
protected:
    CBuildMgr();
    ~CBuildMgr();

//////////////////////////////////////////////////////
public:


///////////////////////////////////////////////////////


private:
    CID2BuildMap			m_mapID2Build;
	CSDObjectPool<CBuild, CSDMutex> m_oBuildShmemObjMgr;	
	
};




#endif //#ifndef _ROLEMGR_H_

