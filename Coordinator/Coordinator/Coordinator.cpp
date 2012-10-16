// Coordinator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\ThreadPool\ThreadPool.h"



int _tmain(int argc, _TCHAR* argv[])
{
	ThreadPool pool(4);

	for (;;)
	{
		///
		//pool.DoAsync([]()
		//	{
		//		// connect to server
		//		// download file
		//	}
		//);
		
	}

	return 0;
}