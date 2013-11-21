

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Jan 05 15:03:18 2013
 */
/* Compiler settings for ATLasLongTask.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "ATLasLongTask_i.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   31                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _ATLasLongTask_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } ATLasLongTask_MIDL_TYPE_FORMAT_STRING;

typedef struct _ATLasLongTask_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } ATLasLongTask_MIDL_PROC_FORMAT_STRING;

typedef struct _ATLasLongTask_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } ATLasLongTask_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const ATLasLongTask_MIDL_TYPE_FORMAT_STRING ATLasLongTask__MIDL_TypeFormatString;
extern const ATLasLongTask_MIDL_PROC_FORMAT_STRING ATLasLongTask__MIDL_ProcFormatString;
extern const ATLasLongTask_MIDL_EXPR_FORMAT_STRING ATLasLongTask__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILongTask_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ILongTask_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITest_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITest_ProxyInfo;



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const ATLasLongTask_MIDL_PROC_FORMAT_STRING ATLasLongTask__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure BigBangOperation */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 24 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const ATLasLongTask_MIDL_TYPE_FORMAT_STRING ATLasLongTask__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ILongTask, ver. 0.0,
   GUID={0x0A3DA849,0xD59F,0x48E1,{0x97,0x5D,0x25,0x89,0x04,0xB4,0xF6,0xBA}} */

#pragma code_seg(".orpc")
static const unsigned short ILongTask_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ILongTask_ProxyInfo =
    {
    &Object_StubDesc,
    ATLasLongTask__MIDL_ProcFormatString.Format,
    &ILongTask_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ILongTask_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    ATLasLongTask__MIDL_ProcFormatString.Format,
    &ILongTask_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _ILongTaskProxyVtbl = 
{
    &ILongTask_ProxyInfo,
    &IID_ILongTask,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* ILongTask::BigBangOperation */
};

const CInterfaceStubVtbl _ILongTaskStubVtbl =
{
    &IID_ILongTask,
    &ILongTask_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITest, ver. 0.0,
   GUID={0xA9A8CB65,0xA18F,0x4376,{0x9C,0x22,0x95,0xBB,0x73,0x69,0x6E,0x0F}} */

#pragma code_seg(".orpc")
static const unsigned short ITest_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ITest_ProxyInfo =
    {
    &Object_StubDesc,
    ATLasLongTask__MIDL_ProcFormatString.Format,
    &ITest_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ITest_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    ATLasLongTask__MIDL_ProcFormatString.Format,
    &ITest_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _ITestProxyVtbl = 
{
    0,
    &IID_ITest,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _ITestStubVtbl =
{
    &IID_ITest,
    &ITest_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    ATLasLongTask__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x700022b, /* MIDL Version 7.0.555 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _ATLasLongTask_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ILongTaskProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITestProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _ATLasLongTask_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ILongTaskStubVtbl,
    ( CInterfaceStubVtbl *) &_ITestStubVtbl,
    0
};

PCInterfaceName const _ATLasLongTask_InterfaceNamesList[] = 
{
    "ILongTask",
    "ITest",
    0
};


#define _ATLasLongTask_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _ATLasLongTask, pIID, n)

int __stdcall _ATLasLongTask_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _ATLasLongTask, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _ATLasLongTask, 2, *pIndex )
    
}

const ExtendedProxyFileInfo ATLasLongTask_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _ATLasLongTask_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _ATLasLongTask_StubVtblList,
    (const PCInterfaceName * ) & _ATLasLongTask_InterfaceNamesList,
    0, /* no delegation */
    & _ATLasLongTask_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

