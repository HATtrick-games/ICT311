#pragma once

#include "Graphics.h"
#include <GL\freeglut.h>
#include "GameSettings.h"

#include <iostream>
class OpenGL :public Graphics
{
public:
	static OpenGL * GetInstance();
	~OpenGL(void);

	//Virtual functions
	void Init(); // Used to intialise freeglut and call setup for the opengl context and window.
	void DrawModel(std::string Path); // To be changed to take in a more meaningful identifier(or different datatype) once we decide how / where we are storing model vertex data
	void Reshape(int width, int height);

	//OpenGL specific functions

private:
	OpenGL(void); // Used to intialise and setup anything required before freeglut sets up the window

	unsigned int iDisplayMode;
	int iMainWindow;
	
	//singleton stuff
	static OpenGL *OpenGLsingleton;
	static bool instanceFlag;

	GameSettings *Ini;

	static void ReshapeCallback(int width, int height)
	{
		OpenGLsingleton->Reshape(width, height);
	}
};


