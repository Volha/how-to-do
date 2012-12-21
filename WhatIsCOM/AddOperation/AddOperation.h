#pragma once
#include "../WhatIsCOM/IPluginOp.h"

class AddOperation : public IPluginOp
{
public:
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	AddOperation();
	void DoOperation(int a, int b);
	const std::string& GetNameOperation() const;

private: 
	std::string m_name;
	DWORD m_ref;
};
