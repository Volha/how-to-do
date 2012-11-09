#pragma once
#include "MessageReceiver.h"

class Reciever : public MessageReceiver
{
public:
	Reciever(int id, Dispatcher* disp)
		:MessageReceiver(id, disp)
	{
	
	}

	void ReceiveMessage(const std::string& message, int sender = 0) 
	{
		std::cout << "I, " << this->GetID() << ", got a message: " << message << "\n";

	}
};