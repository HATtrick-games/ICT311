#pragma once

#include "OpenGL.h"

#include "boost\smart_ptr.hpp"
#include <glload/gl_3_3.h>
#include <GL/freeglut.h>

class Camera
{
public:
	Camera(void);
	~Camera(void);
	
	static boost::scoped_ptr<Camera>* GetInstance();

	void SetupCamera(GLuint ProgObj);
	void CreateCamera(GLuint ProgObj);
	void SetCameraScale(float newScale);
	void ReshapeViewport(int NewWidth, int NewHeight, GLuint ProgObj);
	
private:

	float fPerspectiveMatrix[16];
	float fCameraScale;
	float fzNear;
	float fzFar;

	GLuint UniPerspectiveMatrix;
	GLuint ProgObj;

	static boost::scoped_ptr<Camera> pCameraSingleton;
};

