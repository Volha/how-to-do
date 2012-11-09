// Messages.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include "Dispatcher.h"
#include "MessageReceiver.h"
#include "Reciever.h"
#include "RepliedReceiver.h"

typedef std::shared_ptr<Reciever> RecieverPtr;
typedef std::shared_ptr<RepliedReceiver> RepliedReceiverPtr;

int _tmain(int argc, _TCHAR* argv[])
{
	Dispatcher::GetInstance()->AddMessageReceiver(std::make_shared<Reciever>(1, Dispatcher::GetInstance()));
	Dispatcher::GetInstance()->AddMessageReceiver(std::make_shared<Reciever>(2, Dispatcher::GetInstance()));
	Dispatcher::GetInstance()->AddMessageReceiver(std::make_shared<RepliedReceiver>(3, Dispatcher::GetInstance()));

	Dispatcher::GetInstance()->SendMessage(2, 1, "hello from 2");
	Dispatcher::GetInstance()->SendMessage(3, 2, "hello from 3");
	Dispatcher::GetInstance()->SendMessage(1, 3, "hello from 1");
	return 0;
}

