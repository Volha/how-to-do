#pragma once
#include "MessageReceiver.h"

class RepliedReceiver : public MessageReceiver
{
public:
	RepliedReceiver(int id, Dispatcher* disp)
		:MessageReceiver(id, disp)
	{
	
	}

	void ReceiveMessage(const std::string& message, int sender) 
	{
		std::cout << "I, " << this->GetID() << ", got a message: " << message << "\n";
		SendBack(sender, message);
	}
};