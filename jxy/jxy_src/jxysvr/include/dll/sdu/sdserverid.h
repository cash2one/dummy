


#ifndef SDSERVERID_H
#define SDSERVERID_H
/**
* @file sdserverid.h

* @brief ServerID��
*
**/
#include "sdtype.h"
#include <string>
#include "sdstring.h"

// ���������Ͷ���
enum eServerType {
	TYPE_BALANCE_SERVER		= 1,
	TYPE_LOGIN_SERVER,	
	TYPE_GATE_SERVER,	
	TYPE_GAME_SERVER,	
	TYPE_DB_SERVER,		
	TYPE_CENTER_SERVER,	
	TYPE_GATE_LISTENER,	
	TYPE_GAME_LISTENER,	
	TYPE_CLIENT,			
	TYPE_NOTICE_SERVER,		//֪ͨ������
	TYPE_GM_SERVER,			//GM���������
	TYPE_MS_SERVER,			//��ط�����
	TYPE_TLC_SERVER,		//��������֤��ֵ������
	TYPE_PK_SERVER,			//���ս������

	TYPE_PK_Cnt,

	TYPE_INVALID_SERVER = 0,
};

namespace SGDP
{
    /**
    * @defgroup groupgametools GAME TOOLS
    * @ingroup  SGDP
    * @{
    */

    /**
    * @brief
    * ��ServerID������ת��Ϊ�ַ���
    * @param dwServerID : ���ֵ�ServerID
    * @param dwMask : ���룬�����ַ�����ServerID��ÿһλռ���ֵ�ServerID�Ķ���λ
    * �磬���maskΪ0x08080808��
    * �����ֵ�ServerID��31��24λ�����ַ�����ServerID�ĵ�һλpart1��
    * ���ֵ�ServerID��23��16�����ַ�����ServerID�ĵڶ�λpart2��
    * ���ֵ�ServerID��15��8�����ַ�����ServerID�ĵ���λpart3��
    * ���ֵ�ServerID��7��0�����ַ�����ServerID�ĵ���λpart4��
    * @return ת��Ϊ�ַ�����ServerID
    * @remark : �ַ���ServerID�ĸ�ʽΪ: part1-part2-part3-part4.
    */
    tstring  SDServerIDUtoa(UINT32 dwServerID, UINT32 dwMask = 0x08080808);

    /**
    * @brief
    * ��ServerID���ַ���ת��Ϊ����
    * @param pszServerID : �ַ�����ServerID
    * @param dwMask : ���룬�����ַ�����ServerID��ÿһλռ���ֵ�ServerID�Ķ���λ
    * �磬���maskΪ0x08080808��
    * ���ַ�����ServerID�ĵ�һλpart1�������ֵ�ServerID��31��24λ��
    * �ַ�����ServerID�ĵ�һλpart2�������ֵ�ServerID��23��16λ��
    * �ַ�����ServerID�ĵ�һλpart3�������ֵ�ServerID��15��8λ��
    * �ַ�����ServerID�ĵ�һλpart4�������ֵ�ServerID��7��0λ��
    * @return ת��Ϊ���ֵ�ServerID
    * @remark : �ַ���ServerID�ĸ�ʽΪ: part1-part2-part3-part4.
    */
    UINT32  SDServerIDAtou(const CHAR *pszServerID, UINT32 dwMask = 0x08080808);

	tstring GetServerShortName(UINT8 byServerType);//��ø�����������


	/**
    * @brief pipe����������Ϣ
    */
    struct SPipeInfo
    {
        UINT32   dwID;       ///< �Է���ServerID���        
        TCHAR    szIP[16];   ///< �Է�ʹ�õ�����IP��ַ �ַ���������
        UINT32   dwIP;       ///< �Է�ʹ�õ�����IP��ַ INT32������
        UINT16   wPort;      ///< �Է�ʹ�õ����Ӷ˿�
        BOOL     bConnect;   ///< ����״̬������FALSE���Ͽ���TRUE��������
        BOOL     bDirection; ///< ���ӷ��򣬼������ӷ������ӷ�
    };
	
