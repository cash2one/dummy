///<------------------------------------------------------------------------------
//< @file:   server\basic\ringbuffer.h
//< @author: ������
//< @date:   2015��8��3�� 19:14:52
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _ringbuffer_h_
#define _ringbuffer_h_

class Link;

struct RingBufferBlock {
	RingBufferBlock()
	{
		bzero(this, sizeof(*this));
	}

	int getTotalLength()
	{
		int totalLength = 0;
		RingBufferBlock *block = this;
		while(block) {
			totalLength += block->size();
			block = block->m_next;
		}

		return totalLength;
	}

	char* begin()
	{
		return (char*)this + sizeof(*this) + m_skip;
	}

	int size() { return m_length - m_skip; }

	void take(Buffer &buff, int len)
	{
		RingBufferBlock *block = this;
		while(block) {
			int blockSize = block->size();

			if (len > blockSize) {
				buff.append(block->begin(), blockSize);
				len -= blockSize;
			}
			else {
				buff.append(block->begin(), len);
				break;
			}

			block = block->m_next;
		}
	}

	void take(int len, char *to)
	{
		int start = 0;
		RingBufferBlock *block = this;

		while(block) {
			int blockSize = block->size();

			if (len > blockSize) {
				memcpy(to + start, block->begin(), blockSize);

				len -= blockSize;
				start += blockSize;
			}
			else {
				memcpy(to + start, block->begin(), len);
				break;
			}

			block = block->m_next;
		}
	}

	// ��Ծָ���ľ��룬��������Ծ����ʱ��block
	RingBufferBlock* skip(int len)
	{
		RingBufferBlock *block = this;
		RingBufferBlock *next  = NULL;

		int blockSize = 0;

		while(block) {
			blockSize = block->size();
			next = block->m_next;

			if (len >= blockSize) {
				block->m_link = NULL;
				block->m_next = NULL;
				block->m_skip = block->m_length;

				len -= blockSize;
			}
			else {
				block->m_skip += len;
				break;
			}

			block = next;
		}

		return block;
	}

	void bind(Link *link);

	int m_length;
	RingBufferBlock *m_next;
	Link *m_link;

	// ��¼��block��������Ӧ������: skip֮ǰ���������ѱ����������skip��ʼ�����ݲ���δ���������
	int m_skip;
};

// RingBuffer�ķֲ�������
// | ���� ��һ��Block �������� ���� | ���� ��һ��Block �������� ���� | ���� ��һ��Block �������� ���� | ......
class RingBuffer
{
public:
	RingBuffer(int length)
		: m_size(length)
		, m_head(0)
	{
		m_data = new char[m_size];
		bzero(m_data, m_size);

		RingBufferBlock* head = getHead();
		head->m_length = m_size - sizeof(RingBufferBlock);
	}

	~RingBuffer()
	{
		delete[] m_data;
	}

public:
	RingBufferBlock* add(const char* data, int len, Link *link);

	void skip(int len);

	RingBufferBlock* getHead();

	// �������ܺ�Ϊsum��1����������������block�и�Ϊ2��block[size, sum - size]
	RingBufferBlock* splitBlock(int sum, int size);

	// ����������ָ����С�ĵ�һ������block��������������blockҲ�����ڣ�
	RingBufferBlock* searchFreeBlock(int size);

	// �����ָ����С�Ŀ���block
	RingBufferBlock* allocFreeBlock(int size);

	// �ͷ�block
	void freeBlock(RingBufferBlock*);

	// ��block���ӵ�head���е�β������: head -> next -> next ...... -> next = block
	void linkBlock(RingBufferBlock *head, RingBufferBlock *block);

	// ��ȡblock��ƫ��
	int getBlockOffset(RingBufferBlock *block);

	// ��ȡ���ڵ���һ��block��ʼλ��
	RingBufferBlock *getNextBlock(RingBufferBlock *block);

	void statistic();

public:
	int m_size;
	int m_head;

	char *m_data;
};

#endif //_ringbuffer_h_