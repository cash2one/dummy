

#ifndef _EVENTREACTOR_H_
#define _EVENTREACTOR_H_

#include <sdtype.h>
#include <sdhashmap.h>
#include <sdtime.h>
#include <sdobjectpool.h>
#include <list>
#include <map>

namespace SGDP {
    static const UINT32 MAX_ENABLE_TIME = 0xFFFFFFFF - 1000;	///< �����û����õĳ�ʱʱ�����ֵ
    static const UINT32 WHEELARRAY_COUNT = 5;					///< ʱ�����в���,ʱ��������ϸ��Ϊ0��
    static const UINT32 WHEEL_ARRAY_LEN = 1000;					///< ʱ������ÿ���м���

    /**
     * @brief ��Ӧ��������ʽ
     */
    enum EExecuteType
    {
	    EXECUTE_LAZY = 0,		///< ����ִ�У��ᶪʧ�����¼�����һ�μ���ʱ����ɵ�ǰ����ʱ�������
	    EXECUTE_LOOSE,			///< ���ϸ�ִ�У�Ĭ�ϣ����ᶪʧ�����¼�����ִ��ʱ�䲻��
	    EXECUTE_STRICT			///< �ϸ�ִ��
    };

    /**
     * @brief �¼�״̬
     */
    enum EEventStatus
    {
        EVENT_READY = 0,		///< ��δ���뷴Ӧ��
        EVENT_RUNNING,			///< ���ڷ�Ӧ��������
        EVENT_HALTING			///< ������ֹ
    };

    class CEvent;

    class CEventMeter;
    class CCommonEventMeter;

    template <typename element>
    class CEventPump;

    template <typename element>
    class CListPump;

    class CWheelItem;
    class CWheelLevel;

    template <typename element>
    class CWheelPump;

    template <typename element, typename meter = CCommonEventMeter, typename pump = CWheelPump<element> >
    class CEventReactor;

    /**
     * @brief ���ڷ�Ӧ��Ԫ�ػ���
     */
    class CEvent
    {
    public:
        CEvent();
        virtual ~CEvent();

        /**
         * @brief
         * �����Դ���
         */
        virtual UINT32 OnEvent() = 0;

        /**
         * @brief �����¼�
         * @return ���������0��Ĭ�ϣ�
         */
        virtual BOOL OnDestroy() = 0;

    public:
        enum EEventStatus m_eEventStatus;           ///< �¼�״̬
        UINT64 m_qwNextTick;                        ///< �´δ���ʱ��
        UINT32 m_dwInterval;                        ///< ����

        // �����ڷ�Ӧ���������ں���һ�δ���ʱ����ڲ���Ա
        template <typename element, typename meter, typename pump>
        friend class CEventReactor;
        // ����ж����Դ
        friend class CWheelItem;
        // ������ÿ������ں���һ�δ���ʱ����ڲ���Ա
        template <typename element>
        friend class CWheelPump;
        template <typename element>
        friend class CListPump;
    };

    /**
     * @brief ���ڷ�Ӧ��
     * @param element : ��������
     * @param pump ��Ӧ����ʹ�õı�����
     */
    template <typename element, typename meter, typename pump>
    class CEventReactor
    {
    public:
	    /**
	     * @brief ���캯��
	     * @param dwInitCount : ����س�ʼ����С
	     * @param eExecuteType : ��Ӧ��������ʽ
	     */
	    CEventReactor(UINT32 dwInitCount, EExecuteType eExecuteType = EXECUTE_LOOSE) :
		    m_oObjectPool(dwInitCount),
		    m_oPump(eExecuteType)
	    {
            m_oPump.SetMeter(&m_oMeter);
            m_oPump.m_poObjectPool = &m_oObjectPool;
	    }

	    /**
	     * @brief ��������
	     */
	    virtual ~CEventReactor()
	    {
		    m_oPump.Clear();
	    }

    public:
	    /**
	     * @brief ����һ��Ԫ��
	     * @return Ԫ��ָ��
	     */
	    element* CreateEvent()
	    {
		    return m_oObjectPool.Alloc();
	    }

	    /**
	     * @brief ����һ��Ԫ��
	     * @param p1 : �������
	     * @return Ԫ��ָ��
	     */
	    template<typename P1>
	    element* CreateEvent(P1 p1)
	    {
		    return m_oObjectPool.Alloc(p1);
	    }

