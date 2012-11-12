#include "stdafx.h"
#include "FileSource.h"

class FileSource::HandleWrapper
{
	public:
		HandleWrapper(HANDLE handle)
			:m_handle(handle)
		{
			
		}
		bool IsValid() const 
		{
			return m_handle != INVALID_HANDLE_VALUE;
		}

		HANDLE operator*()
		{
			return m_handle;
		}
		~HandleWrapper()
		{
			if(IsValid())
			{
				CloseHandle(m_handle);
			}
		}

	private:
		HANDLE m_handle;
	};

FileSource::FileSource(const std::wstring& fileName)
	: m_fileName(fileName)
	, m_packet(new Packet)
	, m_fileHandle(std::make_shared<HandleWrapper>(CreateFile(m_fileName.c_str(),            
                       GENERIC_READ,          
                       FILE_SHARE_READ,      
                       nullptr,                 
                       OPEN_EXISTING,         
                       FILE_ATTRIBUTE_NORMAL, 
					   nullptr)))
{
	 
}

Packet* FileSource::GetPacket()
{
	if (m_fileHandle->IsValid())
	{
		
		ReadFile(**m_fileHandle, m_packet->m_array, 100 , reinterpret_cast<LPDWORD>(&(m_packet->m_size)), nullptr);
		return m_packet;
	}
	return nullptr;
}

bool FileSource::HasPack()
{
	return true;
}

