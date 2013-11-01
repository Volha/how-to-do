// DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DLL.h"
#include "../TestDLL/ModuleClass.h"

// This is an example of an exported variable
//DLL_API int nDLL=0;

// This is an example of an exported function.
extern "C" DLL_API int fnDLL(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see DLL.h for the class definition
CDLL::CDLL()
{
	return;
}



extern "C" DLL_API int MakeThisWorldBetter()
{
	
		ModuleClass module(L"User32.dll");
		if (module)
		{
			typedef int  (WINAPI *TypeMB)(	HWND hWnd,
									LPCTSTR lpText,
									LPCTSTR lpCaption,
									UINT uType);
		
			auto messageBox = module.GetProcAdr("MessageBoxW");

			if (messageBox)
			{
				TypeMB MB = reinterpret_cast<TypeMB>(messageBox);
				auto call = MB(	NULL,
								(LPCWSTR)L"Resource not available\nDo you want to try again?",
								(LPCWSTR)L"Account Details",
								MB_ICONWARNING | MB_OKCANCEL | MB_DEFBUTTON2
							);

			}
		}
	
	return 0; 
	
}

extern "C" DLL_API int Function(void)
{
	
	return 3;
}

