#include "stdafx.h"
#include "TmgB.h"
#include <iostream>
namespace Tamagochi
{
	void TmgB::OnAction(int action)
	{
		std::cout << "\nTamagochi B, action " << action;
	}
}