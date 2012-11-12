#pragma once

#include "IPacketSink.h"

class FileSink : public IPacketSink
{
	FileSink();
	void Consume();
};