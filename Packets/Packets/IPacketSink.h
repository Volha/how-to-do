#pragma once
#include "PacketType.h"
#include "Windows.h"

class IPacketSink
{
public:
	
	virtual void Consume(PacketType* p) = 0;
};