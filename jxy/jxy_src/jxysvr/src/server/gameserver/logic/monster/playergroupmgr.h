
#ifndef _PLAYERGROUPMGR_H_
#define _PLAYERGROUPMGR_H_


#include "playergroup.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <protocol/server/protocommondata.h>


using namespace SGDP;

/**
* @brief ���������
*/
class CPlayerGroupMgr
{
    friend class CPlayerGroup;
public:
    DECLARE_SINGLETON(CPlayerGroupMgr)

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
    * �ڹ�����������������Ϣ
    * @param vector<CHero*> vecHero		:	�佫��Ϣ
    * @return CPlayerGroup*			:	�����
    * ���ڷ�������Ľ���Ϣ��ʹ�����Ҫɾ��������������ڴ�й¶
    */
    CPlayerGroup*			CreatePlayerGroup(vector<CHero*> vecHero);
    /**
    * @brief
    * ɾ����������Ϣ
    * @param CPlayerGroup* poPlayerGroup		:	�佫��Ϣ
    */
    VOID					RemovePlayerGroup(CPlayerGroup* poPlayerGroup);
protected:
    CPlayerGroupMgr();
    ~CPlayerGroupMgr();

private:
    CSDObjectPool<CPlayerGroup, CSDMutex>	m_oPlayerGroupPool;
};




#endif //#ifndef

