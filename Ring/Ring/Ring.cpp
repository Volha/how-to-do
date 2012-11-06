// Ring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RingClass.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "Weapon.h"
#include "GunWeapon.h"
#include "Bazuka.h"
#include "RealGunWeapon.h"

template <typename T> 
RingClass<T> InitializeRing(const std::vector<T>& vec)
{
	RingClass<T> r;
	for(size_t i = 0; i < vec.size(); ++i)
	{
		r.AddNode(vec[i]);
	}
	return r;
}

bool CheckRing(RingClass<int>& r, const std::vector<int>& v)
{
	bool isEqual = true;
	for(size_t i = v.size(); i > 0; --i)
	{
		if(v[i-1] != r.GetCurrentValue())
		{
			isEqual = false;
			return isEqual;
		}
		r.MoveNext();
	}
	
	r.MovePrevious();
		for(size_t i = 0; i < (v.size()-1); ++i)
	{
		if(v[i] != r.GetCurrentValue())
		{
			isEqual = false;
			return isEqual;
		}
		r.MovePrevious();
	}
	return isEqual;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(10);
	v.push_back(9);
	v.push_back(15);
	v.push_back(5);

	RingClass<int> ring = InitializeRing(v); 
	

	if (CheckRing(ring, v))
	{
		std::cout << "OK" << "\n";
	}
	std::vector<Weapon*> weapons;
	weapons.push_back(new GunWeapon("Gun"));
	weapons.push_back(new RealGunWeapon("Gun"));
	weapons.push_back(new Bazuka("Gun"));

	RingClass<Weapon*> boonk = InitializeRing(weapons);
	
	while(true)
	{
		boonk.GetCurrentValue()->Shot();
		boonk.MoveNext();
	}

	return 0;
}

