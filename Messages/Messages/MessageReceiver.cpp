#include "stdafx.h"
#include "MessageReceiver.h"
#include "Dispatcher.h"

	MessageReceiver::MessageReceiver(int id, Dispatcher* disp)
		:m_id(id)
		,m_disp(disp)
	{
		
	}	

	int MessageReceiver::GetID() const
	{
		return m_id;
	}

	Dispatcher* MessageReceiver::GetDisp()
	{
		return m_disp;
	}

	void MessageReceiver::SendBack(int sender, const std::string& message)
	{
		m_disp->SendMessage(m_id, sender, message);
	}