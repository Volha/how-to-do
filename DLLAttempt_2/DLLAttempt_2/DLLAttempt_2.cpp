// DLLAttempt_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "Handler.h"
#include <process.h> 
#include <iostream>

void PrintHello()
{
	std::cout << "hello World" << std::endl;

}


DWORD WINAPI MyThreadFunction( LPVOID lpParam ) 
{
	std::cout << "MyThreadFunction" << std::endl;
	HMODULE module = LoadLibrary(L"SomeFunctions.dll");
	if (module != 0)
	{
		auto func = GetProcAddress(module, "PrintLetters");
		func();
	}
	FreeLibrary(module);
	std::cin.get();
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "main" << std::endl;
	Handler moduleHandler(L"SomeFunctions.dll");
	auto func = moduleHandler.GetProcess("PrintNumbers");
	func();
	
	DWORD dwThreadID;
	
	HANDLE hThread = CreateThread(NULL, 0,  MyThreadFunction, NULL, 0, &dwThreadID); 
	WaitForSingleObject(hThread, INFINITE);
	
	DWORD dwThread2ID;
	HANDLE hThread2 = CreateThread(NULL, 0,  MyThreadFunction, NULL, 0, &dwThread2ID); 
	WaitForSingleObject(hThread2, INFINITE);
	CloseHandle(hThread);
	CloseHandle(hThread2);
	
	PROCESS_INFORMATION pi;
	STARTUPINFO si = {sizeof(si)};
	BOOL result = CreateProcess(NULL, L"cmd.exe", 0, 0, FALSE, 
		0, 0, 0, &si, &pi);
	if (result)
	{
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	/*auto module = LoadLibrary(L"FunctionsToPrint.dll");
	auto id = GetProcAddress(module, "PrintLetters");
	FreeLibrary(module);*/
	/*HMODULE module = LoadLibrary(L"SomeFunctions.dll");
	if (module != 0)
	{
		auto func = GetProcAddress(module, "PrintNumbers");
		func();
	}
	FreeLibrary(module);*/
	std::cin.get();
	return 0;
}

