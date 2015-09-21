///<------------------------------------------------------------------------------
//< @file:   server\basic\bind.h
//< @author: ������
//< @date:   2015��4��10�� 18:11:9
//< @brief:	 ģ����boost��bind�����ļ��󲿷���������fflib�е�bind��
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _bind_h_
#define _bind_h_

typedef void (*taskFunc)(void*);

class ITask
{
public:
	virtual ~ITask() {}
	virtual void run()    = 0;
	virtual ITask* clone() = 0;
};

class TaskFunction: public ITask
{
public:
	TaskFunction(taskFunc func, void* arg):
		m_func(func),
		m_arg(arg)
	{}

	virtual void run()
	{
		m_func(m_arg);
	}

	virtual ITask* clone()
	{
		return new TaskFunction(m_func, m_arg);
	}

protected:
	taskFunc m_func;
	void*       m_arg;
};

struct Task {
	static void dummy(void*) {}

	Task(taskFunc func, void* arg):
		m_task(new TaskFunction(func, arg))
	{}

	Task(ITask* task):
		m_task(task)
	{}

	Task(const Task& src):
		m_task(src.m_task->clone())
	{}

	Task()
		: m_task(NULL)
	{
		// m_task = new TaskFunction(&Task::dummy, NULL);
	}

	~Task()
	{
		delete m_task;
	}

	Task& operator=(const Task& src)
	{
		delete m_task;
		m_task = src.m_task->clone();
		return *this;
	}

	void run()
	{
		if (m_task) {
			m_task->run();
		}
	}

	ITask* m_task;
};

namespace bindtool
{
// �����Ա����
	template<typename RET>
	struct Task_0 {
		static void task_func(void* p_)
		{
			(*(RET(*)(void))p_)();
		};
	};

	template<typename FUNCT, typename ARG1>
	struct Task_1: public ITask {
		Task_1(FUNCT func, const ARG1& arg1_):
			m_func(func),
			arg1(arg1_)
		{}
		virtual void run() {(*m_func)(arg1);}
		virtual ITask* clone() {return new Task_1(m_func, arg1);}

		FUNCT m_func;
		ARG1  arg1;
	};

	template<typename FUNCT, typename ARG1, typename ARG2>
	struct Task_2: public ITask {
		Task_2(FUNCT func, const ARG1& arg1_, const ARG2& arg2_):
			m_func(func),
			arg1(arg1_),
			arg2(arg2_)
		{}
		virtual void run() {(*m_func)(arg1, arg2);}
		virtual ITask* clone() {return new Task_2(m_func, arg1, arg2);}

		FUNCT m_func;
		ARG1 arg1;
		ARG2 arg2;
	};

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3>
	struct Task_3: public ITask {
		Task_3(FUNCT func, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_):
			m_func(func),
			arg1(arg1_),
			arg2(arg2_),
			arg3(arg3_)
		{}
		virtual void run() {(*m_func)(arg1, arg2, arg3);}
		virtual ITask* clone() {return new Task_3(m_func, arg1, arg2, arg3);}

		FUNCT m_func;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
	};

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
	struct Task_4: public ITask {
		Task_4(FUNCT func, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_):
			m_func(func),
			arg1(arg1_),
			arg2(arg2_),
			arg3(arg3_),
			arg4(arg4_)
		{}
		virtual void run() {(*m_func)(arg1, arg2, arg3, arg4);}
		virtual ITask* clone() {return new Task_4(m_func, arg1, arg2, arg3, arg4);}

		FUNCT m_func;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
	};

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
	struct Task_5: public ITask {
		Task_5(FUNCT func, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_,
		       const ARG5& arg5_):
			m_func(func),
			arg1(arg1_),
			arg2(arg2_),
			arg3(arg3_),
			arg4(arg4_),
			arg5(arg5_)
		{}
		virtual void run() {(*m_func)(arg1, arg2, arg3, arg4, arg5);}
		virtual ITask* clone() {return new Task_5(m_func, arg1, arg2, arg3, arg4, arg5);}

