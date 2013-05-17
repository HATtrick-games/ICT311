#pragma once

#include "stdafx.h"

/**
 * \class	IMouse
 *
 * \brief	Mouse.
 * 			
 * \author	Timothy Veletta
 */
class IMouse
{
public:

	/**
	 * \struct	sPosition
	 *
	 * \brief	Used to show the position of the mouse pointer
	 */
	struct sPosition
	{
		int x;
		int y;
	};

	/**
	 * \fn	virtual sPosition IMouse::GetMousePosition() = 0;
	 *
	 * \brief	Gets mouse position.
	 *
	 * \return	The mouse position.
	 */
	virtual sPosition GetMousePosition() = 0;

	/**
	 * \fn	virtual bool IMouse::IsButtonDown(int button) = 0;
	 *
	 * \brief	Query if 'button' is button down.
	 *
	 * \param	button	The button.
	 *
	 * \return	true if button down, false if not.
	 */
	virtual bool IsButtonDown(int button) = 0;

	virtual bool IsButtonDown(std::string button) = 0;

	/**
	 * \fn	virtual double IMouse::GetScrollValue() = 0;
	 *
	 * \brief	Gets scroll value.
	 *
	 * \return	The scroll value.
	 */
	virtual double GetScrollValue() = 0;

	/**
	 * \fn	void IMouse::DefineButton(std::string identifier, int key);
	 *
	 * \brief	Define button.
	 *
	 * \param	identifier	The identifier.
	 * \param	key		  	The key.
	 */
	void DefineButton(std::string identifier, int key);

	/**
	 * \fn	void IMouse::UndefineButton(std::string identifier);
	 *
	 * \brief	Undefine button.
	 *
	 * \param	identifier	The identifier.
	 */
	void UndefineButton(std::string identifier);
protected:
	std::map<std::string, int> mButtonsDefined; //!< The buttons defined
};

