#ifndef __SD_CSVFILE_H_
#define __SD_CSVFILE_H_
#include "sdtype.h"
#include <vector>
#include <string>
#include "sdstring.h"
using namespace std;
namespace SGDP 
{
    /**
    * @brief ��������������ַ�������
    *        falfj     afljslf       aldfj
             alfdlasf  oeeofljdfls   adljldo   sdf;sdfk
             aldjl     aldfjolsdf    ljoewrjjls
    */
	class  CSDCsvBase
	{
	public:

		/**
		* @brief ���캯��
		*/
		CSDCsvBase(){}

		/**
		* @brief ��������
		*/
		~CSDCsvBase(){}

        /**
        * @brief �����������������m_vLine��СΪ0
        * @return VOID
        */
		VOID    Clear()
        {
            m_vLine.resize(0);
        }

        /*
        * @brief ����еĸ���
        * @return ����
        */
		INT32 GetLineCount();

        /**
        * @brief ���ָ���е�����
        * @param line : ָ����
        * @return ����
        */
		INT32 GetItemCount(INT32 line);

        /**
        * @brief ��ָ���в���һ������
        * @param line : ָ����
        * @return ����������Ĵ�С
        */
		INT32 InsertLine(INT32 line);

        /**
        * @brief ������β������һ������
        * @return ����������Ĵ�С
        */
		INT32 AddLine();

        /**
        * @brief ��ָ���С�ָ�����в���һ������
        * @param line : ָ����
        * @param item : ָ����
        * @param data : �����������
        * @return �����ǰ�е�����
        */
		INT32 InsertItem(INT32 line, INT32 item, const TCHAR *data);

		/**
        * @brief ɾ��ָ���С�ָ����
        * @param line : ָ����
        * @param item : ָ����
        * @return �ɹ��򷵻�ɾ����ǰ�е����������򷵻�-1
        */
		INT32 DelItem(INT32 line, INT32 item);

		/**
        * @brief ɾ��ָ����
        * @param line : ָ����
        * @return �ɹ��򷵻�ɾ�������������������򷵻�-1
        */
		INT32 DelLine(INT32 line);

		/**
        * @brief ����ָ���С�ָ���е�����Ϊ""
        * @param line : ָ����
        * @param item : ָ����
        * @return �ɹ��򷵻����ú�ǰ�е����������򷵻�-1
        */
		INT32 EmptyItem(INT32 line, INT32 item);

		/**
        * @brief �޸�ָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param data : �޸ĺ������
        * @return �ɹ��򷵻����ú�ǰ�е����������򷵻�-1
        */
		INT32 ModifyItem(INT32 line, INT32 item, const TCHAR *data);

		/**
        * @brief ��ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param data : ���ȡ��������
        * @param size : ָ���С�ָ���е����ݳ���
        * @return �ɹ��򷵻�ʣ����и��������򷵻�-1
        */
		INT32 ReadData(INT32 line, INT32 item, TCHAR *data, INT32 size);

        /**
        * @brief ���¸���T*���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, T* obItem);

		/**
        * @brief ���¸���T&���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, T& obItem);

		/**
        * @brief ���¸���TCHAR&���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, TCHAR& cItem);

		/**
        * @brief ���¸���INT8&���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, UINT8& byItem);

		/**
        * @brief ���¸���INT16&���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, INT16& shItem);

		/**
        * @brief ���¸���UINT16&���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, UINT16& wItem);

		/**
        * @brief ���¸���TINT32&���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, INT32& nItem);

		/**
        * @brief ���¸���UINT32&���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, UINT32& dwItem);

		/**
        * @brief ���¸���float&���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, float& fItem);

		/**
        * @brief ���¸���double&���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, double& fItem);

		/**
        * @brief ���¸���tstring&���ͻ�ȡָ���С�ָ���е�����
        * @param line : ָ����
        * @param item : ָ����
        * @param ?+Item : ����ȡ���Ĳ�ͬ��������
        * @return �ɹ��򷵻�0�����򷵻�-1
        */
		template <typename T>
		INT32 ReadData(INT32 line, INT32 item, tstring& strItem);

