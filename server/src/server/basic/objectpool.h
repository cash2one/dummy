///<------------------------------------------------------------------------------
//< @file:   server\basic\objectpool.h
//< @author: ������
//< @date:   2015��4��3�� 23:35:15
//< @brief:  �����
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _objectpool_h_
#define _objectpool_h_

#include <deque>
#include "lock.h"

// �����
template <typename T, typename MutexType = NonMutex /* Ĭ�ϲ����� */>
class ObjectPool
{
	typedef std::vector<T*> ObjectQueue;

	enum {
		POOL_EXPAND_SIZE = 100,
	};

public:
	ObjectPool(uint32 initSize = 0, uint32 growSize = 1) throw()
		: m_totalSize(0)
	{
		init(initSize, growSize);
	}

	~ObjectPool() throw()
	{
		lock_guard_t<MutexType> lock(m_mutex);

		for(typename ObjectQueue::iterator itr = m_objects.begin(); itr != m_objects.end(); ++itr) {
			::operator delete (*itr);
		}

		m_objects.clear();
	}

	void init(uint32 initSize, uint32 growSize)
	{
		m_initSize = initSize;
		m_growSize = growSize;

		lock_guard_t<MutexType> lock(m_mutex);
		grow(m_initSize);
	}

	// ����һ������, ��������캯��û�в�����ʹ�ô˽ӿ�
	inline T* alloc()
	{
		return new (allocate())T;
	}

	// ����һ������, ����Ĺ��캯������һ���������
	template<typename P1>
	T* alloc(P1 p1)
	{
		return new (allocate())T(p1);
	}

	// ����һ������, ����Ĺ��캯������2���������
	template<typename P1, typename P2>
	T* alloc(P1 p1, P2 p2)
	{
		return new (allocate())T(p1, p2);
	}

	// ����һ������, ����Ĺ��캯������3���������
	template<typename P1, typename P2, typename P3>
	T* alloc(P1 p1, P2 p2, P3 p3)
	{
		return new (allocate())T(p1, p2, p3);
	}

	// ����һ������, ����Ĺ��캯������4���������
	template<typename P1, typename P2, typename P3, typename P4>
	T* alloc(P1 p1, P2 p2, P3 p3, P4 p4)
	{
		return new (allocate())T(p1, p2, p3, p4);
	}

	// ����һ������, ����Ĺ��캯������5���������
	template<typename P1, typename P2, typename P3, typename P4, typename P5>
	T* alloc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
	{
		return new (allocate())T(p1, p2, p3, p4, p5);
	}

	// ����һ������, ����Ĺ��캯������6���������
	template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	T* alloc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
	{
		return new (allocate())T(p1, p2, p3, p4, p5, p6);
	}

	// �黹һ������
	void free(T * obj)
	{
		obj->~T();
		deallocate(obj);
	}

	void clear()
	{
		lock_guard_t<MutexType> lock(m_mutex);

		m_totalSize -= m_objects.size();

		for(typename ObjectQueue::iterator itr = m_objects.begin(); itr != m_objects.end(); ++itr) {
			T *obj = *itr;
			::operator delete (obj);
		}

		m_objects.clear();
	}

	int size()
	{
		return m_objects.size();
	}

private:
	T* allocate()
	{
		lock_guard_t<MutexType> lock(m_mutex);
		if (m_objects.empty()) {
			this->grow(m_growSize);
			m_growSize <<= 1;
		}

		T * first = m_objects.back();
		m_objects.pop_back();
		return first;
	}

	// ����һ������
	void deallocate(T* obj)
	{
		lock_guard_t<MutexType> lock(m_mutex);

		// 		for (size_t i = 0; i < m_objects.size(); i++) {
		// 			if (m_objects[i] == obj) {
		// 				return;
		// 			}
		// 		}
		//
		// 		for(typename ObjectQueue::iterator itr = m_objects.begin(); itr != m_objects.end(); ++itr) {
		// 			if (*itr == obj) {
		// 				return;
		// 			}
		// 		}


		//�������ڴ���еĶ������ݣ�������һ�����и���ʱ�ͷţ���ֹ�ڴ���ֱ���
		if (m_objects.size() > (uint32)(m_initSize + m_growSize)) {
			// 			T * first = m_objects.front();
			::operator delete (obj);
			//
			// 			m_objects[0] = obj;
			// 			m_totalSize--;
		} else {
			m_objects.push_back(obj);
		}
	}

	// һ�������ų�count������
	void grow(int count)
	{
		//ע�⣺�ⲿӦ����
		for (int i = 0; i < count ; i++) {
			T *obj = static_cast<T*>(::operator new (sizeof(T)));
			m_objects.push_back(obj);
		}

		m_totalSize += count;
	}

public:
	// ��ǰ�ܶ����� = �������ȥ�Ķ����� + ���ж�����
	int	m_totalSize;

	int	m_growSize;
	int	m_initSize;

private:
	ObjectQueue m_objects;
	MutexType m_mutex;
};

#endif //_objectpool_h_