#pragma once
#include <Unknwn.h>
#include "IOperationFactory.h"


class AddOperationFactory : public IOperationFactory
{
public:
	
	virtual ~AddOperationFactory(){};
	static AddOperationFactory* GetInstance();
	HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppv);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObj);
	HRESULT STDMETHODCALLTYPE LockServer(BOOL fLock);

private: 
	AddOperationFactory();
protected:
   long m_ref;
private:
   static AddOperationFactory* m_instance;

};