#include "stdafx.h"
#include "Dispatcher.h"
#include <algorithm>

Dispatcher* Dispatcher::m_instance = nullptr;

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

