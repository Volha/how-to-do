// Packets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Packet.h"
#include "IPacketSource.h"
#include "FileSource.h"

int _tmain(int argc, _TCHAR* argv[])
{
	IPacketSource* ip = new FileSource(L"C:\\file.txt"); 
	ip->GetPacket();
	return 0;
}

