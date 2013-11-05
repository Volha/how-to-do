#pragma once

#include "IPluginOp.h"
#include "IMyEvent.h"
#include <atlcomcli.h>
#include <map>
#include "ConnectionPointContainer.h"

class DivOperation 
	: public IPluginOp
	
{
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	HRESULT DoOperation(int a, int b, long double& res);
	HRESULT GetNameOperation(BSTR* name);
	CComPtr<ConnectionPointContainer> GetConnPointContainer();

public:
	DivOperation();
private: 
	CComPtr<ConnectionPointContainer> m_connPointContainer;
	std::string m_name;
	DWORD m_ref;
};
