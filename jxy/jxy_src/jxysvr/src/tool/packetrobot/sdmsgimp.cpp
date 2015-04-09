#include "sdmsgimp.h"
#include <algorithm>

using namespace std;
using namespace SGDP;

typedef UINT16 lenType ;
#define LENGTH_TAG (sizeof(lenType))
#define BUFFER_LEN	512

SGDP::ISDMsg* SDAPI SGDP::NewSDMsg()
{
	CSDMsgImp* pMsg = new CSDMsgImp;
	return pMsg;
}

CSDMsgImp::CSDMsgImp()
{
}

CSDMsgImp::~CSDMsgImp()
{
	CleanData();
}

VOID SDAPI CSDMsgImp::CleanData()
{
	ItMapKeyValue it = m_mapKeyValue.begin();
	ItMapKeyValue itend = m_mapKeyValue.end();
	for (; it != itend; ++it)
	{
		_Alnod.deallocate(it->second.pszValue, 1);
	}

	m_mapKeyValue.clear();
}

BOOL SDAPI CSDMsgImp::PushValue( const CHAR* pszKey, const UINT8* pData, UINT32 nLen )
{
	if ((NULL == pszKey) || (nLen <= 0) || (NULL == pData))
	{
		return FALSE;
	}
	std::string strKey = pszKey;
	// ת�ɴ�д
	transform(strKey.begin(), strKey.end(), strKey.begin(), toupper);

	if ((strKey.length() > 255) || (nLen > 255))
	{
		return FALSE;
	}

	ItMapKeyValue it = m_mapKeyValue.find(strKey);
	ItMapKeyValue itend = m_mapKeyValue.end();
	SValue sValue;
	sValue.pszValue = _Alnod.allocate(nLen);
	if (NULL == sValue.pszValue)
	{
		return FALSE;
	}
	sValue.nValueLen = nLen;
	memcpy_s(sValue.pszValue, nLen, pData, nLen);
	if (it != itend)
	{
		_Alnod.deallocate(it->second.pszValue, 1);
	}

	m_mapKeyValue[strKey] = sValue;

	return TRUE;
}

INT32 SDAPI CSDMsgImp::GetValue( const CHAR* pszKey, UINT8* pValue, UINT32 &nLen )
{
	std::string strKey = pszKey;
	// ת�ɴ�д
	transform(strKey.begin(), strKey.end(), strKey.begin(), toupper);
	ItMapKeyValue it = m_mapKeyValue.find(strKey);
	ItMapKeyValue itend = m_mapKeyValue.end();
	if (it != itend)
	{
		SValue sValue = it->second;
		if (sValue.nValueLen > nLen)
		{
			nLen = sValue.nValueLen;
			return SDMSG_GET_DEST_INSUFFICIENT;
		}
		memset(pValue, 0, nLen);
		memcpy_s(pValue, nLen, sValue.pszValue, sValue.nValueLen);
		nLen = sValue.nValueLen;
		return SDMSG_SUCCESS;
	}
	
	nLen = 0;
	return SDMSG_GET_NO_CONTENT;
}

BOOL SDAPI CSDMsgImp::PushBuffer( const UINT8* pBuf, UINT32 nLen )
{
	// �������Ϊ0����û���κ���Ϣ��Ҫ����
	if (nLen == 0)
	{
		return TRUE;
	}

	if ((nLen < 0) || (NULL == pBuf))
	{
		return FALSE;
	}

	const BYTE* pPos = pBuf;
	UINT32 nTmpLen = 0;
#define TMP_BUF_LEN 50
	CHAR szTmpBuf[TMP_BUF_LEN] = {0};
	for(; pPos < pBuf + nLen; )
	{
		// Key�ĳ���
		nTmpLen = (UINT32)(*(lenType*)pPos);
		// ��Ϊ��ʹvalue����Ϊ0����ôҲ���б�ʶvalue���ȵ�LENGTH_TAG���ֽڣ�����key�ĳ���һ��С����ʣ�ֽ���
		// - LENGTH_TAG ��ʾȥ��������
		if (nTmpLen >= nLen - (pPos - pBuf) - LENGTH_TAG)
		{
			CleanData();
			return FALSE;
		}
		pPos += LENGTH_TAG;
		memset(szTmpBuf, 0, TMP_BUF_LEN);
		memcpy_s(szTmpBuf, TMP_BUF_LEN, pPos, nTmpLen);//�����õ���Key
		std::string strKey = szTmpBuf;
		// ת�ɴ�д
		transform(strKey.begin(), strKey.end(), strKey.begin(), toupper);
		pPos += nTmpLen;

		memset(szTmpBuf, 0, TMP_BUF_LEN);
		nTmpLen = (UINT32)(*pPos);
		if (nTmpLen > nLen - (pPos - pBuf) - LENGTH_TAG)
		{
			CleanData();
			return FALSE;
		}
		pPos += LENGTH_TAG;
		this->PushValue(strKey.c_str(), pPos, nTmpLen);
		pPos += nTmpLen;
	}
#undef TMP_BUF_LEN
	if (nLen != (pPos - pBuf))
	{
		CleanData();
		return FALSE;
	}
	return TRUE;
}

