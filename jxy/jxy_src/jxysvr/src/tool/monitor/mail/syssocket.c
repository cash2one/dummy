/*==================================================================================================
 * ��Ŀ����:����ģ��
 *    ����:�շ���������
 *    ����: 
 *    ��ϵ: 
 *    �汾: v1.0.0
 ==================================================================================================*/

#include "syssocket.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>

#define BACKLOG 50

/*********************************************************************************************
 *��   ��   ����sysutil_activate_keepalive
 *��        �ܣ����ͱ��ֻ����
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
void sysutil_activate_keepalive(int fd) {
	int keepalive = 1;
	int retval = setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &keepalive,
			sizeof(keepalive));
	if (retval != 0) {
		perror("setsockopt: keepalive");
	}
}

/*********************************************************************************************
 *��   ��   ����sysutil_activate_reuseaddr
 *��        �ܣ������׽ӿں�һ������ʹ���еĵ�ַ����
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
void sysutil_activate_reuseaddr(int fd) {
	int reuseaddr = 1;
	int retval = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr,
			sizeof(reuseaddr));
	if (retval != 0) {
		perror("setsockopt: reuseaddr");
	}
}

/*********************************************************************************************
 *��   ��   ����sysutil_set_nodelay
 *��        �ܣ���ֹ���ͺϲ���Nagle�㷨
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
void sysutil_set_nodelay(int fd) {
	int nodelay = 1;
	int retval = setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &nodelay,
			sizeof(nodelay));
	if (retval != 0) {
		perror("setsockopt: nodelay");
	}
}

/*********************************************************************************************
 *��   ��   ����sysutil_activate_oobinline
 *��        �ܣ��ڳ����������н��մ�������
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
void sysutil_activate_oobinline(int fd) {
	int oob_inline = 1;
	int retval = setsockopt(fd, SOL_SOCKET, SO_OOBINLINE, &oob_inline,
			sizeof(oob_inline));
	if (retval != 0) {
		perror("setsockopt: oobinline");
	}
}
/*********************************************************************************************
 *��   ��   ����sysutil_set_iptos_throughput
 *��        �ܣ���IPͷ������ѡ��
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
void sysutil_set_iptos_throughput(int fd) {
	int tos = IPTOS_THROUGHPUT;
	/* Ignore failure to set (maybe this IP stack demands privilege for this) */
	(void) setsockopt(fd, IPPROTO_IP, IP_TOS, &tos, sizeof(tos));
}
/*********************************************************************************************
 *��   ��   ����sysutil_activate_linger
 *��        �ܣ���ر�ʱ��δ�������ݣ�����
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
void sysutil_activate_linger(int fd) {
	int retval;
	struct linger the_linger;
	memset(&the_linger, 0x00, sizeof(the_linger));
	the_linger.l_onoff = 1;
	the_linger.l_linger = 32767;
	retval = setsockopt(fd, SOL_SOCKET, SO_LINGER, &the_linger,
			sizeof(the_linger));
	if (retval != 0) {
		perror("setsockopt: linger");
	}
}
/*********************************************************************************************
 *��   ��   ����sysutil_deactivate_linger_failok
 *��        �ܣ���ر�ʱ��δ�������ݣ�����
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
void sysutil_deactivate_linger_failok(int fd) {
	struct linger the_linger;
	the_linger.l_onoff = 0;
	the_linger.l_linger = 0;
	(void) setsockopt(fd, SOL_SOCKET, SO_LINGER, &the_linger,
			sizeof(the_linger));
}

/*********************************************************************************************
 *��   ��   ����sysutil_activate_sigurg
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
void sysutil_activate_sigurg(int fd) {
	int retval = fcntl(fd, F_SETOWN, getpid());
	if (retval != 0) {
		perror("fcntl");
	}
}

/*********************************************************************************************
 *��   ��   ����sysutil_activate_noblock
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
void sysutil_activate_noblock(int fd) {
	int retval;
	int curr_flags = fcntl(fd, F_GETFL);
	if (curr_flags < 0) {
		perror("fcntl");
	}
	curr_flags |= O_NONBLOCK;
	retval = fcntl(fd, F_SETFL, curr_flags);
	if (retval != 0) {
		perror("fcntl");
	}
}
/*********************************************************************************************
 *��   ��   ����sysutil_deactivate_noblock
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
void sysutil_deactivate_noblock(int fd) {
	int retval;
	int curr_flags = fcntl(fd, F_GETFL);
	if (curr_flags < 0) {
		perror("fcntl");
	}
	curr_flags &= ~O_NONBLOCK;
	retval = fcntl(fd, F_SETFL, curr_flags);
	if (retval != 0) {
		perror("fcntl");
	}
}
/*********************************************************************************************
 *��   ��   ����sysutil_recv_peek
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_recv_peek(const int fd, void* p_buf, unsigned int len) {
	while (1) {
		int retval = recv(fd, p_buf, len, MSG_PEEK);
		if (retval < 0) {
			continue;
		}
		return retval;
	}
}

/*********************************************************************************************
 *��   ��   ����sysutil_get_ipv4_sock
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_get_ipv4_sock(void) {
	int retval = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (retval < 0) {
		perror("sysutil_get_ipv4_sock");
	}
	return retval;
}

/*********************************************************************************************
 *��   ��   ����sysutil_get_ipv6_sock
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_bind(int fd, const int port) {
	struct sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	return bind(fd, (struct sockaddr*) &addr, sizeof(addr));
}

/*********************************************************************************************
 *��   ��   ����sysutil_get_ipv6_sock
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_listen(int fd, const unsigned int backlog) {
	return listen(fd, backlog);
}


/*********************************************************************************************
 *��   ��   sysutil_dns_resolve
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_dns_resolve(char *ip, const unsigned int max, const char * host)
{
	struct hostent* hent = (struct hostent*)gethostbyname(host); //���ض�Ӧ�ڸ����������İ����������ֺ͵�ַ��Ϣ��hostent�ṹָ��
	if (hent != NULL){
		strcpy(ip, inet_ntoa(*(struct in_addr *)hent->h_addr_list[0]));
		//strcpy(ip, inet_ntoa((unsigned int *)hent->h_addr_list[0]));
	}
	else{
		strcat(ip, host);
	}
	return 0;
}

/*********************************************************************************************
 *��   ��   ����sysutil_accept_timeout
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_accept_timeout(int fd, struct sockaddr_in* p_sockaddr,
		unsigned int wait_seconds) {
	int retval;
	int saved_errno;
	fd_set accept_fdset;
	struct timeval timeout;
	unsigned int socklen = sizeof(struct sockaddr_in);
	if (wait_seconds > 0) {
		FD_ZERO(&accept_fdset);
		FD_SET(fd, &accept_fdset);
		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;
		do {
			retval = select(fd + 1, &accept_fdset, NULL, NULL, &timeout);
			saved_errno = errno;
		} while (retval < 0 && saved_errno == EINTR);
		if (retval == 0) {
			errno = EAGAIN;
			return -1;
		}
	}
	retval = accept(fd, (struct sockaddr*) p_sockaddr, &socklen);
	return retval;
}

/*********************************************************************************************
 *��   ��   ����sysutil_connect_timeout
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_connect_timeout(int fd, const char* ip, const unsigned int port,
		unsigned int wait_seconds) {
	unsigned int addrlen = 0;
	int retval;
	int saved_errno;

	struct sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(port);
	sockaddr.sin_addr.s_addr = inet_addr(ip);
	addrlen = sizeof(sockaddr);
	if (wait_seconds > 0) {
		sysutil_activate_noblock(fd);
	}
	retval = connect(fd, (struct sockaddr*) &sockaddr, addrlen);
	if (retval < 0 && errno == EINPROGRESS) {
		fd_set connect_fdset;
		struct timeval timeout;
		FD_ZERO(&connect_fdset);
		FD_SET(fd, &connect_fdset);
		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;
		do {
			retval = select(fd + 1, NULL, &connect_fdset, NULL, &timeout);
			saved_errno = errno;
		} while (retval < 0 && saved_errno == EINTR);
		if (retval == 0) {
			retval = -1;
			errno = EAGAIN;
		} else {
			socklen_t socklen = sizeof(retval);
			int sockoptret = getsockopt(fd, SOL_SOCKET, SO_ERROR, &retval,
					&socklen);
			if (sockoptret != 0 || retval) {
				retval = -1;
			}
		}
	}
	if (wait_seconds > 0) {
		sysutil_deactivate_noblock(fd);
	}
	return retval;
}

/*********************************************************************************************
 *��   ��   ����sysutil_read
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_read(const int fd, void* p_buf, const unsigned int size) {
	while (1) {
		int retval = read(fd, p_buf, size);
		int saved_errno = errno;
		if (retval < 0 && saved_errno == EINTR) {
			continue;
		}
		return retval;
	}
}

/*********************************************************************************************
 *��   ��   ����sysutil_read_timeout
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_read_timeout(const int fd, void* p_buf, const unsigned int size,
		unsigned int wait_seconds) {
	//if (wait_seconds > 0) {
	//	sysutil_activate_noblock(fd);
	//}
	fd_set fdset;
	struct timeval timeout;
	FD_ZERO(&fdset);
	FD_SET(fd, &fdset);
	timeout.tv_sec = wait_seconds;
	timeout.tv_usec = 0;

	int retval = select(fd + 1, NULL, &fdset, NULL, &timeout);
	if ((retval > 0) && (FD_ISSET(fd, &fdset))) {
		printf("*******************\n");
		retval = sysutil_read(fd, p_buf, size);
	} else {
		printf("*******************\n");
		retval = -1;
	}
	//if (wait_seconds > 0) {
	//	sysutil_deactivate_noblock(fd);
	//}
	return retval;
}

/*********************************************************************************************
 *��   ��   ����sysutil_write
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_write(const int fd, const void* p_buf, const unsigned int size) {
	while (1) {
		int retval = write(fd, p_buf, size);
		int saved_errno = errno;
		if (retval < 0 && saved_errno == EINTR) {
			continue;
		}
		return retval;
	}
}

/*********************************************************************************************
 *��   ��   ����sysutil_read_loop
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_read_loop(const int fd, void* p_buf, unsigned int size) {
	int retval;
	int num_read = 0;
	while (1) {
		retval = sysutil_read(fd, (char*) p_buf + num_read, size);
		if (retval < 0) {
			return retval;
		} else if (retval == 0) {
			/* Read all we're going to read.. */
			return num_read;
		}
		if ((unsigned int) retval > size) {
			perror("retval too big in sysutil_read_loop");
			return -1;
		}
		num_read += retval;
		size -= (unsigned int) retval;
		if (size == 0) {
			/* Hit the read target, cool. */
			return num_read;
		}
	}
}

/*********************************************************************************************
 *��   ��   ����sysutil_write_loop
 *��        �ܣ�
 *��        �룺
 *
 *��        ����
 *��        �أ�RT_OK���ɹ���RT_NG��ʧ��
 *�� ��  �� ¼��NONE
 *********************************************************************************************/
int sysutil_write_loop(const int fd, const void* p_buf, unsigned int size) {
	int retval;
	int num_written = 0;
	while (1) {
		retval = sysutil_write(fd, (const char*) p_buf + num_written, size
				- num_written);
		if (retval < 0) {
			/* Error */
			return retval;
		} else if (retval == 0) {
			/* Written all we're going to write.. */
			return num_written;
		}
		if ((unsigned int) retval > size) {
			perror("retval too big in sysutil_read_loop");
			return -1;
		}
		num_written += retval;
		size -= (unsigned int) retval;
		if (size == 0) {
			/* Hit the write target, cool. */
			return num_written;
		}
	}
}

