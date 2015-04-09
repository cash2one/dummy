#include "eventreactor.h"
#include "sdtime.h"

namespace SGDP { 
    CEvent::CEvent()
    {
	    m_eEventStatus = EVENT_READY;
	    m_qwNextTick = 0;
    }

    CEvent::~CEvent()
    {
	    m_eEventStatus = EVENT_READY;
	    m_qwNextTick = 0;
    }

    CEventMeter::CEventMeter()
    {

    }

    CEventMeter::~CEventMeter()
    {

    }


    CCommonEventMeter::CCommonEventMeter()
    {
        m_qwLastTickCount = 0;
        m_dwLastEventCount = 0;
        m_qwTotalTickCount = 0;
        m_dwTotalEventCount = 0;
        m_dwTotalLoopCount = 0;
        m_qwRecentTickCount = 0;
        m_dwRecentEventCount = 0;
        m_dwRecentLoopCount = 0;

        memset(m_aoElementMeterInfo, 0, sizeof(m_aoElementMeterInfo));
	    m_bStatus = FALSE;
    }

    CCommonEventMeter::~CCommonEventMeter()
    {
        m_qwLastTickCount = 0;
        m_dwLastEventCount = 0;
        m_qwTotalTickCount = 0;
        m_dwTotalEventCount = 0;
        m_dwTotalLoopCount = 0;
        m_qwRecentTickCount = 0;
        m_dwRecentEventCount = 0;
        m_dwRecentLoopCount = 0;
        memset(m_aoElementMeterInfo, 0, sizeof(m_aoElementMeterInfo));

	    m_bStatus = FALSE;
    }

    /**
     * @brief ��ʼ��¼�õ�����ѭ��
     * @param dwCurTick : ��ǰϵͳTick
     */
    VOID CCommonEventMeter::BeginLoop(UINT64 qwCurTick)
    {
	    if(FALSE == m_bStatus)
	    {
		    return;
	    }
	    m_qwBeginTick = qwCurTick;
        memset(m_aoElementMeterInfo, 0, sizeof(m_aoElementMeterInfo));
    }

    /**
     * @brief ������¼�õ�����ѭ��
     * @param dwEventCount : ��ִ��������ִ���˶�����ЧԪ������
     * @param dwCurTick : ��ǰϵͳTick
     */
    VOID CCommonEventMeter::EndLoop(UINT32 dwEventCount, UINT64 qwCurTick)
    {
	    if(FALSE == m_bStatus)
	    {
		    return;
	    }
	    m_qwLastTickCount = qwCurTick - m_qwBeginTick;
	    m_dwLastEventCount = dwEventCount;
	    m_qwTotalTickCount += m_qwLastTickCount;
	    m_dwTotalEventCount += m_dwLastEventCount;
	    m_dwTotalLoopCount++;
	    m_qwRecentTickCount += m_qwLastTickCount;
	    m_dwRecentEventCount += m_dwLastEventCount;
	    m_dwRecentLoopCount++;
    }

    /**
     * @brief �Ե���Ԫ�����ڽ��г���
     * @param dwElementType : Ԫ�����ͣ����û�����
     * @param qwTickCount : ����Ԫ�����ڳ���ʱ��
     */
    INT32 CCommonEventMeter::AddSamplePoint(UINT32 dwElementType, UINT64 qwTickCount)
    {
	    if(FALSE == m_bStatus)
	    {
		    return -1;
	    }
        (m_aoElementMeterInfo[dwElementType].dwEventCount)++;
        m_aoElementMeterInfo[dwElementType].qwEventTick += qwTickCount;
        if(m_aoElementMeterInfo[dwElementType].qwEventMaxTick < qwTickCount)
        {
            m_aoElementMeterInfo[dwElementType].qwEventMaxTick = qwTickCount;
        }
        if(m_aoElementMeterInfo[dwElementType].qwHistoryMaxTick < m_aoElementMeterInfo[dwElementType].qwEventMaxTick)
        {
            m_aoElementMeterInfo[dwElementType].qwHistoryMaxTick = m_aoElementMeterInfo[dwElementType].qwEventMaxTick;
        }
	    return 0;
    }

    /**
     * @brief �������ͳ������
     */
    VOID CCommonEventMeter::Reset()
    {
	    if(FALSE == m_bStatus)
	    {
		    return;
	    }
	    m_qwRecentTickCount = 0;
	    m_dwRecentEventCount = 0;
	    m_dwRecentLoopCount = 0;
    }

