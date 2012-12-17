#pragma once
#include <vector>
#include <queue>
#include <boost\function.hpp>
#include <boost\thread.hpp>


class ThreadPool
{
	typedef boost::mutex Mutex;
	typedef boost::unique_lock<Mutex> Lock;
	

public:
	typedef boost::function<void ()> Functor;

	static ThreadPool* GetInstance();
	~ThreadPool();
	void DoAsync(Functor f);
private:
	ThreadPool(int threadNumber);
	void MonitorQueue();
	Functor GetFunctor();
	void SendStopCycle();
	bool CheckIsWorking();
	void WaitUntilProcessAppears();
private:
	std::vector<boost::thread> m_threads;
	std::queue<Functor> m_queue;
	boost::condition_variable m_condition;
	bool m_isWorking;
	static ThreadPool* instance;
	static Mutex m_mutex;

};

