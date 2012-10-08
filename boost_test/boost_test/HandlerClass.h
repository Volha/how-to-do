#pragma once
#include <boost\thread\thread.hpp>
#include <boost\thread\locks.hpp>
class HandlerClass
{
	typedef boost::mutex Mutex;
	typedef boost::unique_lock<Mutex> Lock;
public:
	HandlerClass();	
	~HandlerClass();
	void OnProgress(int);
	int GetProgress() const;
	void WaitUntilProgressChanged();
	void IncrementProgress();
private:
	boost::condition_variable m_condition;
	mutable boost::mutex m_mutex;
	int m_progress;
};