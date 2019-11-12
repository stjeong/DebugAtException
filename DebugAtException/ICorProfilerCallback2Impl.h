#pragma once

#include <cor.h>
#include <corprof.h>

#include <atlbase.h>

#pragma comment (lib, "corguids.lib")
#include "ICorProfilerCallbackImpl.h"

template<class T>
class ATL_NO_VTABLE ICorProfilerCallback2Impl : 
    public ICorProfilerCallback2
{
public:

    ICorProfilerCallback2Impl() {};
    virtual ~ICorProfilerCallback2Impl() {};

    STDMETHOD(QueryInterface)(REFIID riid, void** ppvObject) = 0;
    _ATL_DEBUG_ADDREF_RELEASE_IMPL(ICorProfilerCallback2Impl)

    STDMETHOD(Initialize)(IUnknown * pICorProfilerInfoUnk)
    {
        UNREFERENCED_PARAMETER(pICorProfilerInfoUnk);
        return E_NOTIMPL;
    }

    STDMETHOD(Shutdown)()
    {
        return E_NOTIMPL;
    }

    STDMETHOD(AppDomainCreationStarted)(AppDomainID appDomainId)
    {
        UNREFERENCED_PARAMETER(appDomainId);
        return E_NOTIMPL;
    }

    STDMETHOD(AppDomainCreationFinished)(AppDomainID appDomainId, HRESULT hrStatus)
    {
        UNREFERENCED_PARAMETER(appDomainId);
        UNREFERENCED_PARAMETER(hrStatus);
        return E_NOTIMPL;
    }

    STDMETHOD(AppDomainShutdownStarted)(AppDomainID appDomainId)
    {
        UNREFERENCED_PARAMETER(appDomainId);
        return E_NOTIMPL;
    }

    STDMETHOD(AppDomainShutdownFinished)(AppDomainID appDomainId, HRESULT hrStatus)
    {
        UNREFERENCED_PARAMETER(appDomainId);
        UNREFERENCED_PARAMETER(hrStatus);
        return E_NOTIMPL;
    }

    STDMETHOD(AssemblyLoadStarted)(AssemblyID assemblyId)
    {
        UNREFERENCED_PARAMETER(assemblyId);
        return S_OK;
    }

    STDMETHOD(AssemblyLoadFinished)(AssemblyID assemblyId, HRESULT hrStatus)
    {
        UNREFERENCED_PARAMETER(assemblyId);
        UNREFERENCED_PARAMETER(hrStatus);
        return S_OK;
    }

    STDMETHOD(AssemblyUnloadStarted)(AssemblyID assemblyId)
    {
        UNREFERENCED_PARAMETER(assemblyId);
        return E_NOTIMPL;
    }

    STDMETHOD(AssemblyUnloadFinished)(AssemblyID assemblyId, HRESULT hrStatus)
    {
        UNREFERENCED_PARAMETER(assemblyId);
        UNREFERENCED_PARAMETER(hrStatus);
        return E_NOTIMPL;
    }

    STDMETHOD(ModuleLoadStarted)(ModuleID moduleId)
    {
        UNREFERENCED_PARAMETER(moduleId);
        return S_OK;
    }

    STDMETHOD(ModuleLoadFinished)(ModuleID moduleId, HRESULT hrStatus)
    {
        UNREFERENCED_PARAMETER(moduleId);
        UNREFERENCED_PARAMETER(hrStatus);
        return S_OK;
    }

    STDMETHOD(ModuleUnloadStarted)(ModuleID moduleId)
    {
        UNREFERENCED_PARAMETER(moduleId);
        return E_NOTIMPL;
    }

    STDMETHOD(ModuleUnloadFinished)(ModuleID moduleId, HRESULT hrStatus)
    {
        UNREFERENCED_PARAMETER(moduleId);
        UNREFERENCED_PARAMETER(hrStatus);
        return E_NOTIMPL;
    }

    STDMETHOD(ModuleAttachedToAssembly)(ModuleID moduleId, AssemblyID assemblyId)
    {
        UNREFERENCED_PARAMETER(moduleId);
        UNREFERENCED_PARAMETER(assemblyId);
        return S_OK;
    }

    STDMETHOD(ClassLoadStarted)(ClassID classId)
    {
        UNREFERENCED_PARAMETER(classId);
        return E_NOTIMPL;
    }

    STDMETHOD(ClassLoadFinished)(ClassID classId, HRESULT hrStatus)
    {
        UNREFERENCED_PARAMETER(classId);
        UNREFERENCED_PARAMETER(hrStatus);
        return E_NOTIMPL;
    }

    STDMETHOD(ClassUnloadStarted)(ClassID classId)
    {
        UNREFERENCED_PARAMETER(classId);
        return E_NOTIMPL;
    }

    STDMETHOD(ClassUnloadFinished)(ClassID classId, HRESULT hrStatus)
    {
        UNREFERENCED_PARAMETER(classId);
        UNREFERENCED_PARAMETER(hrStatus);
        return E_NOTIMPL;
    }

    STDMETHOD(FunctionUnloadStarted)(FunctionID functionId)
    {
        UNREFERENCED_PARAMETER(functionId);
        return E_NOTIMPL;
    }

    STDMETHOD(JITCompilationStarted)(FunctionID functionId, BOOL fIsSafeToBlock)
    {
        UNREFERENCED_PARAMETER(functionId);
        UNREFERENCED_PARAMETER(fIsSafeToBlock);
        return S_OK;
    }

    STDMETHOD(JITCompilationFinished)(FunctionID functionId, HRESULT hrStatus,
                                        BOOL fIsSafeToBlock)
    {
        UNREFERENCED_PARAMETER(functionId);
        UNREFERENCED_PARAMETER(hrStatus);
        UNREFERENCED_PARAMETER(fIsSafeToBlock);
        return S_OK;
    }

    STDMETHOD(JITCachedFunctionSearchStarted)(FunctionID functionId,
                                                BOOL * pbUseCachedFunction)
    {
        UNREFERENCED_PARAMETER(functionId);
        UNREFERENCED_PARAMETER(pbUseCachedFunction);
        return E_NOTIMPL;
    }

    STDMETHOD(JITCachedFunctionSearchFinished)(FunctionID functionId,
                                                COR_PRF_JIT_CACHE result)
    {
        UNREFERENCED_PARAMETER(functionId);
        UNREFERENCED_PARAMETER(result);
        return E_NOTIMPL;
    }

    STDMETHOD(JITFunctionPitched)(FunctionID functionId)
    {
        UNREFERENCED_PARAMETER(functionId);
        return E_NOTIMPL;
    }

    STDMETHOD(JITInlining)(FunctionID callerId, FunctionID calleeId,
                            BOOL * pfShouldInline)
    {
        UNREFERENCED_PARAMETER(callerId);
        UNREFERENCED_PARAMETER(calleeId);
        UNREFERENCED_PARAMETER(pfShouldInline);
        return E_NOTIMPL;
    }

    STDMETHOD(ThreadCreated)(ThreadID threadId)
    {
        UNREFERENCED_PARAMETER(threadId);
        return E_NOTIMPL;
    }

    STDMETHOD(ThreadDestroyed)(ThreadID threadId)
    {
        UNREFERENCED_PARAMETER(threadId);
        return E_NOTIMPL;
    }

    STDMETHOD(ThreadAssignedToOSThread)(ThreadID managedThreadId,
                                            ULONG osThreadId)
    {
        UNREFERENCED_PARAMETER(managedThreadId);
        UNREFERENCED_PARAMETER(osThreadId);
        return E_NOTIMPL;
    }

    STDMETHOD(RemotingClientInvocationStarted)()
    {
        return E_NOTIMPL;
    }
    
    STDMETHOD(RemotingClientSendingMessage)(GUID * pCookie, BOOL fIsAsync)
    {
        UNREFERENCED_PARAMETER(pCookie);
        UNREFERENCED_PARAMETER(fIsAsync);
        return E_NOTIMPL;
    }

    STDMETHOD(RemotingClientReceivingReply)(GUID * pCookie, BOOL fIsAsync)
    {
        UNREFERENCED_PARAMETER(pCookie);
        UNREFERENCED_PARAMETER(fIsAsync);
        return E_NOTIMPL;
    }

    STDMETHOD(RemotingClientInvocationFinished)()
    {
        return E_NOTIMPL;
    }

    STDMETHOD(RemotingServerReceivingMessage)(GUID * pCookie, BOOL fIsAsync)
    {
        UNREFERENCED_PARAMETER(pCookie);
        UNREFERENCED_PARAMETER(fIsAsync);
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
        UNREFERENCED_PARAMETER(pCookie);
        UNREFERENCED_PARAMETER(fIsAsync);
        return E_NOTIMPL;
    }

    STDMETHOD(UnmanagedToManagedTransition)(FunctionID functionId,
                                            COR_PRF_TRANSITION_REASON reason)
    {
        UNREFERENCED_PARAMETER(functionId);
        UNREFERENCED_PARAMETER(reason);
        return E_NOTIMPL;
    }

    STDMETHOD(ManagedToUnmanagedTransition)(FunctionID functionId,
                                            COR_PRF_TRANSITION_REASON reason)
    {
        UNREFERENCED_PARAMETER(functionId);
        UNREFERENCED_PARAMETER(reason);
        return E_NOTIMPL;
    }

    STDMETHOD(RuntimeSuspendStarted)(COR_PRF_SUSPEND_REASON suspendReason)
    {
        UNREFERENCED_PARAMETER(suspendReason);
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
        UNREFERENCED_PARAMETER(threadId);
        return E_NOTIMPL;
    }

    STDMETHOD(RuntimeThreadResumed)(ThreadID threadId)
    {
        UNREFERENCED_PARAMETER(threadId);
        return E_NOTIMPL;
    }

    STDMETHOD(MovedReferences)(ULONG cMovedObjectIDRanges,
                                ObjectID oldObjectIDRangeStart[],
                                ObjectID newObjectIDRangeStart[],
                                ULONG cObjectIDRangeLength[])
    {
        UNREFERENCED_PARAMETER(cMovedObjectIDRanges);
        UNREFERENCED_PARAMETER(oldObjectIDRangeStart);
        UNREFERENCED_PARAMETER(newObjectIDRangeStart);
        UNREFERENCED_PARAMETER(cObjectIDRangeLength);
        return E_NOTIMPL;
    }

    STDMETHOD(ObjectAllocated)(ObjectID objectId, ClassID classId)
    {
        UNREFERENCED_PARAMETER(objectId);
        UNREFERENCED_PARAMETER(classId);
        return E_NOTIMPL;
    }

    STDMETHOD(ObjectsAllocatedByClass)(ULONG cClassCount, ClassID classIds[],
                                        ULONG cObjects[])
    {
        UNREFERENCED_PARAMETER(cClassCount);
        UNREFERENCED_PARAMETER(classIds);
        UNREFERENCED_PARAMETER(cObjects);
        return E_NOTIMPL;
    }

    STDMETHOD(ObjectReferences)(ObjectID objectId, ClassID classId,
                                    ULONG cObjectRefs, ObjectID objectRefIds[])
    {
        UNREFERENCED_PARAMETER(objectId);
        UNREFERENCED_PARAMETER(classId);
        UNREFERENCED_PARAMETER(cObjectRefs);
        UNREFERENCED_PARAMETER(objectRefIds);
        return E_NOTIMPL;
    }

    STDMETHOD(RootReferences)(ULONG cRootRefs, ObjectID rootRefIds[])
    {
        UNREFERENCED_PARAMETER(cRootRefs);
        UNREFERENCED_PARAMETER(rootRefIds);
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionThrown)(ObjectID thrownObjectId)
    {
        UNREFERENCED_PARAMETER(thrownObjectId);
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionSearchFunctionEnter)(FunctionID functionId)
    {
        UNREFERENCED_PARAMETER(functionId);
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionSearchFunctionLeave)()
    {
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionSearchFilterEnter)(FunctionID functionId)
    {
        UNREFERENCED_PARAMETER(functionId);
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionSearchFilterLeave)()
    {
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionSearchCatcherFound)(FunctionID functionId)
    {
        UNREFERENCED_PARAMETER(functionId);
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionOSHandlerEnter)(FunctionID functionId)
    {
        UNREFERENCED_PARAMETER(functionId);
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionOSHandlerLeave)(FunctionID functionId)
    {
        UNREFERENCED_PARAMETER(functionId);
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionUnwindFunctionEnter)(FunctionID functionId)
    {
        UNREFERENCED_PARAMETER(functionId);
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionUnwindFunctionLeave)()
    {
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionUnwindFinallyEnter)(FunctionID functionId)
    {
        UNREFERENCED_PARAMETER(functionId);
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionUnwindFinallyLeave)()
    {
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionCatcherEnter)(FunctionID functionId, ObjectID objectId)
    {
        UNREFERENCED_PARAMETER(functionId);
        UNREFERENCED_PARAMETER(objectId);
        return E_NOTIMPL;
    }

    STDMETHOD(ExceptionCatcherLeave)()
    {
        return E_NOTIMPL;
    }

    STDMETHOD(COMClassicVTableCreated)(ClassID wrappedClassId,
                        REFGUID implementedIID, void *pVTable, ULONG cSlots)
    {
        UNREFERENCED_PARAMETER(wrappedClassId);
        UNREFERENCED_PARAMETER(implementedIID);
        UNREFERENCED_PARAMETER(pVTable);
        UNREFERENCED_PARAMETER(cSlots);
        return E_NOTIMPL;
    }

    STDMETHOD(COMClassicVTableDestroyed)(ClassID wrappedClassId,
                        REFGUID implementedIID, void *pVTable)
    {
        UNREFERENCED_PARAMETER(wrappedClassId);
        UNREFERENCED_PARAMETER(implementedIID);
        UNREFERENCED_PARAMETER(pVTable);
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

    STDMETHOD(ThreadNameChanged)(ThreadID threadId, ULONG cchName, WCHAR* name)
    {
        UNREFERENCED_PARAMETER(threadId);
        UNREFERENCED_PARAMETER(cchName);
        UNREFERENCED_PARAMETER(name);
        return E_NOTIMPL;
    }
    
    STDMETHOD(GarbageCollectionStarted)( 
            /* [in] */ int cGenerations,
            /* [length_is][size_is][in] */ BOOL generationCollected[  ],
            /* [in] */ COR_PRF_GC_REASON reason)
    {
        UNREFERENCED_PARAMETER(cGenerations);
        UNREFERENCED_PARAMETER(generationCollected);
        UNREFERENCED_PARAMETER(reason);
        return E_NOTIMPL;
    }

    STDMETHOD(SurvivingReferences)( 
            /* [in] */ ULONG cSurvivingObjectIDRanges,
            /* [size_is][in] */ ObjectID objectIDRangeStart[  ],
            /* [size_is][in] */ ULONG cObjectIDRangeLength[  ])
    {
        UNREFERENCED_PARAMETER(cSurvivingObjectIDRanges);
        UNREFERENCED_PARAMETER(objectIDRangeStart);
        UNREFERENCED_PARAMETER(cObjectIDRangeLength);
        return E_NOTIMPL;
    }

    STDMETHOD(GarbageCollectionFinished)()
    {
        return E_NOTIMPL;
    }
        
    STDMETHOD(FinalizeableObjectQueued)( 
            /* [in] */ DWORD finalizerFlags,
            /* [in] */ ObjectID objectID)
    {
        UNREFERENCED_PARAMETER(finalizerFlags);
        UNREFERENCED_PARAMETER(objectID);
        return E_NOTIMPL;
    }
        
    STDMETHOD(RootReferences2)( 
            /* [in] */ ULONG cRootRefs,
            /* [size_is][in] */ ObjectID rootRefIds[  ],
            /* [size_is][in] */ COR_PRF_GC_ROOT_KIND rootKinds[  ],
            /* [size_is][in] */ COR_PRF_GC_ROOT_FLAGS rootFlags[  ],
            /* [size_is][in] */ UINT_PTR rootIds[  ])
    {
        UNREFERENCED_PARAMETER(cRootRefs);
        UNREFERENCED_PARAMETER(rootRefIds);
        UNREFERENCED_PARAMETER(rootKinds);
        UNREFERENCED_PARAMETER(rootFlags);
        UNREFERENCED_PARAMETER(rootIds);
        return E_NOTIMPL;
    }
        
    STDMETHOD(HandleCreated)( 
            /* [in] */ GCHandleID handleId,
            /* [in] */ ObjectID initialObjectId)
    {
        UNREFERENCED_PARAMETER(handleId);
        UNREFERENCED_PARAMETER(initialObjectId);
        return E_NOTIMPL;
    }
        
    STDMETHOD(HandleDestroyed)( 
            /* [in] */ GCHandleID handleId)
    {
        UNREFERENCED_PARAMETER(handleId);
        return E_NOTIMPL;
    }

};

