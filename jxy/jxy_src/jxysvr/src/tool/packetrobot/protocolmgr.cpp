#include "protocolmgr.h"

CProtocolMgr::CProtocolMgr()
{
	DeleteAll();
	for(INT32 n = 0; n < SDF_MAX_PROCTOL_MSG; n++)
	{
		m_SDProtocol[n] = NULL;
	}
}

CProtocolMgr::~CProtocolMgr()
{
	DeleteAll();
}

/// ��ȡʵ��
CProtocolMgr* CProtocolMgr::Instance()
{
	static CProtocolMgr oProtocolMgr;
	return &oProtocolMgr;
}

/// ��������Э��
VOID CProtocolMgr::DeleteAll()
{
	map<string ,CSDProtocol*>::iterator iter ;
	for(iter = begin(); iter != end(); iter ++ )
	{
		CSDProtocol* pProtocol = (CSDProtocol*)(iter->second);
		if (pProtocol)
		{
            // TODO
			// delete pProtocol ;
			pProtocol = NULL ;
		}
	}
	clear();
}

/// ����Э��
CSDProtocol* CProtocolMgr::AddProtocol( CSDProtocol *pProtocol)
{
	CSDProtocol* pResult = FindProtocol(pProtocol->GetName()) ;
	if(NULL == pResult)
	{
		pResult = pProtocol ;
		insert(make_pair(pProtocol->GetName(),pProtocol));
		vector<INT32>* pVector = pProtocol->GetMsgList();
		if(pVector)
		{
			vector<INT32>::iterator vectorMsg;
			for(vectorMsg = pVector->begin(); vectorMsg != pVector->end(); vectorMsg ++ )
			{
				INT32 nMsg = (*vectorMsg);
				m_SDProtocol[nMsg] = pProtocol;
			}
		}
	}
	else
    {
		pResult = NULL;
    }
	return pResult ;
}

/// ������Ϣ�Ų���Э��
CSDProtocol* CProtocolMgr::FindProtocol(UINT32 nMsgID)
{
	CSDProtocol* pResult = NULL;
	if(nMsgID > 0 && nMsgID < SDF_MAX_PROCTOL_MSG)
	{
		pResult = m_SDProtocol[nMsgID];
	}
	return pResult;
}

/// �������Ʋ���Э��
CSDProtocol* CProtocolMgr::FindProtocol(std::string strName)
{
	CSDProtocol* pResult = NULL;
	map<string ,CSDProtocol*>::iterator iter = find(strName);
	if(iter != end())
	{
		pResult = (CSDProtocol*)(iter->second);
	}
	return pResult;
}

/// ��������ɾ��ָ��Э��
CSDProtocol* CProtocolMgr::RemoveProtocol(std::string strName)
{
	CSDProtocol* pResult = NULL;
	map<string,CSDProtocol*>::iterator iter = find(strName);
	if(iter != end())
	{
		pResult = iter->second;
		erase(iter);
	}
	return pResult;
}

