#pragma once
#include "MessageReceiver.h"

class Reciever : public MessageReceiver
{
public:
	Reciever(int id)
		:MessageReceiver(id)
	{
	
	}
	void ReceiveMessage(const std::string& message) 
	{
		
	}
	
};