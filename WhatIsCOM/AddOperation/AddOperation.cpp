// AddOperation.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <InitGuid.h>
#include "AddOperation.h"
#include <iostream>

AddOperation::AddOperation()
	: m_name("ADD OPERATION: + ")
	, m_ref(0)
{
	
}


HRESULT AddOperation::DoOperation(int a, int b, long double& res)
{
	res = a + b;
	return S_OK;
}

HRESULT AddOperation::GetNameOperation(BSTR* name)
{
	//*name = SysAllocString(m_name.c_str());//_com_util::ConvertStringToBSTR(m_name.c_str());
	CComBSTR s(m_name.c_str());
	*name = s.Detach();
	return S_OK;
}

HRESULT AddOperation::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IPluginOp || (riid == IID_IUnknown))
	{
		*ppv = this;
		AddRef();
		return (S_OK);
	}
	return (E_NOINTERFACE);
}

ULONG STDMETHODCALLTYPE AddOperation::Release( )
{
	InterlockedDecrement(&m_ref); 
	if ( m_ref == 0 )
	{
		delete this;
		return 0;
	}
	else
	return m_ref;
}

ULONG STDMETHODCALLTYPE AddOperation::AddRef( )
{
	InterlockedIncrement(&m_ref);
	return m_ref;
}


