#pragma once
#include "IniReader.h"
#include "IniWriter.h"
#include "boost\smart_ptr.hpp"

class GameSettings
{
public:
	~GameSettings(void) {};

	static boost::scoped_ptr<GameSettings>* GetInstance();

	//Getters
	int GetiWindowWidth() const {return iWindowWidth;}
	int GetiWindowHeight() const {return iWindowHeight;}
	int GetiVolume() const {return iMasterVolume;}
	//Setters
	void SetiWindowWidth(int iValue);
	void SetiWindowHeight(int iValue);
	void SetiVolume(int iValue);

private:
	static boost::scoped_ptr<GameSettings> pSingleton;
	
	GameSettings(void);
	GameSettings& operator=(const GameSettings&);
	GameSettings(const GameSettings&);
	//Update
	void UpdateiWindowWidth();
	void UpdateiWindowHeight();
	void UpdateiMasterVolume();

	IniReader *iniReader;
	IniWriter *iniWriter;
	//Video Settings
	int iWindowWidth;
	int iWindowHeight;
	//Audio Settings
	int iMasterVolume;
};