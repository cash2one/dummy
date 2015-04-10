///<------------------------------------------------------------------------------
//< @file:   server\basic\taskqueue.h
//< @author: ������
//< @date:   2014��11��27�� 16:26:55
//< @brief:
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _taskqueue_h_
#define _taskqueue_h_

#include <stdexcept>
#include "lock.h"

typedef void (*task_func)(void*);

class task_impl_i
{
public:
	virtual ~task_impl_i() {}
	virtual void run()          = 0;
	virtual task_impl_i* fork() = 0;
};

class task_impl_t: public task_impl_i
{
public:
	task_impl_t(task_func func_, void* arg_):
		m_func(func_),
		m_arg(arg_)
	{}

	virtual void run()
	{
		m_func(m_arg);
	}

	virtual task_impl_i* fork()
	{
		return new task_impl_t(m_func, m_arg);
	}

protected:
	task_func m_func;
	void*       m_arg;
};

struct task_t {
	static void dumy(void*) {}
	task_t(task_func f_, void* d_):
		task_impl(new task_impl_t(f_, d_))
	{
	}
	task_t(task_impl_i* task_imp_):
		task_impl(task_imp_)
	{
	}
	task_t(const task_t& src_):
		task_impl(src_.task_impl->fork())
	{
	}
	task_t()
	{
		task_impl = new task_impl_t(&task_t::dumy, NULL);
	}
	~task_t()
	{
		delete task_impl;
	}
	task_t& operator=(const task_t& src_)
	{
		delete task_impl;
		task_impl = src_.task_impl->fork();
		return *this;
	}

	void run()
	{
		task_impl->run();
	}
	task_impl_i*    task_impl;
};

class task_queue_i
{
public:
	typedef std::list<task_t> task_list_t;
public:
	virtual ~task_queue_i() {}
	virtual void close() = 0;
	virtual void produce(const task_t& task_) = 0;
	virtual void multi_produce(const task_list_t& task_) = 0;
	virtual int  consume(task_t& task_) = 0;
	virtual int  consume_all(task_list_t&) = 0;
	virtual int run() = 0;
	virtual int batch_run() = 0;
};

struct task_binder_t {
	//! C function