	    /**
	     * @brief ����һ��Ԫ��
	     * @param p1 : �������
	     * @param p2 : �������
	     * @return Ԫ��ָ��
	     */
	    template<typename P1, typename P2>
	    element* CreateEvent(P1 p1, P2 p2)
	    {
		    return m_oObjectPool.Alloc(p1, p2);
	    }

	    /**
	     * @brief ����һ��Ԫ��
	     * @param p1 : �������
	     * @param p2 : �������
	     * @param p3 : �������
	     * @return Ԫ��ָ��
	     */
	    template<typename P1, typename P2, typename P3>
	    element* CreateEvent(P1 p1, P2 p2, P3 p3)
	    {
		    return m_oObjectPool.Alloc(p1, p2, p3);
	    }

	    /**
	     * @brief ����һ��Ԫ��
	     * @param p1 : �������
	     * @param p2 : �������
	     * @param p3 : �������
	     * @param p4 : �������
	     * @return Ԫ��ָ��
	     */
	    template<typename P1, typename P2, typename P3, typename P4>
	    element* CreateEvent(P1 p1, P2 p2, P3 p3, P4 p4)
	    {
		    return m_oObjectPool.Alloc(p1, p2, p3, p4);
	    }

	    /**
	     * @brief ����һ��Ԫ��
	     * @param p1 : �������
	     * @param p2 : �������
	     * @param p3 : �������
	     * @param p4 : �������
	     * @param p5 : �������
	     * @return Ԫ��ָ��
	     */
	    template<typename P1, typename P2, typename P3, typename P4, typename P5>
	    element* CreateEvent(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
	    {
		    return m_oObjectPool.Alloc(p1, p2, p3, p4, p5);
	    }

        /**
         * @brief ��ʼԪ�������Լ���
         * @param poEvent : ֮ǰ�������¼�����ָ��
         * @param bDoOnDestroy : �Ƿ񼤷����ٻص�
         * @return ִ�н����TRUE�ɹ���FALSEʧ��
         */
        BOOL DestroyEvent(element* poEvent, BOOL bDoOnDestroy = TRUE)
        {
            if(EVENT_HALTING == poEvent->m_eEventStatus)
            {
                return FALSE;
            }
            else if(EVENT_READY == poEvent->m_eEventStatus)
            {
                m_oObjectPool.Free(poEvent);
                return TRUE;
            }
            else
            {
                poEvent->m_eEventStatus = EVENT_HALTING;
                if(FALSE == bDoOnDestroy)
                {
                    return TRUE;
                }
                else
                {
                    return poEvent->OnDestroy();
                }
            }
        }

	    /**
	     * @brief ��ʼԪ�������Լ���
	     * @param Element : ����ӵ�Ԫ��
	     * @param dwInterval : �������ʱ��(ms)
	     * @param qwStartTime : ��ʼ����ʱ��
	     * @return ִ�н����TRUE�ɹ���FALSEʧ��
	     */
	    BOOL SetEvent(element* poElement, UINT32 dwInterval, UINT64 qwStartTime = SDTimeSecs())
	    {
			dwInterval = 0 == dwInterval ? 1 : dwInterval;
            if(NULL == poElement)
            {
                return FALSE;
            }
            CEvent* poEventElement = (CEvent*)poElement;
            if(EVENT_READY != poEventElement->m_eEventStatus)
            {
                // ��ֹ�ظ����
                return FALSE;
            }
		    poEventElement->m_qwNextTick = qwStartTime + dwInterval;
		    poEventElement->m_dwInterval = dwInterval;
		    poEventElement->m_eEventStatus = EVENT_RUNNING;
		    m_oPump.AddElement(poElement);
		    return TRUE;
	    }

	    /**
	     * @brief ����ִ������
	     * @param Element : ����ӵ�Ԫ��
	     * @param dwInterval : �������ʱ��(ms)
	     * @return ִ�н����TRUE�ɹ���FALSEʧ��
	     */
	    BOOL ResetInterval(element* poElement, UINT32 dwInterval)
	    {	
		    return m_oPump.ResetInterval(poElement, dwInterval);
	    }

	    /**
	     * @brief �����Դ���
	     * @param qwCurTick : ��ǰϵͳTick
	     */
	    VOID Run(UINT64 qwCurTick = SGDP::SDTimeSecs())
	    {
			//CAutoCycle oAutoCycle("CEventReactor::Run");

		    m_oMeter.BeginLoop();
		    UINT32 dwEventCount = m_oPump.Run(qwCurTick);
		    m_oMeter.EndLoop(dwEventCount);
	    }

	    /**
	     * @brief ���Ԫ��
	     */
	    VOID Clear()
	    {
		    m_oPump.Clear();
	    }

        /**
         * @brief �����Ƿ���ͳ����
         * @param bStatus : ͳ�����Ƿ���
         */
        VOID SetMeterStatus(BOOL bStatus)
        {
            m_oMeter.m_bStatus = bStatus;
        }

        /**
         * @brief ��ȡͳ����
         * @return ͳ��������
         */
        inline meter& GetMeter()
        {
            return m_oMeter;
        }

    protected:
	    pump        m_oPump;                        ///< Ԫ�ؼ�����
        meter       m_oMeter;                       ///< ͳ����
	    SGDP::CSDObjectPool<element> m_oObjectPool; ///< �����ʵ��
    };

