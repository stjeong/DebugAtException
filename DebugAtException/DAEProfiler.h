// TestIgnore.h : Declaration of the CTestIgnore

#pragma once
#include "resource.h"       // main symbols



#include "DebugAtException_i.h"

#include "ICorProfilerCallback3Impl.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CDAEProfiler

class ATL_NO_VTABLE CDAEProfiler :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CDAEProfiler, &CLSID_DAEProfiler>,
	public IDispatchImpl<IDAEProfiler, &IID_IDAEProfiler, &LIBID_DebugAtExceptionLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public ICorProfilerCallback3Impl<CDAEProfiler>
{
public:
    CDAEProfiler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)

DECLARE_NOT_AGGREGATABLE(CDAEProfiler)

BEGIN_COM_MAP(CDAEProfiler)
	COM_INTERFACE_ENTRY(IDAEProfiler)
	COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(ICorProfilerCallback)
    COM_INTERFACE_ENTRY(ICorProfilerCallback2)
    COM_INTERFACE_ENTRY(ICorProfilerCallback3)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}
    
    STDMETHOD(Initialize)(IUnknown* pICorProfilerInfoUnk) override;
    STDMETHOD(Shutdown)() override;
    STDMETHOD(JITCompilationStarted)(FunctionID functionId, BOOL fIsSafeToBlock) override;
    STDMETHOD(ExceptionThrown)(ObjectID thrownObjectId) override;
    STDMETHOD(ExceptionSearchFunctionEnter)(FunctionID functionId) override;
    STDMETHOD(ExceptionSearchFunctionLeave)() override;

    CComQIPtr<ICorProfilerInfo> m_pICorProfilerInfo; 
    CComQIPtr<ICorProfilerInfo2> m_pICorProfilerInfo2;
    CComQIPtr<ICorProfilerInfo3> m_pICorProfilerInfo3;

public:
    
};

OBJECT_ENTRY_AUTO(__uuidof(DAEProfiler), CDAEProfiler)
