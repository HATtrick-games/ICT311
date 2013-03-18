#pragma once

#include "Graphics.h"
#include <GL\freeglut.h>
#include "GameSettings.h"

class OpenGL :public Graphics
{
public:
	OpenGL(void); // Used to intialise and setup anything required before freeglut sets up the window
	~OpenGL(void);

	//Virtual functions
	void Init(); // Used to intialise freeglut and call setup for the opengl context and window.
	void DrawModel(std::string Path); // To be changed to take in a more meaningful identifier(or different datatype) once we decide how / where we are storing model vertex data
	void Reshape(int width, int height);

	//OpenGL specific functions

private:
	unsigned int iDisplayMode;
	int iMainWindow;
	GameSettings *Ini;
};


