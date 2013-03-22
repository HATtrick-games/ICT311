#include "GameSettings.h"

boost::scoped_ptr<GameSettings> GameSettings::pSingleton(NULL);

boost::scoped_ptr<GameSettings> * GameSettings::GetInstance()
{
	if(pSingleton.get() == NULL)
	{
		pSingleton.reset(new GameSettings);
	}
	return &pSingleton;
	
}

GameSettings::GameSettings()
{
	iniReader = new IniReader(_T(".\\Config.ini"));
	UpdateiWindowWidth();
	UpdateiWindowHeight();
	UpdateiMasterVolume();
}