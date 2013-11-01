// DivOperation.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <InitGuid.h>
#include "DivOperation.h"
#include <iostream>
#include <algorithm>
#include "ConnectionPointContainer.h"

DivOperation::DivOperation()
	: m_name("DIV OPERATION: / ")
	, m_ref(0)
	, m_connPointContainer(nullptr)
{
	
}

HRESULT DivOperation::DoOperation(int a, int b, long double& res)
{
	if (b == 0)
	{
		GetConnPointContainer()->GetInner()->NotifyAll();
		return E_FAIL;
	}
	
	res = a / b;
	return S_OK;
}

HRESULT DivOperation::GetNameOperation(BSTR* name)
{
	*name = CComBSTR(m_name.c_str()).Detach(); 
	return S_OK;
}

CComPtr<ConnectionPointContainer> DivOperation::GetConnPointContainer()
{
	if (m_connPointContainer == nullptr)
		{
			m_connPointContainer = new ConnectionPointContainer(static_cast<IPluginOp*>(this));
		}
	return m_connPointContainer;
}

HRESULT DivOperation::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IConnectionPointContainer)
	{
		*ppv = GetConnPointContainer();
		AddRef();
		return S_OK;
	}
	
	else if (riid == IID_IPluginOp || riid == IID_IUnknown)
	{
		*ppv = static_cast<IPluginOp*>(this);
		AddRef();
		return S_OK;
	}
	return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE DivOperation::Release( )
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

ULONG STDMETHODCALLTYPE DivOperation::AddRef( )
{
	InterlockedIncrement(&m_ref);
	return m_ref;
}

