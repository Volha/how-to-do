// LongTask.cpp : Implementation of CLongTask

#include "stdafx.h"
#include "LongTask.h"


// CLongTask



STDMETHODIMP CLongTask::BingBandOperation(void)
{
	// TODO: Add your implementation code here
	double sum = 0;
	for (int i = 0; i <= 100000000; ++i)
	{
		sum = sum + (2*i*i) / 100; 
	}
	Fire_OnFinish();
	return S_OK;
}
