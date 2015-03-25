/*
*File: connection_pool.h
*Author: csc
*/
#ifndef _CONNECTION_POOL_H
#define	_CONNECTION_POOL_H

#include <base/Mutex.h>

#include<list>
#include<cppconn/connection.h>

#include<mysql_driver.h>

using namespace std;
using namespace sql;

class ConnPool{
public:
    //static ConnPool* GetInstance();//��ȡ���ݿ����ӳض���

    ConnPool(const char* url, const char* usr, const char* pwd, const char* dbname, int maxSize);//���췽��
    ~ConnPool();

    void Init();

    Connection* GetConnection();//������ݿ�����
    void ReleaseConnection(Connection *conn);//�����ݿ����ӷŻص����ӳص�������


private:
    

    Connection* CreateConnection();//����һ������
    void InitConnection(int iInitialSize);//��ʼ�����ݿ����ӳ�
    void DestoryConnection(Connection *conn);//�������ݿ����Ӷ���
    void DestoryConnPool();//�������ݿ����ӳ�

private:
    int m_curSize;//��ǰ�ѽ��������ݿ���������
    int m_maxSize;//���ӳ��ж����������ݿ�������
    string m_username;
    string m_password;
    string m_dbname;
    string m_url;

    list<Connection*> connList;//���ӳص���������

    mutable MutexLock m_mutex; // �߳���

    static ConnPool* connPool;
    sql::mysql::MySQL_Driver *m_driver;
};

#endif	/*_CONNECTION_POOL_H */