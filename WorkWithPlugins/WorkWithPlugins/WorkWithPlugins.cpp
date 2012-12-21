// WorkWithPlugins.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include "IPlugin.h"
#include "HModuleWrapper.h"

std::vector<HModuleWrapper> LoadPlugins()
{
	TCHAR szPath[MAX_PATH] = {0};
	if( !GetModuleFileName( NULL, szPath, MAX_PATH ) )
    {
        printf("Cannot find (%d)\n", GetLastError()); 
    }

	std::wstring pathWithExe(szPath);
	std::wstring pathPlugins;
	pathPlugins.assign(pathWithExe, 0, pathWithExe.find(L"WorkWithPlugins.exe"));
	pathPlugins.append(L"Plugins\\*.dll");
	
	WIN32_FIND_DATAW FindFileData;
	std::vector<HModuleWrapper> listPlugins;
	HANDLE hFind = FindFirstFile(pathPlugins.c_str(), &FindFileData);
	
	if(hFind == INVALID_HANDLE_VALUE)
	{
		std::cout << "FindFirstFile failed " << GetLastError() << std::endl;
	}
	else
	{
		std::string str;
		do
		{
			std::wcout << "Found \n"<< FindFileData.cFileName << std::endl; 
			IPlugin* pPlugin = nullptr;
			listPlugins.push_back(HModuleWrapper(FindFileData.cFileName));
		}
		while(FindNextFile(hFind, &FindFileData));
	}
	FindClose(hFind);
	return listPlugins;
}

typedef HRESULT (*GETPLUGIN)(IPlugin** pPlugin);
typedef HRESULT (*FREEPLUGIN)(IPlugin** pPlugin);

int _tmain  (int argc, _TCHAR* argv[])
{
	std::vector<HModuleWrapper> loadedPlugins = LoadPlugins();
	IPlugin* pPlugin = nullptr;
	try
	{
		for(int i = 0; i != loadedPlugins.size(); ++i)
		{
			if (!loadedPlugins[i])
			{
				throw std::runtime_error("The DLL haven't been found");
			}
			auto pfnPlugin = (GETPLUGIN)loadedPlugins[i].GetProcedure("GetPlugin");
			if (pfnPlugin == nullptr)
			{
				throw std::runtime_error("The command or plugin didn't find");
			}
			HRESULT hr = pfnPlugin(&pPlugin);
			if (!FAILED(hr))
			{
				pPlugin->DoOperation(2, 3);
				std::cout << pPlugin->GetNameOperation() << std::endl;

				pPlugin->Release();
				pPlugin = nullptr;
			}
		}
	}

	catch(const std::runtime_error& ia)
	{
		std::cout << ia.what() << std::endl;
	}
	return 0;
}

