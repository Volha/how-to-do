#include "stdafx.h"
#include "BaseTmg.h"
namespace Tamagochi
{
	BaseTmg::BaseTmg()
		:m_alive(true)
		,m_dateBirth(0)
		,m_age(0)
	{
			
	}

	int BaseTmg::GetAge() const
	{
		return m_age;
	}

	int BaseTmg::GetHungry() const
	{
		return m_hungryLevel;
	}

	bool BaseTmg::IsAlive() const
	{
		return m_alive;
	}

	void BaseTmg::SetAge(int age)
	{
		m_age = age;
	}
}