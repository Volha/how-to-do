#pragma once
#include <string>
#include <memory>
#include <iostream>

class Dispatcher;

class MessageReceiver
{
public: 
	typedef std::shared_ptr<MessageReceiver> MessRecPtr;	
	MessageReceiver(int id, Dispatcher* disp);
	int GetID() const;
	Dispatcher* GetDisp();
	virtual void ReceiveMessage(const std::string& message, int sender = 0) = 0;

protected:
	void SendBack(int sender, const std::string& message);
	
private:
	int m_id;
	Dispatcher* m_disp;
};
