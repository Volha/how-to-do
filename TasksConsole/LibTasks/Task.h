#pragma once
#include <queue>
#include <boost\function.hpp>

namespace Tasks
{
	class Task
	{
	public: 
		typedef boost::function<void()> Functor;
		~Task();
		friend Task* CreateTask(Task::Functor functor);
		void Wait();
	protected:
		Task();
	public: 
	};
	Task* CreateTask(Task::Functor functor);
}

