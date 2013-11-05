// dllmain.h : Declaration of module class.

class CATLCPModule : public ATL::CAtlDllModuleT< CATLCPModule >
{
public :
	DECLARE_LIBID(LIBID_ATLCPLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLCP, "{374272FA-8DC6-44D7-917F-D5C4480E43E2}")
};

extern class CATLCPModule _AtlModule;
