#ifndef _ACCEPTCONDITON_H
#define _ACCEPTCONDITON_H


#include "taskprop.h"


//��������������
class CAcceptCondition
{
public:
    CAcceptCondition() {};
    virtual ~CAcceptCondition() {};
public:
    virtual EAcceptConditionType GetAcceptType() = 0;
};

//��������������_���
class CAcceptCondition_Player: public CAcceptCondition
{
public:
    CAcceptCondition_Player()
    {
        wPlayerLevel = 0;
    };
    ~CAcceptCondition_Player() {};
public:
    virtual EAcceptConditionType GetAcceptType()
    {
        return EACT_PLAYER;
    }

    UINT16 wPlayerLevel;
};

//��������������_����
class CAcceptCondition_Instance: public CAcceptCondition
{
public:
    CAcceptCondition_Instance()
    {
        wSceneIdx = 0;
        byTownIdx = 0;
        byInstanceIdx = 0;
    };
    ~CAcceptCondition_Instance() {};
public:
    virtual EAcceptConditionType GetAcceptType()
    {
        return EACT_INSTANCE;
    }

    UINT16 wSceneIdx;
    UINT8 byTownIdx;
    UINT8 byInstanceIdx;
};

//��������������_����
//class CAcceptCondition_Build: public CAcceptCondition
//{
//public:
//    CAcceptCondition_Build()
//    {
//        byBuildKindID = 0;
//        wLevel = 0;
//    };
//    ~CAcceptCondition_Build() {};
//public:
//    virtual EAcceptConditionType GetAcceptType()
//    {
//        return EACT_BUILD;
//    }
//
//    UINT8 byBuildKindID;
//    UINT16 wLevel;
//};

//��������������_��������
class CAcceptCondition_MainTask: public CAcceptCondition
{
public:
    CAcceptCondition_MainTask()
    {
        dwTaskIdx = 0;
    };
    ~CAcceptCondition_MainTask() {};
public:
    virtual EAcceptConditionType GetAcceptType()
    {
        return EACT_MAINTASK;
    }

    UINT32	dwTaskIdx;
};


typedef HashMap<UINT8, CAcceptCondition*> CAcceptType2CheckMap;
typedef CAcceptType2CheckMap::iterator CAcceptType2CheckMapItr;

#endif

