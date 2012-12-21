#include "stdafx.h"
#include "AddOperationFactory.h"
#include "AddOperation.h"
#include "SubOperationFactory.h"

long g_lObjs = 0;
long g_lLocks = 0;
AddOperationFactory* AddOperationFactory::m_instance = nullptr;

AddOperationFactory::AddOperationFactory()
	:m_ref(0)
{
	
}
AddOperationFactory* AddOperationFactory::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new AddOperationFactory();
	}
	return m_instance;
}

ULONG STDMETHODCALLTYPE AddOperationFactory::Release( )
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

ULONG STDMETHODCALLTYPE AddOperationFactory::AddRef( )
{
	InterlockedIncrement(&m_ref);
	return m_ref;
}

HRESULT AddOperationFactory::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IClassFactory || (riid == IID_IUnknown))
	{
		*ppv = this;
		AddRef();
		return (S_OK);
	}
	return (E_NOINTERFACE);
}


HRESULT STDMETHODCALLTYPE AddOperationFactory::CreateInstance( IUnknown* pUnkOuter, REFIID riid, void** ppvObj)
{
	CComPtr<AddOperation> pAddOp;

	pAddOp = new AddOperation;
	if ( pAddOp == 0 )
	{
		return( E_OUTOFMEMORY );
	}
	HRESULT hr = pAddOp->QueryInterface( riid, ppvObj ) ;
	return hr;
}

STDMETHODIMP AddOperationFactory::LockServer( BOOL fLock )
{
	if ( fLock )
	{
		InterlockedIncrement( &g_lLocks ); 
	}
	else
	{
		InterlockedDecrement( &g_lLocks );
	}
	return S_OK;
}

STDAPI DllGetClassObject( REFCLSID rclsid, REFIID riid, void** ppv )
{
	HRESULT hr;
	CComPtr<IOperationFactory> iPtr = nullptr;
	
	if ((rclsid != CLSID_AddOp) && (rclsid != CLSID_SubOp))
	{
		return (E_FAIL);
	}
	if (rclsid == CLSID_AddOp)
	{
		iPtr = AddOperationFactory::GetInstance();
	}
	if (rclsid == CLSID_SubOp)
	{
		iPtr = SubOperationFactory::GetInstnace();
	}
	if (iPtr == 0)
	{
		return (E_OUTOFMEMORY);
	}
	hr = iPtr->QueryInterface(riid, ppv);
	return hr;
}

