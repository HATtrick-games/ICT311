#include "stdafx.h"
#include "OGLKeyboard.h"

bool* OGLKeyboard::pKeyStates = new bool[512];

OGLKeyboard::OGLKeyboard(void)
{
	glutKeyboardFunc(KeyPressed);
	glutKeyboardUpFunc(KeyUp);
	glutSpecialFunc(SpecialKeyPressed);
	glutSpecialUpFunc(SpecialKeyUp);

	for(int i = 0; i < 512; i++)
	{
		OGLKeyboard::pKeyStates[i] = false;
	}
}

OGLKeyboard::~OGLKeyboard(void)
{
}

bool OGLKeyboard::IsKeyDown(int key)
{
	return OGLKeyboard::pKeyStates[key];
}

bool OGLKeyboard::IsKeyDown(std::string key)
{
	return OGLKeyboard::pKeyStates[mKeysDefined[key]];
}

void OGLKeyboard::KeyPressed(unsigned char key, int x, int y)
{
	pKeyStates[(int)tolower(key)] = true;
	(*Game::GetInstance())->Input();
}

void OGLKeyboard::KeyUp(unsigned char key, int x, int y)
{
	pKeyStates[(int)tolower(key)] = false;
}

void OGLKeyboard::SpecialKeyPressed(int key, int x, int y)
{
	pKeyStates[key + 256] = true;
}

void OGLKeyboard::SpecialKeyUp(int key, int x, int y)
{
	pKeyStates[key + 256] = false;
}