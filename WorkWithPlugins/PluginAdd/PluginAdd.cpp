// PluginAdd.cpp : Defines the exported functions for the DLL application.


#include "stdafx.h"
#include "PluginAdd.h"
#include <iostream>

PluginAdd::PluginAdd()
	: m_name("ADD OPERATION: + ")
	, m_ref(0)
{
	
}

PluginAdd::~PluginAdd()
{
	
}

void PluginAdd::DoOperation(int a, int b)
{
	std::cout << a + b << std::endl;
}

const std::string& PluginAdd::GetNameOperation() const
{
	return m_name; 
}

void PluginAdd::Init()
{
	++m_ref;
}

void PluginAdd::Release()
{
	if(--m_ref == 0)
	{
		delete this;
	}
}

HRESULT GetPlugin(IPlugin** pPlugin)
{
   if(!*pPlugin)
   {
		*pPlugin= new PluginAdd;
		(*pPlugin)->Init();
		return S_OK;
   }
 return E_FAIL;
}

//HRESULT FreePlugin(IPlugin** pPlugin)
//{
//   if(!* pPlugin)
//      return E_FAIL;
//   delete *pPlugin;
//   *pPlugin = 0;
//   return S_OK;
//}