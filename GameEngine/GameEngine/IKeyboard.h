#pragma once

#include <map>
#include <string>

/**
 * \class	IKeyboard
 *
 * \brief	Keyboard.
 * 			
 * \author	Timothy Veletta
 */
class IKeyboard
{
public:

	/**
	 * \fn	virtual bool IKeyboard::IsKeyDown(int key) = 0;
	 *
	 * \brief	Query if 'key' is key down.
	 *
	 * \param	key	The key.
	 *
	 * \return	true if key down, false if not.
	 */
	virtual bool IsKeyDown(int key) = 0;

	/**
	 * \fn	virtual bool IKeyboard::IsKeyDown(std::string key) = 0;
	 *
	 * \brief	Query if 'key' is key down.
	 *
	 * \param	key	The key.
	 *
	 * \return	true if key down, false if not.
	 */
	virtual bool IsKeyDown(std::string key) = 0;

	/**
	 * \fn	void IKeyboard::DefineKey(std::string identifier, int key);
	 *
	 * \brief	Define key.
	 *
	 * \param	identifier	The identifier.
	 * \param	key		  	The key.
	 */
	void DefineKey(std::string identifier, int key);

	/**
	 * \fn	void IKeyboard::UndefineKey(std::string identifier);
	 *
	 * \brief	Undefine key.
	 *
	 * \param	identifier	The identifier.
	 */
	void UndefineKey(std::string identifier);
protected:
	std::map<std::string, int> mKeysDefined;	//!< The keys defined
};

