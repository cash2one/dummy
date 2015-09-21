///<------------------------------------------------------------------------------
//< @file:   server\basic\buffer.h
//< @author: ������
//< @date:   2015��2��26�� 18:32:56
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _buffer_h_
#define _buffer_h_

#include <string.h>

#ifdef WIN
	#pragma warning( disable : 4996 )
#endif

#include "tool/endiantool.h"

// ������

// ��Buffer��ģ����muduo��Buffer��
//
// +-------------------+------------------+------------------+
// | prependable bytes |  readable bytes  |  writable bytes  |
// |                   |     (CONTENT)    |                  |
// +-------------------+------------------+------------------+
// |                   |                  |                  |
// 0      <=      readerIndex   <=   writerIndex    <=     size
class Buffer
{
public:
	static const size_t g_cheapPrepend;
	static const size_t g_initSize;

	explicit Buffer(size_t initialSize = g_initSize)
		: m_buffer(g_cheapPrepend + initialSize),
		  m_readPos(g_cheapPrepend),
		  m_writePos(g_cheapPrepend)
	{
	}

	explicit Buffer(const char *data, int size)
		: m_buffer(data, data + size)
		, m_readPos(0)
		, m_writePos(size)
	{
	}

	// implicit copy-ctor, move-ctor, dtor and assignment are fine
	// NOTE: implicit move-ctor is added in g++ 4.6

	void swap(Buffer& buffer)
	{
		m_buffer.swap(buffer.m_buffer);
		std::swap(m_readPos, buffer.m_readPos);
		std::swap(m_writePos, buffer.m_writePos);
	}

	void copy(Buffer& rhs)
	{
		m_buffer = rhs.m_buffer;

		m_readPos = rhs.m_readPos;
		m_writePos = rhs.m_writePos;
	}

	inline size_t readableBytes() const { return m_writePos - m_readPos; }

	inline size_t writableBytes() const { return m_buffer.size() - m_writePos; }

	inline size_t prependableBytes() const { return m_readPos; }

	inline char* peek() { return begin() + m_readPos; }

	inline bool empty() const { return readableBytes() == 0; }

	// retrieve returns void, to prevent
	// string str(retrieve(readableBytes()), readableBytes());
	// the evaluation of two functions are unspecified
	void skip(size_t len)
	{
		if (len < readableBytes()) {
			m_readPos += len;
		} else {
			clear();
		}
	}

	inline void clear()
	{
		m_readPos = g_cheapPrepend;
		m_writePos = g_cheapPrepend;

// 		if (m_buffer.capacity() > 2 * g_initSize) {
// 			recycle();
// 		}
	}

	// ���»����ڴ�
	void recycle()
	{
		m_buffer.swap(std::vector<char>());
	}

	inline void append(const char* data, size_t len)
	{
		if (writableBytes() < len) {
			makeSpace(len);
		}

		memcpy(beginWrite(), data, len);
		hasWritten(len);
	}

	char* beginWrite() { return begin() + m_writePos; }

	inline void hasWritten(size_t len)
	{
		m_writePos += len;
	}

	inline void unread(size_t len)
	{
		m_readPos -= len;
	}

	inline void unwrite(size_t len)
	{
		m_writePos -= len;
	}

	void prepend(const void* /*restrict*/ data, size_t len)
	{
		m_readPos -= len;
		memcpy(peek(), data, len);
	}

	inline size_t capacity() const
	{
		return m_buffer.capacity();
	}

	inline char* begin() { return &m_buffer[0]; }

private:
	// ����ռ�ʹ�ÿ��пռ��㹻��������len�ֽ�
	void makeSpace(size_t len)
	{
		if (writableBytes() + prependableBytes() < len + g_cheapPrepend) {
			// ���·���ռ�
			m_buffer.resize(m_writePos + len);
		} else {
			// �������ƶ�����ͷ
			size_t readable = readableBytes();

			memcpy(begin() + g_cheapPrepend, begin() + m_readPos, readableBytes());
			m_readPos = g_cheapPrepend;
			m_writePos = m_readPos + readable;
			assert(readable == readableBytes());
		}
	}

private:
	std::vector<char> m_buffer;
	size_t m_readPos;
	size_t m_writePos;
};

#endif //_buffer_h_