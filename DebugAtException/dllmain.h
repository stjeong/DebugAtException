// dllmain.h : Declaration of module class.

class CDebugAtExceptionModule : public ATL::CAtlDllModuleT< CDebugAtExceptionModule >
{
public :
	DECLARE_LIBID(LIBID_DebugAtExceptionLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DEBUGATEXCEPTION, "{4fc3ab69-b991-4796-9fe3-5fad6b304b25}")
};

extern class CDebugAtExceptionModule _AtlModule;
