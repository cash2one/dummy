#ifndef _CLIDEFINE_H_
#define _CLIDEFINE_H_

#include <sdbase.h>

/// ���ͻ�������С
#define SD_CLIENT_SENDBUFFER    200 * 1024
/// ������󳤶�
#define PACKAGE_LENGTH          1024 * 1024

//�����ͷ��ʼ��־
#define PKTHEADMAK				0xCCDD

/**
 * @brief ����㱨��ͷ
 */
#pragma pack(push, 1)
struct STNetMsgHeader
{
	UINT16	wMark;			///< ��ͷ��ʾ
    UINT16	wMsgID;         ///< ��Ϣ��
    UINT32	dwDataLen;      ///< ���ݰ�����
};
#pragma pack(pop)

/// ����������󳤶�
#define PACKAGE_CONTENT_LENGTH  PACKAGE_LENGTH - sizeof(STNetMsgHeader)

/// �ͻ��˰汾
const SGDP::SSGDPVersion SDCLIENT_MODULE_VERSION = {3, 2, 0, 0};

#endif // #ifndef _CLIDEFINE_H_

