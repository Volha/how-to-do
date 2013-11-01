#include "stdafx.h"
#include "Environment.h"
#include <time.h>
#include <algorithm>

namespace Tamagochi
{
	Environment::Environment()
		:hours(0)
	{
		srand(time( NULL ));
	}

	Environment::~Environment()
	{
		
	}

	void Environment::AddListener(BaseTmg* tmg)
	{
		listeners.push_back(tmg);
	}

	void Environment::Update()
	{
		++hours;
		int action = rand () % 10;
		for (size_t i = 0; i < listeners.size(); ++i)
		{
			listeners[i]->SetAge(hours);
			listeners[i]->OnAction(action);
		}
	}

	void  Environment::RemoveListener(BaseTmg* tmg)
	{
		listeners.erase(find(listeners.begin(), listeners.end(), tmg));
	}
}
