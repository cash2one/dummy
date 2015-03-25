//************************************  
// ��������: $SymbolName$  
// ����˵����  
// �� �� �ߣ�Mr.M  
// �������ڣ�$DATE$  
// �� �� ֵ: $SymbolType$  
// ��    ��: $MethodArg$  
//************************************  

// �������Ļ��࣬������������Ӵ�����

#ifndef Server_h__
#define Server_h__


#include <vector>

using namespace std;

class Client;
typedef vector<Client*> ClientVec;

class Thread;

class Server
{
public:
    void Init();

    void StartUp();

    void Run(){}

    void Terminate();

private:
    ClientVec m_clients;

    Thread *m_pWorker;
};
#endif // Server_h__