	static task_t gen(void (*func_)(void*), void* p_)
	{
		return task_t(func_, p_);
	}
	template<typename RET>
	static task_t gen(RET (*func_)(void))
	{
		struct lambda_t {
			static void task_func(void* p_)
			{
				(*(RET(*)(void))p_)();
			};
		};
		return task_t(lambda_t::task_func, (void*)func_);
	}
	template<typename FUNCT, typename ARG1>
	static task_t gen(FUNCT func_, ARG1 arg1_)
	{
		struct lambda_t: public task_impl_i {
			FUNCT dest_func;
			ARG1  arg1;
			lambda_t(FUNCT func_, const ARG1& arg1_):
				dest_func(func_),
				arg1(arg1_)
			{}
			virtual void run()
			{
				(*dest_func)(arg1);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, arg1);
			}
		};
		return task_t(new lambda_t(func_, arg1_));
	}
	template<typename FUNCT, typename ARG1, typename ARG2>
	static task_t gen(FUNCT func_, ARG1 arg1_, ARG2 arg2_)
	{
		struct lambda_t: public task_impl_i {
			FUNCT dest_func;
			ARG1 arg1;
			ARG2 arg2;
			lambda_t(FUNCT func_, const ARG1& arg1_, const ARG2& arg2_):
				dest_func(func_),
				arg1(arg1_),
				arg2(arg2_)
			{}
			virtual void run()
			{
				(*dest_func)(arg1, arg2);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, arg1, arg2);
			}
		};
		return task_t(new lambda_t(func_, arg1_, arg2_));
	}
	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3>
	static task_t gen(FUNCT func_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_)
	{
		struct lambda_t: public task_impl_i {
			FUNCT dest_func;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			lambda_t(FUNCT func_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_):
				dest_func(func_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_)
			{}
			virtual void run()
			{
				(*dest_func)(arg1, arg2, arg3);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, arg1, arg2, arg3);
			}
		};
		return task_t(new lambda_t(func_, arg1_, arg2_, arg3_));
	}
	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
	static task_t gen(FUNCT func_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_)
	{
		struct lambda_t: public task_impl_i {
			FUNCT dest_func;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			lambda_t(FUNCT func_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_):
				dest_func(func_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_),
				arg4(arg4_)
			{}
			virtual void run()
			{
				(*dest_func)(arg1, arg2, arg3, arg4);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, arg1, arg2, arg3, arg4);
			}
		};
		return task_t(new lambda_t(func_, arg1_, arg2_, arg3_, arg4_));
	}
	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
	static task_t gen(FUNCT func_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_, ARG5 arg5_)
	{
		struct lambda_t: public task_impl_i {
			FUNCT dest_func;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			ARG5 arg5;
			lambda_t(FUNCT func_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_,
			         const ARG5& arg5_):
				dest_func(func_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_),
				arg4(arg4_),
				arg5(arg5_)
			{}
			virtual void run()
			{
				(*dest_func)(arg1, arg2, arg3, arg4, arg5);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, arg1, arg2, arg3, arg4, arg5);
			}
		};
		return task_t(new lambda_t(func_, arg1_, arg2_, arg3_, arg4_, arg5_));
	}
	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
	static task_t gen(FUNCT func_,
	                  ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_,
	                  ARG5 arg5_, ARG6 arg6_)
	{
		struct lambda_t: public task_impl_i {
			FUNCT dest_func;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			ARG5 arg5;
			ARG6 arg6;
			lambda_t(FUNCT func_,
			         const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_,
			         const ARG5& arg5_, const ARG6& arg6_):
				dest_func(func_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_),
				arg4(arg4_),
				arg5(arg5_),
				arg6(arg6_)
			{}
			virtual void run()
			{
				(*dest_func)(arg1, arg2, arg3, arg4, arg5, arg6);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, arg1, arg2, arg3, arg4, arg5, arg6);
			}
		};
		return task_t(new lambda_t(func_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_));
	}
	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6,
	         typename ARG7>
	static task_t gen(FUNCT func_,
	                  ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_,
	                  ARG5 arg5_, ARG6 arg6_, ARG7 arg7_)
	{
		struct lambda_t: public task_impl_i {
			FUNCT dest_func;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			ARG5 arg5;
			ARG6 arg6;
			ARG7 arg7;
			lambda_t(FUNCT func_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_,
			         const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_):
				dest_func(func_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_),
				arg4(arg4_),
				arg5(arg5_),
				arg6(arg6_),
				arg7(arg7_)
			{}
			virtual void run()
			{
				(*dest_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
			}
		};
		return task_t(new lambda_t(func_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_));
	}
	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6,
	         typename ARG7, typename ARG8>
	static task_t gen(FUNCT func_,
	                  ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_,
	                  ARG5 arg5_, ARG6 arg6_, ARG7 arg7_, ARG8 arg8_)
	{
		struct lambda_t: public task_impl_i {
			FUNCT dest_func;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			ARG5 arg5;
			ARG6 arg6;
			ARG7 arg7;
			ARG8 arg8;
			lambda_t(FUNCT func_,
			         const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_,
			         const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_, const ARG8& arg8_):
				dest_func(func_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_),
				arg4(arg4_),
				arg5(arg5_),
				arg6(arg6_),
				arg7(arg7_),
				arg8(arg8_)
			{}
			virtual void run()
			{
				(*dest_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
			}
		};
		return task_t(new lambda_t(func_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_, arg8_));
	}
	template<typename FUNCT, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6,
	         typename ARG7, typename ARG8, typename ARG9>
	static task_t gen(FUNCT func_,
	                  ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_,
	                  ARG5 arg5_, ARG6 arg6_, ARG7 arg7_, ARG8 arg8_, ARG9 arg9_)
	{
		struct lambda_t: public task_impl_i {
			FUNCT dest_func;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			ARG5 arg5;
			ARG6 arg6;
			ARG7 arg7;
			ARG8 arg8;
			ARG9 arg9;
			lambda_t(FUNCT func_,
			         const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_,
			         const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_, const ARG8& arg8_, const ARG9& arg9_):
				dest_func(func_),
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
			virtual void run()
			{
				(*dest_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
			}
		};
		return task_t(new lambda_t(func_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_, arg8_, arg9_));
	}
	//! class fuctions
	template<typename T, typename RET>
	static task_t gen(RET (T::*func_)(void), T* obj_)
	{
		struct lambda_t: public task_impl_i {
			RET (T::*dest_func)(void);
			T* obj;
			lambda_t(RET (T::*func_)(void), T* obj_):
				dest_func(func_),
				obj(obj_)
			{}
			virtual void run()
			{
				(obj->*dest_func)();
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, obj);
			}
		};
		return task_t(new lambda_t(func_, obj_));
	}
	template<typename T, typename RET, typename FARG1, typename ARG1>
	static task_t gen(RET (T::*func_)(FARG1), T* obj_, ARG1 arg1_)
	{
		struct lambda_t: public task_impl_i {
			RET (T::*dest_func)(FARG1);
			T* obj;
			ARG1 arg1;
			lambda_t(RET (T::*func_)(FARG1), T* obj_, const ARG1& arg1_):
				dest_func(func_),
				obj(obj_),
				arg1(arg1_)
			{}
			virtual void run()
			{
				(obj->*dest_func)(arg1);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, obj, arg1);
			}
		};
		return task_t(new lambda_t(func_, obj_, arg1_));
	}
	template<typename T, typename RET, typename FARG1, typename FARG2, typename ARG1, typename ARG2>
	static task_t gen(RET (T::*func_)(FARG1, FARG2), T* obj_, ARG1 arg1_, ARG2 arg2_)
	{
		struct lambda_t: public task_impl_i {
			RET (T::*dest_func)(FARG1, FARG2);
			T* obj;
			ARG1 arg1;
			ARG2 arg2;
			lambda_t(RET (T::*func_)(FARG1, FARG2), T* obj_, const ARG1& arg1_, const ARG2& arg2_):
				dest_func(func_),
				obj(obj_),
				arg1(arg1_),
				arg2(arg2_)
			{}
			virtual void run()
			{
				(obj->*dest_func)(arg1, arg2);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, obj, arg1, arg2);
			}
		};
		return task_t(new lambda_t(func_, obj_, arg1_, arg2_));
	}
	template<typename T, typename RET, typename FARG1, typename FARG2, typename FARG3, typename ARG1, typename ARG2,
	         typename ARG3>
	static task_t gen(RET (T::*func_)(FARG1, FARG2, FARG3), T* obj_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_)
	{
		struct lambda_t: public task_impl_i {
			RET (T::*dest_func)(FARG1, FARG2, FARG3);
			T* obj;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			lambda_t(RET (T::*func_)(FARG1, FARG2, FARG3), T* obj_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_):
				dest_func(func_),
				obj(obj_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_)
			{}
			virtual void run()
			{
				(obj->*dest_func)(arg1, arg2, arg3);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, obj, arg1, arg2, arg3);
			}
		};
		return task_t(new lambda_t(func_, obj_, arg1_, arg2_, arg3_));
	}
	template<typename T, typename RET, typename FARG1, typename FARG2, typename FARG3, typename FARG4,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4>
	static task_t gen(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4), T* obj_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_)
	{
		struct lambda_t: public task_impl_i {
			RET (T::*dest_func)(FARG1, FARG2, FARG3, FARG4);
			T* obj;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			lambda_t(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4), T* obj_, const ARG1& arg1_, const ARG2& arg2_,
			         const ARG3& arg3_, const ARG4& arg4_):
				dest_func(func_),
				obj(obj_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_),
				arg4(arg4_)
			{}
			virtual void run()
			{
				(obj->*dest_func)(arg1, arg2, arg3, arg4);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, obj, arg1, arg2, arg3, arg4);
			}
		};
		return task_t(new lambda_t(func_, obj_, arg1_, arg2_, arg3_, arg4_));
	}
	template<typename T, typename RET,  typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
	static task_t gen(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4, FARG5), T* obj_, ARG1 arg1_, ARG2 arg2_,  ARG3 arg3_, ARG4 arg4_, ARG5 arg5_)
	{
		struct lambda_t: public task_impl_i {
			RET (T::*dest_func)(FARG1, FARG2, FARG3, FARG4, FARG5);
			T* obj;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			ARG5 arg5;
			lambda_t(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4, FARG5), T* obj_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_,
			         const ARG5& arg5_):
				dest_func(func_),
				obj(obj_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_),
				arg4(arg4_),
				arg5(arg5_)
			{}
			virtual void run()
			{
				(obj->*dest_func)(arg1, arg2, arg3, arg4, arg5);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, obj, arg1, arg2, arg3, arg4, arg5);
			}
		};
		return task_t(new lambda_t(func_, obj_, arg1_, arg2_, arg3_, arg4_, arg5_));
	}
	template<typename T, typename RET, typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5,
	         typename FARG6, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
	static task_t gen(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6), T* obj_, ARG1 arg1_, ARG2 arg2_,
	                  ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_)
	{
		struct lambda_t: public task_impl_i {
			RET (T::*dest_func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6);
			T* obj;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			ARG5 arg5;
			ARG6 arg6;
			lambda_t(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6), T* obj_, const ARG1& arg1_, const ARG2& arg2_,
			         const ARG3& arg3_, const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_):
				dest_func(func_),
				obj(obj_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_),
				arg4(arg4_),
				arg5(arg5_),
				arg6(arg6_)
			{}
			virtual void run()
			{
				(obj->*dest_func)(arg1, arg2, arg3, arg4, arg5, arg6);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, obj, arg1, arg2, arg3, arg4, arg5, arg6);
			}
		};
		return task_t(new lambda_t(func_, obj_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_));
	}
	template<typename T, typename RET, typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5,
	         typename FARG6, typename FARG7,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
	static task_t gen(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7), T* obj_, ARG1 arg1_, ARG2 arg2_,
	                  ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_)
	{
		struct lambda_t: public task_impl_i {
			RET (T::*dest_func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7);
			T* obj;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			ARG5 arg5;
			ARG6 arg6;
			ARG7 arg7;
			lambda_t(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7), T* obj_, const ARG1& arg1_, const ARG2& arg2_,
			         const ARG3& arg3_, const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_):
				dest_func(func_),
				obj(obj_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_),
				arg4(arg4_),
				arg5(arg5_),
				arg6(arg6_),
				arg7(arg7_)
			{}
			virtual void run()
			{
				(obj->*dest_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
			}
		};
		return task_t(new lambda_t(func_, obj_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_));
	}
	template<typename T, typename RET, typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5,
	         typename FARG6, typename FARG7, typename FARG8,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
	static task_t gen(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8), T* obj_, ARG1 arg1_, ARG2 arg2_,
	                  ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_, ARG8 arg8_)
	{
		struct lambda_t: public task_impl_i {
			RET (T::*dest_func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8);
			T* obj;
			ARG1 arg1;
			ARG2 arg2;
			ARG3 arg3;
			ARG4 arg4;
			ARG5 arg5;
			ARG6 arg6;
			ARG7 arg7;
			ARG8 arg8;
			lambda_t(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8), T* obj_, const ARG1& arg1_, const ARG2& arg2_,
			         const ARG3& arg3_, const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_, const ARG8& arg8_):
				dest_func(func_),
				obj(obj_),
				arg1(arg1_),
				arg2(arg2_),
				arg3(arg3_),
				arg4(arg4_),
				arg5(arg5_),
				arg6(arg6_),
				arg7(arg7_),
				arg8(arg8_)
			{}
			virtual void run()
			{
				(obj->*dest_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
			}
		};
		return task_t(new lambda_t(func_, obj_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_, arg8_));
	}
	template<typename T, typename RET, typename FARG1, typename FARG2, typename FARG3, typename FARG4, typename FARG5,
	         typename FARG6, typename FARG7, typename FARG8, typename FARG9,
	         typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7,
	         typename ARG8, typename ARG9>
	static task_t gen(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8, FARG9), T* obj_, ARG1 arg1_, ARG2 arg2_,
	                  ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_, ARG8 arg8_, ARG9 arg9_)
	{
		struct lambda_t: public task_impl_i {
			RET (T::*dest_func)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8, FARG9);
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
			lambda_t(RET (T::*func_)(FARG1, FARG2, FARG3, FARG4, FARG5, FARG6, FARG7, FARG8, FARG9), T* obj_,
			         const ARG1& arg1_, const ARG2& arg2_,
			         const ARG3& arg3_, const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_,
			         const ARG8& arg8_, const ARG9& arg9_):
				dest_func(func_),
				obj(obj_),
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
			virtual void run()
			{
				(obj->*dest_func)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
			}
			virtual task_impl_i* fork()
			{
				return new lambda_t(dest_func, obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
			}
		};
		return task_t(new lambda_t(func_, obj_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_, arg8_, arg9_));
	}
};

