// PluginSub.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "PluginSub.h"
#include <iostream>

PluginSub::PluginSub()
	: m_name("SUB OPERATION: - ")
	, m_ref(0)
{
	
}

PluginSub::~PluginSub()
{
	
}

void PluginSub::DoOperation(int a, int b)
{
	std::cout << a - b << std::endl;
}

const std::string& PluginSub::GetNameOperation() const
{
	return m_name; 
}

void PluginSub::Init()
{
	++m_ref;
}

void PluginSub::Release()
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
		*pPlugin= new PluginSub;
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