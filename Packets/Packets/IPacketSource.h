#pragma once
#include "Packet.h"


class IPacketSource
{
public: 
	virtual Packet* GetPacket() = 0;
	virtual bool HasPack() = 0;
};