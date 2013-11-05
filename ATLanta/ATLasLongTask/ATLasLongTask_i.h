

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#ifndef __ATLasLongTask_i_h__
#define __ATLasLongTask_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILongTask_FWD_DEFINED__
#define __ILongTask_FWD_DEFINED__
typedef interface ILongTask ILongTask;
#endif 	/* __ILongTask_FWD_DEFINED__ */


#ifndef __ITest_FWD_DEFINED__
#define __ITest_FWD_DEFINED__
typedef interface ITest ITest;
#endif 	/* __ITest_FWD_DEFINED__ */


#ifndef ___ILongTaskEvents_FWD_DEFINED__
#define ___ILongTaskEvents_FWD_DEFINED__
typedef interface _ILongTaskEvents _ILongTaskEvents;
#endif 	/* ___ILongTaskEvents_FWD_DEFINED__ */


#ifndef __LongTask_FWD_DEFINED__
#define __LongTask_FWD_DEFINED__

#ifdef __cplusplus
typedef class LongTask LongTask;
#else
typedef struct LongTask LongTask;
#endif /* __cplusplus */

#endif 	/* __LongTask_FWD_DEFINED__ */


#ifndef ___ITestEvents_FWD_DEFINED__
#define ___ITestEvents_FWD_DEFINED__
typedef interface _ITestEvents _ITestEvents;
#endif 	/* ___ITestEvents_FWD_DEFINED__ */


#ifndef __Test_FWD_DEFINED__
#define __Test_FWD_DEFINED__

#ifdef __cplusplus
typedef class Test Test;
#else
typedef struct Test Test;
#endif /* __cplusplus */

#endif 	/* __Test_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ILongTask_INTERFACE_DEFINED__
#define __ILongTask_INTERFACE_DEFINED__

/* interface ILongTask */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ILongTask;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0A3DA849-D59F-48E1-975D-258904B4F6BA")
    ILongTask : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BigBangOperation( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILongTaskVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILongTask * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILongTask * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILongTask * This);
        
        HRESULT ( STDMETHODCALLTYPE *BigBangOperation )( 
            ILongTask * This);
        
        END_INTERFACE
    } ILongTaskVtbl;

    interface ILongTask
    {
        CONST_VTBL struct ILongTaskVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILongTask_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILongTask_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILongTask_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILongTask_BigBangOperation(This)	\
    ( (This)->lpVtbl -> BigBangOperation(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILongTask_INTERFACE_DEFINED__ */


#ifndef __ITest_INTERFACE_DEFINED__
#define __ITest_INTERFACE_DEFINED__

/* interface ITest */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A9A8CB65-A18F-4376-9C22-95BB73696E0F")
    ITest : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ITestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITest * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITest * This);
        
        END_INTERFACE
    } ITestVtbl;

    interface ITest
    {
        CONST_VTBL struct ITestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITest_INTERFACE_DEFINED__ */



#ifndef __ATLasLongTaskLib_LIBRARY_DEFINED__
#define __ATLasLongTaskLib_LIBRARY_DEFINED__

/* library ATLasLongTaskLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ATLasLongTaskLib;

#ifndef ___ILongTaskEvents_INTERFACE_DEFINED__
#define ___ILongTaskEvents_INTERFACE_DEFINED__

/* interface _ILongTaskEvents */
/* [uuid] */ 


EXTERN_C const IID IID__ILongTaskEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("92022BAC-C005-407E-A0C9-58167070B2A3")
    _ILongTaskEvents
    {
    public:
        BEGIN_INTERFACE
        virtual HRESULT STDMETHODCALLTYPE OnError( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Test( void) = 0;
        
        END_INTERFACE
    };
    
#else 	/* C style interface */

    typedef struct _ILongTaskEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *OnError )( 
            _ILongTaskEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *Test )( 
            _ILongTaskEvents * This);
        
        END_INTERFACE
    } _ILongTaskEventsVtbl;

    interface _ILongTaskEvents
    {
        CONST_VTBL struct _ILongTaskEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ILongTaskEvents_OnError(This)	\
    ( (This)->lpVtbl -> OnError(This) ) 

#define _ILongTaskEvents_Test(This)	\
    ( (This)->lpVtbl -> Test(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___ILongTaskEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LongTask;

#ifdef __cplusplus

class DECLSPEC_UUID("EBF07F07-03B6-45EA-B830-AC1267A4810F")
LongTask;
#endif

#ifndef ___ITestEvents_INTERFACE_DEFINED__
#define ___ITestEvents_INTERFACE_DEFINED__

/* interface _ITestEvents */
/* [object][uuid] */ 


EXTERN_C const IID IID__ITestEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3D3C888B-0875-4F0A-8156-40F360CFCC7F")
    _ITestEvents : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct _ITestEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ITestEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ITestEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ITestEvents * This);
        
        END_INTERFACE
    } _ITestEventsVtbl;

    interface _ITestEvents
    {
        CONST_VTBL struct _ITestEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ITestEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ITestEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ITestEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___ITestEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Test;

#ifdef __cplusplus

class DECLSPEC_UUID("E59C5788-B210-4A8B-8D9E-C5E56C02983E")
Test;
#endif
#endif /* __ATLasLongTaskLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


