#ifndef OPENGL_H
#define OPENGL_H

#include "Graphics.h"

class OpenGL :public Graphics
{
public:
	OpenGL(void);
	~OpenGL(void);

	void Init();
	void DrawModel(std::string Path); // To be changed to take in a more meaningful identifier(or different datatype) once we decide how / where we are storing model vertex data
};

#endif

