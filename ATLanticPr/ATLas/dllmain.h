// dllmain.h : Declaration of module class.

class CATLasModule : public ATL::CAtlDllModuleT< CATLasModule >
{
public :
	DECLARE_LIBID(LIBID_ATLasLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLAS, "{37E7906B-0644-4FED-B122-91680D2AEBB7}")
};

extern class CATLasModule _AtlModule;