    /**
     * @brief ����Ԫ��ͳ����Ϣ�ṹ��
     */
    typedef struct tagElementMeterInfo
    {
	    UINT32 dwEventCount;		///< ������ЧԪ�����ڴ���
	    UINT64 qwEventTick;		    ///< ������ЧԪ�������ܺ�ʱ
	    UINT64 qwEventMaxTick;		///< ��������ʱ
	    UINT64 qwHistoryMaxTick;	///< ��ʱ����ʱ
    }SElementMeterInfo;


    /**
     * @brief ���ڷ�Ӧ��ͳ��������
     */
    class CEventMeter
    {
    public:
	    CEventMeter();
	    virtual ~CEventMeter();

	    /**
	     * @brief ��ʼ��¼�õ�����ѭ��
	     * @param qwCurTick : ��ǰϵͳTick
	     */
	    virtual VOID BeginLoop(UINT64 qwCurTick = SGDP::SDTimeSecs()) = 0;

	    /**
	     * @brief ������¼�õ�����ѭ��
	     * @param dwEventCount : ��ִ��������ִ���˶�����ЧԪ������
	     * @param qwCurTick : ��ǰϵͳTick
	     */
	    virtual VOID EndLoop(UINT32 dwEventCount, UINT64 qwCurTick = SGDP::SDTimeSecs()) = 0;

	    /**
	     * @brief �Ե���Ԫ�����ڽ��г���
	     * @param dwElementType : Ԫ�����ͣ����û�����
	     * @param qwTickCount : ����Ԫ�����ڳ���ʱ��
	     */
	    virtual INT32 AddSamplePoint(UINT32 dwElementType, UINT64 qwTickCount) = 0;

	    /**
	     * @brief �������ͳ������
	     */
	    virtual VOID Reset() = 0;

	    /**
	     * @brief ���ȫ��ͳ������
	     */
	    virtual VOID Clear() = 0;

	    /**
	     * @brief ��ʼͳ��
	     */
	    virtual INT32 Start() = 0;

	    /**
	     * @brief ��ͣͳ��
	     */
	    virtual INT32 Stop() = 0;

    public:
        /**
         * @brief �Ƿ���ͳ��
         */
        BOOL m_bStatus;
    };

    const static UINT32 DEFAULT_METERINFO_SIZE = 100;
    /**
     * @brief Ĭ��ʱ������ͳ����
     */
    class CCommonEventMeter:public CEventMeter
    {
    public:
	    CCommonEventMeter();
	    virtual ~CCommonEventMeter();

	    /**
	     * @brief ��ʼ��¼�õ�����ѭ��
	     * @param qwCurTick : ��ǰϵͳTick
	     */
	    VOID BeginLoop(UINT64 qwCurTick = SGDP::SDTimeSecs());

	    /**
	     * @brief ������¼�õ�����ѭ��
	     * @param dwEventCount : ��ִ��������ִ���˶�����ЧԪ������
	     * @param qwCurTick : ��ǰϵͳTick
	     */
	    VOID EndLoop(UINT32 dwEventCount, UINT64 qwCurTick = SGDP::SDTimeSecs());

	    /**
	     * @brief �Ե���Ԫ�����ڽ��г���
	     * @param dwElementType : Ԫ�����ͣ����û�����
	     * @param qwTickCount : ����Ԫ�����ڳ���ʱ��
	     */
	    INT32 AddSamplePoint(UINT32 dwElementType, UINT64 qwTickCount);

