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
typedef int socket_t;
class IFd
{
public:
	// ����socketֵ
	virtual socket_t socket() const = 0;

	// ����ɶ��ź�
	virtual int handleRead()  = 0;

	// �����д�ź�
	virtual int handleWrite() = 0;

	// �����쳣�ź�
	virtual int handleError()   = 0;

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

//! �����¼��ַ���
class INet
{
public:
	virtual ~INet() {}

	virtual bool init(int initLinkCount, int linkGrowCount) = 0;

	// �����¼�����ѭ��
	virtual int eventLoop() 		    = 0;
	virtual void close() 				= 0;
	virtual int interruptLoop()			= 0;

	virtual void addFd(IFd*)			= 0;
	virtual void delFd(IFd*)			= 0;

	virtual void enableRead(IFd*)		= 0;
	virtual void disableRead(IFd*)		= 0;

	virtual void enableWrite(IFd*)		= 0;
	virtual void disableWrite(IFd*)		= 0;

	virtual void enableAll(IFd*)		= 0;
	virtual void disableAll(IFd*)		= 0;

	virtual void reopen(IFd*)			= 0;

	virtual TaskQueue* getTaskQueue()	= 0;
	virtual TimerQueue& getTimerQueue() = 0;
	virtual LinkPool& getLinkPool()		= 0;
};

#ifndef WIN

// linux��epoll
class Epoll : public INet
{
private:
	typedef std::vector<IFd*> FdList;

public:
	Epoll();
	~Epoll();

	virtual bool init(int initLinkCount, int linkGrowCount);

	virtual int eventLoop();
	virtual void close();

	virtual void reopen(IFd*);

	virtual void addFd(IFd*);
	virtual void delFd(IFd*);

	virtual void enableRead(IFd*);
	virtual void disableRead(IFd*);

	virtual void enableWrite(IFd*);
	virtual void disableWrite(IFd*);

	virtual void enableAll(IFd*);
	virtual void disableAll(IFd*);

	virtual TaskQueue* getTaskQueue() { return &m_tasks;}
	virtual TimerQueue& getTimerQueue() { return m_timers; }
	inline virtual LinkPool& getLinkPool() { return m_linkPool; }
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

	// ���ڻ���epoll��socketpair
	int m_interupt_sockets[2];

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
};

#else

// windows��select
class Select : public INet
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

	virtual bool init(int initLinkCount, int linkGrowCount);

	virtual int eventLoop();
	virtual void reopen(IFd*) {}
	virtual void close();

	virtual void addFd(IFd*);
	virtual void delFd(IFd*);

	virtual void enableRead(IFd*);
	virtual void disableRead(IFd*);

	virtual void enableWrite(IFd*);
	virtual void disableWrite(IFd*);

	virtual void enableAll(IFd*);
	virtual void disableAll(IFd*);

	virtual TaskQueue* getTaskQueue() { return &m_tasks;}
	virtual TimerQueue& getTimerQueue() { return m_timers; }
	inline virtual LinkPool& getLinkPool() { return m_linkPool; }
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

	// ��ʱ��
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
};

#endif

#endif //_net_h_