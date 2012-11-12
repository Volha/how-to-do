#pragma once
#include "Packet.h"

class IPacketSink
{
public:
	virtual void Consume(Packet()) = 0;
};