		FUNCT m_func;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
		ARG5 arg5;
	};

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
	struct Task_6: public ITask {
		Task_6(FUNCT func,
		       const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_,
		       const ARG5& arg5_, const ARG6& arg6_):
			m_func(func),
			arg1(arg1_),
			arg2(arg2_),
			arg3(arg3_),
			arg4(arg4_),
			arg5(arg5_),
			arg6(arg6_)
		{}
		virtual void run() {(*m_func)(arg1, arg2, arg3, arg4, arg5, arg6);}
		virtual ITask* clone() {return new Task_6(m_func, arg1, arg2, arg3, arg4, arg5, arg6);}

		FUNCT m_func;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
		ARG5 arg5;
		ARG6 arg6;
	};

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
	struct Task_7: public ITask {
		Task_7(FUNCT func, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_,
		       const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_):
			m_func(func),
			arg1(arg1_),
			arg2(arg2_),
			arg3(arg3_),
			arg4(arg4_),
			arg5(arg5_),
			arg6(arg6_),
			arg7(arg7_)
		{}
		virtual void run() {(*m_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);}
		virtual ITask* clone() {return new Task_7(m_func, arg1, arg2, arg3, arg4, arg5, arg6, arg7);}

		FUNCT m_func;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
		ARG5 arg5;
		ARG6 arg6;
		ARG7 arg7;
	};

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
	struct Task_8: public ITask {
		Task_8(FUNCT func,
		       const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_,
		       const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_, const ARG8& arg8_)
			: m_func(func),
			  arg1(arg1_),
			  arg2(arg2_),
			  arg3(arg3_),
			  arg4(arg4_),
			  arg5(arg5_),
			  arg6(arg6_),
			  arg7(arg7_),
			  arg8(arg8_)
		{}
		virtual void run() {(*m_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);}
		virtual ITask* clone() {return new Task_8(m_func, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);}

		FUNCT m_func;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
		ARG5 arg5;
		ARG6 arg6;
		ARG7 arg7;
		ARG8 arg8;
	};

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
	struct Task_9: public ITask {
		Task_9(FUNCT func,
		       const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
		       const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_,
		       const ARG7& arg7_, const ARG8& arg8_, const ARG9& arg9_)
			: m_func(func),
			  arg1(arg1_),
			  arg2(arg2_),
			  arg3(arg3_),
			  arg4(arg4_),
			  arg5(arg5_),
			  arg6(arg6_),
			  arg7(arg7_),
			  arg8(arg8_),
			  arg9(arg9_)
		{}
		virtual void run() {(*m_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);}
		virtual ITask* clone() {return new Task_9(m_func, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);}

		FUNCT m_func;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
		ARG5 arg5;
		ARG6 arg6;
		ARG7 arg7;
		ARG8 arg8;
		ARG9 arg9;
	};

// ���Ա����
	template<typename T, typename RET>
	struct ClassTask_0: public ITask {
		ClassTask_0(RET (T::*func)(void), T* obj)
			: m_func(func),
			  obj(obj)
		{}
		virtual void run() {(obj->*m_func)();}
		virtual ITask* clone() {return new ClassTask_0(m_func, obj);}

		RET (T::*m_func)(void);
		T* obj;
	};

	template<typename T, typename RET, typename FARG1, typename ARG1>
	struct ClassTask_1: public ITask {
		ClassTask_1(RET (T::*func)(FARG1), T* obj, const ARG1& arg1_)
			: m_func(func),
			  obj(obj),
			  arg1(arg1_)
		{}
		virtual void run() {(obj->*m_func)(arg1);}
		virtual ITask* clone() {return new ClassTask_1(m_func, obj, arg1);}

		RET (T::*m_func)(FARG1);
		T* obj;
		ARG1 arg1;
	};

	template<typename T, typename RET, typename FARG1, typename FARG2, typename ARG1, typename ARG2>
	struct ClassTask_2: public ITask {
		ClassTask_2(RET (T::*func)(FARG1, FARG2), T* obj, const ARG1& arg1_, const ARG2& arg2_)
			: m_func(func),
			  obj(obj),
			  arg1(arg1_),
			  arg2(arg2_)
		{}
		virtual void run() {(obj->*m_func)(arg1, arg2);}
		virtual ITask* clone() {return new ClassTask_2(m_func, obj, arg1, arg2);}

		RET (T::*m_func)(FARG1, FARG2);
		T* obj;
		ARG1 arg1;
		ARG2 arg2;
	};

