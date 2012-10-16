// Coordinator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\ThreadPool\ThreadPool.h"
#include <iostream>

void BackgroundTask(int start, int finish)
{
	for(int i = start; i < finish; ++i)
	{
		double di = static_cast<double>(i);
		double d = std::sqrt(std::sqrt(di) + std::sqrt(di+ 1));
		d = d - 8;	
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ThreadPool pool(4);

	for (;;)
	{
		
		pool.DoAsync([]()
			{
				BackgroundTask(100, 20000);
				// connect to server
				// download file
			}
		);
		
	}

	return 0;
}