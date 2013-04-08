#include "OGLMouse.h"

IMouse::sPosition OGLMouse::mousePosition;
bool* OGLMouse::pButtonStates = new bool[3];
double OGLMouse::dScrollValue = 0.0;

OGLMouse::OGLMouse(void)
{
	glutMotionFunc(MouseMotion);
	glutPassiveMotionFunc(MouseMotion);
	glutMouseFunc(Mouse);

	for(int i = 0; i < 3; i++)
	{
		OGLMouse::pButtonStates[i] = false;
	}
}

OGLMouse::~OGLMouse(void)
{
}

IMouse::sPosition OGLMouse::GetMousePosition()
{
	return OGLMouse::mousePosition;
}

bool OGLMouse::IsButtonDown(int button)
{
	return pButtonStates[button];
}

bool OGLMouse::IsButtonDown(std::string button)
{
	return pButtonStates[mButtonsDefined[button]];
}

double OGLMouse::GetScrollValue()
{
	return OGLMouse::dScrollValue;
}

void OGLMouse::MouseMotion(int x, int y)
{
	mousePosition.x = x;
	mousePosition.y = y;
}

void OGLMouse::Mouse(int button, int state, int x, int y)
{
	// button presses
	if(button <= 2)
	{
		bool st = false;

		if(state == GLUT_DOWN)
		{
			st = true;
		}

		pButtonStates[button] = st;
	}
	else if(button == 3)
	{
		// scroll up
		dScrollValue += 0.1;
	}
	else if(button == 4)
	{
		// scroll down
		dScrollValue -= 0.1;
	}
}