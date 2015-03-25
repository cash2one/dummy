#ifndef ScheduleApi_h__
#define ScheduleApi_h__

#include <base/Timestamp.h>

class DelayTask;

namespace scheduleapi
{
    // ��ʱһ��ʱ��ִ��task����
    void DizzyTask(DelayTask *pTask, TimeInMs delay);

    // ÿ��interval����ִ��һ�Σ�ֱ��ִ����ָ���������ս�
    void runEvery_very_ery_ry_y(DelayTask *pTask, TimeInMs interval, int triggerTimes/*��������*/);

    // ÿ��interval����ִ��һ�Σ������ս�
    void runEvery(DelayTask *pTask, TimeInMs interval);

    // ָ����xx��xxСʱxx��ʱ�����ִ��
    void runAt(DelayTask *pTask, Timestamp clock);
}

#endif // ScheduleApi_h__