	#define MAX_PIPE_CONNECT_NUM 255 //���pipe����
	struct SAllPipeInfo
	{
		SAllPipeInfo() { byPipeNum = 0; memset(astPipeInfo, 0, sizeof(astPipeInfo));}		
		UINT8		byPipeNum;
		SPipeInfo	astPipeInfo[MAX_PIPE_CONNECT_NUM];
	};

//TODO ���ӹ淶

    /**
    *@brief ServerID��
    */
    class CSDServerID
    {
    public:

		/**
		* @brief ���캯������ʼ��������ID������
		* @param dwID : ������ID
		* @param dwMask : ����
		*/
        CSDServerID(UINT32 dwID = 0, UINT32 dwMask = 0x08080808);

		/**
		* @brief ��������
		*/
        ~CSDServerID() {}

        /**
        * @brief
        * ����ID
        * @param pszID  : ���õ������͵�ID
        * @param dwMask : ����
        * @return VOID
        */
        VOID  SetID(UINT32 dwID, UINT32 dwMask = 0x08080808);

        /**
        * @brief
        * ����ID
        * @param pszID  : ���õ��ַ����͵�ID
        * @param dwMask : ����
        * @return VOID
        */
        VOID  SetID(const TCHAR *pszID, UINT32 dwMask = 0x08080808);

        /**
        * @brief
        * ��������
        * @param dwMask : ���õ�����, ע���������ܺͲ��ܳ���sizeof(UINT32)
        * @return VOID
        */
        VOID  SetMask(UINT32 dwMask);

        /**
        * @brief
        * ��ȡ����
        * @return VOID
        */
        UINT32  GetMask();

        /**
        * @brief
        * ��ȡAreaID�����ַ�����ServerID�ĵ�һλ
        * @return ��ȡAreaID
        */
        UINT32  GetAreaID();

        /**
        * @brief
        * ��ȡGroupID�����ַ�����ServerID�ĵڶ�λ
        * @return ��ȡGroupID
        */
        UINT32  GetGroupID();

        /**
        * @brief
        * ��ȡServerType�����ַ�����ServerID�ĵ���λ
        * @return ��ȡServerType
        */
        UINT32  GetServerType();

        /**
        * @brief
        * ��ȡServerIndex�����ַ�����ServerID�ĵ���λ
        * @return ��ȡServerIndex
        */
        UINT32  GetServerIndex();

        /**
        * @brief
        * ��ȡ�ַ����͵�ServerID
        * @return �ַ����͵�ServerID
        */
        tstring  AsString();

        /**
        * @brief
        * ��ȡ�����͵�ServerID
        * @return �����͵�ServerID
        */
        UINT32  AsNumber();

    private:
        UINT32       m_dwMaskLen[4]; //mask�ĳ��ȣ�������λ
        UINT32       m_dwSubMask[4]; //mask��ֵ
        UINT32       m_dwID;          // ����ID
        UINT32       m_dwMask;        //����,ע���������ܺͲ��ܳ���32
        tstring		 m_strID;
    };


    /**
    * @brief
    * ��ServerID������ת��Ϊ�ַ���
    * @param dwServerID : ���ֵ�ServerID
    * @param dwMask : ���룬�����ַ�����ServerID��ÿһλռ���ֵ�ServerID�Ķ���λ
    * �磬���maskΪ0x08080808��
    * �����ֵ�ServerID��31��24λ�����ַ�����ServerID�ĵ�һλpart1��
    * ���ֵ�ServerID��23��16�����ַ�����ServerID�ĵڶ�λpart2��
    * ���ֵ�ServerID��15��8�����ַ�����ServerID�ĵ���λpart3��
    * ���ֵ�ServerID��7��0�����ַ�����ServerID�ĵ���λpart4��
    * @return ת��Ϊ�ַ�����ServerID
    * @remark : �ַ���ServerID�ĸ�ʽΪ: part1-part2-part3-part4.
    */
    tstring  SDServerIDExUtoa(UINT64 dwServerID, UINT32 dwMask = 0x08080808);

