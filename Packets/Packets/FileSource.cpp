#include "stdafx.h"
#include "FileSource.h"


FileSource::FileSource(const std::wstring& fileName)
	: m_fileName(fileName)
	, m_packet(new PacketType)
	, m_fileHandle(std::make_shared<HandleWrapper>(CreateFile(m_fileName.c_str(),            
                       GENERIC_READ,          
                       FILE_SHARE_READ,      
                       nullptr,                 
                       OPEN_EXISTING,         
                       FILE_ATTRIBUTE_NORMAL, 
					   nullptr)))
{
	 
}

PacketType* FileSource::GetPacket()
{
	if (m_fileHandle->IsValid())
	{
		ReadFile(**m_fileHandle, m_packet->m_array, m_packet->GetFullSize(), reinterpret_cast<LPDWORD>(&(m_packet->m_size)), nullptr);
		return m_packet;
	}
	return nullptr;
}

bool FileSource::HasPack()
{
	if(m_packet->m_size == 0)
	{
		return false;
	}
	return true;
}

