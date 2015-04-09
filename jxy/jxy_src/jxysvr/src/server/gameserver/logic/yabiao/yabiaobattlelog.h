
#ifndef _YABIAO_BATTLE_LOG_H_
#define _YABIAO_BATTLE_LOG_H_

#include <logic/base/baseobj.h>
#include <protocol/server/protocommondata.h>
#include "common/server/utility.h"

class CPlayer;
class CYabiaoBattleLog: public CBaseObj
{
public:
    CYabiaoBattleLog();
    ~CYabiaoBattleLog();
public:
    virtual VOID	InitAttach() ; //��ʼ��δʹ��shmem��װ������(map/vector)�������������Ա���
    BOOL Init(DT_YABIAO_BATTLELOG_DATA stDT_PAOSHANG_BATTLELOG_DATA, CPlayer* poOwner);
    DT_YABIAO_BATTLELOG_DATA& GetDT_PAOSHANG_BATTLELOG_DATA();
private:
    DT_YABIAO_BATTLELOG_DATA	m_stDT_PAOSHANG_BATTLELOG_DATA;
};

DECLARE_CLASS_POOL_MGR(CYabiaoBattleLog)

#endif

