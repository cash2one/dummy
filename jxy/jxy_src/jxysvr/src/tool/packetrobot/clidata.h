
#ifndef _CLIDATA_H_
#define _CLIDATA_H_

#include "clisession.h"

class CPacketRobotDlg;

/**
 * @brief ȫ������
 *
 * ��������ļ�������ʹ��ö���
 */
class CGlobe
{
public:
    static CPacketRobotDlg* m_poDlg;        ///< �Ի���
    static CCliSession*    m_poSeesion;    ///< �ͻ���Session
};

#endif // #ifndef _CLIDATA_H_

