#include "ConnectionPool.h"

#include<stdexcept>
#include<exception>
#include<stdio.h>

#include<mysql_connection.h>
#include<mysql_driver.h>
#include<cppconn/exception.h>
#include<cppconn/driver.h>
#include<cppconn/resultset.h>
#include<cppconn/prepared_statement.h>
#include<cppconn/statement.h>

#include <base/Logging.h>

using namespace std;

ConnPool* ConnPool::connPool=NULL;

//���ӳصĹ��캯��
ConnPool::ConnPool(const char* url, const char* usr, const char* pwd, const char* dbname, int maxSize) :
    m_url(url),
    m_username(usr),
    m_password(pwd),
    m_dbname(dbname),
    m_curSize(0),
    m_maxSize(maxSize)
{
}

void ConnPool::Init()
{
    try{
        m_driver = sql::mysql::get_mysql_driver_instance();
    }
    catch(sql::SQLException &e)
    {
        LOG_ERROR << "�������ӳ���:" << e.what();
    }
    catch(std::runtime_error&)
    {
        LOG_ERROR << "���г�����:";
    }

    this->InitConnection(m_maxSize);
}

/*
//��ȡ���ӳض��󣬵���ģʽ
ConnPool* ConnPool::GetInstance(){
    if(connPool==NULL)
    {
        connPool = new ConnPool("tcp://127.0.0.1:3306","root","root",50);
    }
    return connPool;
}
}*/

//��ʼ�����ӳأ����������������һ����������
void ConnPool::InitConnection(int initialSize)
{
    Connection *conn;

    MutexLockGuard lock(m_mutex);

    for(int i = 0;i < initialSize; i++)
    {
        conn = this->CreateConnection();
        if(conn){
            connList.push_back(conn);
            ++(this->m_curSize);
        }
        else
        {
            perror("����CONNECTION����");
        }
    }
}

//��������,����һ��Connection
Connection* ConnPool::CreateConnection()
{
    Connection*conn;

    try{
        conn = m_driver->connect(m_url, m_username, m_password);//��������
        return conn;
    }
    catch(sql::SQLException &e)
    {
        LOG_ERROR << "�������ӳ���:" << e.what();
        return NULL;
    }
    catch(std::runtime_error&)
    {
        perror("����ʱ����");
        return NULL;
    }

    return NULL;
}

//�����ӳ��л��һ������
Connection* ConnPool::GetConnection()
{
    Connection*con;
    MutexLockGuard lock(m_mutex);

    if(connList.size()>0)//���ӳ������л�������
    {
        con = connList.front();//�õ���һ������
        connList.pop_front();//�Ƴ���һ������
        
        if(con->isClosed())//��������Ѿ����رգ�ɾ�������½���һ��
        {
            delete con;
            con=this->CreateConnection();
        }

        //�������Ϊ�գ��򴴽����ӳ���
        if(con == NULL)
        {
            --m_curSize;
        }

        return con;
    }
    else{
        if(m_curSize< m_maxSize){//�����Դ����µ�����
            con= this->CreateConnection();
            if(con){
                ++m_curSize;
                return con;
            }
            else{
                return NULL;
            }
        }
        else{//�������������Ѿ��ﵽmaxSize
            return NULL;
        }
    }
}

//�������ݿ�����
void ConnPool::ReleaseConnection(sql::Connection * conn){
    if(conn){
        MutexLockGuard lock(m_mutex);
        connList.push_back(conn);
    }
}

//���ӳص���������
ConnPool::~ConnPool()
{
    this->DestoryConnPool();
}

//�������ӳ�,����Ҫ���������ӳص�������
void ConnPool::DestoryConnPool(){
    list<Connection*>::iterator icon;
    MutexLockGuard lock(m_mutex);
    for(icon=connList.begin();icon!=connList.end();++icon)
    {
        this->DestoryConnection(*icon);//�������ӳ��е�����
    }
    m_curSize=0;
    connList.clear();//������ӳ��е�����
}

//����һ������
void ConnPool::DestoryConnection(Connection* conn)
{
    if(conn)
    {
        try{
            conn->close();
        }
        catch(sql::SQLException&e)
        {
            perror(e.what());
        }
        catch(std::exception&e)
        {
            perror(e.what());
        }
        delete conn;
    }
}
