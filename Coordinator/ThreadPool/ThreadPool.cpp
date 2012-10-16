#include "StdAfx.h"
#include "ThreadPool.h"
#include <iostream>


ThreadPool::ThreadPool(int threadNumber)
{
	for(int i = 0; i < threadNumber; ++i)
	{
		m_threads.push_back(boost::thread(
			[this]()
			{
				MonitorQueue();
			}
		));
	}
}

void ThreadPool::DoAsync(Functor f)
{
	Lock lock(m_mutex);
	m_queue.push(f);
	m_condition.notify_one();
}

void ThreadPool::MonitorQueue()
{
	while (true)
	{
		Functor f = GetFunctor();
		if (f)
		{
			f();
		}
	}
}

ThreadPool::Functor ThreadPool::GetFunctor()
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