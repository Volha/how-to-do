#pragma once

template<class T>
class CProxy_ILongTaskEvents :
	public ATL::IConnectionPointImpl<T, &__uuidof(_ILongTaskEvents)>
{
public:
	HRESULT Fire_OnFinish()
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			_ILongTaskEvents * pConnection = static_cast<_ILongTaskEvents *>(punkConnection.p);

			if (pConnection)
			{
				hr = pConnection->OnFinish();
			}
		}
		return hr;
	}
};

