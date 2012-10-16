#pragma once
class ThreadPool
{
public:
	ThreadPool(void);
	ThreadPool(int);
	~ThreadPool(void);
	void ThreadPool::Initialize();
private:
	int m_threadNumber;
	
};

