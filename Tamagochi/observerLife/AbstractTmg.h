#pragma once
namespace Tamagochi
{ 
	class AbstractTmg
	{
	public:
		virtual ~AbstractTmg(){}
		virtual int GetAge() const = 0;
		virtual int GetHungry() const = 0;
		virtual bool IsAlive() const = 0;

		virtual void OnAction(int action) = 0;
	};
}