	    /**
	     * @brief �������ͳ������
	     */
	    VOID Reset();

	    /**
	     * @brief ���ȫ��ͳ������
	     */
	    VOID Clear();

	    /**
	     * @brief ��ʼͳ��
	     */
	    INT32 Start();

	    /**
	     * @brief ��ͣͳ��
	     */
	    INT32 Stop();

    public:
        /**
        * @brief ���һ�α���������ʱ��
        */
        UINT64 m_qwLastTickCount;

        /**
        * @brief ���һ�α�����ִ���˶�����ЧԪ������
        */
        UINT32 m_dwLastEventCount;

        /**
        * @brief ��ʱ����������ʱ���ܺ�
        */
        UINT64 m_qwTotalTickCount;

        /**
        * @brief ��ʷ������ִ���˶�����ЧԪ�������ܺ�
        */
        UINT32 m_dwTotalEventCount;

        /**
        * @brief ��ʷ������ִ���˶���Ԫ�������ܺ�
        */
        UINT32 m_dwTotalLoopCount;

        /**
        * @brief ���һ��ʱ�����������ʱ���ܺ�
        */
        UINT64 m_qwRecentTickCount;

        /**
        * @brief ���һ��ʱ�������ִ���˶�����ЧԪ�������ܺ�
        */
        UINT32 m_dwRecentEventCount;

        /**
        * @brief ���һ��ʱ�������ִ���˶���Ԫ�������ܺ�
        */
        UINT32 m_dwRecentLoopCount;

        /**
        * @brief ����Ԫ��ͳ����Ϣ
        */
        SElementMeterInfo m_aoElementMeterInfo[DEFAULT_METERINFO_SIZE];

    private:
	    /**
	     * @brief ��ʼͳ�Ʊ�ѭ����ʱ��
	     */
	    UINT64 m_qwBeginTick;
    };

    /**
     * @brief ���ڼ����û���
     * @param element : �йܶ���
     */
    template <typename element>
    class CEventPump
    {
    public:
        CEventPump()
        {
            m_bMeterStatus = FALSE;
        }

        virtual ~CEventPump()
        {

        }

	    /**
	     * @brief ���Ԫ��
	     * @param poElement : ����ӵ�Ԫ��ָ��
	     * @return ִ�н����TRUE�ɹ���FALSEʧ��
	     */
	    virtual BOOL AddElement(element* poElement) = 0;

	    /**
	     * @brief ����ִ������
	     * @param Element : ����ӵ�Ԫ��
	     * @param dwInterval : �������ʱ��(ms)
	     * @return ִ�н����TRUE�ɹ���FALSEʧ��
	     */
	    virtual BOOL ResetInterval(element* poElement, UINT32 dwInterval) = 0;

	    /**
	     * @brief ���Ԫ��
	     */
	    virtual VOID Clear() = 0;

	    /**
	     * @brief �����Դ���
	     * @param qwCurTick : ��ǰϵͳTick
	     */
	    virtual UINT32 Run(UINT64 qwCurTick) = 0;

        /**
         * @brief ����ͳ����
         * @param poMeter : ͳ����ָ��
         */
        virtual VOID SetMeter(CEventMeter* poMeter)
        {
            m_poMeter = poMeter;
        }

    public:
	    /**
	     * @brief �Ƿ���ͳ����
	     */
	    BOOL m_bMeterStatus;

        /**
         * @brief �����ָ��
         */
        SGDP::CSDObjectPool<element> * m_poObjectPool; /**<�����ʵ��*/

	    /**
	     * @brief ͳ����
	     */
	    CEventMeter* m_poMeter;
    };

    /**
     * @brief �����
     * @param element ����Ϊ�йܶ���ָ��
     */
    template <typename element>
    class CListPump : public CEventPump<element>
    {
    public:
	    CListPump(EExecuteType eExecuteType = EXECUTE_LOOSE)
	    {
		    m_eExecuteType = eExecuteType;
			m_qwLastRunTime = SDTimeSecs();
	    }

	    /**
	     * @brief
	     * ���Ԫ��
	     * @param poElement : ����ӵ�Ԫ��ָ��
	     * @return ִ�н����TRUE�ɹ���FALSEʧ��
	     */
	    BOOL AddElement(element* poElement)
	    {
		    m_lsElements.push_back(poElement);
		    return TRUE;
	    }

