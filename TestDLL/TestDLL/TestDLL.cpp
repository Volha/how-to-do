// TestDLL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
//#include "../DLL/DLL.h"
#include "ModuleClass.h"

int _tmain(int argc, _TCHAR* argv[])
{// RAII
	//unspecified bool idiom
	ModuleClass module(L"DLL.dll");
	if (module)
	{
		typedef int (*FuncType)();
		void* func = module.GetProcAdr("MakeThisWorldBetter");
		if (func)
		{
			FuncType f = reinterpret_cast<FuncType>(func);
			auto i = f();
		}
	
	}
	return 0;	
}

