// dllmain.h : Declaration of module class.

class CATLasLongTaskModule : public ATL::CAtlDllModuleT< CATLasLongTaskModule >
{
public :
	DECLARE_LIBID(LIBID_ATLasLongTaskLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLASLONGTASK, "{B0050284-C51F-4252-81A6-84108AE5EADF}")
};

extern class CATLasLongTaskModule _AtlModule;
