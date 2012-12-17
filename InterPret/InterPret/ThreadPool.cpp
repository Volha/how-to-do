#include "stdafx.h"
#include "ThreadPool.h"


ThreadPool* ThreadPool::m_instance = nullptr;
ThreadPool::Mutex ThreadPool::m_mutex;

ThreadPool::ThreadPool(size_t threadNumbers)
	: m_isWorking(true)
	, m_countRef(0)
{
	for(size_t i = 0; i < threadNumbers; ++i)
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
	SendStopWorking();
	for(size_t i = 0; i < m_threads.size(); ++i)
	{0
		m_threads[i].join();
	}
}

void ThreadPool::AddRef()
{
	Lock lock(m_mutex);
	++m_countRef;
}
void ThreadPool::DecRefs()
{
	size_t tempCount = 0;
	{
		Lock lock(m_mutex);
		if (m_countRef != 0)
		{
			--m_countRef;
		}
		tempCount = m_countRef;
	}
	if (tempCount == 0)
	{
		delete this;
		m_instance = nullptr;
	}
}

void ThreadPool::SendStopWorking()
{
	Lock lock(m_mutex);
	m_isWorking = false;
	m_condition.notify_all();
}

bool ThreadPool::CheckIsWorking()
{
	Lock lock(m_mutex);
	return m_isWorking;
}

ThreadPool* ThreadPool::Instance()
{
	if (m_instance == nullptr)
	{
		Lock lock(m_mutex);
		if (m_instance == nullptr)
		{
			m_instance = new ThreadPool(3);
		}
	}
	return m_instance;
}


void ThreadPool::DoAsync(Functor f)
{
	Lock lock(m_mutex);
	m_queue.push(f);
	m_condition.notify_one();
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