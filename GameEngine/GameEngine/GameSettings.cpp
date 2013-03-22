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

void GameSettings::UpdateiWindowWidth()
{
	iWindowWidth = iniReader->ReadInteger(_T("Video Settings"), _T("ResolutionWidth"), 1280);
}
void GameSettings::UpdateiWindowHeight()
{
	iWindowHeight = iniReader->ReadInteger(_T("Video Settings"), _T("ResolutionHeight"), 960);
}
void GameSettings::UpdateiMasterVolume()
{
	iMasterVolume = iniReader->ReadInteger(_T("Audio Settings"), _T("Master Volume"), 100);
}
void GameSettings::SetiWindowWidth(int iValue)
{
	iniWriter->WriteInteger(_T("Video Settings"), _T("ResolutionWidth"), iValue); iWindowWidth = iValue;
}
void GameSettings::SetiWindowHeight(int iValue)
{
	iniWriter->WriteInteger(_T("Video Settings"), _T("ResolutionHeight"), iValue); iWindowHeight = iValue;
}
void GameSettings::SetiVolume(int iValue)
{
	iniWriter->WriteInteger(_T("Audio Settings"), _T("Master Volume"), iValue); iMasterVolume = iValue;
}