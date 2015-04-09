


#ifndef _SGDP_PIPE_CHANNEL_H_
#define _SGDP_PIPE_CHANNEL_H_

#include "sdtype.h"
#include "sdnet.h"
#include "sdpipe.h"
#include "sdstring.h"
#include "sdpacketprocessor.h"
#include "netdata.h"

namespace SGDP{
    class CSDPacketProcessor;
    /**
    * @brief CSDPipeChannel �������以��ͨ��������
    *
    */
    class CSDPipeChannel : public ISDPipeSink
    {
    public:
        /**
	    * @brief ���캯��
	    */
        CSDPipeChannel();
        
        /**
	    * @brief ��������
	    */
        ~CSDPipeChannel();

        /**
	    * @brief �趨sdpipe�Ĳ������ָ�룬�Ա�����������ʹ�ã��Լ������������ͨ�ŵײ�
	    * @param pPipe ����ͨ�Ų���ָ��
	    */
        VOID            SetPipe(const ISDPipe* pPipe);

        /**
	    * @brief ��ȡPipeChannel�ĶԷ���ServerIDֵ
	    * @return ����PipeChannel�ĶԷ���ServerIDֵ
	    */
        UINT32			GetPipeID() const;
        
        /**
	    * @brief ��ȡPipeChannel�ĶԷ�����������
	    * @return ����PipeChannel�ĶԷ�����������
	    */
        UINT8			GetSvrType() const;

        /**
	    * @brief ��ȡPipeChannel�ĶԷ�����IP��ַ
	    * @return ����PipeChannel�ĶԷ�����IP��ַ�ַ���
	    */
        TCHAR*			GetLocalIPStr() const;
        
        /**
	    * @brief ��ȡPipeChannel�ĶԷ�����IP��ַ
	    * @return ����PipeChannel�ĶԷ�����IP��ַ��������
	    */
        UINT32			GetLocalIP() const; 
        
        /**
	    * @brief ��ȡPipeChannel�ĶԷ�����IP��ַ���Ӷ˿�
	    * @return ����PipeChannel�ĶԷ�����IP��ַ���Ӷ˿�
	    */
        UINT16          GetLocalPort() const;
        
        /**
	    * @brief ��ȡPipeChannel�ĶԷ�Զ��IP��ַ
	    * @return ����PipeChannel�ĶԷ�Զ��IP��ַ�ַ���
	    */
        tstring			GetRemoteIPStr() const;

        /**
	    * @brief ��ȡPipeChannel�ĶԷ�Զ��IP��ַ
	    * @return ����PipeChannel�ĶԷ�Զ��IP��ַ��������
	    */
        UINT32			GetRemoteIP() const; 
        
        /**
	    * @brief ��ȡPipeChannel�ĶԷ�Զ��IP��ַ���Ӷ˿�
	    * @return ����PipeChannel�ĶԷ�Զ��IP��ַ���Ӷ˿�
	    */
        UINT16          GetRemotePort() const;
        
        /**
	    * @brief �趨PipeChannelЭ�鴦�����Э����
	    * @param poPacketProcessor PipeChannelЭ�鴦�����Э����ָ��
	    */
        VOID            SetPacketProcessor(CSDPacketProcessor* poPacketProcessor);

        /**
	    * @brief ���ʹ�������
	    * @param pszData: ��Ҫ����������ڴ�ָ��
        * @param dwLen: ��Ҫ����������ڴ泤��
	    * @return BOOL�����ݣ�TRUE�����ͳɹ���FALSE������ʧ�ܡ�
	    */
        BOOL            Send( const CHAR* pszData, const UINT32 dwLen);

        /**
	    * @brief ���ʹ�����Ϣ���ݣ���Send��ͬ���ǣ�SendMsg��ִ��Encode��������װ����
	    * @param dwTransID: ���Ĵ����CUser�����Ӧ��ClientID
        * @param dwMsgID: ������Ϣ��MessageID
	    * @param pData: ��Ҫ����������ڴ�ָ��
	    * @return BOOL�����ݣ�TRUE�����ͳɹ���FALSE������ʧ�ܡ�
	    */
        BOOL            SendMsg( UINT32 dwTransID, const UINT32 dwMsgID ,const CHAR* pData);
        
        /**
	    * @brief ���������ӳɹ�������ϵͳ�ڲ��Զ��ص�
	    */
        virtual VOID    OnEstablish();
    protected:    
        /**
	    * @brief ���������ӳɹ�������ϵͳ�ڲ��Զ��ص�
	    */
        virtual VOID    OnTerminate();

        /**
	    * @brief ���������ӳ����쳣����
        * @param nErrCode: �쳣����Ĵ�����
	    */
        virtual VOID    OnError(const INT32 nErrCode);
    protected:
        CSDPacketProcessor*  m_poPacketProcessor; ///< ��������ָ��

