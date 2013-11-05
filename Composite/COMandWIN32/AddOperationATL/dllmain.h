// dllmain.h : Declaration of module class.

class CAddOperationATLModule : public ATL::CAtlDllModuleT< CAddOperationATLModule >
{
public :
	DECLARE_LIBID(LIBID_AddOperationATLLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ADDOPERATIONATL, "{54890C97-C12E-4507-A25D-E4616651D097}")
};

extern class CAddOperationATLModule _AtlModule;
