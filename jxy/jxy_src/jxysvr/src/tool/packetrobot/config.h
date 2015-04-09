#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <sdtype.h>
#include <list>

// ---------------- �궨�� ----------------

// ���ó����ַ�������
#define STRING_SIZE_DEFAULT 128

// ---------------- �ṹ�� ----------------

// �������
typedef struct sInputInfo
{
	// �ؼ�ID
	INT32 nCtrlId;
	// ����
	CHAR szCaption[STRING_SIZE_DEFAULT];
	// Ĭ��ֵ
	CHAR szValue[STRING_SIZE_DEFAULT];
}InputInfo;

// ������Ϣ
typedef struct sMsgInfo
{
	// ����
	CHAR szCaption[STRING_SIZE_DEFAULT];
	// ����
	CHAR szDescribe[STRING_SIZE_DEFAULT];
	// ��ע
	CHAR szNote[STRING_SIZE_DEFAULT];
	// ���Ĳ�����Ҫ�������������
	std::list<InputInfo> lsInputs;
}MsgInfo;

// ---------------- ��  Ա ----------------

// ������IP
extern CHAR g_acServerIP[32];
// �������˿�
extern UINT32 g_dwServerPort;
// ������Ƶ��
extern UINT32 g_dwTick;
// ��������
extern std::list<MsgInfo> g_lsMessages;

// ---------------- ��  �� ----------------

// ��ȡ���������ļ���ʧ�ܷ��� FALSE
BOOL LoadFromXML(CHAR* _Path);

#endif

