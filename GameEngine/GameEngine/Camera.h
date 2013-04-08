#pragma once

#include "OpenGL.h"

#include "boost\smart_ptr.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "AngleMath.h"
//#include <glload/gl_3_3.h>
//#include <GL/freeglut.h>

class Camera
{
public:
	Camera(void);
	~Camera(void);
	
	static boost::scoped_ptr<Camera>* GetInstance();

	void SetupCamera();
	void CreateCamera();
	void SetCameraFov(float newFov);
	float CalcCameraScale(float newScale);
	void ReshapeViewport(int NewWidth, int NewHeight);
	void UpdateProgObj(GLuint ProgObj);
private:

	glm::mat4 fPerspectiveMatrix;
	float fCameraScale;
	float fzNear;
	float fzFar;

	GLuint UniPerspectiveMatrix;
	GLuint ProgObjLocal;

	static boost::scoped_ptr<Camera> pCameraSingleton;
};

