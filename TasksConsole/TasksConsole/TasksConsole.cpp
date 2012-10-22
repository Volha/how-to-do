// TasksConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost\function.hpp>
#include "..\LibTasks\Task.h"
#include "..\LibTasks\Singleton.h"

class A
{
public:
	A()
	{
	
	}
	void Func()
	{
	
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Singleton<A>::GetInstance()->Func();
	Singleton<A>::GetInstance()->Func();
	Tasks::Task* t = Tasks::CreateTask([](){});
	t->Wait();
	return 0;
}

