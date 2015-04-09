#ifndef _SMS_MGR_H_
#define _SMS_MGR_H_

#include <sdsingleton.h>
#include <sdtype.h>
#include <sdstring.h>
#include <sdthread.h>
#include <deque>
#include <map>
#include <dll/sddb/sddb.h>
#include <list>
#include "basesmscmd.h"
#include "bindsmscmd.h"
#include "unbindsmscmd.h"


using namespace SGDP;
using namespace std;






typedef std::list<CBaseSmsCMD*>		CBaseSmsCMDList;
typedef CBaseSmsCMDList::iterator	CBaseSmsCMDListItr;





class CSmsMgr: public CSDThread
{
    DECLARE_SINGLETON(CSmsMgr);
public:
    CSmsMgr();
    virtual ~CSmsMgr();
    BOOL Init();
    VOID UnInit();
    BOOL Run();

	CBaseSmsCMD*	CreateCmd(enum ESMSCmdType eSmsCmdType);
	VOID			FreeCmd(CBaseSmsCMD* poBaseDBCMD);

	BOOL			AddCommand(CBaseSmsCMD* poDBCommand);


private:
    const static UINT32 ms_dwSleepTime = 1; //˯�ߵ�ʱ����
protected:
    //�߳�
    virtual VOID  ThrdProc();

private:
    VOID Stop();


private:
    BOOL m_bStop;
    time_t m_tLastWriteTime; //�ϴ�д�����ݿ��ʱ��
    //������Ҫִ�е�����
    CBaseSmsCMDList	m_oBaseSmsCMDListing;
    CSDMutex			m_ListingMutex;
    //ִ����ɵ�����
    CBaseSmsCMDList	m_oBaseSmsCMDListed;
    CSDMutex			m_ListedMutex;

    CSDObjectPool<CBindSmsCMD, CSDMutex>	m_oBindSmsCMDPool;
	CSDObjectPool<CUnBindSmsCMD, CSDMutex>	m_oUnBindSmsCMDPool;
};


#endif