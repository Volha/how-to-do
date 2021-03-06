#pragma once
#include "windows.h"
#include <string>
#include <Unknwn.h>
#include <atlcomcli.h>
//#include <InitGuid.h>


// {C3012071-E87D-486D-AD6A-FFCCA978118A}
DEFINE_GUID(CLSID_SubOp, 
0xc3012071, 0xe87d, 0x486d, 0xad, 0x6a, 0xff, 0xcc, 0xa9, 0x78, 0x11, 0x8a);

// {DFBBDC18-533C-411F-A27A-5684C6FD83A3}
DEFINE_GUID( CLSID_AddOp, 
	0xdfbbdc18, 0x533c, 0x411f, 0xa2, 0x7a, 0x56, 0x84, 0xc6, 0xfd, 0x83, 0xa3);

// {3DD44D46-F5F6-4052-B012-47952AF04496}
DEFINE_GUID( CLSID_DivOp, 
	0x3dd44d46, 0xf5f6, 0x4052, 0xb0, 0x12, 0x47, 0x95, 0x2a, 0xf0, 0x44, 0x96);

DEFINE_GUID( IID_IPluginOp, 
	0xdb64b6d2, 0x7012, 0x4fd2, 0xaf, 0xfa, 0x31, 0x4c, 0x54, 0x1a, 0x3a, 0xb3);


class IPluginOp : public IUnknown
{
public:
	virtual HRESULT DoOperation(int a, int b, long double& res) = 0;
	virtual HRESULT GetNameOperation(BSTR* name) = 0;
};

// {2CFF9EA9-FFA6-42CF-A2A4-60488D6E113D}
DEFINE_GUID(IID_IMyEvents, 
0x2cff9ea9, 0xffa6, 0x42cf, 0xa2, 0xa4, 0x60, 0x48, 0x8d, 0x6e, 0x11, 0x3d);

interface IMyEvents : IUnknown
{
	virtual HRESULT OnError(DWORD error) = 0;
};