#include "stdafx.h"
#include "TmgC.h"
#include <iostream>
namespace Tamagochi
{
	void TmgC::OnAction(int action)
	{
		switch(action)
		{
			case 1 :
				std::cout << "\nTamagochi C, action " << action;
				break; 
			case 2 :

				break;
		}
		std::cout << "\nTamagochi C, action " << action;
		std::cout << "Age "<< this->GetAge();
	}
}