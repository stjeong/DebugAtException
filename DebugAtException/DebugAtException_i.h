

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for DebugAtException.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DebugAtException_i_h__
#define __DebugAtException_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDAEProfiler_FWD_DEFINED__
#define __IDAEProfiler_FWD_DEFINED__
typedef interface IDAEProfiler IDAEProfiler;

#endif 	/* __IDAEProfiler_FWD_DEFINED__ */


#ifndef __DAEProfiler_FWD_DEFINED__
#define __DAEProfiler_FWD_DEFINED__

#ifdef __cplusplus
typedef class DAEProfiler DAEProfiler;
#else
typedef struct DAEProfiler DAEProfiler;
#endif /* __cplusplus */

#endif 	/* __DAEProfiler_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDAEProfiler_INTERFACE_DEFINED__
#define __IDAEProfiler_INTERFACE_DEFINED__

/* interface IDAEProfiler */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDAEProfiler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("82a8e8b9-3613-42af-a487-0b7babfe968f")
    IDAEProfiler : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IDAEProfilerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDAEProfiler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDAEProfiler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDAEProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDAEProfiler * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDAEProfiler * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDAEProfiler * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDAEProfiler * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IDAEProfilerVtbl;

    interface IDAEProfiler
    {
        CONST_VTBL struct IDAEProfilerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDAEProfiler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDAEProfiler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDAEProfiler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDAEProfiler_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDAEProfiler_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDAEProfiler_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDAEProfiler_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDAEProfiler_INTERFACE_DEFINED__ */



#ifndef __DebugAtExceptionLib_LIBRARY_DEFINED__
#define __DebugAtExceptionLib_LIBRARY_DEFINED__

/* library DebugAtExceptionLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DebugAtExceptionLib;

EXTERN_C const CLSID CLSID_DAEProfiler;

#ifdef __cplusplus

class DECLSPEC_UUID("9aa43723-a2fd-4886-ba0c-ab1897214dc6")
DAEProfiler;
#endif
#endif /* __DebugAtExceptionLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


