#pragma once
#include <Unknwn.h>
#include <atlcomcli.h>
class IOperationFactory : public IClassFactory
{
public:

	virtual ~IOperationFactory(){};
	virtual HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObj) = 0;
};