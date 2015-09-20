///<------------------------------------------------------------------------------
//< @file:   server\net\net.h
//< @author: ������
//< @date:   2014��11��26�� 10:42:10
//< @brief:
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _net_h_
#define _net_h_

#include "basic/timerqueue.h"
#include "basic/lock.h"
#include "basic/taskqueue.h"
#include "basic/objectpool.h"
#include "basic/buffer.h"
#include "basic/ringbuffer.h"

class Listener;
class Link;

// �ļ��������ӿ�(file descriptor)���׽��ֺͼ��������Ӵ�������
class IFd
{
public:
	// ����socketֵ
	virtual socket_t socket() const = 0;

	// ����ɶ��ź�
	virtual void handleRead()  = 0;

	// �����д�ź�
	virtual void handleWrite() = 0;

	// �����쳣�ź�
	virtual void handleError() = 0;

	// �ر�
	virtual void close() = 0;

	// ɾ����fd
	virtual void erase() = 0;

#ifndef WIN
public:
	uint32 m_events;
#endif
};

typedef ObjectPool<Link> LinkPool;
typedef ObjectPool<Buffer> BufferPool;

#define MAX_PACKET_LEN (1 * 1024 * 1024) // 2MB

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

	// ���ڻ���epoll��socketpair��ʵ�����ǰ�˫��ͨ�ţ�����������ֻ��������ͨ�ţ���������Ϊpipe
	int m_pipe[2];

	// �����ٵ�socket�б�
	FdList m_deletingFdList;

	// ɾ��socket�б�
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
	char g_recvBuf[MAX_PACKET_LEN];
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
	char g_recvBuf[MAX_PACKET_LEN];
	char g_sendBuf[MAX_PACKET_LEN];
};

#endif

#endif //_net_h_