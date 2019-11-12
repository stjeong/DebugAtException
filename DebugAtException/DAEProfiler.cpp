// DAEProfiler.cpp : Implementation of CDAEProfiler

#include "pch.h"
#include "DAEProfiler.h"
#include <vector>

using namespace std;

// https://www.sysnet.pe.kr/2/0/11886

#define OPDEF( id, s, pop, push, args, type, l, OpCode1, OpCode2, ctrl ) id,
typedef enum enumOpcode
{
#include "opcode.def"
    CEE_COUNT,  /* number of instructions and macros pre-defined */
} OPCODE;
#undef OPDEF

// CTestIgnore

HRESULT CDAEProfiler::Initialize(IUnknown* pICorProfilerInfoUnk)
{
    if (pICorProfilerInfoUnk == NULL)
    {
        return S_OK;
    }

    m_pICorProfilerInfo = pICorProfilerInfoUnk;
    if (m_pICorProfilerInfo == NULL)
    {
        return S_OK;
    }

    m_pICorProfilerInfo2 = pICorProfilerInfoUnk;
    m_pICorProfilerInfo3 = pICorProfilerInfoUnk;

    DWORD dwEventMask = COR_PRF_MONITOR_JIT_COMPILATION | COR_PRF_USE_PROFILE_IMAGES | COR_PRF_MONITOR_EXCEPTIONS;

    m_pICorProfilerInfo->SetEventMask(dwEventMask);

    ::OutputDebugString(L"Profiler Initialize - End!\r\n");

    return S_OK;
}

HRESULT CDAEProfiler::JITCompilationStarted(FunctionID functionId, BOOL fIsSafeToBlock)
{
    ClassID classId;
    ModuleID moduleId = 0;
    mdToken methodToken = 0;

    HRESULT hr = m_pICorProfilerInfo->GetFunctionInfo(functionId, &classId, &moduleId, &methodToken);

    IMetaDataImport* pMetaDataImport = nullptr;
    IMetaDataAssemblyImport* pMetaDataAssemblyImport = nullptr;
    IMetaDataEmit* pMetaDataEmit = nullptr;
    IMethodMalloc* pMalloc = nullptr;

    do
    {
        hr = m_pICorProfilerInfo->GetModuleMetaData(moduleId, (ofRead | ofWrite), IID_IMetaDataAssemblyImport, (LPUNKNOWN*)&pMetaDataAssemblyImport);
        pMetaDataAssemblyImport->QueryInterface(IID_IMetaDataImport, (LPVOID*)&pMetaDataImport);

        ULONG cchFunction;
        mdToken typeToken;
        wchar_t szFunction[2048];
        wchar_t szClass[2048];

        hr = pMetaDataImport->GetMethodProps(methodToken,
            &typeToken,
            szFunction,
            2048,
            &cchFunction,
            NULL, NULL, NULL, NULL, NULL);
        if (S_OK != hr)
        {
            break;
        }

        ULONG cchClass;
        hr = pMetaDataImport->GetTypeDefProps(typeToken,
            szClass,
            2048,
            &cchClass,
            0, 0);
        if (S_OK != hr)
        {
            break;
        }

        HRESULT hr = pMetaDataAssemblyImport->QueryInterface(IID_IMetaDataEmit, (LPVOID*)&pMetaDataEmit);
        if (S_OK != hr)
        {
            break;
        }

        hr = m_pICorProfilerInfo->GetILFunctionBodyAllocator(moduleId, &pMalloc);
        if (S_OK != hr)
        {
            break;
        }

        const int bufLen = 2048;
        wchar_t buf[bufLen];
        _snwprintf_s(buf, bufLen, _TRUNCATE, L"%s.%s", szClass, szFunction);

        if (wcscmp(buf, L"...[원하는 메서드]...") == 0)
        {
            // 가장 처음 실행되었을 때...
            // dump를 남기는 식의 동작 가능
            break;
        }

    } while (false);

    if (pMalloc != nullptr)
    {
        pMalloc->Release();
    }

    if (pMetaDataEmit != nullptr)
    {
        pMetaDataEmit->Release();
    }

    if (pMetaDataAssemblyImport != nullptr)
    {
        pMetaDataAssemblyImport->Release();
    }

    if (pMetaDataImport != nullptr)
    {
        pMetaDataImport->Release();
    }

    return S_OK;
}

