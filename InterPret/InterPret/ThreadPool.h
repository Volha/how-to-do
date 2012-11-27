#pragma once
#include <boost\thread.hpp>
#include <vector>
#include <queue>

class ThreadPool
{
	typedef std::function<void()> Functor;
	typedef boost::mutex Mutex;
	typedef boost::unique_lock<Mutex> Lock;
public:
	static ThreadPool* Instance();
	~ThreadPool();
	void DoAsync(Functor f);
	void DecRefs();
	void AddRef();
	
private:
	ThreadPool(size_t threadNumbers);
	void SendStopWorking();
	void MonitorQueue();
	bool CheckIsWorking();
	Functor GetFunctor();
	
private:
	boost::condition_variable m_condition;
	std::queue<Functor> m_queue;
	std::vector<boost::thread> m_threads;
	bool m_isWorking;
	size_t m_countRef;
	static ThreadPool* m_instance;
	static Mutex m_mutex;
};