#pragma once
#include "IniReader.h"
#include "IniWriter.h"


class GameSettings
{
public:
	~GameSettings(void) {instanceFlag = false; singleton = 0; delete[] singleton;}

	static GameSettings* GetInstance();

	//Update
	void UpdateiWindowWidth(){iWindowWidth = iniReader->ReadInteger(_T("Video Settings"), _T("ResolutionWidth"), 1280);}
	void UpdateiWindowHeight(){iWindowHeight = iniReader->ReadInteger(_T("Video Settings"), _T("ResolutionHeight"), 960);}
	void UpdateiMasterVolume(){iMasterVolume = iniReader->ReadInteger(_T("Audio Settings"), _T("Master Volume"), 100);}
	//Getters
	int GetiWindowWidth() const {return iWindowWidth;}
	int GetiWindowHeight() const {return iWindowHeight;}
	int GetiVolume() const {return iMasterVolume;}
	//Setters
	void SetiWindowWidth(int iValue){iniWriter->WriteInteger(_T("Video Settings"), _T("ResolutionWidth"), iValue); iWindowWidth = iValue;}
	void SetiWindowHeight(int iValue){iniWriter->WriteInteger(_T("Video Settings"), _T("ResolutionHeight"), iValue); iWindowHeight = iValue;}
	void SetiVolume(int iValue){iniWriter->WriteInteger(_T("Audio Settings"), _T("Master Volume"), iValue); iMasterVolume = iValue;}

private:
	static bool instanceFlag;
	static GameSettings *singleton;
	
	GameSettings(void){iniReader = new IniReader(_T(".\\Config.ini"));}

	IniReader *iniReader;
	IniWriter *iniWriter;
	//Video Settings
	int iWindowWidth;
	int iWindowHeight;
	//Audio Settings
	int iMasterVolume;
};