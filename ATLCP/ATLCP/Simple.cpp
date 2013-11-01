// Simple.cpp : Implementation of CSimple

#include "stdafx.h"
#include "Simple.h"


// CSimple



STDMETHODIMP CSimple::TestMethod(BSTR s)
{
	// TODO: Add your implementation code here
	Fire_OnFire();
	CComBSTR error(L"test");
	Fire_OnError(error);
	return S_OK;
}
