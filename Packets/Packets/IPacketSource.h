#pragma once
#include "PacketType.h"


class IPacketSource
{
public: 
	virtual  PacketType* GetPacket() = 0;
	virtual bool HasPack() = 0;
};