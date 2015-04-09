
#ifndef _CLIPKTPARSER_H_
#define _CLIPKTPARSER_H_

/**
 * @file ����У��ģ��
 *
 * ����У�鱨����������Ϸ��ԣ�Ŀǰ������ƴ��
 *
 * @author �������ķ��������沿
 */
#include "sdnet.h"

/**
 * @brief ���ĺϷ��Ժ�������У��
 */
class CCliPacketParser : public SGDP::ISDPacketParser
{
private:
    CCliPacketParser();

    virtual ~CCliPacketParser();

public:
    /**
     * @brief ��ȡʵ��
     * @return ����У��ģ�����ָ��
     */
    static CCliPacketParser* Instance();

    /**
     * @brief ��������
     * @param pBuf ���յ��ı��ĵ�ַ
     * @param pBuf ���յ����ֽ���
     * @return ���յ���ʵ�ʴ�С
     */
    virtual INT32 SDAPI ParsePacket(const CHAR *pBuf, UINT32 dwLen);
};

#endif // #ifndef _CLIPKTPARSER_H_

