#pragma once 
#include <atlcomcli.h>
#include <Windows.h>
#include "ConnectionPoint.h"

class ConnectionPointContainer
	: public IConnectionPointContainer 
{
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);

	HRESULT STDMETHODCALLTYPE EnumConnectionPoints(IEnumConnectionPoints **ppEnum);
	HRESULT STDMETHODCALLTYPE FindConnectionPoint(REFIID riid, IConnectionPoint **ppCP);
	
public:
	ConnectionPointContainer(CComPtr<IUnknown> ppv);
	CComPtr<ConnectionPoint> m_inner;
	CComPtr<ConnectionPoint> GetInner();

	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

private:
	DWORD m_ref;
	CComPtr<IUnknown> m_extern;

};