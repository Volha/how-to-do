// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <sstream>


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
		
	case DLL_PROCESS_ATTACH:
		{
			//std::map 
			DWORD ProcessID = GetCurrentProcessId();
			std::wstringstream ss;
			ss << L"DLL process attached " << ProcessID << std::endl;
			OutputDebugString(ss.str().c_str());
		}
			break;
	case DLL_THREAD_ATTACH:
		{
			DWORD threadID = GetCurrentThreadId();
			std::wstringstream ss;
			ss << L"thread attached " << threadID << std::endl;
			OutputDebugString(ss.str().c_str());

		}
		
		
		break;
	case DLL_THREAD_DETACH:
		{
			DWORD ThreadID = GetCurrentThreadId();
			std::wstringstream ss;
			ss << L"thread detached " << ThreadID << std::endl;
			OutputDebugString(ss.str().c_str());
		}
		break;
	case DLL_PROCESS_DETACH:
		{
			DWORD ProcessID = GetCurrentProcessId();
			std::wstringstream ss;
			ss << L"dll process detached " << ProcessID << std::endl;
			OutputDebugString(ss.str().c_str());
		
		}
	}
	return TRUE;
}