	    /**
	     * @brief
	     * ����ִ������
	     * @param Element : ����ӵ�Ԫ��
	     * @param dwInterval : �������ʱ��(ms)
	     * @return ִ�н����TRUE�ɹ���FALSEʧ��
	     */
	    BOOL ResetInterval(element* poElement, UINT32 dwInterval)
	    {
		    poElement->m_dwInterval = dwInterval;
		    return TRUE;
	    }

        UINT64 GetMsFromLast(UINT64 qwLastTime)
        {
            return SDTimeSecs() - qwLastTime;;
        }

	    /**
	     * @brief
	     * ���Ԫ��
 	     */
	    VOID Clear()
	    {
		    m_lsElements.clear();
	    }

	    /**
	     * @brief �����Դ���
	     * @param qwCurTick : ��ǰϵͳTick
	     */
	    UINT32 Run(UINT64 qwCurTick)
		{
			//�����ת
			if(qwCurTick <= m_qwLastRunTime)
			{
				return 0;
			}
			UINT32 dwElementType; // Ԫ������
			UINT64 qwTick = 0;
			UINT32 dwRet = 0;
			for(typename std::list<element*>::iterator iter = m_lsElements.begin(); iter != m_lsElements.end();)
			{
				UINT64 qwElementTick = (*iter)->m_dwNextTick;
				UINT32 dwInterval = (*iter)->m_dwInterval;
				if(EVENT_HALTING == (*iter)->m_eEventStatus)
				{
					// ɾ����ȷ����Ч��Ԫ��
					this->m_poObjectPool->Free(*iter);
					m_lsElements.erase(iter++);
				}
				else if(qwElementTick <= qwCurTick) // ����ʱ
				{
					if(EXECUTE_LOOSE == m_eExecuteType)
					{
						// ���ϸ�ִ�У��ᶪʧ�����¼�����ִ��ʱ�䲻��
						if(FALSE == this->m_bMeterStatus)
						{
							dwElementType = (*iter)->OnEvent();
						}
						else
						{
							qwTick = SGDP::SDTimeSecs();
							dwElementType = (*iter)->OnEvent();
							qwCurTick = SDTimeSecs();

							UINT64 qwTickTime = GetMsFromLast(qwTick);
							this->m_poMeter->AddSamplePoint(dwElementType, qwTickTime);
						}
						dwRet++;
						while(qwElementTick <= qwCurTick)
						{
							qwElementTick += dwInterval;
						}
						(*iter)->m_dwNextTick = qwElementTick;
					}
					else if(EXECUTE_LAZY == m_eExecuteType)
					{
						// ���ϸ�ִ�У��ᶪʧ�����¼�����һ�μ���ʱ����ɵ�ǰ����ʱ�������
						if(FALSE == this->m_bMeterStatus)
						{
							dwElementType = (*iter)->OnEvent();
						}
						else
						{
							qwTick = SGDP::SDTimeSecs();
							dwElementType = (*iter)->OnEvent();

							qwCurTick = SDTimeSecs();
							UINT64 qwTickTime = GetMsFromLast(qwTick);
							this->m_poMeter->AddSamplePoint(dwElementType, qwTickTime);
						}
						dwRet++;
						// 
						(*iter)->m_dwNextTick = qwCurTick + dwInterval;
					}
					else if(EXECUTE_STRICT == m_eExecuteType)
					{
						// �ϸ�ִ��
						while(qwElementTick < qwCurTick)
						{
							if(EVENT_HALTING == (*iter)->m_eEventStatus)
							{
								break;
							}
							if(FALSE == this->m_bMeterStatus)
							{
								dwElementType = (*iter)->OnEvent();
							}
							else
							{
								qwTick = SGDP::SDTimeSecs();
								dwElementType = (*iter)->OnEvent();
								qwCurTick = SDTimeSecs();

								UINT64 qwTickTime = GetMsFromLast(qwTick);
								this->m_poMeter->AddSamplePoint(dwElementType, qwTickTime);
							}
							dwRet++;
							qwElementTick += dwInterval;
						}
						(*iter)->m_dwNextTick = qwElementTick;
					}
					iter++;
				}
				else
				{
					iter++;
				}
			}
			m_qwLastRunTime = SDTimeSecs();

			return dwRet;
		}

