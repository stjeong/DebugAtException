#pragma once

#include <atlbase.h>

#pragma comment (lib, "corguids.lib")

template<class T>
class ATL_NO_VTABLE ICorProfilerCallbackImpl : public ICorProfilerCallback
{
public:
	ICorProfilerCallbackImpl() {};
	virtual ~ICorProfilerCallbackImpl() {};

	STDMETHOD(QueryInterface)(REFIID riid, void** ppvObject) = 0;
	_ATL_DEBUG_ADDREF_RELEASE_IMPL(ICorProfilerCallbackImpl)

	STDMETHOD(Initialize)(IUnknown * pICorProfilerInfoUnk)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(Shutdown)()
	{
		return E_NOTIMPL;
	}

	STDMETHOD(AppDomainCreationStarted)(AppDomainID appDomainId)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(AppDomainCreationFinished)(AppDomainID appDomainId, HRESULT hrStatus)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(AppDomainShutdownStarted)(AppDomainID appDomainId)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(AppDomainShutdownFinished)(AppDomainID appDomainId, HRESULT hrStatus)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(AssemblyLoadStarted)(AssemblyID assemblyId)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(AssemblyLoadFinished)(AssemblyID assemblyId, HRESULT hrStatus)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(AssemblyUnloadStarted)(AssemblyID assemblyId)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(AssemblyUnloadFinished)(AssemblyID assemblyId, HRESULT hrStatus)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(ModuleLoadStarted)(ModuleID moduleId)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(ModuleLoadFinished)(ModuleID moduleId, HRESULT hrStatus)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(ModuleUnloadStarted)(ModuleID moduleId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ModuleUnloadFinished)(ModuleID moduleId, HRESULT hrStatus)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(ModuleAttachedToAssembly)(ModuleID moduleId, AssemblyID assemblyId)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(ClassLoadStarted)(ClassID classId)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(ClassLoadFinished)(ClassID classId, HRESULT hrStatus)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(ClassUnloadStarted)(ClassID classId)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(ClassUnloadFinished)(ClassID classId, HRESULT hrStatus)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(FunctionUnloadStarted)(FunctionID functionId)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(JITCompilationStarted)(FunctionID functionId, BOOL fIsSafeToBlock)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(JITCompilationFinished)(FunctionID functionId, HRESULT hrStatus,
                                        BOOL fIsSafeToBlock)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(JITCachedFunctionSearchStarted)(FunctionID functionId,
                                                BOOL * pbUseCachedFunction)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(JITCachedFunctionSearchFinished)(FunctionID functionId,
                                                COR_PRF_JIT_CACHE result)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(JITFunctionPitched)(FunctionID functionId)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(JITInlining)(FunctionID callerId, FunctionID calleeId,
                            BOOL * pfShouldInline)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ThreadCreated)(ThreadID threadId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ThreadDestroyed)(ThreadID threadId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ThreadAssignedToOSThread)(ThreadID managedThreadId,
                                            ULONG osThreadId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RemotingClientInvocationStarted)()
	{
		return E_NOTIMPL;
	}
	
    STDMETHOD(RemotingClientSendingMessage)(GUID * pCookie, BOOL fIsAsync)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(RemotingClientReceivingReply)(GUID * pCookie, BOOL fIsAsync)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RemotingClientInvocationFinished)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RemotingServerReceivingMessage)(GUID * pCookie, BOOL fIsAsync)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RemotingServerInvocationStarted)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RemotingServerInvocationReturned)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RemotingServerSendingReply)(GUID * pCookie, BOOL fIsAsync)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(UnmanagedToManagedTransition)(FunctionID functionId,
                                            COR_PRF_TRANSITION_REASON reason)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ManagedToUnmanagedTransition)(FunctionID functionId,
                                            COR_PRF_TRANSITION_REASON reason)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RuntimeSuspendStarted)(COR_PRF_SUSPEND_REASON suspendReason)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RuntimeSuspendFinished)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RuntimeSuspendAborted)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RuntimeResumeStarted)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RuntimeResumeFinished)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RuntimeThreadSuspended)(ThreadID threadId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RuntimeThreadResumed)(ThreadID threadId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(MovedReferences)(ULONG cMovedObjectIDRanges,
                                ObjectID oldObjectIDRangeStart[],
                                ObjectID newObjectIDRangeStart[],
                                ULONG cObjectIDRangeLength[])
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ObjectAllocated)(ObjectID objectId, ClassID classId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ObjectsAllocatedByClass)(ULONG cClassCount, ClassID classIds[],
                                        ULONG cObjects[])
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ObjectReferences)(ObjectID objectId, ClassID classId,
                                    ULONG cObjectRefs, ObjectID objectRefIds[])
	{
		return E_NOTIMPL;
	}

    STDMETHOD(RootReferences)(ULONG cRootRefs, ObjectID rootRefIds[])
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionThrown)(ObjectID thrownObjectId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionSearchFunctionEnter)(FunctionID functionId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionSearchFunctionLeave)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionSearchFilterEnter)(FunctionID functionId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionSearchFilterLeave)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionSearchCatcherFound)(FunctionID functionId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionOSHandlerEnter)(FunctionID functionId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionOSHandlerLeave)(FunctionID functionId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionUnwindFunctionEnter)(FunctionID functionId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionUnwindFunctionLeave)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionUnwindFinallyEnter)(FunctionID functionId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionUnwindFinallyLeave)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionCatcherEnter)(FunctionID functionId, ObjectID objectId)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionCatcherLeave)()
	{
		return E_NOTIMPL;
	}

    STDMETHOD(COMClassicVTableCreated)(ClassID wrappedClassId,
                        REFGUID implementedIID, void *pVTable, ULONG cSlots)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(COMClassicVTableDestroyed)(ClassID wrappedClassId,
                        REFGUID implementedIID, void *pVTable)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionCLRCatcherFound)(void)
	{
		return E_NOTIMPL;
	}

    STDMETHOD(ExceptionCLRCatcherExecute)(void)
	{
		return E_NOTIMPL;
	}
};
