
#ifndef _BUFFMGR_H_
#define _BUFFMGR_H_

#include "buff.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>

using namespace SGDP;




typedef HashMap<UINT32, CBuff*> CID2BuffMap;
typedef CID2BuffMap::iterator CID2BuffMapItr;


/**
* @brief BUFF������
*/
class CBuffMgr
{
public:
    DECLARE_SINGLETON(CBuffMgr)

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

	   /**
    * @brief
    * ����Buff
    * @return CBuff*       : Buff����
    */
	CBuff*		CreateBuff();


    /**
    * @brief
    * �Ƴ�Buff���ӹ��������Ƴ�
    * @return VOID
    */
	VOID            RemoveBuff(UINT32 dwBuffID);
 
protected:
    CBuffMgr();
    ~CBuffMgr();


private:
	CSDObjectPool<CBuff, CSDMutex>		m_oBuffPool;
	CID2BuffMap							m_mapID2Buff;
	static UINT32						m_dwBuffIDGen;//���������ڴ��е�ID
};



#endif //#ifndef _BUFFMGR_H_

