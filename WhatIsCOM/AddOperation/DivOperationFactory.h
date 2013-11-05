#pragma once
#include <Unknwn.h>
#include "IOperationFactory.h"


class DivOperationFactory : public IOperationFactory
{
public:
	
	virtual ~DivOperationFactory(){};
	static DivOperationFactory* GetInstance();
	HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppv);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObj);
	HRESULT STDMETHODCALLTYPE LockServer(BOOL fLock);

private: 
	DivOperationFactory();
protected:
	long m_ref;
	static DivOperationFactory* m_instance;

};