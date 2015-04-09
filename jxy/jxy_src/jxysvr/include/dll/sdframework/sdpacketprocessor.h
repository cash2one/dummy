

#ifndef _SGDP_PACKET_PROCESSOR_H_
#define _SGDP_PACKET_PROCESSOR_H_
#include "sdtype.h"
#include <map>
using namespace std;

namespace SGDP {
    class CSDPipeChannel;
    class CSDProtocol;
    typedef BOOL (*PPROCESSFUNC)(VOID* poReceiver, VOID* pHeader, const CHAR* pBody, UINT32 dwBodyLen);

#define COMMAND_COUNT      5000
#define COMMAND_STARTINDEX 1

    /**
    * @brief ���������Mapӳ���ϵ��
    *
    */
    class CCommandMap
    {
    public:
        /**
	    * @brief ���캯��
	    */
	    CCommandMap();
        
        /**
	    * @brief ��������
	    */
	    ~CCommandMap();
	    
        /**
	    * @brief ɾ�����е�����
	    * @return VOID
	    */
	    VOID  Reset();

	    /**
	    * @brief ��������봦��������Ķ�Ӧ��ϵ
	    * @param wMsgID ��Ϣ��ID
	    * @param pFunc ��Ϣ��Ӧ�Ĵ�����
	    * @param bForce �Ƿ�ǿ��ִ��
	    * @return BOOL �Ƿ���ӳɹ�,���bForceΪFALSE,ԭ��Ҳ���ڴ���Ϣ,����Ӳ��ɹ�
	    */
	    BOOL AddCommand(UINT16 wMsgID, PPROCESSFUNC pFunc, BOOL bForce = FALSE);

	    /**
	    * @brief ����ĳ����Ϣ��Ӧ�Ĵ�����
	    * @param wMsgID ��Ϣ��ID
	    * @return ���ض�Ӧ�Ĵ�����
	    *
	    */
	    PPROCESSFUNC FindCommand(UINT16 wMsgID);

	    /**
	    * @brief ɾ��ĳ����Ϣ��Ӧ�Ĵ�����
	    * @param wMsgID ��Ϣ��ID
	    * @return ����ɾ���Ĵ�����
	    *
	    */
	    PPROCESSFUNC RemoveCommand(UINT16 wMsgID);

	    /**
	    * @brief �޸���Ϣ�������������䣬��������Ҫ��AddCommand��RemoveCommand֮ǰ���ã�
                 ���򣬻����֮ǰ�ӵ�command������
	    * @param wArrayStart ��ʼ��Ϣ��ID
                 wArraySize  �����д�����Ϣ�����С
	    * @return ��
	    *
	    */
        VOID         InitCommandSize(const UINT16 wArrayStart,const UINT16 wArraySize);

    private:
	    PPROCESSFUNC* m_poFuncArray;  ///< ��������ָ��
        UINT16 m_wArraySize;          ///< ����������
        UINT16 m_wArrayStart;         ///< ��������ʼMsgID
        UINT16 m_wArrayEnd;           ///< ���������MsgID
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    /**
    * @brief �������ݰ�������,���ڴ����������ݰ�
    *
    */
    class CSDPacketProcessor 
    {
    public:
        /**
	    * @brief ���캯��
	    */
	    CSDPacketProcessor();
        
        /**
	    * @brief ��������
	    */
	    ~CSDPacketProcessor();

	    /**
	    * @brief ��ʼ���˾��
	    * @return �Ƿ��ʼ���ɹ�,TRUE����ɹ�,FALSE����ʧ��
	    */
        virtual BOOL Init(){return TRUE;};

	    /**
	    * @brief �ͷŴ˾��
	    * @return VOID
	    */
        virtual VOID UnInit() {};

	    /**
	    * @brief ����wBusinessID��ȡ��Ӧ��Э�鴦����
	    * @param wBusinessID Э���������ϢID��
	    * @return �����Э������Ĵ�����
	    */
        virtual CSDProtocol* GetProtocol() = 0;

	    /**
	    * @brief ����Э�������MessageID��ȡ��Ӧ�Ĵ�����
	    * @param wMsgID Э���������ϢID��
	    * @return �����Э������Ĵ�����
	    */
	    PPROCESSFUNC SDAPI LookupProcessFunc(UINT16 wMsgID);

	    /**
	    * @brief ����Э���������ݰ��Ĵ�����,�˺����ܹ�����Э������������Զ�ѡ����������
	    * �˺�����װ��LookupProcessFunc����
	    * @param poReceiver ���մ�Э������ĻỰ
	    * @param pHeader Э���������Ϣͷ
	    * @param pBody Э����������ݰ�����
	    * @param dwBodyLen Э����������ݰ����ݳ���
	    * @return �Ƿ���ɹ�.TRUEΪ����ɹ�,FALSEΪ����ʧ��
	    */
	    BOOL ProcessPacket(VOID* poReceiver, VOID* pHeader, const CHAR* pBody, UINT32 dwBodyLen);

	    /**
	    * @brief ע��Э��������Ӧ�Ĵ�����,û��ע���Э�����������
	    * @param wMsgID Э���������ϢID��
	    * @param pFunc ��Ӧ�Ĵ�����
	    * @return VOID
	    */
	    BOOL SDAPI RegisterCommand(UINT16 wMsgID, PPROCESSFUNC pFunc, BOOL bForce = TRUE);

	    /**
	    * @brief ע��Э��������Ӧ�Ĵ�����,û��ע���Э�����������
	    * @param wMsgID Э���������ϢID��
	    * @param pFunc ��Ӧ�Ĵ�����
	    * @return VOID
	    */
	    BOOL SDAPI UnRegisterCommand(UINT16 wMsgID);
	    /**
	    * @brief �޸���Ϣ�������������䣬��������Ҫ��AddCommand��RemoveCommand֮ǰ���ã�
                 ���򣬻����֮ǰ�ӵ�command������
	    * @param wArrayStart ��ʼ��Ϣ��ID
                 wArraySize  �����д�����Ϣ�����С
	    * @return ��
	    *
	    */
        VOID         InitCommandSize(const UINT16 wArrayStart,const UINT16 wArraySize);
    private:	    
	    CCommandMap m_mapCommand;     ///< ���е�����Ĵ��ӳ��
    };
}
#endif //#ifndef _SGDP_PACKET_PROCESSOR_H_

