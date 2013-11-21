

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ILongTask,0x0A3DA849,0xD59F,0x48E1,0x97,0x5D,0x25,0x89,0x04,0xB4,0xF6,0xBA);


MIDL_DEFINE_GUID(IID, IID_ITest,0xA9A8CB65,0xA18F,0x4376,0x9C,0x22,0x95,0xBB,0x73,0x69,0x6E,0x0F);


MIDL_DEFINE_GUID(IID, LIBID_ATLasLongTaskLib,0x981FDB33,0x93C5,0x4B01,0x88,0x76,0xC5,0xCD,0x00,0xE6,0x14,0x8B);


MIDL_DEFINE_GUID(IID, IID__ILongTaskEvents,0x92022BAC,0xC005,0x407E,0xA0,0xC9,0x58,0x16,0x70,0x70,0xB2,0xA3);


MIDL_DEFINE_GUID(CLSID, CLSID_LongTask,0xEBF07F07,0x03B6,0x45EA,0xB8,0x30,0xAC,0x12,0x67,0xA4,0x81,0x0F);


MIDL_DEFINE_GUID(IID, IID__ITestEvents,0x3D3C888B,0x0875,0x4F0A,0x81,0x56,0x40,0xF3,0x60,0xCF,0xCC,0x7F);


MIDL_DEFINE_GUID(CLSID, CLSID_Test,0xE59C5788,0xB210,0x4A8B,0x8D,0x9E,0xC5,0xE5,0x6C,0x02,0x98,0x3E);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



