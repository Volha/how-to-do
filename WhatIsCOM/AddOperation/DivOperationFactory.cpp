#include "stdafx.h"
#include "DivOperationFactory.h"
#include "DivOperation.h"

long g2_lLocks = 0;
DivOperationFactory* DivOperationFactory::m_instance = nullptr;

DivOperationFactory::DivOperationFactory()
	:m_ref(0)
{
	
}
DivOperationFactory* DivOperationFactory::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new DivOperationFactory();
	}
	return m_instance;
}

ULONG STDMETHODCALLTYPE DivOperationFactory::Release( )
{
	InterlockedDecrement(&m_ref); 
	if ( m_ref == 0 )
	{
		delete this;
		m_instance = nullptr;
		return 0;
	}
	else
	return m_ref;
}

ULONG STDMETHODCALLTYPE DivOperationFactory::AddRef( )
{
	InterlockedIncrement(&m_ref);
	return m_ref;
}

HRESULT DivOperationFactory::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IClassFactory || (riid == IID_IUnknown))
	{
		*ppv = this;
		AddRef();
		return (S_OK);
	}
	return (E_NOINTERFACE);
}


HRESULT STDMETHODCALLTYPE DivOperationFactory::CreateInstance( IUnknown* pUnkOuter, REFIID riid, void** ppvObj)
{
	CComPtr<IPluginOp> pAddOp;

	pAddOp = new DivOperation;
	if ( pAddOp == 0 )
	{
		return( E_OUTOFMEMORY );
	}
	HRESULT hr = pAddOp->QueryInterface( riid, ppvObj ) ;
	return hr;
}

STDMETHODIMP DivOperationFactory::LockServer( BOOL fLock )
{
	if ( fLock )
	{
		InterlockedIncrement( &g2_lLocks ); 
	}
	else
	{
		InterlockedDecrement( &g2_lLocks );
	}
	return S_OK;
}

