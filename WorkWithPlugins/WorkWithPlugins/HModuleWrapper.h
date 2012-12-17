#pragma once
#include "windows.h"

class HModuleWrapper
{
public: 
	HModuleWrapper(LPCWSTR dllName);
	HModuleWrapper(HModuleWrapper&& other);
	~HModuleWrapper();
	operator bool() const;
	FARPROC HModuleWrapper::GetProcedure(LPCSTR funcName);

private:
	HMODULE m_module;
};