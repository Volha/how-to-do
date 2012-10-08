// boost_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost\thread\thread.hpp>
#include <boost\thread\locks.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "HandlerClass.h"

typedef std::shared_ptr<HandlerClass> HandlerPtr;
const int TASK_SIZE = 1000000000;
const int IT_DIV = TASK_SIZE / 100;

void BackgroundTask(HandlerPtr handler, int start, int finish)
{
	
	for(int i = start; i < finish; ++i)
	{
		double di = static_cast<double>(i);
		double d = std::sqrt(std::sqrt(di) + std::sqrt(di+ 1));
		d = d - 8;
		if ((i % IT_DIV) == 0 && handler)
		{
			handler->IncrementProgress();
		}
	}
}

int main(int argc, char* argv[])
{
	const size_t THREAD_COUNT = 1;
	HandlerPtr handler = std::make_shared<HandlerClass>();
	std::vector<boost::thread> threads;
	int subTaskSize = TASK_SIZE / THREAD_COUNT; 
	int subTaskStart = 0;
	for(size_t i = 0; i < THREAD_COUNT; ++i)
	{
		threads.push_back(boost::thread(&BackgroundTask, handler, subTaskStart, subTaskSize + subTaskStart));
		subTaskStart += subTaskSize;
	}
	for (;;)
	{
		handler->WaitUntilProgressChanged();
		auto p = handler->GetProgress();
		std::cout << "\r" << p << "%";
	}
	std::for_each(threads.begin(), threads.end(), [](boost::thread& t){ t.join();});
	return 0;
}