// UseDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "UseDLL.h"

#define MAXMODULE 150

char module[MAXMODULE];

extern "C" __declspec(dllexport) void NumberList() 
{
    GetModuleFileName(NULL, (LPTSTR)module, MAXMODULE);
    std::cout << "This function was called from "<< module << std::endl;
    std::cout << "NumberList(): ";
    for(int i = 0; i < 10; i++) 
    {
       std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
}

extern "C" __declspec(dllexport) void LetterList() 
{
    GetModuleFileName(NULL, (LPTSTR)module, MAXMODULE);
    std::cout << "This function was called from "<< module << std::endl;
    std::cout << "LetterList(): ";
    for(int i = 0; i < 26; i++) 
    {
       std::cout << char(97 + i) << " ";
    }
    std::cout << std::endl << std::endl;
} 