    private:
	    std::list<element*> m_lsElements;		///< Ԫ������
	    EExecuteType	m_eExecuteType;			///< ִ�з�ʽ
		UINT64			m_qwLastRunTime;		///< �ϴ�ִ��ʱ��
    };

    /**
     * @brief ��ʱ��Ԫ��
     */
    class CWheelItem
    {
    public:
	    /**
	     * @brief ��ʼ��������ʱ��
	     * @param poPumpCtrl ����Ķ�ʱ��������
	     * @param poElement ����Ķ�ʱ���������ӿ�
	     * @param dwInterval ��ʱ���ļ��
	     */
	    template <typename element>
	    VOID Init(CWheelPump<element>* poPumpCtrl, CEvent* poElement)
	    {
		    m_poElementHandler = poElement;
		    m_byWheelLevel = WHEELARRAY_COUNT;
		    m_qwLastExpTime = SGDP::SDTimeSecs();
		    for(UINT32 i = 0; i < WHEELARRAY_COUNT; i++)
		    {
			    m_aqwSlotIndexes[i] = poPumpCtrl->GetSlotLevel(i).GetCurSlotIndex();
		    }
	    }

	    /**
	     * @brief ������һ�δ���
	     * @param qwDelay : ��ǰʱ��
	     * @return ���ڲ㼶
	     */
	    UINT8 SetupForNextTrigger(UINT64 qwDelay, UINT32 dwInterval = 0);

	    /**
	     * @brief ��ȡ��һ�δ���ʱ��
	     * @return ��һ�δ���ʱ��
	     */
	    inline UINT64 GetLastExpdTime()
	    {
		    return 	m_qwLastExpTime;
	    }

	    /**
	     * @brief ������һ�δ���ʱ��
	     * @param dwExpTime : ��һ�δ���ʱ��
	     */
	    inline VOID SetLastExpdTime(UINT64 qwExpTime)
	    {
		    m_qwLastExpTime = qwExpTime;
	    }

	    /**
	     * @brief ��ȡ��һ������ʱ��
	     * @param byLevel : ��ʱ���㼶
	     * @return ��һ������ʱ��
	     */
	    UINT64 GetSlotIndexForNextTrigger(UINT8 byLevel);

	    /**
	     * @brief �����Դ���
	     */
	    INT32 OnEvent();

    public:
	    UINT8				m_byWheelLevel;						///< ʱ�ӵ�ǰ���ڵ�ʱ�����в㼶
	    CEvent*             m_poElementHandler;					///< �û����õĶ�ʱ����ʱ������
        UINT64				m_qwLastExpTime;					///< �ϴγ�ʱʱ��

    private:
	    UINT64				m_aqwSlotIndexes[WHEELARRAY_COUNT]; ///< ��ʱ��Ԫ�ص��´γ�ʱʱ��
    };

    /**
     * @brief ��ʱ��Ԫ������
     */
    typedef std::list<CWheelItem*> CWheelItemList;

    /**
     * @brief ��ʱ���㼶������
     */
    class CWheelLevel
    {
    public:
	    /**
	     * @brief ���캯��
	     */
	    CWheelLevel();

	    /**
	     * @brief ʱ������ƶ�
	     * @param bRewindOnEnd : �Ƿ����յ�ѭ������ʼλ��
	     * @return ��������յ㷵��FALSE�����򷵻�TRUE
	     */
	    BOOL NextSlot(BOOL bRewindOnEnd);

	    /**
	     * @brief �����²㼶ʱ��۶���
	     * @param oSlotLevel : �����ص�ʱ��۲㼶����
	     * @return ��������յ㷵��FALSE�����򷵻�TRUE
	     */
	    VOID ReloadFromLevel(CWheelLevel &oSlotLevel);

	    /**
	     * @brief ��ʼ���㼶
	     * @param level : Ŀ��㼶
	     */
	    inline VOID Init(UINT8 level)
	    {
		    m_byWheelLevel = level;
	    }

	    /**
	     * @brief ��ȡ��ǰ�㼶����
	     * @return ��ǰ�㼶����
	     */
	    inline UINT32 GetCurSlotIndex()
	    {
		    return m_dwCurSlot;
	    }

	    /**
	     * @brief ��ȡ��ǰ�㼶����
	     * @return ��ǰ�㼶����
	     */
	    inline std::list<CWheelItem*> &GetCurSlot()
	    {
		    return m_aoWheels[m_dwCurSlot];
	    }

