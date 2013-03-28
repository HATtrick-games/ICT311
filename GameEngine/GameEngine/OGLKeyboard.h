#pragma once
#include "ikeyboard.h"
#include <GL/freeglut.h>

/**
 * \typedef	enum OGLKeys
 *
 * \brief	Defines an alias representing the ogl keys.
 */
typedef enum OGLKeys
{
	KEY_Q = int('q'),
	KEY_W = int('w'),
	KEY_E = int('e'),
	KEY_R = int('r'),
	KEY_T = int('t'),
	KEY_Y = int('y'),
	KEY_U = int('u'),
	KEY_I = int('i'),
	KEY_O = int('o'),
	KEY_P = int('p'),
	KEY_A = int('a'),
	KEY_S = int('s'),
	KEY_D = int('d'),
	KEY_F = int('f'),
	KEY_G = int('g'),
	KEY_H = int('h'),
	KEY_J = int('j'),
	KEY_K = int('k'),
	KEY_L = int('l'),
	KEY_Z = int('z'),
	KEY_X = int('x'),
	KEY_C = int('c'),
	KEY_V = int('v'),
	KEY_B = int('b'),
	KEY_N = int('n'),
	KEY_M = int('m'),
	KEY_1 = int('1'),
	KEY_2 = int('2'),
	KEY_3 = int('3'),
	KEY_4 = int('4'),
	KEY_5 = int('5'),
	KEY_6 = int('6'),
	KEY_7 = int('7'),
	KEY_8 = int('8'),
	KEY_9 = int('9'),
	KEY_0 = int('0'),
	KEY_UP = GLUT_KEY_UP + 256,
	KEY_DOWN = GLUT_KEY_DOWN + 256,
	KEY_LEFT = GLUT_KEY_LEFT + 256,
	KEY_RIGHT = GLUT_KEY_RIGHT + 256,
	KEY_F1 = GLUT_KEY_F1 + 256,
	KEY_F2 = GLUT_KEY_F2 + 256,
	KEY_F3 = GLUT_KEY_F3 + 256,
	KEY_F4 = GLUT_KEY_F4 + 256,
	KEY_F5 = GLUT_KEY_F5 + 256,
	KEY_F6 = GLUT_KEY_F6 + 256,
	KEY_F7 = GLUT_KEY_F7 + 256,
	KEY_F8 = GLUT_KEY_F8 + 256,
	KEY_F9 = GLUT_KEY_F9 + 256,
	KEY_F10 = GLUT_KEY_F10 + 256,
	KEY_F11 = GLUT_KEY_F11 + 256,
	KEY_F12 = GLUT_KEY_F12 + 256,
	KEY_PAGEUP = GLUT_KEY_PAGE_UP + 256,
	KEY_PAGEDOWN = GLUT_KEY_PAGE_DOWN + 256,
	KEY_HOME = GLUT_KEY_HOME + 256,
	KEY_END = GLUT_KEY_END + 256,
	KEY_INSERT = GLUT_KEY_INSERT + 256,
	KEY_BACKSPACE = 8,
	KEY_SPACE = 32,
	KEY_ENTER = 13,
	KEY_ESCAPE = 27,
	KEY_TAB = 9,
	KEY_TILDE = 96,
	KEY_LCTRL = GLUT_KEY_CTRL_L + 256,
	KEY_RCTRL = GLUT_KEY_CTRL_R + 256,
	KEY_LALT = GLUT_KEY_ALT_L + 256,
	KEY_RALT = GLUT_KEY_ALT_R + 256,
	KEY_LSHIFT = GLUT_KEY_SHIFT_L + 256,
	KEY_RSHIFT = GLUT_KEY_SHIFT_R + 256,
};

/**
 * \class	OGLKeyboard
 *
 * \brief	Ogl keyboard.
 */
class OGLKeyboard :
	public IKeyboard
{
public:

	/**
	 * \fn	OGLKeyboard::OGLKeyboard(void);
	 *
	 * \brief	Default constructor.
	 */
	OGLKeyboard(void);

	/**
	 * \fn	OGLKeyboard::~OGLKeyboard(void);
	 *
	 * \brief	Destructor.
	 */
	~OGLKeyboard(void);

	/**
	 * \fn	virtual bool OGLKeyboard::IsKeyDown(int key);
	 *
	 * \brief	Query if 'key' is key down.
	 *
	 * \param	key	The key.
	 *
	 * \return	true if key down, false if not.
	 */
	virtual bool IsKeyDown(int key);

	/**
	 * \fn	virtual bool OGLKeyboard::IsKeyDown(std::string key);
	 *
	 * \brief	Query if 'key' is key down.
	 *
	 * \param	key	The key.
	 *
	 * \return	true if key down, false if not.
	 */
	virtual bool IsKeyDown(std::string key);

private:
	static void KeyPressed(unsigned char key, int x, int y);
	static void KeyUp(unsigned char key, int x, int y);
	static void SpecialKeyPressed(int key, int x, int y);
	static void SpecialKeyUp(int key, int x, int y);

	static bool* pKeyStates;	//!< List of states of the keys
};

