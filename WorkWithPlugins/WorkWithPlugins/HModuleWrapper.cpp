#include "stdafx.h"
#include "HModuleWrapper.h"


HModuleWrapper::HModuleWrapper(LPCWSTR dllName)
			:m_module(LoadLibrary(dllName))
{

}

HModuleWrapper::HModuleWrapper(HModuleWrapper&& other)
	:m_module(other.m_module)
{
	other.m_module = 0;
}

HModuleWrapper::~HModuleWrapper()
{
	if (m_module)
	{
		FreeLibrary(m_module);		
	}
}

 HModuleWrapper::operator bool () const
 {
	return m_module != 0;

 }

FARPROC HModuleWrapper::GetProcedure(LPCSTR funcName)
{
	if (m_module != nullptr)
	{
		return GetProcAddress(m_module, funcName);
	}
	return nullptr;
}