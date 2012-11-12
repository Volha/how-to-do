#pragma once
#include "Windows.h"

class HandlerWr
{
public:
	explicit HandlerWr(HANDLE handle)
		: m_handle(handle)
	{
		
	}
	
	bool IsValid() const 
	{
		return m_handle != INVALID_HANDLE_VALUE;
	}

	HANDLE operator* () const
	{
		return m_handle;
	}

	~HandlerWr()
	{
		if (IsValid()) 
		{
			CloseHandle(m_handle);
		}
	}
private:
	HANDLE m_handle;
};
