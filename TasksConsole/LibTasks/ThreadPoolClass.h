#pragma once
#include <vector>
#include <queue>
#include <boost\function.hpp>
#include <boost\thread.hpp>


class ThreadPoolClass
{
	typedef boost::mutex Mutex;
	typedef boost::unique_lock<Mutex> Lock;
	

public:
	typedef boost::function<void ()> Functor;

	ThreadPoolClass(int threadNumber);
	~ThreadPoolClass();
	void DoAsync(Functor f);
private:
	void MonitorQueue();
	Functor GetFunctor();
	void SendStopCycle();
	bool CheckIsWorking();
	void WaitUntilProcessAppears();
private:
	std::vector<boost::thread> m_threads;
	std::queue<Functor> m_queue;
	mutable Mutex m_mutex;
	boost::condition_variable m_condition;
	bool m_isWorking;
};