	protected:
		std::vector<std::vector<tstring> > m_vLine;
	private:
	};

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, T& obItem )
	{
		return -1;
	}

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, T* obItem )
	{
		return -1;  
	}

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, TCHAR& cItem )
	{
		if (line >= (INT32)m_vLine.size())
		{
			return -1;
		}
		std::vector<tstring> & itemvec = m_vLine[line];
		//get item
		if (item >= (INT32)itemvec.size())
		{
			return -1;
		}

		cItem = _SDTTtoi(itemvec[item].c_str());
		return 0;
	}

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, UINT8& byItem )
	{
		if (line >= (INT32)m_vLine.size())
		{
			return -1;
		}
		std::vector<tstring> & itemvec = m_vLine[line];
		//get item
		if (item >= (INT32)itemvec.size())
		{
			return -1;
		}

		byItem = atoi(_SDTT2A(itemvec[item].c_str()));
		return 0;
	}

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, INT16& shItem )
	{
		if (line >= (INT32)m_vLine.size())
		{
			return -1;
		}
		std::vector<tstring> & itemvec = m_vLine[line];
		//get item
		if (item >= (INT32)itemvec.size())
		{
			return -1;
		}

		shItem = _SDTTtoi(itemvec[item].c_str());
		return 0;
	}

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, UINT16& wItem )
	{
		if (line >= (INT32)m_vLine.size())
		{
			return -1;
		}
		std::vector<tstring> & itemvec = m_vLine[line];
		//get item
		if (item >= (INT32)itemvec.size())
		{
			return -1;
		}

		wItem = _SDTTtoi(itemvec[item].c_str());
		return 0;
	}

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, INT32& nItem )
	{
		if (line >= (INT32)m_vLine.size())
		{
			return -1;
		}
		std::vector<tstring> & itemvec = m_vLine[line];
		//get item
		if (item >= (INT32)itemvec.size())
		{
			return -1;
		}

		nItem = _SDTTtoi(itemvec[item].c_str());
		return 0;
	}

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, UINT32& dwItem )
	{
		if (line >= (INT32)m_vLine.size())
		{
			return -1;
		}
		std::vector<tstring> & itemvec = m_vLine[line];
		//get item
		if (item >= (INT32)itemvec.size())
		{
			return -1;
		}

		dwItem = _SDTTtoi(itemvec[item].c_str());
		return 0;
	}

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, float& fItem )
	{
		if (line >= (INT32)m_vLine.size())
		{
			return -1;
		}
		std::vector<tstring> & itemvec = m_vLine[line];
		//get item
		if (item >= (INT32)itemvec.size())
		{
			return -1;
		}

		fItem = static_cast<float>(atof(_SDTT2A(itemvec[item].c_str())));
		return 0;
	}

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, double& fItem )
	{
		if (line >= (INT32)m_vLine.size())
		{
			return -1;
		}
		std::vector<tstring> & itemvec = m_vLine[line];
		//get item
		if (item >= (INT32)itemvec.size())
		{
			return -1;
		}

		fItem = atof(_SDTT2A(itemvec[item].c_str()));
		return 0;
	}

	template <typename T>
	INT32 CSDCsvBase::ReadData( INT32 line, INT32 item, tstring& strItem )
	{
		if (line >= (INT32)m_vLine.size())
		{
			return -1;
		}
		std::vector<std::string> & itemvec = m_vLine[line];
		//get item
		if (item >= (INT32)itemvec.size())
		{
			return -1;
		}

		strItem = itemvec[item];
		return 0;
	}

	class CSDCsvString:public CSDCsvBase
	{
		/*
		�ַ�����ʽ:
		{.,..,...,...}...{.,..,...,...}
		*/
	public:

		/**
		* @brief ���캯��
		*/
		CSDCsvString(){}

		/**
		* @brief ��������
		*/
		~CSDCsvString(){}

        /**
        * @brief ���ݸ�����ʽ���ַ�����ʼ������
        * @param strData : �ַ�������
        * @return �����Ĵ�С
        */
		INT32 Init(const tstring& strData);

        /**
        * @brief ����ַ�������
        * @return 0
        */
		INT32 FlushData(tstring& strOutPut);
	};

	class CSDCsvfile:public CSDCsvBase
	{
	public:

		/**
		* @brief ���캯��
		*/
		CSDCsvfile(){}

		/**
		* @brief ��������
		*/
		~CSDCsvfile(){}

		/**
        * @brief �����ļ�·����ȡ������ʽ���ַ�������ʼ������
        * @param path : csv�ļ�·��
        * @return �ɹ��򷵻������Ĵ�С�����򷵻�-1
        */
		INT32 Init(const TCHAR *path);

		/**
        * @brief �������е�����������ļ���
        * @return �ɹ��򷵻�1�����򷵻�-1
        */
		INT32 FlushData();

        /**
        * @brief ��������ָ���С�ָ�����ж�ȡ�ַ�����obCsvString��
        * @param line : ָ����
        * @param item : ָ����
        * @param obCsvString : �����ȡ���ַ���
        * @return �ɹ��򷵻�������С�����򷵻�-1
        */
		INT32 ReadCsvString(INT32 line, INT32 item, CSDCsvString& obCsvString);

	private:
		//file path
		tstring m_strFilePath;
	};
}
#endif //#ifndef _CSVFILE_H_

