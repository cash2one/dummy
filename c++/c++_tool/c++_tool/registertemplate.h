/********************************************************************
            Copyright (c) 2010, �������߹�����
                   All rights reserved
         
    �������ڣ�  2010��5��31�� 18ʱ04��
    �ļ����ƣ�  RegisterTemplate.h
    ˵    ����  ע����ģ��,���ڳ��õ��¼��۲��ߵ�ע��     
    
    ��ǰ�汾��  1.00
    ��    �ߣ�  Sizhi Huang
    ��    ����  ����    

*********************************************************************/
#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;

//#define SZFrame_RegistDelay
#define SZFrame_UnRegistDelay

template<typename RegT>
class VectorRegister
{
public:
	typedef typename std::vector<RegT*> RegTContainer;
	typedef typename std::vector<RegT*>::iterator RegTContainerItor;
	VectorRegister() : m_bNeedTidy(false) {}
	virtual ~VectorRegister() {};

	bool RegListener(RegT *pRegT);
	bool UnRegListener(RegT *pRegT);

protected:
	void tidy();

	virtual void onRegListener(RegT *) {};
	virtual void onUnRegListener(RegT *) {};

	bool isEmpty();

protected:
	RegTContainer m_RegTContainer;

private:
	// �Ƿ���Ҫ����
	bool m_bNeedTidy;
};

template<typename RegT>
bool VectorRegister<RegT>::isEmpty() {
	tidy();
	return m_RegTContainer.empty();
}

template<typename RegT>
void VectorRegister<RegT>::tidy() {
	if (!m_bNeedTidy) {
		return;
	}

	RegTContainerItor iter = m_RegTContainer.begin();
	for (; iter != m_RegTContainer.end(); ) {
		if (NULL != (*iter)) {
			++iter;
		} else {
			iter = m_RegTContainer.erase(iter);
		}
	}

	m_bNeedTidy = false;
}

template<typename RegT>
bool  VectorRegister<RegT>::UnRegListener(RegT *pRegT) {
	for (RegTContainerItor iter= m_RegTContainer.begin(); iter != m_RegTContainer.end(); ++iter) {
		if ((*iter) == pRegT) {

			(*iter) = NULL;
			m_bNeedTidy = true;
			break;
		}
	}
	return m_bNeedTidy;
}

template<typename RegT>
bool VectorRegister<RegT>::RegListener(RegT *pRegT) {
	for (RegTContainerItor iter= m_RegTContainer.begin(); iter != m_RegTContainer.end(); ++iter) {
		if ((*iter) == pRegT) {
			return false;
		}
	}
	m_RegTContainer.push_back(pRegT);
	return true;
}

template<typename RegT>
class SingleRegister
{
	typedef bool IsUsing;
	typedef typename std::set<RegT*> RegTWaitLst;
public:
	typedef typename std::map<RegT*, IsUsing> RegTContainer;
	typedef typename RegTContainer::iterator RegTContaineriterator;
	//typedef std::map<RegT*, IsUsing>::iterator RegTContainerItor;
public:
	SingleRegister();
	virtual ~SingleRegister() {};


	void regListener(RegT *pRegT);

	bool unRegListener(RegT *pRegT);

protected:

	virtual void onRegListener(RegT *) {};

	virtual void onUnRegListener(RegT *) {};

	void tidy();

#ifdef SZFrame_RegistDelay
	void regWaiting();
#endif

	bool isEmpty();

// 	//friend SingleRegister<RegT>::merge(const SingleRegister<RegT> &rOther);
// 	friend void merge(const SingleRegister<RegT> &rOther) {
// 
// #ifdef SZFrame_RegistDelay
// 		m_WaitRegLst.merge(rOther.m_WaitRegLst);
// #endif // SZFrame_RegistDelay
// 
// 		m_RegTContainer.merge(rOther.m_RegTContainer);
// 
// #ifdef SZFrame_RegistDelay
// 		regWaiting();
// #endif // SZFrame_RegistDelay
// 
// 	}

protected:
	RegTContainer m_RegTContainer;
#ifdef SZFrame_RegistDelay
	RegTWaitLst m_WaitRegLst;
#endif // SZFrame_RegistDelay

private:
	bool m_bNeedTidy;


};

template<typename RegT>
SingleRegister<RegT>::SingleRegister() : m_bNeedTidy(false) {

}

template<typename RegT>
bool SingleRegister<RegT>::isEmpty() {
#ifdef SZFrame_RegistDelay
	regWaiting();
#endif // SZFrame_RegistDelay
	tidy();
	return m_RegTContainer.empty();
}

#ifdef SZFrame_RegistDelay
template<typename RegT>
void SingleRegister<RegT>::regWaiting() {
	RegTWaitLst::iterator iter = m_WaitRegLst.begin();
	RegTWaitLst::iterator iterEnd = m_WaitRegLst.end();
	for (; iter != iterEnd; ++iter) {
		m_RegTContainer[*iter] = true;
	}
	m_WaitRegLst.clear();
}
#endif // SZFrame_RegistDelay

