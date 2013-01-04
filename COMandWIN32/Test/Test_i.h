

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Jan 04 16:12:27 2013
 */
/* Compiler settings for Test.idl:
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

#ifndef __Test_i_h__
#define __Test_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITestObj_FWD_DEFINED__
#define __ITestObj_FWD_DEFINED__
typedef interface ITestObj ITestObj;
#endif 	/* __ITestObj_FWD_DEFINED__ */


#ifndef __TestObj_FWD_DEFINED__
#define __TestObj_FWD_DEFINED__

#ifdef __cplusplus
typedef class TestObj TestObj;
#else
typedef struct TestObj TestObj;
#endif /* __cplusplus */

#endif 	/* __TestObj_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITestObj_INTERFACE_DEFINED__
#define __ITestObj_INTERFACE_DEFINED__

/* interface ITestObj */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITestObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ECEFB3C1-F2B8-472D-BCA5-3DD8F9C72A6C")
    ITestObj : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MyMethod( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetName( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetName2( 
            /* [retval][out] */ BSTR *name) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITestObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITestObj * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITestObj * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITestObj * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITestObj * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITestObj * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITestObj * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITestObj * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MyMethod )( 
            ITestObj * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            ITestObj * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetName2 )( 
            ITestObj * This,
            /* [retval][out] */ BSTR *name);
        
        END_INTERFACE
    } ITestObjVtbl;

    interface ITestObj
    {
        CONST_VTBL struct ITestObjVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITestObj_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITestObj_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITestObj_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITestObj_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITestObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITestObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITestObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITestObj_MyMethod(This)	\
    ( (This)->lpVtbl -> MyMethod(This) ) 

#define ITestObj_GetName(This)	\
    ( (This)->lpVtbl -> GetName(This) ) 

#define ITestObj_GetName2(This,name)	\
    ( (This)->lpVtbl -> GetName2(This,name) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITestObj_INTERFACE_DEFINED__ */



#ifndef __TestLib_LIBRARY_DEFINED__
#define __TestLib_LIBRARY_DEFINED__

/* library TestLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_TestLib;

EXTERN_C const CLSID CLSID_TestObj;

#ifdef __cplusplus

class DECLSPEC_UUID("A30225CD-1A4F-4C6A-9526-07AFF50FF2B9")
TestObj;
#endif
#endif /* __TestLib_LIBRARY_DEFINED__ */

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


