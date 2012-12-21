#pragma once
#include <Unknwn.h>
#include "windows.h"

class IClassFactory1 : public IUnknown
{
public:
   virtual HRESULT GetPlugin(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj) = 0;
};