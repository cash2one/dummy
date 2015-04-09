
//  Defines the entry point for the console application.
//  ʱ�䣺2010-12-27��
//

#include "gtpipechannel.h"
#include <net/cli/usermgr.h>
#include <protocol/server/protocligs.h>
#include <protocol/server/protogtgs.h>
#include <sdutil.h>



VOID CGTPipeChannel::OnRecv(UINT16 wBusinessID, const CHAR *pData, UINT32 dwLen)
{
    if (m_poPacketProcessor && !m_bRefusePkg)
    {
        CSDProtocol* poProtocol = m_poPacketProcessor->GetProtocol();
        if (poProtocol)
        {
            SDPipeMsgHeader* pHeader = (SDPipeMsgHeader*)pData;
            pHeader->dwTransID = SGDP::SDNtohl(pHeader->dwTransID);
            pHeader->wMsgID = SGDP::SDNtohs(pHeader->wMsgID);
            static CHAR  DecodeData[PACKET_LENGTH] = {0};
            INT32 nDecodeLen = poProtocol->Decode( pHeader->wMsgID,
                                                   (CHAR*)(pData + sizeof(SDPipeMsgHeader) ) ,
                                                   dwLen - sizeof(SDPipeMsgHeader),
                                                   DecodeData,
                                                   PACKET_LENGTH);

            if ( nDecodeLen > 0)
            {
                VOID* poSrcSession = NULL;

                switch(pHeader->wMsgID)
                {
                    //δ����CUserʱ��Э��,ʹ��PipeChannel����
                case GTGS_ENTERGS_REQ:
                {
                    poSrcSession = this;
                }
                break;
                //���û�������Э��
                case GSGT_KICK_OUT_ACK:
                {
                    poSrcSession = this;
                }
                break;

                //ʹ��CUser����
                default:
                {
                    CUser* poUser = CUserMgr::Instance()->FindUser(pHeader->dwTransID);
                    if (NULL == poUser)
                    {
                        USR_INFO(_SDT("[%s: %d] FindUser[%d] failed!"), MSG_MARK, pHeader->dwTransID);
                        return;
                    }
                    poUser->CkUserLogin();
                    poSrcSession = poUser;
                }
                break;
                }

                m_poPacketProcessor->ProcessPacket(poSrcSession,
                                                   pHeader,
                                                   DecodeData,
                                                   nDecodeLen);
            }
            else
            {
                USR_INFO(_SDT("[%s: %d]:decode packet error! TransID[%d],MsgID[%d]"), MSG_MARK, pHeader->dwTransID, pHeader->wMsgID);
            }
        }
    }
}