	template<typename T, typename RET, typename FARG1, typename FARG2, typename FARG3, typename ARG1, typename ARG2, typename ARG3>
	struct ClassTask_3: public ITask {
		ClassTask_3(RET (T::*func)(FARG1, FARG2, FARG3), T* obj, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_)
			: m_func(func),
			  obj(obj),
			  arg1(arg1_),
			  arg2(arg2_),
			  arg3(arg3_)
		{}
		virtual void run() {(obj->*m_func)(arg1, arg2, arg3);}
		virtual ITask* clone() {return new ClassTask_3(m_func, obj, arg1, arg2, arg3);}

		RET (T::*m_func)(FARG1, FARG2, FARG3);
		T* obj;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
	};

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3, typename FARG4,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4>
	struct ClassTask_4: public ITask {
		ClassTask_4(RET (T::*func)(FARG1, FARG2, FARG3, FARG4), T* obj, const ARG1& arg1_, const ARG2& arg2_,
		            const ARG3& arg3_, const ARG4& arg4_)
			: m_func(func),
			  obj(obj),
			  arg1(arg1_),
			  arg2(arg2_),
			  arg3(arg3_),
			  arg4(arg4_)
		{}
		virtual void run() {(obj->*m_func)(arg1, arg2, arg3, arg4);}
		virtual ITask* clone() {return new ClassTask_4(m_func, obj, arg1, arg2, arg3, arg4);}

		RET (T::*m_func)(FARG1, FARG2, FARG3, FARG4);
		T* obj;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
	};

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
	struct ClassTask_5: public ITask {
		ClassTask_5(RET (T::*func)(FARG1, FARG2, FARG3, FARG4, FARG5), T* obj,
		            const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_, const ARG5& arg5_)
			: m_func(func),
			  obj(obj),
			  arg1(arg1_),
			  arg2(arg2_),
			  arg3(arg3_),
			  arg4(arg4_),
			  arg5(arg5_)
		{}
		virtual void run() {(obj->*m_func)(arg1, arg2, arg3, arg4, arg5);}
		virtual ITask* clone() {return new ClassTask_5(m_func, obj, arg1, arg2, arg3, arg4, arg5);}

		RET (T::*m_func)(FARG1, FARG2, FARG3, FARG4, FARG5);
		T* obj;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
		ARG5 arg5;
	};

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5, typename FARG6,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
	struct ClassTask_6: public ITask {
		ClassTask_6(RET (T::*func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6), T* obj, const ARG1& arg1_, const ARG2& arg2_,
		            const ARG3& arg3_, const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_)
			: m_func(func),
			  obj(obj),
			  arg1(arg1_),
			  arg2(arg2_),
			  arg3(arg3_),
			  arg4(arg4_),
			  arg5(arg5_),
			  arg6(arg6_)
		{}
		virtual void run() {(obj->*m_func)(arg1, arg2, arg3, arg4, arg5, arg6);}
		virtual ITask* clone() {return new ClassTask_6(m_func, obj, arg1, arg2, arg3, arg4, arg5, arg6);}

		RET (T::*m_func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6);
		T* obj;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
		ARG5 arg5;
		ARG6 arg6;
	};

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5, typename FARG6, typename FARG7,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
	struct ClassTask_7: public ITask {
		ClassTask_7(RET (T::*func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7), T* obj, const ARG1& arg1_, const ARG2& arg2_,
		            const ARG3& arg3_, const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_)
			: m_func(func),
			  obj(obj),
			  arg1(arg1_),
			  arg2(arg2_),
			  arg3(arg3_),
			  arg4(arg4_),
			  arg5(arg5_),
			  arg6(arg6_),
			  arg7(arg7_)
		{}
		virtual void run() {(obj->*m_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);}
		virtual ITask* clone() {return new ClassTask_7(m_func, obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7);}

