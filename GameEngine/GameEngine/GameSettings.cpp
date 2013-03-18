#include "GameSettings.h"
bool GameSettings::instanceFlag = false;
GameSettings* GameSettings::singleton = 0;

GameSettings * GameSettings::GetInstance()
{
	if(!instanceFlag)
	{
		singleton = new GameSettings;
		instanceFlag = true;
	}
	return singleton;
	
}
