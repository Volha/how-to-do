

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Jan 05 14:44:20 2013
 */
/* Compiler settings for ATLCP.idl:
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

MIDL_DEFINE_GUID(IID, IID_ISimple,0x46AFF237,0x53BA,0x4904,0xA4,0xBC,0xE5,0xAB,0xEB,0x35,0xB6,0xAE);


MIDL_DEFINE_GUID(IID, LIBID_ATLCPLib,0xC261272F,0xBEA9,0x4377,0x8A,0xB5,0x6E,0x99,0x92,0x76,0x07,0x26);


MIDL_DEFINE_GUID(IID, IID__ISimpleEvents,0x9E38636D,0x1B74,0x49C0,0x90,0x85,0x4E,0x24,0x86,0x70,0x58,0x10);


MIDL_DEFINE_GUID(CLSID, CLSID_Simple,0xF6E873C7,0xF4FC,0x40E1,0x8B,0xDA,0xDD,0x32,0x2B,0x7E,0xF9,0xD0);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



