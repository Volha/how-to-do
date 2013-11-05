// Simple.h : Declaration of the CSimple

#pragma once
#include "resource.h"       // main symbols



#include "ATLCP_i.h"
#include "_ISimpleEvents_CP.h"



using namespace ATL;


// CSimple

class ATL_NO_VTABLE CSimple :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CSimple, &CLSID_Simple>,
	public IConnectionPointContainerImpl<CSimple>,
	public CProxy_ISimpleEvents<CSimple>,
	public ISimple
{
public:
	CSimple()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SIMPLE)


BEGIN_COM_MAP(CSimple)
	COM_INTERFACE_ENTRY(ISimple)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CSimple)
	CONNECTION_POINT_ENTRY(__uuidof(_ISimpleEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(TestMethod)(BSTR s);
};

OBJECT_ENTRY_AUTO(__uuidof(Simple), CSimple)
