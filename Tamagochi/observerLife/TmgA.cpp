#include "stdafx.h"
#include "TmgA.h"
#include <iostream>
namespace Tamagochi
{
	void TmgA::OnAction(int action)
	{
		
		std::cout << "\nTamagochi A, action " << action;
	}
}