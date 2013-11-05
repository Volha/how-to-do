// dllmain.h : Declaration of module class.

class CTestModule : public ATL::CAtlDllModuleT< CTestModule >
{
public :
	DECLARE_LIBID(LIBID_TestLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TEST, "{D16A5064-FFD2-40AC-882B-A510C8981684}")
};

extern class CTestModule _AtlModule;
