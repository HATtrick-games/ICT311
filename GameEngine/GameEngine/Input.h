#pragma once

#include <string>
#include "IKeyboard.h"
#include "IMouse.h"
#include "OGLKeyboard.h"
#include "OGLMouse.h"

#include <boost/scoped_ptr.hpp>

/**
 * \class	Input
 *
 * \brief	Input.
 */
class Input
{
public:

	/**
	 * \fn	Input::Input(void);
	 *
	 * \brief	Default constructor.
	 */
	Input(void);

	/**
	 * \fn	Input::Input(std::string inputMethod);
	 *
	 * \brief	Constructor.
	 *
	 * \param	inputMethod	The input method.
	 */
	Input(std::string inputMethod);

	/**
	 * \fn	Input::~Input(void);
	 *
	 * \brief	Destructor.
	 */
	~Input(void);

	/**
	 * \fn	void Input::SetInputMethod(std::string inputMethod);
	 *
	 * \brief	Sets input method.
	 *
	 * \param	inputMethod	The input method.
	 */
	void SetInputMethod(std::string inputMethod);

	/**
	 * \fn	IKeyboard* Input::GetKeyboard();
	 *
	 * \brief	Gets the keyboard.
	 *
	 * \return	null if it fails, else the keyboard.
	 */
	IKeyboard* GetKeyboard();

	/**
	 * \fn	IMouse* Input::GetMouse();
	 *
	 * \brief	Gets the mouse.
	 *
	 * \return	null if it fails, else the mouse.
	 */
	IMouse* GetMouse();

	static boost::scoped_ptr<Input>* GetInstance(); 
private:
	static boost::scoped_ptr<Input> pInput;

	static IKeyboard* sKeyboard;	//!< The keyboard
	static IMouse* sMouse;  //!< The mouse
};
