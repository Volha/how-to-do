#include "stdafx.h"
#include "Dispatcher.h"


Dispatcher* Dispatcher::m_instance = NULL;

void Dispatcher::SendMessage(MessageReceiver* sender, MessageReceiver* receiver, const std::string& message)
{
	
}

void Dispatcher::AddMessageReceiver(MessageReceiver* rec)
{
	subscribers.insert(std::pair<int, MessageReceiver*>(rec->GetID(), rec));
}

void Dispatcher::RemoveMessageReceiver(MessageReceiver* rec)
{
	subscribers.erase(rec->GetID());
}