    /**
     * @brief ���ȫ��ͳ������
     */
    VOID CCommonEventMeter::Clear()
    {
	    if(FALSE == m_bStatus)
	    {
		    return;
	    }
	    m_qwLastTickCount = 0;
	    m_dwLastEventCount = 0;
	    m_qwTotalTickCount = 0;
	    m_dwTotalEventCount = 0;
	    m_dwTotalLoopCount = 0;
	    m_qwRecentTickCount = 0;
	    m_dwRecentEventCount = 0;
	    m_dwRecentLoopCount = 0;
	    memset(m_aoElementMeterInfo, 0, sizeof(m_aoElementMeterInfo));
    }

    /**
     * @brief ��ʼͳ��
     */
    INT32 CCommonEventMeter::Start()
    {
	    if(FALSE == m_bStatus)
	    {
		    m_bStatus = TRUE;
		    return 0;
	    }
	    else
	    {
		    // �Ѿ���ʼ
		    return -1;
	    }
    }

    /**
     * @brief ��ͣͳ��
     */
    INT32 CCommonEventMeter::Stop()
    {
	    if(FALSE == m_bStatus)
	    {
		    return -1;
	    }
	    else
	    {
		    // �Ѿ���ʼ
		    m_bStatus = FALSE;
		    return 0;
	    }
    }


    /**
     * @brief ������һ�δ���
     * @param qwDelay ��ǰʱ��
     * @return ���ڲ㼶
     */
    UINT8 CWheelItem::SetupForNextTrigger(UINT64 qwDelay, UINT32 dwInterval)
    {
	    UINT8 byLevel = 0;
        if(0 == dwInterval)
        {
	        m_aqwSlotIndexes[0] += m_poElementHandler->m_dwInterval + qwDelay;
        }
        else
        {
            m_aqwSlotIndexes[0] += dwInterval + qwDelay;
        }
	    for(byLevel = 0; byLevel < WHEELARRAY_COUNT - 1; byLevel++)
	    {
		    if(m_aqwSlotIndexes[byLevel] < WHEEL_ARRAY_LEN)
		    {
			    break;
		    }
		    m_aqwSlotIndexes[byLevel + 1] += m_aqwSlotIndexes[byLevel] / WHEEL_ARRAY_LEN;
		    m_aqwSlotIndexes[byLevel] = m_aqwSlotIndexes[byLevel] % WHEEL_ARRAY_LEN;
	    }
	    // ������һ��������⴦��
	    if(m_aqwSlotIndexes[WHEELARRAY_COUNT-1] >= WHEEL_ARRAY_LEN)
	    {
		    m_aqwSlotIndexes[WHEELARRAY_COUNT-1] %= WHEEL_ARRAY_LEN;
	    }
	    return byLevel;
    }

    /**
     * @brief ��ȡ��һ������ʱ��
     * @param byLevel ��ʱ���㼶
     * @return ��һ������ʱ��
     */
    UINT64 CWheelItem::GetSlotIndexForNextTrigger( UINT8 level )
    {
	    return m_aqwSlotIndexes[level];
    }

    /**
     * @brief �����Դ���
     */
    INT32 CWheelItem::OnEvent()
    {
        return m_poElementHandler->OnEvent();
    }

    /**
     * @brief ���캯��
     */
    CWheelLevel::CWheelLevel() :
	    m_byWheelLevel(0),
	    m_dwCurSlot(0)
    {
    }

    /**
     * @brief ʱ������ƶ�
     * @param bRewindOnEnd �Ƿ����յ�ѭ������ʼλ��
     * @return ��������յ㷵��FALSE�����򷵻�TRUE
     */
    BOOL CWheelLevel::NextSlot(BOOL bRewindOnEnd)
    {
	    if(WHEEL_ARRAY_LEN - 1 == m_dwCurSlot)
	    {
		    if(TRUE == bRewindOnEnd)
		    {
			    m_dwCurSlot = 0;
		    }
		    return FALSE;
	    }
	    else
	    {
		    m_dwCurSlot++;
	    }
	    return TRUE;
    }

    /**
     * @brief �����²㼶ʱ��۶���
     * @param oSlotLevel �����ص�ʱ��۲㼶����
     * @return ��������յ㷵��FALSE�����򷵻�TRUE
     */
    VOID CWheelLevel::ReloadFromLevel(CWheelLevel &oSlotLevel)
    {
	    std::list<CWheelItem*> &lsSlot = oSlotLevel.m_aoWheels[oSlotLevel.m_dwCurSlot];
	    CWheelItem* poWheelItem = NULL;
	    while (lsSlot.empty() == FALSE)
	    {
		    poWheelItem = lsSlot.front();
		    lsSlot.pop_front();
		    CWheelLevel::AddItem(poWheelItem);
	    }
    }

}

