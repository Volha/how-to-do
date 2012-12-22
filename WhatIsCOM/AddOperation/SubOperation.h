#pragma once

#include "IPluginOp.h"

class SubOperation : public IPluginOp
{
public:
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	SubOperation();
	double DoOperation(int a, int b);
	const std::string& GetNameOperation() const;

private: 
	std::string m_name;
	DWORD m_ref;
};
