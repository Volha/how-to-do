#pragma once
#include "AbstractTmg.h"
namespace Tamagochi
{
	class BaseTmg : public AbstractTmg
	{
	public:
		BaseTmg();
		int GetAge() const;
		int GetHungry() const;
		bool IsAlive() const;
		void SetAge(int age);
	private:
		int m_dateBirth;
		int m_age;
		int m_hungryLevel;
		bool m_alive;
	};
}