// Sanguine Wanderer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graphics.h"
#include "Game.h"

int main()
{
	
	(*Game::GetInstance())->Init();

	return 0;
}