    private:      
        /**
	    * @brief ����������״̬��Ǩ�ص�������
        * @param wBusinessID: ҵ��������
        * @param nErrCode: �쳣����Ĵ�����
	    */
        virtual VOID SDAPI   OnReport(UINT16 wBusinessID, INT32 nErrCode);

        /**
	    * @brief �յ����Է�������������ı������ݡ�
        * @param wBusinessID: ҵ��������
        * @param pData: �յ��������ڴ�ָ��
        * @param pData: �յ��������ڴ泤��
	    */
        virtual VOID SDAPI   OnRecv(UINT16 wBusinessID, const CHAR *pData, UINT32 dwLen);

        ISDPipe*			 m_poPipe;            ///< ���������Ӷ�Ӧ��sdpipe��������ָ��
        UINT8                m_byServerType;      ///< ���������Ӷ�Ӧ�ķ���������
        static UINT32        m_dwIndex;           ///< �������Ӿ�̬������
    };

    /**
    * @brief ������֮��Ķ��ػ�����״̬����ص��ӿڣ��Լ�PipeChannel�ļ��й�����
    *
    */
    class CSDPipeChannelMgr : public ISDPipeReporter
    {
    public:
        typedef map<UINT32, CSDPipeChannel*>            CPipeChannelMap;
        typedef map<UINT32, CSDPipeChannel*>::iterator  CPipeChannelMapItr;
      
        /**
	    * @brief ���캯��
	    */
        CSDPipeChannelMgr();
        
        /**
	    * @brief ��������
	    */
        ~CSDPipeChannelMgr();

	    /**
	    * @brief ���Ա���ݳ�ʼ���ӿ�
	    * @param poPipeModule : ���Ӧ�ò����õ�pipeģ����ָ��
	    */
        VOID               Init(ISDPipeModule* poPipeModule);

        /**
	    * @brief �ͷŵײ�����ϵͳ�������Դ
	    */
        VOID               UnInit();

        /**
	    * @brief ����ServerID���ҵ���Ӧ�ķ���������
	    * @param dwID : ��Ҫ���ҵķ��������ӵ�ServerID
        * @return �������ֵΪ�գ������ָ���ķ��������Ӳ����ڣ����򣬷��ص��Ƕ�Ӧ�����������PipeChannelָ�롣
	    */
        CSDPipeChannel*	   FindPipeChannel(const UINT32 dwID);

        /**
	    * @brief �����ӹ����������һ���������Ӿ��ָ�룬��PipeChannel��Ӧ��ServerIDΪkey��
	    * @param poPipeChannel : ��Ҫ��ӵ��������е��������Ӿ��ָ��
	    */
        VOID               AddPipeChannel ( CSDPipeChannel* poPipeChannel );

        /**
	    * @brief �ӹ������и���ָ����ServerID��ɾ����Ӧ����������ָ�����
	    * @param dwID : ��Ҫ��ӵ��������е��������Ӿ��ָ��
	    */
        VOID               RemovePipeChannel(const UINT32 dwID);

        /**
	    * @brief ������ӹ�����map���ö���
        * @return �������ӹ�����map���ö���
	    */
        CPipeChannelMap&   GetPipeChannelMap();

        /**
	    * @brief ��������ͬ������������ӹ㲥
	    * @param dwTranID : ���Ĵ����CUser�����Ӧ��ClientID
        * @param wMsgID : ������Ϣ��MessageID
	    * @param pData: ��Ҫ����������ڴ�ָ��
	    * @param byType: ��Ҫ�㲥���ݵķ���������
	    */
        VOID               BroadcastToSameTypeServers(
                                                      const UINT32 dwTranID,
                                                      const UINT16 wMsgID,
                                                      const CHAR*  pData,                                                      
                                                      const UINT8 byType);

    protected:
        /**
	    * @brief ����������״̬��Ǩ�ص�������
        * @param dwID: ��Ӧ��������ServerID
        * @param nErrCode: �쳣����Ĵ�����
	    */
        virtual VOID SDAPI OnReport(INT32 nErrCode, UINT32 dwID);
       
        /**
	    * @brief ���������ӳɹ�������ϵͳ�ص�
        * @param dwPipeID: ��Ӧ��������ServerID
	    */
        virtual VOID _OnConnected(UINT32 dwPipeID);

        /**
	    * @brief ���������ӶϿ���ϵͳ�ص�
        * @param dwPipeID: ��Ӧ��������ServerID
	    */
        virtual VOID _OnDisconnected(UINT32 dwPipeID);
    private:
        CPipeChannelMap     m_mapPipeChannel;    ///< ��������������map������
        ISDPipeModule*      m_poPipeModule;      ///< application�㿪����pipeģ����ָ��
    };

}
#endif

