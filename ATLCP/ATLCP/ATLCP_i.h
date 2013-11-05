

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ATLCP_i_h__
#define __ATLCP_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISimple_FWD_DEFINED__
#define __ISimple_FWD_DEFINED__
typedef interface ISimple ISimple;
#endif 	/* __ISimple_FWD_DEFINED__ */


#ifndef ___ISimpleEvents_FWD_DEFINED__
#define ___ISimpleEvents_FWD_DEFINED__
typedef interface _ISimpleEvents _ISimpleEvents;
#endif 	/* ___ISimpleEvents_FWD_DEFINED__ */


#ifndef __Simple_FWD_DEFINED__
#define __Simple_FWD_DEFINED__

#ifdef __cplusplus
typedef class Simple Simple;
#else
typedef struct Simple Simple;
#endif /* __cplusplus */

#endif 	/* __Simple_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISimple_INTERFACE_DEFINED__
#define __ISimple_INTERFACE_DEFINED__

/* interface ISimple */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISimple;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("46AFF237-53BA-4904-A4BC-E5ABEB35B6AE")
    ISimple : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE TestMethod( 
            BSTR s) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISimpleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimple * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimple * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimple * This);
        
        HRESULT ( STDMETHODCALLTYPE *TestMethod )( 
            ISimple * This,
            BSTR s);
        
        END_INTERFACE
    } ISimpleVtbl;

    interface ISimple
    {
        CONST_VTBL struct ISimpleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimple_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimple_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimple_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimple_TestMethod(This,s)	\
    ( (This)->lpVtbl -> TestMethod(This,s) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimple_INTERFACE_DEFINED__ */



#ifndef __ATLCPLib_LIBRARY_DEFINED__
#define __ATLCPLib_LIBRARY_DEFINED__

/* library ATLCPLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ATLCPLib;

#ifndef ___ISimpleEvents_INTERFACE_DEFINED__
#define ___ISimpleEvents_INTERFACE_DEFINED__

/* interface _ISimpleEvents */
/* [uuid] */ 


EXTERN_C const IID IID__ISimpleEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9E38636D-1B74-49C0-9085-4E2486705810")
    _ISimpleEvents
    {
    public:
        BEGIN_INTERFACE
        virtual HRESULT STDMETHODCALLTYPE OnFire( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnError( 
            BSTR desc) = 0;
        
        END_INTERFACE
    };
    
#else 	/* C style interface */

    typedef struct _ISimpleEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *OnFire )( 
            _ISimpleEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnError )( 
            _ISimpleEvents * This,
            BSTR desc);
        
        END_INTERFACE
    } _ISimpleEventsVtbl;

    interface _ISimpleEvents
    {
        CONST_VTBL struct _ISimpleEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISimpleEvents_OnFire(This)	\
    ( (This)->lpVtbl -> OnFire(This) ) 

#define _ISimpleEvents_OnError(This,desc)	\
    ( (This)->lpVtbl -> OnError(This,desc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___ISimpleEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Simple;

#ifdef __cplusplus

class DECLSPEC_UUID("F6E873C7-F4FC-40E1-8BDA-DD322B7EF9D0")
Simple;
#endif
#endif /* __ATLCPLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