//template<typename RegT>
//void SingleRegister<RegT>::merge(const SingleRegister<RegT> &rOther) {
//#ifdef SZFrame_RegistDelay
//	m_WaitRegLst.merge(rOther.m_WaitRegLst);
//#endif // SZFrame_RegistDelay
//	m_RegTContainer.merge(rOther.m_RegTContainer);
//#ifdef SZFrame_RegistDelay
//	regWaiting();
//#endif // SZFrame_RegistDelay
//}

template<typename RegT>
void SingleRegister<RegT>::tidy() {
	if (!m_bNeedTidy) {
		return;
	}

	RegTContaineriterator iter = m_RegTContainer.begin();
	for (; iter != m_RegTContainer.end(); ) {
		if (iter->second) {
			++iter;
		} else {
			m_RegTContainer.erase(iter++);
		}
	}
	m_bNeedTidy = false;
}

template<typename RegT>
bool SingleRegister<RegT>::unRegListener(RegT *pRegT) {
#ifdef SZFrame_RegistDelay
	RegTWaitLst::iterator iterWait = m_WaitRegLst.find(pRegT);
	if (m_WaitRegLst.end() != iterWait) {
		m_WaitRegLst.erase(pRegT);
	}
#endif // SZFrame_RegistDelay

	RegTContaineriterator iterFound = m_RegTContainer.find(pRegT);
	if (m_RegTContainer.end() != iterFound) {

#ifdef SZFrame_UnRegistDelay
		iterFound->second = false;
		m_bNeedTidy = true;
#else
		m_RegTContainer.erase(iterFound);
#endif // SZFrame_UnRegistDelay

	}

	onUnRegListener(pRegT);
	return m_bNeedTidy;
}

template<typename RegT>
void SingleRegister<RegT>::regListener(RegT *pRegT) {
#ifdef SZFrame_RegistDelay
	m_WaitRegLst.insert(pRegT);
#else
	m_RegTContainer[pRegT] = true;
#endif // SZFrame_RegistDelay

	onRegListener(pRegT);
}

template<typename RegT>
class ComboVecRegister : public VectorRegister<RegT>
{
public:
	typedef typename std::vector<RegT*> RegTContainer;
	typedef typename std::vector<RegT*>::iterator RegTContainerItor;
public:
	RegTContainer &getRegList(){
		return VectorRegister<RegT>::m_RegTContainer;
	}
	void tidy();

	void clear();

	void regListener(RegT *pRegT) ;

	bool unRegListener(RegT *pRegT);
};
// 
// template<typename RegT>
// ComboVecRegister<RegT>::RegTContainer ComboVecRegister<RegT>::getRegList() {
// 	return m_RegTContainer;
// }

template<typename RegT>
void ComboVecRegister<RegT>::tidy() {
	VectorRegister<RegT>::tidy();
}

template<typename RegT>
void ComboVecRegister<RegT>::clear() {
	VectorRegister<RegT>::m_RegTContainer.clear();
}

template<typename RegT>
void ComboVecRegister<RegT>::regListener(RegT *pRegT) {
	VectorRegister<RegT>::RegListener(pRegT);
}

template<typename RegT>
bool ComboVecRegister<RegT>::unRegListener(RegT *pRegT) { 
	return VectorRegister<RegT>::UnRegListener(pRegT);
}

template<typename RegT>
class ComboSGRegister : public SingleRegister<RegT>
{
public:
	typedef bool IsUsing;
	typedef typename std::map<RegT*, IsUsing> RegTContainer;
	typedef typename RegTContainer::iterator RegTContaineriterator;
public:
	RegTContainer &getRegList() { return SingleRegister<RegT>::m_RegTContainer; }
	void tidy() {
		SingleRegister<RegT>::tidy();
	}

	// ��ռ�������
	void clear() {SingleRegister<RegT>::m_RegTContainer.clear();}
};

