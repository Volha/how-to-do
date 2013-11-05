#pragma once

template<class T>
class CProxy_ISimpleEvents :
	public ATL::IConnectionPointImpl<T, &__uuidof(_ISimpleEvents)>
{
public:
	HRESULT Fire_OnFire()
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			_ISimpleEvents * pConnection = static_cast<_ISimpleEvents *>(punkConnection.p);

			if (pConnection)
			{
				hr = pConnection->OnFire();
			}
		}
		return hr;
	}
	HRESULT Fire_OnError(BSTR desc)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			_ISimpleEvents * pConnection = static_cast<_ISimpleEvents *>(punkConnection.p);

			if (pConnection)
			{
				hr = pConnection->OnError(desc);
			}
		}
		return hr;
	}
	HRESULT Fire_OnChtoTo()
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			_ISimpleEvents * pConnection = static_cast<_ISimpleEvents *>(punkConnection.p);

			if (pConnection)
			{
				hr = pConnection->OnChtoTo();
			}
		}
		return hr;
	}
};

