#pragma once
#include <Windows.h>

class ModuleClass
{
public:
	ModuleClass(LPCWSTR dllName): m_module(LoadLibrary(dllName)){};

	~ModuleClass()
	{
		FreeLibrary(m_module);
	}
	
	void* GetProcAdr(LPCSTR funcName)
	{
		if (m_module != 0)
		{
			return GetProcAddress(m_module, funcName);
		}
		return nullptr;
	}
	operator bool() const
	{
		return m_module != 0;
	}

private:
	HMODULE m_module;
};
