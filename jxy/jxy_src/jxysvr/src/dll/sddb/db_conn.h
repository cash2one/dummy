
#ifndef DB_CONN_H_20100728
#define DB_CONN_H_20100728

#include "sddb.h"

/**
  @desc Connection�Ľӿ��ࡣ
  ֮���������IConn��ISDDBConnection�����࣬
  ����Ϊ��IConn�ṩ��һЩ���˱�¶���û��ĺ�����
  ���⣬�ڲ����е���ͺ�����ʹ�õĶ���IConn������ISDDBConnection��
**/
class IConn : public SGDP::ISDDBConnection
{
public:
	/**
	  @desc IConn����������
	**/
	virtual SDAPI ~IConn(){};

	/**
	  @desc �������Ƿ�ʹ��
	  @return true����ʹ�ã�false����δ��ʹ��
	**/
	virtual bool IsUsed() = 0;

	/**
	  @param bUsed ���ø������Ƿ�ʹ�ã�
	  true����ʹ�ã�false����û�б�ʹ��
	  @desc ���ø������Ƿ�ʹ��
	**/
	virtual void SetUsed(bool bUsed) = 0;
};

#endif

