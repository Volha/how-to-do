#include "StdAfx.h"
#include "Task.h"
#include "ThreadPoolClass.h"

namespace Tasks
{ 
	ThreadPoolClass pool(4);
	
	Task::Task()
	{
	
	}
	
	Task::~Task()
	{
	}

	void Task::Wait()
	{
		
	}

	Task* CreateTask(Task::Functor f)
	{
		pool.DoAsync(f);
		return new Task;
	}
}