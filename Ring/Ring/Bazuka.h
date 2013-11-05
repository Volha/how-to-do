#pragma once
#include "Weapon.h"

class Bazuka : public Weapon
{
public:
	Bazuka(const std::string& name)
		:Weapon(name)
	{
	
	};
	void Shot()
	{
		std::cout << "BAZZZZUUUKA" << "\n";
	}
};