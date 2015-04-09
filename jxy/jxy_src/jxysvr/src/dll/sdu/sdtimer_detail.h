#ifndef SD_TIMER_DETAIL_H
#define SD_TIMER_DETAIL_H
#include "sdtimer.h"
#include <list>
#include <sstream>
namespace SGDP
{

// ʱ������ÿ���м���
    static const UINT32 TIMER_ARRAY_LEN = 1000;

// ʱ�����в���,ʱ��������ϸ��Ϊ0��
    static const UINT32 TIMERARRAY_COUNT = 5;

    class CSDTimerImpl;
    class CTimerItem
    {
    public:
        UINT8       m_timerLevel;          // ʱ�ӵ�ǰλ����һ��ʱ��������

        /**
        * @brief
        * ��ʼ��������ʱ��
        * @param poTimerModule : ����Ķ�ʱ�����
        * @param poTimerHandler : ����Ķ�ʱ���������ӿ�
        * @param dwElapse : ��ʱ���ļ��
        * @param dwTimerId : ��ʱ��id
        * @return void
        */
        VOID Init( CSDTimerImpl* poTimerCtrl,
                   ISDTimer* poTimerHandler,
                   UINT32 dwElapse,
                   UINT32 dwTimerID,
                   UINT32 loopCount );


        UINT8 SetupForNextTrigger(UINT32 delay);


        inline VOID SetLastExpdTime(UINT32 dwExpTime)
        {
            m_dwLastExpTime = dwExpTime;
        }

        inline UINT32 GetLastExpdTime()
        {
            return 	m_dwLastExpTime;
        }

        /**
        * @brief
        * ��ȡ��һ�������㼶
        * @param level : ��ʱ���㼶
        * @return ��һ�������㼶
        */
        UINT32 GetSlotIndexForNextTrigger(UINT8 level);

        /**
        * @brief
        * ��ʱ����������
        * @return void
        */
        VOID OnTimer();


        inline BOOL CheckLoop()
        {
            if (m_dwLoopCount == 0xFFFFFFFF)
            {
                return TRUE;
            }
            return m_dwLoopCount --;
        }

    private:
        UINT32      m_dwTimerID;		// ��ʱ�����
        UINT32      m_dwElapse;			// ��ʱ���������
        ISDTimer*   m_poTimerHandler;   // �û����õĶ�ʱ����ʱ������
        UINT32      m_adwSlotIndexes[TIMERARRAY_COUNT]; // Timer���´γ�ʱʱ��
        UINT32		m_dwLastExpTime; //�ϴγ�ʱʱ��
        UINT32      m_dwLoopCount;
    };


    /**
    *@brief ��Ӧ��ĳһʱ�̳�ʱ�����ж�ʱ������
    */
    typedef std::list<CTimerItem*> TimerSlot;

    /**
    *@brief ��ʱ���㼶������
    */
    class CTimerSlotLevel
    {
    public:
        CTimerSlotLevel();

        BOOL NextSlot(BOOL bRewindOnEnd);

        void ReloadFromLevel( CTimerSlotLevel& oSlotLevel );

        void Init(UINT8 level)
        {
            m_timerLevel = level;
        }

        inline UINT32 GetCurSlotIndex()
        {
            return m_dwCurSlot;
        }

        TimerSlot& GetCurSlot()
        {
            return m_aoTimerSlots[m_dwCurSlot];
        }

        inline void AddTimer( CTimerItem* poTimer )
        {
            poTimer->m_timerLevel = m_timerLevel;
            m_aoTimerSlots[poTimer->GetSlotIndexForNextTrigger(m_timerLevel)]
            .push_back(poTimer);
        }

        inline void DelTimer( CTimerItem* poTimer )
        {
            if(poTimer->m_timerLevel != m_timerLevel)
                return;
            m_aoTimerSlots[poTimer->GetSlotIndexForNextTrigger(m_timerLevel)]
            .remove(poTimer);
        }

		std::string DumpTimerInfo()
        {
			std::stringstream info; 
            for (UINT32 slot=0; slot<TIMER_ARRAY_LEN; slot++)
            {
                if (!m_aoTimerSlots[slot].empty())
                {
                    // ��ʾʱ�����ڵ�λ��
					info << "Timer in ArrayLevel " << m_timerLevel << ", Slot " << slot << std::endl; 
                }
            }
			return info.str(); 
        }

    private:
        UINT8   m_timerLevel;
        UINT32  m_dwCurSlot;
        TimerSlot   m_aoTimerSlots[TIMER_ARRAY_LEN];

    };

}

#endif


