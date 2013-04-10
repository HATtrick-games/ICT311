/**
 * \file	GameSettings.h
 *
 * \brief	Declares the game settings class.
 */

#pragma once
#include "IniReader.h"
#include "IniWriter.h"
#include "boost\smart_ptr.hpp"

/**
 * \class	GameSettings
 *
 * \brief	Game settings.
 *
 * \author	Hamish Carrier
 * \date	4/10/2013
 */

class GameSettings
{
public:

	/**
	 * \fn	GameSettings::~GameSettings(void)
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	~GameSettings(void) {};

	/**
	 * \fn	static boost::scoped_ptr<GameSettings>* GameSettings::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<GameSettings>* GetInstance();

	/**
	 * \fn	int GameSettings::GetiWindowWidth() const
	 *
	 * \brief	Getters.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	.
	 */

	int GetiWindowWidth() const {return iWindowWidth;}

	/**
	 * \fn	int GameSettings::GetiWindowHeight() const
	 *
	 * \brief	Gets the geti window height.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	.
	 */

	int GetiWindowHeight() const {return iWindowHeight;}

	/**
	 * \fn	int GameSettings::GetiVolume() const
	 *
	 * \brief	Gets the geti volume.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	.
	 */

	int GetiVolume() const {return iMasterVolume;}

	/**
	 * \fn	void GameSettings::SetiWindowWidth(int iValue);
	 *
	 * \brief	Setters.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	iValue	Zero-based index of the value.
	 */

	void SetiWindowWidth(int iValue);

	/**
	 * \fn	void GameSettings::SetiWindowHeight(int iValue);
	 *
	 * \brief	Seti window height.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	iValue	Zero-based index of the value.
	 */

	void SetiWindowHeight(int iValue);

	/**
	 * \fn	void GameSettings::SetiVolume(int iValue);
	 *
	 * \brief	Seti volume.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	iValue	Zero-based index of the value.
	 */

	void SetiVolume(int iValue);

private:

	/**
	 * \brief	The singleton.
	 */

	static boost::scoped_ptr<GameSettings> pSingleton;

	/**
	 * \fn	GameSettings::GameSettings(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	GameSettings(void);

	/**
	 * \fn	GameSettings& GameSettings::operator=(const GameSettings&);
	 *
	 * \brief	Assignment operator.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	parameter1	The first parameter.
	 *
	 * \return	A shallow copy of this object.
	 */

	GameSettings& operator=(const GameSettings&);

	/**
	 * \fn	GameSettings::GameSettings(const GameSettings&);
	 *
	 * \brief	Copy constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	parameter1	The first parameter.
	 */

	GameSettings(const GameSettings&);

	/**
	 * \fn	void GameSettings::UpdateiWindowWidth();
	 *
	 * \brief	Update.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	void UpdateiWindowWidth();

	/**
	 * \fn	void GameSettings::UpdateiWindowHeight();
	 *
	 * \brief	Updatei window height.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	void UpdateiWindowHeight();

	/**
	 * \fn	void GameSettings::UpdateiMasterVolume();
	 *
	 * \brief	Updatei master volume.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	void UpdateiMasterVolume();

	/**
	 * \brief	The initialise reader.
	 */

	IniReader *iniReader;

	/**
	 * \brief	The initialise writer.
	 */

	IniWriter *iniWriter;

	/**
	 * \brief	Video Settings.
	 */

	int iWindowWidth;

	/**
	 * \brief	Height of the window.
	 */

	int iWindowHeight;

	/**
	 * \brief	Audio Settings.
	 */

	int iMasterVolume;
};