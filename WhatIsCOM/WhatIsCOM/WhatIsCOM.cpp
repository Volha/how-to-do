// WhatIsCOM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IPluginOp.h"
#include <vector>
#include <atlcomcli.h>
#include <algorithm>
#include <iostream>

HRESULT GetAndCreateObj(const IID& rclsid, void** pObj)
{
	HRESULT hr = CoCreateInstance(rclsid, NULL, CLSCTX_INPROC, IID_IPluginOp, pObj); 
	return hr;
}

std::vector<CComPtr<IPluginOp>> LoadPlugins()
{
	std::vector<CComPtr<IPluginOp>> vectPlugins;
	CComPtr<IPluginOp> pCF;
	HRESULT hr = GetAndCreateObj(CLSID_AddOp, (void**) &pCF);
		if (SUCCEEDED(hr))
	{ 
		vectPlugins.push_back(pCF);
	}
	pCF = nullptr;
	hr = GetAndCreateObj(CLSID_SubOp, (void**) &pCF);
	if (SUCCEEDED(hr))
	{
		vectPlugins.push_back(pCF);
	}
	pCF = nullptr;
	hr = GetAndCreateObj(CLSID_DivOp, (void**) &pCF);
	if (SUCCEEDED(hr))
	{
		vectPlugins.push_back(pCF);
	}
	return  vectPlugins;
}

void DoOperation(const std::vector<CComPtr<IPluginOp>>& pcf)
{
	std::for_each(pcf.begin(), pcf.end(),[](CComPtr<IPluginOp> p)
	{
		std::cout << p->GetNameOperation() <<std::endl;
		std::cout << p->DoOperation( 100, 8 ) << std::endl;;
	});
}

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitialize(NULL);
	{
		std::vector<CComPtr<IPluginOp>> pcVec =  LoadPlugins();
		DoOperation(pcVec);
	}
	CoUninitialize();
	
	CoInitialize(NULL);
	{
		std::vector<CComPtr<IPluginOp>> pcVec =  LoadPlugins();
		DoOperation(pcVec);
	}
	CoUninitialize();
	return 0;
}