class BlockingTaskQueue: public task_queue_i
{
public:
	BlockingTaskQueue():
		m_closed(false),
		m_cond(m_mutex)
	{
	}
	~BlockingTaskQueue()
	{
	}
	void close()
	{
		lock_guard_t<> lock(m_mutex);
		m_closed = true;
		m_cond.broadcast();
	}

	void multi_produce(const task_list_t& task_)
	{
		lock_guard_t<> lock(m_mutex);
		bool need_sig = m_tasklist.empty();

		for(task_list_t::const_iterator it = task_.begin(); it != task_.end(); ++it) {
			m_tasklist.push_back(*it);
		}

		if (need_sig) {
			m_cond.notify();
		}
	}
	void produce(const task_t& task_)
	{
		lock_guard_t<> lock(m_mutex);
		bool need_sig = m_tasklist.empty();

		m_tasklist.push_back(task_);
		if (need_sig) {
			m_cond.notify();
		}
	}

	int   consume(task_t& task_)
	{
		lock_guard_t<> lock(m_mutex);
		while (m_tasklist.empty()) {
			if (m_closed) {
				return -1;
			}
			m_cond.wait();
		}

		task_ = m_tasklist.front();
		m_tasklist.pop_front();

		return 0;
	}

	int run()
	{
		task_t t;
		while (0 == consume(t)) {
			t.run();
		}
		return 0;
	}