// ����ע����
// template<typename RegKeyT, typename RegT, template <typename> class ComboRegsterT = ComboVecRegister >
// class MultiRegister
// {
// protected:
// 	typedef typename ComboRegsterT<typename RegT> RegTSGRegister;
// 	//typedef SingleRegister<RegT> RegTSGRegister;
// 	typedef typename std::map<typename RegKeyT, typename RegTSGRegister> RegTMultiContainer;
// 
// #ifdef SZFrame_RegistDelay
// 	struct WaitRegT
// 	{
// 		RegKeyT regkey;
// 		RegT *pRegT;
// 	};
// 	typedef typename vector<WaitRegT> RegTWaitLst;
// 	typedef typename RegTWaitLst::iterator RegTWaitLstIterator;
// #endif // SZFrame_RegistDelay
// 	typedef typename RegTMultiContainer::iterator RegTMultiContainerIterator;
// 
// public:
// 	virtual ~MultiRegister() {};
// 
// 	// ע�����
// 	void regListener(RegKeyT regkey, RegT *pRegT);
// 	// ��ע�������
// 	bool unRegListener(RegKeyT regkey, RegT *pRegT);
// 	bool unRegListener(RegT *pRegT);
// 
// protected:
// 	// ע�����
// 	virtual void onRegListener(RegKeyT , RegT *) {};
// 	// ��ע�������
// 	virtual void onUnRegListener(RegKeyT , RegT *) {};
// 	virtual void onUnRegListener(RegT *) {};
// 
// 	// ������Ч������
// 	void tidy();
// 	// �Ƿ�Ϊ��
// 	bool isEmpty();
// 
// #ifdef SZFrame_RegistDelay
// 	// ע��ȴ�Ԫ��
// 	void regWaiting();
// #endif // SZFrame_RegistDelay
// 
// protected:
// 	RegTMultiContainer m_RegTMultiContainer;
// 
// #ifdef SZFrame_RegistDelay
// 	RegTMultiContainer m_WaitRegLst;
// #endif // SZFrame_RegistDelay
// 
// 	// �Ƿ���Ҫ����
// 	bool m_bNeedTidy;
// };
// 
// template<typename RegKeyT, typename RegT, template <typename> class RegsterT>
// bool MultiRegister<RegKeyT, RegT, RegsterT>::isEmpty() {
// 	tidy();
// 
// #ifdef SZFrame_RegistDelay
// 	regWaiting();
// #endif // SZFrame_RegistDelay
// 
// 	return m_RegTMultiContainer.empty();
// }
// 
// template<typename RegKeyT, typename RegT, template <typename> class RegsterT>
// void MultiRegister<RegKeyT, RegT, RegsterT>::tidy() {
// 	if (!m_bNeedTidy) {
// 		return;
// 	}
// 
// 	RegTMultiContainerIterator iter = m_RegTMultiContainer.begin();
// 	for (; iter != m_RegTMultiContainer.end(); ) {
// 		RegTSGRegister &rRegTSGRegister = iter->second;
// 		if (rRegTSGRegister.isEmpty()) {
// 			m_RegTMultiContainer.erase(iter++);
// 		} else {
// 			++iter;
// 		}
// 	}
// 
// 	// �������
// 	m_bNeedTidy = false;
// }
// 
// #ifdef SZFrame_RegistDelay
// template<typename RegKeyT, typename RegT>
// void MultiRegister<RegKeyT, RegT>::regWaiting() {
// 	RegTWaitLstIterator iter = m_WaitRegLst.begin();
// 	RegTWaitLstIterator iterEnd = m_WaitRegLst.end();
// 	for (; iter != iterEnd; ++iter) {
// 		m_RegTMultiContainer[iter->regkey].regListener(iter->pRegT);
// 	}
// 	m_WaitRegLst.clear();
// }
// #endif // SZFrame_RegistDelay
// 
// template<typename RegKeyT, typename RegT, template <typename> class RegsterT>
// bool MultiRegister<RegKeyT, RegT, RegsterT>::unRegListener(RegKeyT regkey, RegT *pRegT) {
// 	RegTMultiContainerIterator iterFound = m_RegTMultiContainer.find(regkey);
// 	if (m_RegTMultiContainer.end() == iterFound) {
// 		return false;
// 	}
// 
// 	RegTSGRegister &rRegTSGRegister = iterFound->second;
// 	// ��������
// 	m_bNeedTidy = rRegTSGRegister.unRegListener(pRegT);
// 	onUnRegListener(regkey, pRegT);
// 	return m_bNeedTidy;
// }
// 
// template<typename RegKeyT, typename RegT, template <typename> class RegsterT>
// bool MultiRegister<RegKeyT, RegT, RegsterT>::unRegListener(RegT *pRegT) {
// 	RegTMultiContainerIterator iter = m_RegTMultiContainer.begin();
// 	RegTMultiContainerIterator iterEnd = m_RegTMultiContainer.end();
// 	for (; iter != iterEnd; ++iter) {
// 		RegTSGRegister &rRegTSGRegister = iter->second;
// 		if (rRegTSGRegister.unRegListener(pRegT)) {
// 			m_bNeedTidy = true;
// 		}
// 	}
// 
// 	onUnRegListener(pRegT);
// 	return m_bNeedTidy;
// }
// 
// template<typename RegKeyT, typename RegT, template <typename> class RegsterT>
// void MultiRegister<RegKeyT, RegT, RegsterT>::regListener(RegKeyT regkey, RegT *pRegT) {
// 
// #ifdef SZFrame_RegistDelay
// 	m_WaitRegLst[regkey].regListener(pRegT);
// #else
// 	m_RegTMultiContainer[regkey].regListener(pRegT);
// #endif // SZFrame_RegistDelay
// 
// 	onRegListener(regkey, pRegT);
// }
// 
