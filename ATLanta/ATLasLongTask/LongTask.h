// LongTask.h : Declaration of the CLongTask

#pragma once
#include "resource.h"       // main symbols



#include "ATLasLongTask_i.h"
#include "_ILongTaskEvents_CP.h"



using namespace ATL;


// CLongTask

class ATL_NO_VTABLE CLongTask :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CLongTask, &CLSID_LongTask>,
	public IConnectionPointContainerImpl<CLongTask>,
	public CProxy_ILongTaskEvents<CLongTask>,
	public ILongTask
{
public:
	CLongTask()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_LONGTASK)

DECLARE_NOT_AGGREGATABLE(CLongTask)

BEGIN_COM_MAP(CLongTask)
	COM_INTERFACE_ENTRY(ILongTask)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CLongTask)
	CONNECTION_POINT_ENTRY(__uuidof(_ILongTaskEvents))
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



	STDMETHOD(BigBangOperation)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(LongTask), CLongTask)
