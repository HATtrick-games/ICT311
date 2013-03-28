#pragma once

#include <GL/freeglut.h>
#include "imouse.h"

/**
 * \typedef	enum OGLButton
 *
 * \brief	Represents the left, middle and right mouse buttons.
 */
typedef enum OGLButton
{
	MOUSE_LEFT = GLUT_LEFT_BUTTON,
	MOUSE_MIDDLE = GLUT_MIDDLE_BUTTON,
	MOUSE_RIGHT = GLUT_RIGHT_BUTTON,
};

/**
 * \class	OGLMouse
 *
 * \brief	OpenGL Mouse implementation.
 *
 * \author	Timothy Veletta
 * \date	27/03/2013
 */

class OGLMouse :
	public IMouse
{
public:

	/**
	 * \fn	OGLMouse::OGLMouse(void);
	 *
	 * \brief	Default constructor.
	 */
	OGLMouse(void);

	/**
	 * \fn	OGLMouse::~OGLMouse(void);
	 *
	 * \brief	Destructor.
	 */
	~OGLMouse(void);

	/**
	 * \fn	virtual sPosition OGLMouse::GetMousePosition();
	 *
	 * \brief	Gets mouse position.
	 *
	 * \return	The mouse position.
	 */
	virtual sPosition GetMousePosition();

	/**
	 * \fn	virtual bool OGLMouse::IsButtonDown(int button);
	 *
	 * \brief	Query if 'button' is button down.
	 *
	 * \param	button	The button.
	 *
	 * \return	true if button down, false if not.
	 */
	virtual bool IsButtonDown(int button);

	/**
	 * \fn	virtual double OGLMouse::GetScrollValue();
	 *
	 * \brief	Gets scroll value.
	 *
	 * \return	The scroll value.
	 */
	virtual double GetScrollValue();
private:
	static void MouseMotion(int x, int y);
	static void Mouse(int button, int state, int x, int y);

	static sPosition mousePosition; //!< The mouse position
	static bool* pButtonStates; //!< List of states of the buttons
	static double dScrollValue; //!< The scroll value
};

