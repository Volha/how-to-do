#include "stdafx.h"
#include "SubOperation.h"
#include <iostream>

 SubOperation:: SubOperation()
	: m_name("SUB OPERATION: - ")
	, m_ref(0)
{
	
}

double SubOperation::DoOperation(int a, int b)
{
	return a - b;
}

const std::string&  SubOperation::GetNameOperation() const
{
	return m_name; 
}

HRESULT  SubOperation::QueryInterface(REFIID riid, void** ppv)
{
	if ((riid == IID_IPluginOp) || (riid == IID_IUnknown))
	{
		*ppv = this;
		AddRef();
		return (S_OK);
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

