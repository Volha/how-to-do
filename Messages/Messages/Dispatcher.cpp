#include "stdafx.h"
#include "Dispatcher.h"
#include <algorithm>

Dispatcher* Dispatcher::m_instance = nullptr;

Dispatcher* Dispatcher::GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new Dispatcher;
		}
		return m_instance;
	}

void Dispatcher::SendMessage(int sender, int receiver, const std::string& message)
{
	subscribers.find(receiver)->second->ReceiveMessage(message, sender);
}

void Dispatcher::AddMessageReceiver(MessageReceiver::MessRecPtr rec)
{
	subscribers.insert(std::pair<int, MessageReceiver::MessRecPtr>(rec->GetID(), rec));
}

void Dispatcher::RemoveMessageReceiver(MessageReceiver::MessRecPtr rec)
{
	subscribers.erase(rec->GetID());
}

