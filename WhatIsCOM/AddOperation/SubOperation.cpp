#include "stdafx.h"
#include "SubOperation.h"
#include <iostream>

 SubOperation:: SubOperation()
	: m_name("SUB OPERATION: - ")
	, m_ref(0)
{
	
}

HRESULT SubOperation::DoOperation(int a, int b, long double& res)
{
	res = a - b;
	return S_OK;
}

HRESULT SubOperation::GetNameOperation(BSTR* name)
{
	*name = CComBSTR(m_name.c_str()).Detach();
	return S_OK;
}

HRESULT  SubOperation::QueryInterface(REFIID riid, void** ppv)
{
	if ((riid == IID_IPluginOp) || (riid == IID_IUnknown))
	{
		*ppv = this;
		AddRef();
		return S_OK;
	}
	
	return (E_NOINTERFACE);
}

ULONG STDMETHODCALLTYPE  SubOperation::Release( )
{
   InterlockedDecrement(&m_ref); 
	if ( m_ref == 0 )
	{
		delete this;
		return 0;
	}
	else
	{
	return m_ref;
	}
}

ULONG STDMETHODCALLTYPE  SubOperation::AddRef( )
{
	InterlockedIncrement(&m_ref);
	return m_ref;
}

