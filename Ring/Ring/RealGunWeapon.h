#pragma once
#include "Weapon.h"

class RealGunWeapon : public Weapon
{
public:
	RealGunWeapon(const std::string& name)
		:Weapon(name)
	  {
	  
	  }	
	void Shot()
	{
		std::cout << "BOOM" << "\n";
	}
};