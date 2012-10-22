#include "StdAfx.h"
#include "ThreadPoolClass.h"
#include <iostream>


ThreadPoolClass::ThreadPoolClass(int threadNumber)
	: m_isWorking(true)
{
	
	for(size_t i = 0; i < threadNumber; ++i)
	{
		m_threads.push_back(boost::thread(
			[this]()
			{
				MonitorQueue();
			}
		));
	}
}

ThreadPoolClass::~ThreadPoolClass()
{
	SendStopCycle();
	for(size_t i = 0; i < m_threads.size(); ++i)
	{
		m_threads[i].join();
	}
}

void ThreadPoolClass::SendStopCycle()
{
		Lock lock(m_mutex);
		m_isWorking = false;
		m_condition.notify_all();
}

void ThreadPoolClass::DoAsync(Functor f)
{
	Lock lock(m_mutex);
	m_queue.push(f);
	m_condition.notify_one();
}

bool ThreadPoolClass::CheckIsWorking()
{
	Lock lock(m_mutex);
	return m_isWorking;
}

void ThreadPoolClass::MonitorQueue()
{
	while (CheckIsWorking())
	{	
		Functor f = GetFunctor();
		if (f)
		{
			f();
		}
		else WaitUntilProcessAppears();
	}
}

void ThreadPoolClass::WaitUntilProcessAppears()
{
	Lock lock(m_mutex);
	m_condition.wait(lock);
};

ThreadPoolClass::Functor ThreadPoolClass::GetFunctor()
{
	Lock lock(m_mutex);
	Functor f;
	if (!m_queue.empty())
	{
		f = m_queue.back();
		m_queue.pop();
	}
	return f;
}