INT32 SDAPI CSDMsgImp::GetBuffer( UINT8* pDestBuf, UINT32 &nLen )
{
	ItMapKeyValue it = m_mapKeyValue.begin();
	ItMapKeyValue itend = m_mapKeyValue.end();
	if (it == itend)
	{
		nLen = 0;
		return SDMSG_GET_NO_CONTENT;
	}

	// ���жϿռ��Ƿ��㹻��
	UINT32 nTotalLen = 0;
	for (; it != itend; ++it)
	{
		nTotalLen += 2 * LENGTH_TAG + (UINT32)(it->first.length()) + it->second.nValueLen;
	}
	if (nLen < nTotalLen)
	{
		nLen = nTotalLen;
		return SDMSG_GET_DEST_INSUFFICIENT;
	}

	memset(pDestBuf, 0, nLen);
	BYTE* pPos = pDestBuf;
	UINT32 nTmpLen = 0;

	it = m_mapKeyValue.begin();
	for (; it != itend; ++it)
	{
		nTmpLen = (UINT32)it->first.length();
		*(lenType*)pPos = nTmpLen;
		pPos += LENGTH_TAG;
		memcpy_s(pPos, nLen - (pPos - pDestBuf), it->first.c_str(), nTmpLen);
		pPos += nTmpLen;

		nTmpLen = it->second.nValueLen;
		*(lenType*)pPos = nTmpLen;
		pPos += LENGTH_TAG;
		memcpy_s(pPos, nLen - (pPos - pDestBuf), it->second.pszValue, nTmpLen);
		pPos += nTmpLen;
	}

	nLen = (UINT32)(pPos - pDestBuf);

	return SDMSG_SUCCESS;
}

INT32 SDAPI CSDMsgImp::CopyData( ISDMsg* pSrcMsg )
{
	if (NULL == pSrcMsg)
	{
		return SDMSG_COPY_SRC_ERROR;
	}

	UINT8* pBuffer = new UINT8[BUFFER_LEN];
	if (NULL == pBuffer)
	{
		return SDMSG_COPY_SYSTEM_ERROR;
	}

	UINT32 dwBufferLen = BUFFER_LEN;
	INT32 nRet = pSrcMsg->GetBuffer(pBuffer, dwBufferLen);
	switch (nRet)
	{
	case SDMSG_SUCCESS:
		{
			if (!PushBuffer(pBuffer, dwBufferLen))
			{
				delete pBuffer;
				return SDMSG_COPY_PUSH_FAIL;
			}
		}
		break;
	case SDMSG_GET_DEST_INSUFFICIENT: 
		{
			delete pBuffer;
			pBuffer = new UINT8[dwBufferLen];
			if (NULL == pBuffer)
			{
				return SDMSG_COPY_SYSTEM_ERROR;
			}
			if (!PushBuffer(pBuffer, dwBufferLen))
			{
				delete pBuffer;
				return SDMSG_COPY_PUSH_FAIL;
			}
		}
		break;
	case SDMSG_GET_NO_CONTENT:
		break;
	default:
		break;
	}
	delete pBuffer;

	return SDMSG_SUCCESS;
}

VOID SDAPI CSDMsgImp::Release()
{
	delete this;
}

