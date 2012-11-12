#pragma once

#include "IPacketSink.h"
#include "HandleWrapper.h"
#include <memory>

class FileSink : public IPacketSink
{
public:
	FileSink();
	void Consume(PacketType* p);
private:
	std::shared_ptr<HandleWrapper> m_fileHandle;
};