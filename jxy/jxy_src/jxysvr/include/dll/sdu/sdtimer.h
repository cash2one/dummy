/******************************************************************************
			

	sdtimer.h - ��ʱ�����
******************************************************************************/


#ifndef _SGDP_TIMER_H_
#define _SGDP_TIMER_H_
/**
* @file sdtimer.h

* @brief ��ʱ��ϵ��
*
**/
#include "sdtype.h"
#include <string>
using namespace std;
namespace SGDP
{
    /**
    * @defgroup grouptimer ��ʱ�����
    * @ingroup  SGDP
    * @{
    */
    class CSDTimerImpl;

    /**
    * @brief The ISDTimer class is an application-defined timer completion
    *       routine. Specify this address when calling the SetTimer function.
    *       then it will be called when the timer was timeout.
    *       Especially this OnTimer function can't be blocked.
    */
    class ISDTimer
    {
    public:

        /**
        * @brief
        * ��ʱ����������ʱʱ�����ô˶�ʱ����
        * @param dwTimerID : ��ʱʱ�Ķ�ʱ��IDTimer
        * @return VOID
        */
        virtual VOID  OnTimer(UINT32 dwTimerID) = 0;
    };

    /**
    * @brief ��ʱ��ģ���࣬��������LINUX�ķֲ�Ķ�ʱ����������ͨ�����̵߳���ѭ������Run������������ʱ��
    */
    class CSDTimer
    {

    public:

		/**
		* @brief ���캯������ʼ��CSDTimeImpl����
		*/
        CSDTimer();

		/**
		* @brief �����������ͷ�CSDTimeImpl����
		*/
        ~CSDTimer();

        /**
        * @brief
        * ����һ��ʱ�Ӳ�����time-outֵ
        * @param pTimer : �û�����ʱ�ӻص��ӿ���
        * @param dwTimerID : ����ʱ��ID
        * @param dwElapse : ����time-outֵ���Ժ���Ϊ��λ
        * @param dwLoop : ÿ������Ķ�ʱ������ִ��һ�Σ�dwLoop��ʾ��ʱ����ʱ�������ʱ�Ĵ��������Ϊ0xFFFFFFFF����ʾ����ѭ����ʱ��
        * @return ����һ��boolֵ,true��ʾ�ɹ�,false��ʾʧ��
        */
        BOOL  SetTimer(ISDTimer *pTimer, UINT32 dwTimerID, UINT32 dwElapse, UINT32 dwLoop = 0xFFFFFFFF);

        /**
        * @brief
        * ȡ��ʱ��
        * @param dwTimerID : UINT32 ʱ��ID����ʾҪȡ����ʱ��
        * @return ����һ��boolֵ,true��ʾ�ɹ�,false��ʾʧ��
        */
        BOOL  KillTimer(UINT32 dwTimerID);

        /**
        * @brief
        * ʱ����Ϣ����
        * @return ��������¼�û�����귵��true����������¼����������ˣ�����false
        */
        BOOL  Run();

        /**
        * @brief
        * ��ӡ��ʱ����Ϣ
        * @return VOID
        */
		std::string  DumpTimerInfo();

    protected:

		/**
		* @brief �������캯��
		* @param CSDTimer���������
		*/
		CSDTimer(const CSDTimer & ){};

		/**
		* @brief ����=��������ʵ��CSDTimer�ĸ�ֵ
		* @param CSDTimer���������
		* @return CSDTimer���������
		*/
        CSDTimer& operator = (const CSDTimer & );
    private:
        CSDTimerImpl *  m_pTimerImpl;
    };

    /** @} */
}

#endif

