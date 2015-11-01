///<------------------------------------------------------------------------------
//< @file:   server\net\netmodel.h
//< @author: ������
//< @date:   2014��11��26�� 10:42:10
//< @brief:	 �ṩ��ƽ̨����ģ�͵ķ�װ��linux�½�֧��epoll��windows�½�֧��select
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _netmodel_h_
#define _netmodel_h_

#include "basic/timerqueue.h"
#include "basic/lock.h"
#include "basic/taskqueue.h"
#include "basic/objectpool.h"
#include "basic/buffer.h"

#include "netdefine.h"

class Listener;
class Link;

typedef ObjectPool<Link, mutex_t> LinkPool;

#ifndef WIN

// linux��epoll
class Epoll
{
private:
	typedef std::vector<IFd*> FdList;

public:
	Epoll();
	~Epoll();

	bool init(int initLinkCount, int linkGrowCount);

	int eventLoop();
	void close();

	void reopen(IFd*);

	void addFd(IFd*);
	void delFd(IFd*);

	void enableRead(IFd*);
	void disableRead(IFd*);

	void enableWrite(IFd*);
	void disableWrite(IFd*);

	void enableAll(IFd*);
	void disableAll(IFd*);

	inline TaskQueue* getTaskQueue() { return &m_tasks;}
	inline TimerQueue& getTimerQueue() { return m_timers; }
	inline LinkPool& getLinkPool() { return m_linkPool; }
	int interruptLoop();

protected:
	void recycleFds();
	void mod(IFd*, uint32 events);
	void stop();
	void closing();

	// <�����Ƿ���������>��־λ
	bool m_running;

	// epoll���
	int m_efd;

	// ���ڻ���epoll��socketpair��ʵ�����ǰ�˫��ͨ�ţ�����������ֻ��������ͨ��
	int m_wakeup[2];

	// �����ٵ�socket�б�
	FdList m_deletingFdList;

	// ɾ��socket�б����
	mutex_t m_mutex;

	// �������
	TaskQueue m_tasks;

	// ��ʱ���б�
	TimerQueue m_timers;

	// ���ӳأ�����Ԥ�ȷ���õ�����
	LinkPool m_linkPool;

public:
	// Ԥ������ļ��ܻ�����: ���ڷ��ͺͽ�������ʱ���мӽ�������
	char g_encryptBuf[MAX_PACKET_LEN];

	// Ԥ������Ľ��ջ�����
	char g_recvBuf[MAX_PACKET_LEN];

	// Ԥ������ķ��ͻ�����
	char g_sendBuf[MAX_PACKET_LEN];
};

#else

// windows��select
class Select
{
private:
	// ����Ե����ļ��������Ĳ������
	enum FDOperator {
		FD_ADD,			  // ���fd
		FD_DEL,			  // ɾ��fd
		FD_ENABLE_READ,   // �ɶ�
		FD_DISABLE_READ,  // ���ɶ�
		FD_ENABLE_WRITE,  // ��д
		FD_DISABLE_WRITE, // ����д
		FD_ENABLE_ALL,	  // ���������¼�
		FD_DISABLE_ALL	  // ȡ�����������¼�
	};

	// fd�б�
	typedef std::vector<IFd*> LinkerList;


public:
	Select();

	bool init(int initLinkCount, int linkGrowCount);

	int eventLoop();
	void reopen(IFd*) {}
	void close();

	void addFd(IFd*);
	void delFd(IFd*);

	void enableRead(IFd*);
	void disableRead(IFd*);

	void enableWrite(IFd*);
	void disableWrite(IFd*);

	void enableAll(IFd*);
	void disableAll(IFd*);

	inline TaskQueue* getTaskQueue() { return &m_tasks;}
	inline TimerQueue& getTimerQueue() { return m_timers; }
	inline LinkPool& getLinkPool() { return m_linkPool; }
	int interruptLoop() { return 0; }

private:
	void updateFd(IFd*, FDOperator);
	void closing();

private:
	// ��ǰά�ֵ�����
	LinkerList m_links;

	// ���ӳأ�����Ԥ�ȷ���õ�����
	LinkPool m_linkPool;

	// �������
	TaskQueue m_tasks;

	// ��ʱ������
	TimerQueue m_timers;

	// ��ǰ���fd
	int m_maxfd;

	// ���ļ���������
	fd_set m_rset;

	// д�ļ���������
	fd_set m_wset;

	// exception�ļ���������
	fd_set m_eset;

	// <�����Ƿ���������>��־λ
	bool m_running;

public:
	// Ԥ������ļ��ܻ�����: ���ڷ��ͺͽ�������ʱ���мӽ�������
	char g_encryptBuf[MAX_PACKET_LEN];

	// Ԥ������Ľ��ջ�����
	char g_recvBuf[MAX_PACKET_LEN];

	// Ԥ������ķ��ͻ�����
	char g_sendBuf[MAX_PACKET_LEN];
};

#endif

#endif //_net_h_