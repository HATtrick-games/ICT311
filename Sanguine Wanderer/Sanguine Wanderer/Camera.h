#pragma once
#include "stdafx.h"
#include "OpenGL.h"

class Camera
{
public:
	Camera(void);
	~Camera(void);

	void Setup(GLuint ProgObjLocal);
	void CreatePerspective(int Width, int Height);
	void CreateCamera();
	void SetCameraLoc(glm::vec3 movementVec);
	void SetCameraLook(glm::vec3 movementVec);
	void SetLocation(glm::vec3 Location);
	void SetLookAt(glm::vec3 LookAt);

	static boost::scoped_ptr<Camera>* GetInstance();
private:

	GLuint ProgObjLocal;
	GLuint UniPerspectiveMatrix;
	GLuint UniWorldToCamera;
	glm::mat4 mPerspectiveMatrix;
	glm::mat4 mWorldToCamera;

	glm::vec3 CameraLoc;
	glm::vec3 CameraLook;

	static boost::scoped_ptr<Camera> pSingleton;
};

