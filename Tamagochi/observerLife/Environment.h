#pragma once
#include "BaseTmg.h"
#include <vector>

namespace Tamagochi
{
	class Environment
	{
	public:
		Environment();
		void AddListener(BaseTmg* tmg);
		void RemoveListener(BaseTmg* tmg);
		void Update();
		~Environment();
	private:
		int hours;
		enum {
		Rain,
		Fog,
		Sun,
		Snow
		} m_weather;
		int m_currentWeather;
		std::vector<BaseTmg*> listeners;
	};
}