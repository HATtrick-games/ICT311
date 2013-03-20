#pragma once

#include "Graphics.h"
#include "Shader.h"
#include <GL\freeglut.h>
#include "GameSettings.h"
//#include <glload\gl_3_3.h>
#include <glload\gll.hpp>
#include <boost\smart_ptr.hpp>

#include <vector>
#include <iostream>
class OpenGL :public Graphics
{
public:
	static boost::scoped_ptr<Graphics> * GetInstance();
	~OpenGL(void);

	//Virtual functions
	void Init(); // Used to intialise freeglut and call setup for the opengl context and window.
	void DrawModel(std::string Path); // To be changed to take in a more meaningful identifier(or different datatype) once we decide how / where we are storing model vertex data
	void Reshape(int width, int height);
	void Display();

	//OpenGL specific functions
	void SetupProgram();


private:
	OpenGL(void); // Used to intialise and setup anything required before freeglut sets up the window
	OpenGL& operator= (const OpenGL&);
	OpenGL(const OpenGL&);

	unsigned int iDisplayMode;
	int iMainWindow;
	
	//singleton stuff
	static boost::scoped_ptr<Graphics> pOpenGLsingleton;

	boost::scoped_ptr<GameSettings>* Ini;

	static void ReshapeCallback(int width, int height)
	{
		pOpenGLsingleton->Reshape(width, height);
	}
	
	static void DisplayCallback()
	{
		pOpenGLsingleton->Display();
	}
};


