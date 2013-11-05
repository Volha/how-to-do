

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Jan 04 16:12:27 2013
 */
/* Compiler settings for AddOperationATL.idl:
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

#ifndef __AddOperationATL_i_h__
#define __AddOperationATL_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDivOperation_FWD_DEFINED__
#define __IDivOperation_FWD_DEFINED__
typedef interface IDivOperation IDivOperation;
#endif 	/* __IDivOperation_FWD_DEFINED__ */


#ifndef __DivOperation_FWD_DEFINED__
#define __DivOperation_FWD_DEFINED__

#ifdef __cplusplus
typedef class DivOperation DivOperation;
#else
typedef struct DivOperation DivOperation;
#endif /* __cplusplus */

#endif 	/* __DivOperation_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDivOperation_INTERFACE_DEFINED__
#define __IDivOperation_INTERFACE_DEFINED__

/* interface IDivOperation */
/* [unique][uuid][object][oleautomation] */ 


EXTERN_C const IID IID_IDivOperation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AFE356F-9557-450F-9B78-D74C227160AB")
    IDivOperation : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DoOperation( 
            /* [in] */ SHORT param1,
            /* [in] */ SHORT param2,
            DOUBLE *result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDivOperationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDivOperation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDivOperation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDivOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoOperation )( 
            IDivOperation * This,
            /* [in] */ SHORT param1,
            /* [in] */ SHORT param2,
            DOUBLE *result);
        
        END_INTERFACE
    } IDivOperationVtbl;

    interface IDivOperation
    {
        CONST_VTBL struct IDivOperationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDivOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDivOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDivOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDivOperation_DoOperation(This,param1,param2,result)	\
    ( (This)->lpVtbl -> DoOperation(This,param1,param2,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDivOperation_INTERFACE_DEFINED__ */



#ifndef __AddOperationATLLib_LIBRARY_DEFINED__
#define __AddOperationATLLib_LIBRARY_DEFINED__

/* library AddOperationATLLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_AddOperationATLLib;

EXTERN_C const CLSID CLSID_DivOperation;

#ifdef __cplusplus

class DECLSPEC_UUID("16A961E6-4419-46FA-8D90-25CC706F99B9")
DivOperation;
#endif
#endif /* __AddOperationATLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


