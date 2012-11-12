#pragma once

#include "IPacketSource.h"
#include <string>
#include "Windows.h"
#include <memory>
#include "HandlerWr.h"

class FileSource : public IPacketSource
{
private:	
	class HandleWrapper;
public:
	FileSource(const  std::wstring& fileName);
	Packet* GetPacket();
	bool HasPack();
private:
	std::wstring m_fileName;
	std::shared_ptr<HandleWrapper> m_fileHandle;
	Packet* m_packet;
};