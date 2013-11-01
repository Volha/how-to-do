// Tamagochi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../observerLife/Environment.h"
#include "../observerLife/TmgA.h"
#include "../observerLife/TmgB.h"
#include "../observerLife/TmgC.h"


using namespace Tamagochi;

typedef std::shared_ptr<Environment> Env;
int _tmain(int argc, _TCHAR* argv[])
{
	BaseTmg* tamagochiA = new TmgA();
	BaseTmg* tamagochiB = new TmgB();
	BaseTmg* tamagochiC = new TmgC();

	Env e = std::make_shared<Environment>();
	e->AddListener(tamagochiA);
	e->AddListener(tamagochiB);
	e->AddListener(tamagochiC);
	for(;;)
	{
		e->Update();
	}
	return 0;
}


