#pragma once
#include <string>
#include <memory>

class MessageReceiver
{
public: 
typedef std::shared_ptr<MessageReceiver> MessRecPtr;	
	MessageReceiver(int id)
		:m_id(id)
	{
	
	}

	virtual void ReceiveMessage(const std::string& message) = 0;
	
	int GetID() const
	{
		return m_id;
	}

private:
	int m_id;
};