#pragma once
#include "IPluginOp.h"

class AddOperation : public IPluginOp
{
public:
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	AddOperation();
	HRESULT DoOperation(int a, int b, long double& res);
	HRESULT GetNameOperation(BSTR* name);

private: 
	std::string m_name;
	DWORD m_ref;
};
