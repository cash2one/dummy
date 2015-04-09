#include "protocligs.h"


struct SProcessInfo
{
	SProcessInfo()
	{
		nMaxNum=0;
		nSuccessNum=0;
	}
	INT32 nMaxNum;
	INT32 nSuccessNum;
};

//�Ѷ����Ƶ�����ת����json��ʽ�Ĵ洢��ʽ
class Convert
{
public:
	Convert();
	~Convert();
	//��ʼ��
	BOOL Init();

	//���ʼ��
	BOOL UnInit();

	//��ʼ��������ת��
	BOOL Process();

	//��ý��������
	string GetResultDes();
private:
	BOOL ConvertPlayerData();
	BOOL ConvertPlayerPvpData();
	BOOL SavePlayerDataAsJson( DT_PLAYER_DATA &oDT_PLAYER_DATA, const string &strDeviceName, 
		const string &strNotifyID, const string &strCreateTime, const string &strUserName );
	BOOL InsertPalyerData(SGDP::ISDDBSession* pDBSession, UINT32 dwPlayerID, const string &strUserName, 
		const string &strDeviceID, const string &strNotifyID, DT_PLAYER_DATA* pstPlayerData);
	BOOL SavePlayerPvpDataAsJson( DT_PLAYER_DATA &oDT_PLAYER_DATA, const string &strDeviceName, const string &strNotifyID );
	BOOL InsertPlayerPvpData(  );
	BOOL IsPlayerDataExist( UINT32 dwPlayerID );
private:
	string m_strSql;
	SProcessInfo m_stPvpDataProcess;
	SProcessInfo m_stPlayerDataProcess;
};