#include "stdafx.h"

#include "ConnectionPoint.h"
#include <algorithm>

ConnectionPoint::ConnectionPoint(CComPtr<IUnknown> ppv)
	: m_currentCookie(0)
	, m_extern(ppv)
{
	
}


HRESULT STDMETHODCALLTYPE ConnectionPoint::QueryInterface(REFIID riid, void** ppv)
{
	*ppv = static_cast<IConnectionPoint*>(this);
	AddRef();
	return S_OK;
}

ULONG STDMETHODCALLTYPE ConnectionPoint::AddRef()
{
	InterlockedIncrement(&m_ref);
	return m_ref;
}

ULONG STDMETHODCALLTYPE ConnectionPoint::Release()
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

HRESULT STDMETHODCALLTYPE ConnectionPoint::GetConnectionInterface(IID *pIID)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE ConnectionPoint::GetConnectionPointContainer(IConnectionPointContainer **ppCPC)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE ConnectionPoint::Advise(IUnknown *pUnkSink, DWORD *pdwCookie)
{
	CComQIPtr<IMyEvents, &IID_IMyEvents> p(pUnkSink);
	if (!p)
	{
		return E_FAIL;
	}

	*pdwCookie = GetCurrentCookie();
	m_connections.insert(std::make_pair<DWORD, CComPtr<IMyEvents>>(*pdwCookie, p)); 
	return S_OK;
}

HRESULT STDMETHODCALLTYPE ConnectionPoint::Unadvise(DWORD dwCookie)
{
	auto it = m_connections.find(dwCookie);
	if (it != m_connections.end())
	{
		m_connections.erase(it);
		return S_OK;
	}
	return E_FAIL;
}

HRESULT STDMETHODCALLTYPE ConnectionPoint::EnumConnections(IEnumConnections **ppEnum)
{
	return E_NOTIMPL;
}

DWORD ConnectionPoint::GetCurrentCookie()
{
	return m_currentCookie++;
}

void ConnectionPoint::NotifyAll()
{
	std::for_each(m_connections.begin(), m_connections.end(), [](const ConnMap::value_type& p)
	{
		p.second->OnError(1);
	});
}

