// Messages.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include "Dispatcher.h"
#include "MessageReceiver.h"
#include "Reciever.h"

int _tmain(int argc, _TCHAR* argv[])
{
	MessageReceiver* m = new Reciever(1);
	Dispatcher::GetInstance()->AddMessageReceiver(m);
	Dispatcher::GetInstance()->SendMessage(m, m, "message");
	return 0;
}

