#pragma once
#include "MessageReceiver.h"
#include <string>
#include <map>

class Dispatcher
{
public:
	static Dispatcher* GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new Dispatcher;
		}
		return m_instance;
	}
	void SendMessage(MessageReceiver* sender, MessageReceiver* receiver, const std::string& message);
	void AddMessageReceiver(MessageReceiver* rec);
	void RemoveMessageReceiver();
private:
	Dispatcher(){};
	static Dispatcher* m_instance;
	std::map<int, MessageReceiver*> subscribers;
};

