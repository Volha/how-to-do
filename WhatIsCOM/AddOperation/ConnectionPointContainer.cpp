#include "stdafx.h"
#include "ConnectionPointContainer.h"
#include "IPluginOp.h"
#include "ConnectionPoint.h"
ConnectionPointContainer::ConnectionPointContainer(CComPtr<IUnknown> ppv)
	: m_extern(ppv)
	, m_inner(nullptr)
{
	
}

CComPtr<ConnectionPoint> ConnectionPointContainer::GetInner()
{
	if (m_inner == nullptr)
	{
		m_inner = new ConnectionPoint(static_cast<IConnectionPointContainer*>(this));
	}
	return m_inner;
}

HRESULT STDMETHODCALLTYPE ConnectionPointContainer::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IConnectionPoint)
	{
		*ppv = GetInner();
		AddRef();
		return S_OK;
	}
}

ULONG STDMETHODCALLTYPE ConnectionPointContainer::AddRef()
{
	return InterlockedIncrement(&m_ref);
}

ULONG STDMETHODCALLTYPE ConnectionPointContainer::Release()
{
	auto ref = InterlockedDecrement(&m_ref); 
	if ( ref == 0 )
	{
		delete this;
	}
	return ref;
}

HRESULT STDMETHODCALLTYPE ConnectionPointContainer::EnumConnectionPoints(IEnumConnectionPoints **ppEnum)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE ConnectionPointContainer::FindConnectionPoint(REFIID riid, IConnectionPoint **ppCP)
{
	if(riid == IID_IMyEvents)
	{
		return QueryInterface(IID_IConnectionPoint, (void**)ppCP);
	}
	return E_NOINTERFACE;
}