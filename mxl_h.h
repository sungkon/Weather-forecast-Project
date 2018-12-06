

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Dec 03 16:03:00 2018
 */
/* Compiler settings for mxl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
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


#ifndef __mxl_h_h__
#define __mxl_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Imxl_FWD_DEFINED__
#define __Imxl_FWD_DEFINED__
typedef interface Imxl Imxl;

#endif 	/* __Imxl_FWD_DEFINED__ */


#ifndef __mxl_FWD_DEFINED__
#define __mxl_FWD_DEFINED__

#ifdef __cplusplus
typedef class mxl mxl;
#else
typedef struct mxl mxl;
#endif /* __cplusplus */

#endif 	/* __mxl_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __mxl_LIBRARY_DEFINED__
#define __mxl_LIBRARY_DEFINED__

/* library mxl */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_mxl;

#ifndef __Imxl_DISPINTERFACE_DEFINED__
#define __Imxl_DISPINTERFACE_DEFINED__

/* dispinterface Imxl */
/* [uuid] */ 


EXTERN_C const IID DIID_Imxl;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E48FA626-FCAD-4106-A7F3-AD79F860587E")
    Imxl : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ImxlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Imxl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Imxl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Imxl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Imxl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Imxl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Imxl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Imxl * This,
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
    } ImxlVtbl;

    interface Imxl
    {
        CONST_VTBL struct ImxlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Imxl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Imxl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Imxl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Imxl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Imxl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Imxl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Imxl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __Imxl_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_mxl;

#ifdef __cplusplus

class DECLSPEC_UUID("499EAC6E-E52D-4750-99EC-DB0853D183EA")
mxl;
#endif
#endif /* __mxl_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


