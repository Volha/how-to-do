// Coordinator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\ThreadPool\ThreadPool.h"
#include "..\ThreadPool\HandlerClass.h"
#include <iostream>

const int FUNCTION_PARTS = 99;
const int TASK_SIZE = 1000000000;
const int INT_DIV = 10000000;
typedef std::shared_ptr<HandlerClass> HandlerPtr;

void BackgroundTask(HandlerPtr handler, int start, int finish)
{
	for(int i = start; i < finish; ++i)
	{
		double di = static_cast<double>(i);
		double d = std::sqrt(std::sqrt(di) + std::sqrt(di + 1));
		d = d - 8;	
		if ((i % INT_DIV) == 0 && handler)
		{
			handler->IncrementProgress();
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	HandlerPtr handler = std::make_shared<HandlerClass>();
	
		ThreadPool pool(4);
		int subTaskStart = 0;
		 int subTaskSize =  TASK_SIZE / FUNCTION_PARTS;
	
		for (size_t i = 0; i < FUNCTION_PARTS; ++i)
		{
			pool.DoAsync([handler, subTaskStart, subTaskSize]()
				{
					BackgroundTask(handler, subTaskStart, subTaskStart + subTaskSize);
				}
			);
			subTaskStart += subTaskSize;
		}
	
	bool cycle = true;	
	while (cycle)
	{
		handler->WaitUntilProgressChanged();
		auto p = handler->GetProgress();
		std::cout << "\r" << p << "%";
		if (p == 100) 
		{
			cycle = false;
		}
	}
	return 0;
}