	int consume_all(task_list_t& tasks_)
	{
		lock_guard_t<> lock(m_mutex);

		while (m_tasklist.empty()) {
			if (m_closed) {
				return -1;
			}
			m_cond.wait();
		}

		tasks_ = m_tasklist;
		m_tasklist.clear();

		return 0;
	}

	int batch_run()
	{
		task_list_t tasks;
		int ret = consume_all(tasks);
		while (0 == ret) {
			for (task_list_t::iterator it = tasks.begin(); it != tasks.end(); ++it) {
				(*it).run();
			}
			tasks.clear();
			ret = consume_all(tasks);
		}
		return 0;
	}
private:
	volatile bool                   m_closed;
	task_list_t                     m_tasklist;
	mutex_t                         m_mutex;
	condition_var_t                 m_cond;
};

class TaskQueue
{
public:
	void put(const task_t& task_)
	{
		lock_guard_t<> lock(m_mutex);
		m_tasklist.push_back(task_);
	}

	int take(task_t& task_)
	{
		lock_guard_t<> lock(m_mutex);
		task_ = m_tasklist.front();
		m_tasklist.pop_front();
		return 0;
	}

	int run()
	{
		task_queue_i::task_list_t tasks;
		int ret = takeAll(tasks);

		for (task_queue_i::task_list_t::iterator it = tasks.begin(); it != tasks.end(); ++it) {
			task_t &t = *it;
			t.run();
		}

		return ret;
	}

