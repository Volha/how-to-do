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
	static Dispatcher* GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new Dispatcher;
		}
		return m_instance;
	}

	void SendMessage(int sender, int receiver, const std::string& message);
	void AddMessageReceiver(MessageReceiver::MessRecPtr rec);
	void RemoveMessageReceiver(MessageReceiver::MessRecPtr rec);
	
private:
	Dispatcher(){};
	static Dispatcher* m_instance;
	std::map<int, MessageReceiver::MessRecPtr> subscribers;
};

