///<------------------------------------------------------------------------------
//< @file:   zlib.h
//< @date:   2014��2��27�� 10:17:08
//< @brief:  zlib��������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _zlibpkg_h_
#define _zlibpkg_h_

/****************zlibѹ���ͽ�ѹ************************************************/

/**
  * gzipѹ��
  * @uncompr     : ԭ��
  * @uncompr_len : ԭ������
  * @compr       : ѹ����
  * @compr_len   : ѹ��������
  * @err_msg     : ʧ��ʱ���صĴ�����Ϣ
  * @return      ���ɹ�����0�������ʾʧ��
  */
int gzcompress(const char *uncompr, unsigned int uncompr_len, char *compr, unsigned int *compr_len, char **err_msg);

/**
  * gzip��ѹ
  * @compr       : ѹ����
  * @compr_len   : ѹ��������
  * @uncompr     : ԭ��
  * @uncompr_len : ԭ������
  * @err_msg     : ʧ��ʱ���صĴ�����Ϣ
  * @return      : �ɹ�����0�������ʾʧ��
  */
int gzdecompress(const char *compr, unsigned int compr_len, char *uncompr, unsigned int *uncompr_len, char **err_msg);

/**
  * htttpgzip��ѹ
  * @compr       : ѹ����
  * @compr_len   : ѹ��������
  * @uncompr     : ԭ��
  * @uncompr_len : ԭ������
  * @err_msg     : ʧ��ʱ���صĴ�����Ϣ
  * @return      : �ɹ�����0�������ʾʧ��
  */
int httpgzdecompress(const char *compr, unsigned int compr_len, char *uncompr, unsigned int *uncompr_len, char **err_msg);

/****************zlibѹ���ͽ�ѹ************************************************/

#endif //_zlibpkg_h_