	    /**
	     * @brief ��Ӷ�ʱ��Ԫ��
	     * @param poWheelItem ��ʱ��Ԫ��ָ��
	     */
	    inline VOID AddItem(CWheelItem* poWheelItem)
	    {
		    poWheelItem->m_byWheelLevel = m_byWheelLevel;
		    m_aoWheels[poWheelItem->GetSlotIndexForNextTrigger(m_byWheelLevel)].push_back(poWheelItem);
	    }

	    /**
	     * @brief ɾ����ʱ��Ԫ��
	     * @param poWheelItem ��ʱ��Ԫ��ָ��
	     */
	    inline VOID DelItem(CWheelItem* poWheelItem)
	    {
		    if(poWheelItem->m_byWheelLevel != m_byWheelLevel)
		    {
			    return;
		    }
		    m_aoWheels[poWheelItem->GetSlotIndexForNextTrigger(m_byWheelLevel)].remove(poWheelItem);
	    }

        inline CWheelItemList* GetWheelItemLists()
        {
            return m_aoWheels;
        }

    private:
	    UINT8					m_byWheelLevel;						///< ��ǰʱ�����в㼶��
	    UINT32					m_dwCurSlot;						///< ��ǰ����
	    CWheelItemList	        m_aoWheels[WHEEL_ARRAY_LEN];	///< ʱ�������
    };

    /**
     * @brief ʱ��۱�
     * @param element �йܶ���
     */
    template <typename element>
    class CWheelPump : public CEventPump<element>
    {
    public:
	    /**
	     * @brief ���캯��
	     * @param eExecuteType : ִ�з�ʽ
	     */
	    CWheelPump(EExecuteType eExecuteType = EXECUTE_LOOSE) : m_oWheelItemPool()
	    {
		    for(UINT32 i = 0; i < WHEELARRAY_COUNT; i++)
		    {
			    m_aoSlotLevels[i].Init(i);
		    }

		    m_qwLastTickCount = SGDP::SDTimeSecs();
            m_eExecuteType = eExecuteType;
			m_qwLastRunTime = SDTimeSecs();
	    }

	    /**
	     * @brief ��������
	     */
	    ~CWheelPump()
	    {
	    }

	    /**
	     * @brief ���Ԫ��
	     * @param poElement : ����ӵ�Ԫ��ָ��
	     * @return ִ�н����TRUE�ɹ���FALSEʧ��
	     */
	    BOOL AddElement(element* poElement)
	    {
            CEvent* poEventElement = (CEvent*)poElement;
		    if(NULL == poElement || (poEventElement->m_dwInterval > MAX_ENABLE_TIME) || (0 == poEventElement->m_dwInterval))
		    {
			    return FALSE;
		    }
		    CWheelItem* poWheelItem = m_oWheelItemPool.Alloc();
		    if(NULL == poWheelItem)
		    {
			    return FALSE;
		    }
		    poWheelItem->Init(this, poEventElement);
            
            UINT64 qwTickCount = poEventElement->m_qwNextTick - SDTimeSecs();

		    return AddItemForNextTrigger(poWheelItem, (UINT32)qwTickCount);
	    }

	    /**
	     * @brief ����ִ������
	     * @param poElement : ����ӵ�Ԫ��ָ��
	     * @param dwInterval : �������ʱ�䣨���룩
	     * @return ִ�н����TRUE�ɹ���FALSEʧ��
	     */
	    BOOL ResetInterval(element* poElement, UINT32 dwInterval)
	    {
            CEvent* poEventElement = (CEvent*)poElement;
            poEventElement->m_dwInterval = dwInterval;
            return TRUE;
	    }

	    /**
	     * @brief ���Ԫ��
	     */
	    VOID Clear()
	    {
            for(UINT64 qwMsFromLast = GetMsFromLast(); qwMsFromLast > 0; qwMsFromLast--)
            {
                for(UINT16 i = 0; i < WHEELARRAY_COUNT; i++)
                {
                    do
                    {
                        CWheelItemList &oCurSlot = m_aoSlotLevels[i].GetCurSlot();
                        while(FALSE == oCurSlot.empty())
                        {
                            CWheelItem* poWheelItem = oCurSlot.front();
                            m_aoSlotLevels[poWheelItem->m_byWheelLevel].DelItem(poWheelItem);
                            this->m_poObjectPool->Free(dynamic_cast<element*>(poWheelItem->m_poElementHandler));
                            m_oWheelItemPool.Free(poWheelItem);

                            // �ж��Ƿ���OnEvent����ɾ���˸�Ԫ��
                            if (oCurSlot.empty() || (oCurSlot.front() != poWheelItem))
                            {
                                continue;
                            }

                            oCurSlot.pop_front();
                        }
                    }while(m_aoSlotLevels->NextSlot(FALSE));
                }
            }

            /*
		    for(UINT32 i = 0; i < WHEELARRAY_COUNT; i++)
		    {
			    m_aoSlotLevels[i].Init(i);
		    }
		    */
	    }

