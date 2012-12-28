#pragma once
#include <Unknwn.h>
#include "IOperationFactory.h"


class SubOperationFactory : public IOperationFactory
{
public:
	
	virtual ~SubOperationFactory(){};
	static SubOperationFactory* GetInstance();
	HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppv);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObj);
	HRESULT STDMETHODCALLTYPE LockServer(BOOL fLock);

private:
	SubOperationFactory();
protected:
   long m_ref;
   static SubOperationFactory* m_instance;
};