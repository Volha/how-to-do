#pragma once
#include <atlcomcli.h>
#include <Windows.h>
#include "IPluginOp.h"
#include "IMyEvent.h"
#include <map>
 class ConnectionPoint 
	 : public IConnectionPoint
 {
	typedef std::map<DWORD, CComPtr<IMyEvents>> ConnMap;

	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);
	
	
	HRESULT STDMETHODCALLTYPE GetConnectionInterface(IID *pIID);
	HRESULT STDMETHODCALLTYPE GetConnectionPointContainer(IConnectionPointContainer **ppCPC);
	HRESULT STDMETHODCALLTYPE Advise(IUnknown *pUnkSink, DWORD *pdwCookie);
	HRESULT STDMETHODCALLTYPE Unadvise(DWORD dwCookie);
	HRESULT STDMETHODCALLTYPE EnumConnections(IEnumConnections **ppEnum);
	
	DWORD GetCurrentCookie();
	
 private:
	ConnMap m_connections;
	DWORD m_currentCookie;
	DWORD m_ref;
	CComPtr<IUnknown> m_extern;
 public:
	 ConnectionPoint(CComPtr<IUnknown>);
	 void NotifyAll();
	 ULONG STDMETHODCALLTYPE Release(); 
	 ULONG STDMETHODCALLTYPE AddRef();
 };
