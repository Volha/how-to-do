#pragma once
#include "Weapon.h"

class GunWeapon : public Weapon
{
public:
	GunWeapon(const std::string name)
		:Weapon(name)
	{
		
	};
	void Shot()
	{
		std::cout << "TYK TYK"  << "\n";
	}
};