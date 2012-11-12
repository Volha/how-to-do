// Packets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Packet.h"
#include "IPacketSource.h"
#include "FileSource.h"
#include "IPacketSink.h"
#include "FileSink.h"

void Copy(IPacketSource* source, IPacketSink* sink)
{
	do
	{
		sink->Consume(source->GetPacket());
	}
	while(source->HasPack());
};

int _tmain(int argc, _TCHAR* argv[])
{
	IPacketSource* source = new FileSource(L"C:\\file.txt"); 
	IPacketSink* sink = new FileSink();
	Copy(source, sink);
	return 0;
}