    /**
    * @brief
    * ��ServerID���ַ���ת��Ϊ����
    * @param pszServerID : �ַ�����ServerID
    * @param dwMask : ���룬�����ַ�����ServerID��ÿһλռ���ֵ�ServerID�Ķ���λ
    * �磬���maskΪ0x08080808��
    * ���ַ�����ServerID�ĵ�һλpart1�������ֵ�ServerID��31��24λ��
    * �ַ�����ServerID�ĵ�һλpart2�������ֵ�ServerID��23��16λ��
    * �ַ�����ServerID�ĵ�һλpart3�������ֵ�ServerID��15��8λ��
    * �ַ�����ServerID�ĵ�һλpart4�������ֵ�ServerID��7��0λ��
    * @return ת��Ϊ���ֵ�ServerID
    * @remark : �ַ���ServerID�ĸ�ʽΪ: part1-part2-part3-part4.
    */
    UINT64  SDServerIDExAtou(const CHAR* pszServerID, UINT32 dwMask = 0x08080808);

    class CSDServerIDEx
    {
    public:

		/**
		* @brief ���캯������ʼ��������ID������
		* @param dwId : ������ID
		* @param dwMask : ����
		*/
        CSDServerIDEx(UINT64 dwId = 0, UINT32 dwMask = 0x08080808);

		/**
		* @brief ��������
		*/
        ~CSDServerIDEx() {}

        /**
        * @brief
        * ����ID
        * @param pszID : ���õ������͵�ID
        * @param dwMask : ����
        * @return VOID
        */
        VOID  SetID(UINT64 dwID, UINT32 dwMask = 0x08080808);

        /**
        * @brief
        * ����ID
        * @param pszID : ���õ��ַ����͵�ID
        * @param dwMask : ����
        * @return VOID
        */
        VOID  SetID(const TCHAR* pszID, UINT32 dwMask = 0x08080808);

        /**
        * @brief
        * ��������
        * @param dwMask : ���õ�����, ע���������ܺͲ��ܳ���sizeof(UINT32)
        * @return VOID
        */
        VOID  SetMask(UINT32 dwMask);

        /**
        * @brief
        * ��ȡ����
        * @return VOID
        */
        UINT32  GetMask();


        /**
        * @brief
        * ��ȡ��Ϸ��id
        * @return UINT32
        */
        UINT32  GetGameId();


        /**
        * @brief
        * ��ȡAreaID�����ַ�����ServerID�ĵ�һλ
        * @return ��ȡAreaID
        */
        UINT32  GetAreaId();

        /**
        * @brief
        * ��ȡGroupID�����ַ�����ServerID�ĵڶ�λ
        * @return ��ȡGroupID
        */
        UINT32  GetGroupId();

        /**
        * @brief
        * ��ȡServerType�����ַ�����ServerID�ĵ���λ
        * @return ��ȡServerType
        */
        UINT32  GetServerType();

        /**
        * @brief
        * ��ȡServerIndex�����ַ�����ServerID�ĵ���λ
        * @return ��ȡServerIndex
        */
        UINT32  GetServerIndex();

        /**
        * @brief
        * ��ȡ�ַ����͵�ServerID
        * @return �ַ����͵�ServerID
        */
        tstring  AsString();

        /**
        * @brief
        * ��ȡ�����͵�ServerID
        * @return �����͵�ServerID
        */
        UINT64  AsNumber();
    private:
        UINT32        m_maskLen[4]; //mask�ĳ��ȣ�������λ
        UINT32        m_subMask[4]; //mask��ֵ
        UINT32        m_mask; //������ID����
        UINT64        m_id;
        tstring		  m_strId;
    };

    /** @} */
}

#endif // 


