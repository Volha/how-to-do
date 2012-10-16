#include "StdAfx.h"
#include "ThreadPool.h"
#include <boost\thread\thread.hpp>



ThreadPool::ThreadPool(void)
{

}

ThreadPool::ThreadPool(int threadNumber)
{
	std::vector<boost::thread> vecThreads;
	this->m_threadNumber = threadNumber;
	for(int i; i < threadNumber; ++i)
	{
		vecThreads.push_back(boost::thread());
	}
};


ThreadPool::~ThreadPool(void)
{
}

void ThreadPool::Initialize()
{

}
