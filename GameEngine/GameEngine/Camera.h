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
	void SetupCameraToClipMatrix(); //Perspective matrix setup
	void CreateCamera();
	void CalcWorldToCameraMatrix(glm::vec3 CameraPos, glm::vec3 CameraLook, glm::vec3 UpVector);
	void SetCameraFov(float newFov);
	float CalcCameraScale(float newScale);
	void ReshapeViewport(int NewWidth, int NewHeight);
	void UpdateProgObj(GLuint ProgObj);

	glm::vec3 GetCameraPosition() const;
	glm::vec3 GetCameraLookAt() const;

	void SetCameraPosition(glm::vec3 newPosition);
	void SetCameraLookAt(glm::vec3 newLookAt);

private:

	glm::mat4 fPerspectiveMatrix;
	glm::mat4 CameraLookAtMatrix;
	float fCameraScale;
	float fzNear;
	float fzFar;

	GLuint UniPerspectiveMatrix;
	GLuint UniWorldToCamera;
	GLuint ProgObjLocal;

	glm::vec3 CameraPosition;
	glm::vec3 CameraLookAt;

	static boost::scoped_ptr<Camera> pCameraSingleton;
};

