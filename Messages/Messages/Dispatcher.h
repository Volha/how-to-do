#pragma once
#include "MessageReceiver.h"
#include <string>
#include <map>


class Dispatcher
{
public:
	~Dispatcher()
	{
		
	};

	static Dispatcher* GetInstance();
	void SendMessage(int sender, int receiver, const std::string& message);
	void AddMessageReceiver(MessageReceiver::MessRecPtr rec);
	void RemoveMessageReceiver(MessageReceiver::MessRecPtr rec);
	
private:
	Dispatcher(){};
	static Dispatcher* m_instance;
	std::map<int, MessageReceiver::MessRecPtr> subscribers;
};