		RET (T::*m_func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7);
		T* obj;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
		ARG5 arg5;
		ARG6 arg6;
		ARG7 arg7;
	};

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5, typename FARG6, typename FARG7, typename FARG8,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
	struct ClassTask_8: public ITask {
		ClassTask_8(RET (T::*func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8), T* obj, const ARG1& arg1_, const ARG2& arg2_,
		            const ARG3& arg3_, const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_, const ARG8& arg8_)
			: m_func(func),
			  obj(obj),
			  arg1(arg1_),
			  arg2(arg2_),
			  arg3(arg3_),
			  arg4(arg4_),
			  arg5(arg5_),
			  arg6(arg6_),
			  arg7(arg7_),
			  arg8(arg8_)
		{}
		virtual void run() {(obj->*m_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);}
		virtual ITask* clone() {return new ClassTask_8(m_func, obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);}

		RET (T::*m_func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8);
		T* obj;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
		ARG5 arg5;
		ARG6 arg6;
		ARG7 arg7;
		ARG8 arg8;
	};

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3,
	         typename FARG4, typename FARG5, typename FARG6,
	         typename FARG7, typename FARG8, typename FARG9,
	         typename ARG1, typename ARG2, typename ARG3,
	         typename ARG4, typename ARG5, typename ARG6,
	         typename ARG7, typename ARG8, typename ARG9>
	struct ClassTask_9: public ITask {
		ClassTask_9(RET (T::*func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8, FARG9), T* obj,
		            const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
		            const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_,
		            const ARG7& arg7_, const ARG8& arg8_, const ARG9& arg9_)
			: m_func(func),
			  obj(obj),
			  arg1(arg1_),
			  arg2(arg2_),
			  arg3(arg3_),
			  arg4(arg4_),
			  arg5(arg5_),
			  arg6(arg6_),
			  arg7(arg7_),
			  arg8(arg8_),
			  arg9(arg9_)
		{}
		virtual void run() {(obj->*m_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);}
		virtual ITask* clone() {return new ClassTask_9(m_func, obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);}

		RET (T::*m_func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8, FARG9);
		T* obj;
		ARG1 arg1;
		ARG2 arg2;
		ARG3 arg3;
		ARG4 arg4;
		ARG5 arg5;
		ARG6 arg6;
		ARG7 arg7;
		ARG8 arg8;
		ARG9 arg9;
	};
}

using namespace bindtool;

namespace boost
{
// �����Ա����
	static Task bind(void (*func)(void*), void* p_)
	{
		return Task(func, p_);
	}

	template<typename RET>
	static Task bind(RET (*func)(void))
	{
		return Task(Task_0<RET>::task_func, (void*)func);
	}

	template<typename FUNCT, typename ARG1>
	static Task bind(FUNCT func, ARG1 arg1_)
	{
		return Task(new Task_1<FUNCT, ARG1>(func, arg1_));
	}

	template<typename FUNCT, typename ARG1, typename ARG2>
	static Task bind(FUNCT func, ARG1 arg1_, ARG2 arg2_)
	{
		return Task(new Task_2<FUNCT, ARG1, ARG2>(func, arg1_, arg2_));
	}

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3>
	static Task bind(FUNCT func, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_)
	{
		return Task(new Task_3<FUNCT, ARG1, ARG2, ARG3>(func, arg1_, arg2_, arg3_));
	}

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
	static Task bind(FUNCT func, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_)
	{
		return Task(new Task_4<FUNCT, ARG1, ARG2, ARG3, ARG4>(func, arg1_, arg2_, arg3_, arg4_));
	}


	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
	static Task bind(FUNCT func, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_, ARG5 arg5_)
	{
		return Task(new Task_5<FUNCT, ARG1, ARG2, ARG3, ARG4, ARG5>(func, arg1_, arg2_, arg3_, arg4_, arg5_));
	}

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
	static Task bind(FUNCT func,
	                 ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_,
	                 ARG5 arg5_, ARG6 arg6_)
	{
		return Task(new Task_6<FUNCT, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6>(func, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_));
	}

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
	static Task bind(FUNCT func,
	                 ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_,
	                 ARG5 arg5_, ARG6 arg6_, ARG7 arg7_)
	{
		return Task(new Task_7<FUNCT, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7>(func, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_));
	}

	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
	static Task bind(FUNCT func,
	                 ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_,
	                 ARG5 arg5_, ARG6 arg6_, ARG7 arg7_, ARG8 arg8_)
	{

		return Task(new Task_8<FUNCT, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8>(func, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_, arg8_));
	}


	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
	static Task bind(FUNCT func,
	                 ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_,
	                 ARG5 arg5_, ARG6 arg6_, ARG7 arg7_, ARG8 arg8_, ARG9 arg9_)
	{
		return Task(new Task_9<FUNCT, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9>(func, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_, arg8_, arg9_));
	}

// ���Ա����
	template<typename T, typename RET>
	static Task bind(RET (T::*func)(void), T* obj)
	{
		return Task(new ClassTask_0<T, RET>(func, obj));
	}

