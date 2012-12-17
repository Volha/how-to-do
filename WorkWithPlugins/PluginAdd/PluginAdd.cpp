// PluginAdd.cpp : Defines the exported functions for the DLL application.


#include "stdafx.h"
#include "PluginAdd.h"
#include <iostream>

PluginAdd::PluginAdd()
	:m_name("ADD OPERATION: + ")
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

HRESULT GetPlugin(IPlugin** pPlugin)
{
   if(!*pPlugin)
   {
		*pPlugin= new PluginAdd;
		return S_OK;
   }
 return E_FAIL;
}

HRESULT FreePlugin(IPlugin** pPlugin)
{
   if(!* pPlugin)
      return E_FAIL;
   delete *pPlugin;
   *pPlugin = 0;
   return S_OK;
}