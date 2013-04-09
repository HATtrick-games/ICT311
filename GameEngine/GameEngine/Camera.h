#pragma once

#include "OpenGL.h"

#include "boost\smart_ptr.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "AngleMath.h"
#include <glutil/glutil.h>
#include "PlayerObject.h"
//#include <glload/gl_3_3.h>
//#include <GL/freeglut.h>

class Camera
{
public:
	Camera(void);
	~Camera(void);

	static boost::scoped_ptr<Camera>* GetInstance();

	void SetupCamera();
	void SetupCameraToClipMatrix(glutil::MatrixStack &modelMatrix); //Perspective matrix setup
	void CreateCamera(glutil::MatrixStack &modelMatrix);
	void CalcWorldToCameraMatrix(glm::vec3 CameraPos, glm::vec3 CameraLook, glm::vec3 UpVector);
	void CalcRelativePosition();
	void SetCameraFov(float newFov);
	float CalcCameraScale(float newScale);
	void ReshapeViewport(int NewWidth, int NewHeight);
	void UpdateProgObj(GLuint ProgObj);

	glm::vec3 GetCameraPosition() const;
	glm::vec3 GetCameraLookAt() const;

	void SetCameraPosition(glm::vec3 newPosition);
	void SetCameraLookAt(glm::vec3 newLookAt);

	void StorePlayerObj(PlayerObject* PlayerObj);

	glm::mat4 G() {return CameraLookAtMatrix;}

private:

	glm::mat4 fPerspectiveMatrix;
	glm::mat4 CameraLookAtMatrix;
	float fCameraScale;
	float fzNear;
	float fzFar;

	GLuint UniPerspectiveMatrix;
	//GLuint UniWorldToCamera;
	GLuint ProgObjLocal;

	PlayerObject* CameraData;
	glm::vec3 CameraPosition;
	glm::vec3 CameraLookAt;

	static boost::scoped_ptr<Camera> pCameraSingleton;
};

