

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Jan 05 16:58:51 2013
 */
/* Compiler settings for ATLas.idl:
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

#ifndef __ATLas_i_h__
#define __ATLas_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILongTask_FWD_DEFINED__
#define __ILongTask_FWD_DEFINED__
typedef interface ILongTask ILongTask;
#endif 	/* __ILongTask_FWD_DEFINED__ */


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
    
    MIDL_INTERFACE("04892F11-7AC2-4C45-AEA9-8FB438884C9E")
    ILongTask : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BingBandOperation( void) = 0;
        
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
        
        HRESULT ( STDMETHODCALLTYPE *BingBandOperation )( 
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


#define ILongTask_BingBandOperation(This)	\
    ( (This)->lpVtbl -> BingBandOperation(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILongTask_INTERFACE_DEFINED__ */



#ifndef __ATLasLib_LIBRARY_DEFINED__
#define __ATLasLib_LIBRARY_DEFINED__

/* library ATLasLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ATLasLib;

#ifndef ___ILongTaskEvents_INTERFACE_DEFINED__
#define ___ILongTaskEvents_INTERFACE_DEFINED__

/* interface _ILongTaskEvents */
/* [object][uuid] */ 


EXTERN_C const IID IID__ILongTaskEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5DF9179B-C5F3-45A0-B17F-38CCB6B8E470")
    _ILongTaskEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnFinish( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _ILongTaskEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ILongTaskEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ILongTaskEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ILongTaskEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnFinish )( 
            _ILongTaskEvents * This);
        
        END_INTERFACE
    } _ILongTaskEventsVtbl;

    interface _ILongTaskEvents
    {
        CONST_VTBL struct _ILongTaskEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ILongTaskEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ILongTaskEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ILongTaskEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ILongTaskEvents_OnFinish(This)	\
    ( (This)->lpVtbl -> OnFinish(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___ILongTaskEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LongTask;

#ifdef __cplusplus

class DECLSPEC_UUID("0882B6B4-F8DB-430E-BE99-42F27706B51A")
LongTask;
#endif
#endif /* __ATLasLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


