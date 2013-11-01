// DivOperation.cpp : Implementation of CDivOperation

#include "stdafx.h"
#include "DivOperation.h"


// CDivOperation



STDMETHODIMP CDivOperation::DoOperation(SHORT param1, SHORT param2, DOUBLE* result)
{
	// TODO: Add your implementation code here
	if (param2 == 0)
	{
		//GetConnPointContainer()->GetInner()->NotifyAll();
		return E_FAIL;
	}
	
	*result = param1 / param2;
	
	return S_OK;
}
