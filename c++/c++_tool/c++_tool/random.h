/********************************************************************
            Copyright (c) 2010, �������߹�����
                   All rights reserved
         
    �������ڣ�  2010��4��6�� 20ʱ16��
    �ļ����ƣ�  Random.hpp
    ˵    ����  �����������     
    
    ��ǰ�汾��  1.00
    ��    �ߣ�  SiZhi Huang
    ��    ����  ����    

*********************************************************************/
#pragma once

namespace nsTool
{
	class RandomGen
	{
	public:
		RandomGen();
		virtual ~RandomGen();

		// ��������
		unsigned int getRand();

		// ��ȡ[0-uiMax)����������
		unsigned int getRand(unsigned int uiMax);

		unsigned int getRandMax();

		// ��ȡ[0-iMax)����������
		int getRandInt(int iMax);

		// ��ȡ���float[0-fRangle);
		float getRandFloat(float fRangle);

		// ��̬�ֲ�[��ֵ,���]
		double gaussian(double mu, double sigma);
		int gaussian(int mu, unsigned int sigma, unsigned int rangle);
		int gaussianHalf(int mu, unsigned int sigma, unsigned int rangle);
	};
}