HRESULT CDAEProfiler::Shutdown()
{
    if (m_pICorProfilerInfo != nullptr)
    {
        m_pICorProfilerInfo.Release();
    }

    if (m_pICorProfilerInfo2 != nullptr)
    {
        m_pICorProfilerInfo2.Release();
    }

    if (m_pICorProfilerInfo3 != nullptr)
    {
        m_pICorProfilerInfo3.Release();
    }

    return S_OK;
}

HRESULT CDAEProfiler::ExceptionThrown(ObjectID thrownObjectId)
{
    ClassID classId;
    ModuleID moduleId;
    mdTypeDef typeDefToken;

    m_pICorProfilerInfo->GetClassFromObject(thrownObjectId, &classId);
    m_pICorProfilerInfo->GetClassIDInfo(classId, &moduleId, &typeDefToken);

    IMetaDataImport* pMetaDataImport = nullptr;

    do
    {
        m_pICorProfilerInfo->GetModuleMetaData(moduleId, ofRead, IID_IMetaDataImport, (LPUNKNOWN*)&pMetaDataImport);

        mdToken tkExtends;
        DWORD dwTypeDefFlags;
        ULONG chTypeDef;
        const ULONG cchTypeDef = 1024;
        wchar_t szTypeDef[cchTypeDef];
        pMetaDataImport->GetTypeDefProps(typeDefToken, szTypeDef, cchTypeDef, &chTypeDef, &dwTypeDefFlags, &tkExtends);

        printf("ExceptionThrown == %S (ObjectID == %I64x)\n", szTypeDef, thrownObjectId);

    } while (false);

    if (pMetaDataImport != nullptr)
    {
        pMetaDataImport->Release();
    }

    {
        // 예외가 발생했을 때 프로그램을 멈추거나,
        printf("Waiting for being attached from debugger, or press any key to continue...\n");
        getchar();
        
        // 덤프를 남기는 것도 가능
    }
    
    return S_OK;
}

HRESULT CDAEProfiler::ExceptionSearchFunctionEnter(FunctionID functionId)
{
    ClassID classId;
    ModuleID moduleId;
    mdTypeDef typeDefToken;
    mdMethodDef methodToken;

    m_pICorProfilerInfo->GetFunctionInfo(functionId, &classId, &moduleId, &methodToken);
    IMetaDataImport* pMetaDataImport = nullptr;

    do
    {
        m_pICorProfilerInfo->GetModuleMetaData(moduleId, ofRead, IID_IMetaDataImport, (LPUNKNOWN*)&pMetaDataImport);

        ULONG ulCodeRVA;
        const ULONG cchMethod = 1024;
        ULONG chMethod;
        wchar_t szMethod[cchMethod];
        DWORD dwAttr;
        PCCOR_SIGNATURE pvSigBlob;
        ULONG cbSigBlob;
        DWORD dwImplFlags;
        pMetaDataImport->GetMethodProps(methodToken, &typeDefToken, szMethod, cchMethod, &chMethod, &dwAttr, &pvSigBlob, &cbSigBlob, &ulCodeRVA, &dwImplFlags);

        mdToken tkExtends;
        DWORD dwTypeDefFlags;
        ULONG chTypeDef;
        const ULONG cchTypeDef = 1024;
        wchar_t szTypeDef[cchTypeDef];
        pMetaDataImport->GetTypeDefProps(typeDefToken, szTypeDef, cchTypeDef, &chTypeDef, &dwTypeDefFlags, &tkExtends);

        printf("\tat %S.%S\n", szTypeDef, szMethod);

    } while (false);

    if (pMetaDataImport != nullptr)
    {
        pMetaDataImport->Release();
    }

    return S_OK;
}

HRESULT CDAEProfiler::ExceptionSearchFunctionLeave()
{
    return E_NOTIMPL;
}
