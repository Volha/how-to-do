#pragma once

#include "IPacketSource.h"
#include <string>
#include "Windows.h"
#include <memory>
#include "HandleWrapper.h"

class FileSource : public IPacketSource
{
public:
	FileSource(const std::wstring& fileName);
	PacketType* GetPacket();
	bool HasPack();
private:
	std::wstring m_fileName;
	std::shared_ptr<HandleWrapper> m_fileHandle;
	PacketType* m_packet;
};