#include "stdafx.h"
#include "SubOperationFactory.h"
#include "SubOperation.h"

long    g1_lObjs = 0;
long    g1_lLocks = 0;
SubOperationFactory* SubOperationFactory::m_instance = nullptr;

SubOperationFactory* SubOperationFactory::GetInstnace()
{
	if (m_instance == nullptr)
	{
		m_instance = new SubOperationFactory();
	}
	return m_instance;
}

SubOperationFactory::SubOperationFactory()
	:m_ref(0)
{
	
}

ULONG STDMETHODCALLTYPE SubOperationFactory::Release( )
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

ULONG STDMETHODCALLTYPE SubOperationFactory::AddRef( )
{
	InterlockedIncrement(&m_ref);
	return m_ref;
}

HRESULT SubOperationFactory::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IClassFactory || (riid == IID_IUnknown))
	{
		*ppv = this;
		AddRef();
		return (S_OK);
	}
	return (E_NOINTERFACE);
}


HRESULT STDMETHODCALLTYPE SubOperationFactory::CreateInstance( IUnknown* pUnkOuter, REFIID riid, void** ppvObj)
{
	CComPtr<SubOperation> pSubOp;
	pSubOp = new SubOperation;

	if ( pSubOp == 0 )
	{
		return( E_OUTOFMEMORY );
	}
	*ppvObj = nullptr;

	HRESULT hr = pSubOp->QueryInterface( riid, ppvObj );
	return hr;
}

STDMETHODIMP SubOperationFactory::LockServer( BOOL fLock )
{
	if ( fLock )
	{
		InterlockedIncrement( &g1_lLocks ); 
	}
	else
	{
		InterlockedDecrement( &g1_lLocks );
	}
	return S_OK;
}

