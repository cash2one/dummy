#ifndef SDTIMER_IMPL_H
#define SDTIMER_IMPL_H
#include "sdhashmap.h"
#include "sdobjectpool.h"
#include "sdtimer_detail.h"

namespace SGDP
{
    /**
    *@brief ��ʱ��ģ���࣬��������LINUX�ķֲ�Ķ�ʱ����������ͨ�����̵߳���ѭ������Run������������ʱ��
    */

    class CSDTimerImpl
    {
        typedef HashMap<UINT32, CTimerItem*> CTimerMap;

    public:
        CSDTimerImpl();
        ~CSDTimerImpl();

        /**
        * @brief
        * ����һ��ʱ�Ӳ�����time-outֵ
        * @param poTimerHandler : �û�����ʱ�ӻص��ӿ���
        * @param dwTimerId : ����ʱ��ID
        * @param dwElapse : ����time-outֵ���Ժ���Ϊ��λ
        * @param dwLoop : ÿ������Ķ�ʱ������ִ��һ�Σ�dwLoop��ʾ��ʱ����ʱ�������ʱ�Ĵ��������Ϊ0xFFFFFFFF����ʾ����ѭ����ʱ��
        * @return ����һ��boolֵ,true��ʾ�ɹ�,false��ʾʧ��
        */
        BOOL  SetTimer(ISDTimer* poTimerHandler, UINT32 dwTimerId, UINT32 dwElapse, UINT32 dwLoop= SDINFINITE);

        /**
        * @brief
        * ȡ��ʱ��
        * @param dwTimerId : UINT32 ʱ��ID����ʾҪȡ����ʱ��
        * @return ����һ��boolֵ,true��ʾ�ɹ�,false��ʾʧ��
        */
        BOOL  KillTimer(UINT32 dwTimerId);

        /**
        * @brief
        * ʱ����Ϣ����
        * @param nCount : ��ʾ������֤�¼����������ޣ�-1��ʾ�������е��¼�
        * @return ��������¼�û�����귵��true����������¼����������ˣ�����false
        */
        BOOL  Run();

        /**
        * @brief
        * ��ӡʱ����Ϣ
        * @return void
        */
		std::string  DumpTimerInfo();

    private:

        friend class CTimerItem;
        /**
        * @brief
        * �õ�ĳ��ʱ���ֽṹ
        * @param nLevel : ʱ���ֵļ���
        * @return void
        */
        inline CTimerSlotLevel& GetSlotLevel( UINT32 nLevel )
        {
            return m_aoSlotLevels[nLevel];
        }

        /**
        * @brief
        * ����һ��ѭ��������ʱ�����
        * @param dwLevel : ����Ŀ���
        * @return �ɹ�����true��ʧ�ܷ���false
        */
        BOOL ReloadSlotLevel(UINT8 dwLevel = 0);

        /**
        * @brief
        * ����ʱ����ʱ
        */
        UINT32 TrigerTimersForCurSlot();

        /**
        * @brief
        * ���ݵ�ǰʱ��ͳ�ʱʱ�䣬����ʱ�����õ����ʵ�λ��
        * @param poTimer : ָ��timer�ṹ��ָ��
        * @return �ɹ�����true��ʧ�ܷ���false
        */
        BOOL AddTimerForNextTrigger(CTimerItem *pTimer);

        UINT32 GetMsFromLast();
        UINT32 GetMsFromLast(UINT32 dwLastTime);

        CTimerItem* LookupTimer( UINT32 dwTimerId );

        CSDObjectPool<CTimerItem, CSDMutex > m_oTimerPool;	/**<��ʱ���Ļ����*/
        CTimerSlotLevel m_aoSlotLevels[TIMERARRAY_COUNT]; /**<���TimerSlot������*/
        CTimerMap   m_oTimerMap;						/**<��Ŷ�ʱ��ID�Ͷ�ʱ�������ָ���hashmap*/
        UINT32      m_dwLastTickCount;					/**<��һ�ε���Runʱ��tick*/
        UINT32      m_dwMsPerTick;						/**<ϵͳ����ÿ���CPU TICK��*/
    };
}

#endif // 




