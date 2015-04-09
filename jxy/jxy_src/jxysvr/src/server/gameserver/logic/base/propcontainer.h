// SHANDA GAMES PROPRIETARY INFORMATION
//
// This software is supplied under the terms of a license agreement or
// nondisclosure agreement with Shanda Games and may not 
// be copied or disclosed except in accordance with the terms of that 
// agreement.
//
//      Copyright (c) 1999-2010 Shanda Games.
//      All Rights Reserved.
//
// Shanda Games Limited, Shanghai, China, 201203
// http://www.shandagames.com

#ifndef _PROPCONTAINER_H_
#define _PROPCONTAINER_H_

#include <map>
#include <string>
#include <sdtype.h>


/**
* @brief ����������
* ������Ϸ�ж�Ӧ�����ļ��洢�����Թ���
* ����������ԡ��������Եȣ�����Ҫ�ػ���ʵ����������д���
* �ṩ�˻���������ֵ�Ĳ�ѯ���ܣ�����ʹ�����ֱ�ż��������Ʋ�ѯ
*/
template <typename Prop, typename PrimaryKey = UINT32, typename AssistantKey = tstring>
class CPropContainer
{
public:
    typedef std::map<PrimaryKey, Prop>                      CPriKeyPropMap;
    typedef std::map<AssistantKey, PrimaryKey>              CAssKeyPropMap;

    CPropContainer()
    {
        m_PriKeyPropMap.clear();
        m_AssKeyPropMap.clear();
    }

    virtual ~CPropContainer()
    {
        m_PriKeyPropMap.clear();
        m_AssKeyPropMap.clear();
    }

public:
    /**
    * @brief ��ȡ������ǰװ��Ԫ�ظ���
    * @return ������ǰװ��Ԫ�ظ���
    */
    UINT16 GetCount()
    {
        return m_PriKeyPropMap.size();
    }

    /**
    * @brief ��Ӵ���������Ԫ��
    * @param priKey ����
    * @param property ����
    * @return ִ�н����TRUE�ɹ���FALSEʧ��
    */
    BOOL Add(PrimaryKey priKey, Prop& property)
    {
        typename CPriKeyPropMap::iterator itr = m_PriKeyPropMap.find(priKey);
        if(itr != m_PriKeyPropMap.end())
        {
            itr->second = property;
        }
        else
        {
            m_PriKeyPropMap.insert(make_pair(priKey, property));
        }
        return TRUE;
    }

    /**
    * @brief ��Ӵ��������͸�����Ԫ��
    * @param priKey ����
    * @param assKey ����
    * @param property ����
    * @return ִ�н����TRUE�ɹ���FALSEʧ��
    */
    BOOL Add(PrimaryKey priKey, AssistantKey assKey, Prop& property)
    {
        typename CPriKeyPropMap::iterator itr = m_PriKeyPropMap.find(priKey);
        if(itr != m_PriKeyPropMap.end())
        {
            itr->second = property;
        }
        else
        {
            m_PriKeyPropMap.insert(std::make_pair(priKey, property));
        }
        typename CAssKeyPropMap::iterator iter2 = m_AssKeyPropMap.find(assKey);
        if(iter2 != m_AssKeyPropMap.end())
        {
            iter2->second = priKey;
        }
        else
        {
            m_AssKeyPropMap.insert(make_pair(assKey, priKey));
        }
        return TRUE;
    }

    /**
    * @brief ����Ԫ��
    */
    VOID Clear()
    {
        m_PriKeyPropMap.clear();
        m_AssKeyPropMap.clear();
    }

    /**
    * @brief ������������Ԫ��
    * @param key ����
    * @return �����ҵ�Ԫ��
    */
    Prop* GetPropByPrimaryKey(PrimaryKey key)
    {
        typename CPriKeyPropMap::iterator itr = m_PriKeyPropMap.find(key);
        if(itr != m_PriKeyPropMap.end())
        {
            return &itr->second;
        }
        return NULL;
    }

    /**
    * @brief ���ݸ�������Ԫ��
    * @param key ����
    * @return �����ҵ�Ԫ��
    */
    Prop* GetPropByAssistantKey(AssistantKey key)
    {
        typename CAssKeyPropMap::iterator itr = m_AssKeyPropMap.find(key);
        if(itr != m_AssKeyPropMap.end())
        {
            typename CPriKeyPropMap::iterator itrPri = m_PriKeyPropMap.find(itr->second);
            if(itrPri != m_PriKeyPropMap.end())
            {
                return &itrPri->second;
            }
        }
        return NULL;
    }

protected:
    // ������
    CPriKeyPropMap  m_PriKeyPropMap;
    // ������
    CAssKeyPropMap  m_AssKeyPropMap;
};



template <typename SType>
struct SBitContainer
{
#define CHAT_BIT_COUNT 8

    SBitContainer()
    {
        tType = SType();
    }

    SBitContainer(const SType& tData)
    {
        tType = tData;
    }

    operator SType() const
    {
        return tType;
    }

    template<typename SOtherType>
    operator SOtherType()
    {
        return static_cast<SOtherType>(tType);
    }

    BOOL operator [](INT32 nBit)
    {
        return Test(nBit);
    }

    VOID operator = (const SType& tVal)
    {
        tType = tVal;
    }

    VOID  Set(INT32 nBit, BOOL bSet)
    {
        if ((sizeof(SType) * CHAT_BIT_COUNT) <= nBit)
        {
            if (bSet)
            {
                // ֻҪ�����Χ��ֵ���ͽ�ÿ��bit����1, gqf
                tType = (0x1 << sizeof(SType)) - 1;
            }
            return;
        }
        INT32 nBitMask = (0x1 << nBit);
        bSet? (tType |= nBitMask) : (tType &= ~nBitMask);
    }

    BOOL Test(INT32 nBit)
    {
        if ((sizeof(SType) * CHAT_BIT_COUNT) <= nBit)
        {
            return FALSE;
        }
        return ((tType & (0x1 << nBit))? TRUE : FALSE);
    }

    SType Count()
    {
        SType tCount = SType();
        for (SType i = tType; i != 0; i &= (i - 1))
        {
            tCount++;
        }
        return tCount;
    }

    SType tType;
};



#endif // #ifndef _PROPCONTAINER_H_

