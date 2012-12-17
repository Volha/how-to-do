#include "StdAfx.h"
#include "ThreadPool.h"
#include <iostream>

ThreadPool* ThreadPool::instance = nullptr;
ThreadPool::Mutex ThreadPool::m_mutex;

ThreadPool* ThreadPool::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ThreadPool(3);
	}
	return instance;
}

ThreadPool::ThreadPool(int threadNumber)
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

ThreadPool::~ThreadPool()
{
	SendStopCycle();
	for(size_t i = 0; i < m_threads.size(); ++i)
	{
		m_threads[i].join();
	}
}

void ThreadPool::SendStopCycle()
{
		Lock lock(m_mutex);
		m_isWorking = false;
		m_condition.notify_all();
}

void ThreadPool::DoAsync(Functor f)
{
	Lock lock(m_mutex);
	m_queue.push(f);
	m_condition.notify_one();
}

bool ThreadPool::CheckIsWorking()
{
	Lock lock(m_mutex);
	return m_isWorking;
}

void ThreadPool::MonitorQueue()
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

void ThreadPool::WaitUntilProcessAppears()
{
	Lock lock(m_mutex);
	m_condition.wait(lock);
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