	    /**
	     * @brief �����Դ���
	     * @param qwCurTick : ��ǰϵͳTick
	     */
	    UINT32 Run(UINT64 qwCurTick)
	    {
			//�����ת
			if(qwCurTick <= m_qwLastRunTime)
			{
				return 0;
			}
		    UINT32 dwEventCount = 0;
		    for(UINT64 qwMsFromLast = GetMsFromLast(); qwMsFromLast > 0; qwMsFromLast--)
		    {
			    dwEventCount += TrigerItemsForCurSlot();
		    }

			m_qwLastRunTime = SDTimeSecs();
		    return dwEventCount;
	    }

    private:
	    /**
	     * @brief �õ�ĳ��ʱ���ֽṹ
	     * @param nLevel : ʱ���ֵļ���
	     * @return ʱ�Ӳ㼶
	     */
	    inline CWheelLevel& GetSlotLevel(UINT32 nLevel)
	    {
		    return m_aoSlotLevels[nLevel];
	    }

	    /**
	     * @brief ����һ��ѭ��������ʱ�����
	     * @param dwLevel : ����Ŀ���
	     * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
	     */
	    BOOL ReloadSlotLevel(UINT8 dwLevel = 0)
	    {
		    if(dwLevel >= WHEELARRAY_COUNT-1)
		    {
			    return FALSE;
		    }
		    CWheelLevel& oNextLevel = m_aoSlotLevels[dwLevel + 1];

		    if(oNextLevel.NextSlot(TRUE) == FALSE)
		    {
			    ReloadSlotLevel(dwLevel + 1);
		    }
		    m_aoSlotLevels[dwLevel].ReloadFromLevel(oNextLevel);
		    return TRUE;
	    }

	    /**
	     * @brief ����ʱ����ʱ
	     */
	    UINT32 TrigerItemsForCurSlot();

	    /**
	     * @brief ���ݵ�ǰʱ��ͳ�ʱʱ�䣬����ʱ�����õ����ʵ�λ��
	     * @param poWheelItem : ָ��timer�ṹ��ָ��
	     * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
	     */
	    BOOL AddItemForNextTrigger(CWheelItem *poWheelItem, UINT32 dwInterval = 0)
	    {
		    UINT64 qwMsFromLast = GetMsFromLast(m_qwLastTickCount);
		    UINT32 dwLevel = poWheelItem->SetupForNextTrigger(qwMsFromLast, dwInterval);
		    m_aoSlotLevels[dwLevel].AddItem(poWheelItem);
		    return TRUE;
	    }

	    UINT64 GetMsFromLast()
	    {
		    UINT64 qwCurTick = SGDP::SDTimeSecs();
			qwCurTick -= m_qwLastTickCount;
			m_qwLastTickCount = SGDP::SDTimeSecs();

			return qwCurTick;
	    }

	    UINT64 GetMsFromLast(UINT64 qwLastTime)
	    {
			return SDTimeSecs() - qwLastTime;
	    }

    private:
	    EExecuteType			m_eExecuteType;							///< ִ�з�ʽ
	    SGDP::CSDObjectPool<CWheelItem, SGDP::CSDMutex> m_oWheelItemPool;	///< ��ʱ���Ļ����
	    CWheelLevel             m_aoSlotLevels[WHEELARRAY_COUNT];		///< ���ʱ��۵�����
	    UINT64					m_qwLastTickCount;						///< ��һ�ε���ʱ��	  
		UINT64					m_qwLastRunTime;		///< �ϴ�ִ��ʱ��

    // ��ʱ��Ԫ�ؿ��ų�Ա
    friend class CWheelItem;
    };

}

#include "eventreactor.inl"

#endif // #ifndef _EVENTREACTOR_H_