	template<typename T, typename RET, typename FARG1, typename ARG1>
	static Task bind(RET (T::*func)(FARG1), T* obj, ARG1 arg1_)
	{
		return Task(new ClassTask_1<T, RET, FARG1, ARG1>(func, obj, arg1_));
	}

	template<typename T, typename RET, typename FARG1, typename FARG2, typename ARG1, typename ARG2>
	static Task bind(RET (T::*func)(FARG1, FARG2), T* obj, ARG1 arg1_, ARG2 arg2_)
	{
		return Task(new ClassTask_2<T, RET, FARG1, FARG2, ARG1, ARG2>(func, obj, arg1_, arg2_));
	}

	template<typename T, typename RET, typename FARG1, typename FARG2, typename FARG3, typename ARG1, typename ARG2, typename ARG3>
	static Task bind(RET (T::*func)(FARG1, FARG2, FARG3), T* obj, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_)
	{
		return Task(new ClassTask_3<T, RET, FARG1, FARG2, FARG3, ARG1, ARG2, ARG3>(func, obj, arg1_, arg2_, arg3_));
	}

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3, typename FARG4,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4>
	static Task bind(RET (T::*func)(FARG1, FARG2, FARG3, FARG4), T* obj, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_)
	{
		return Task(new ClassTask_4<T, RET, FARG1, FARG2, FARG3, FARG4, ARG1, ARG2, ARG3, ARG4>(func, obj, arg1_, arg2_, arg3_, arg4_));
	}

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
	static Task bind(RET (T::*func)(FARG1, FARG2, FARG3, FARG4, FARG5), T* obj, ARG1 arg1_, ARG2 arg2_,  ARG3 arg3_, ARG4 arg4_, ARG5 arg5_)
	{
		return Task(new ClassTask_5<T, RET, FARG1, FARG2, FARG3, FARG4, FARG5, ARG1, ARG2, ARG3, ARG4, ARG5 >
		            (func, obj, arg1_, arg2_, arg3_, arg4_, arg5_));
	}

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5, typename FARG6,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
	static Task bind(RET (T::*func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6), T* obj, ARG1 arg1_, ARG2 arg2_,
	                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_)
	{
		return Task(new ClassTask_6<T, RET, FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6>
		            (func, obj, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_));
	}

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5, typename FARG6, typename FARG7,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
	static Task bind(RET (T::*func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7), T* obj, ARG1 arg1_, ARG2 arg2_,
	                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_)
	{
		return Task(new ClassTask_7<T, RET, FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7>
		            (func, obj, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_));
	}

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5, typename FARG6, typename FARG7, typename FARG8,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
	static Task bind(RET (T::*func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8), T* obj, ARG1 arg1_, ARG2 arg2_,
	                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_, ARG8 arg8_)
	{
		return Task(new ClassTask_8<T, RET,
		            FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8,
		            ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8>
		            (func, obj, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_, arg8_));
	}

	template<typename T, typename RET,
	         typename FARG1, typename FARG2, typename FARG3,
	         typename FARG4, typename FARG5, typename FARG6,
	         typename FARG7, typename FARG8, typename FARG9,
	         typename ARG1, typename ARG2, typename ARG3,
	         typename ARG4, typename ARG5, typename ARG6,
	         typename ARG7, typename ARG8, typename ARG9>
	static Task bind(RET (T::*func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8, FARG9), T* obj, ARG1 arg1_, ARG2 arg2_,
	                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_, ARG8 arg8_, ARG9 arg9_)
	{

		return Task(
		           new ClassTask_9<T, RET,
		           FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8, FARG9,
		           ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9>
		           (func, obj, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_, arg8_, arg9_));
	}
};

#endif //_bind_h_