#pragma once
#include "windows.h"

class Handler
{
	public:
		Handler(LPCWSTR dllName)
			:m_module(LoadLibrary(dllName))
		{
	
		}

		~Handler()
		{
			FreeLibrary(m_module);		
		}
		
		FARPROC GetProcess(LPCSTR funcName)
		{
			if (m_module != nullptr)
			{
				return GetProcAddress(m_module, funcName);
			}
			return nullptr;
		}
private:
	HMODULE m_module;
};