	int takeAll(task_queue_i::task_list_t& tasks)
	{
		lock_guard_t<> lock(m_mutex);
		tasks = m_tasklist;

		m_tasklist.clear();
		return tasks.size();
	}

	int size()
	{
		lock_guard_t<> lock(m_mutex);
		return m_tasklist.size();
	}

private:
	task_queue_i::task_list_t m_tasklist;
	mutex_t                         m_mutex;
};


class task_queue_pool_t
{
	typedef task_queue_i::task_list_t task_list_t;
	typedef std::vector<BlockingTaskQueue*>    task_queue_vt_t;
	static void task_func(void* pd_)
	{
		task_queue_pool_t* t = (task_queue_pool_t*)pd_;
		t->run();
	}
public:
	static task_t gen_task(task_queue_pool_t* p)
	{
		return task_t(&task_func, p);
	}
public:
	task_queue_pool_t(int n) :
		m_index(0)
	{
		for (int i = 0; i < n; ++i) {
			BlockingTaskQueue* p = new BlockingTaskQueue();
			m_tqs.push_back(p);
		}
	}

	void run()
	{
		BlockingTaskQueue* p = NULL;
		{
			lock_guard_t<> lock(m_mutex);
			if (m_index >= (int)m_tqs.size()) {
				throw std::runtime_error("too more thread running!!");
			}
			p = m_tqs[m_index++];
		}

		p->batch_run();
	}

	~task_queue_pool_t()
	{
		task_queue_vt_t::iterator it = m_tqs.begin();
		for (; it != m_tqs.end(); ++it) {
			delete (*it);
		}
		m_tqs.clear();
	}

	void close()
	{
		task_queue_vt_t::iterator it = m_tqs.begin();
		for (; it != m_tqs.end(); ++it) {
			(*it)->close();
		}
	}

	size_t size() const { return m_tqs.size(); }

	task_queue_i* alloc(long id_)
	{
		return m_tqs[id_ %  m_tqs.size()];
	}
	task_queue_i* rand_alloc()
	{
		static unsigned long id_ = 0;
		return m_tqs[++id_ %  m_tqs.size()];
	}
private:
	mutex_t               m_mutex;
	task_queue_vt_t       m_tqs;
	int					  m_index;
};

#endif //_taskqueue_h_