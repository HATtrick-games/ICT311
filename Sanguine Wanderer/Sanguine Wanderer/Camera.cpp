#include "StdAfx.h"
#include "Camera.h"

boost::scoped_ptr<Camera> Camera::pSingleton(NULL);

Camera::Camera(void)
{
	CameraLoc = glm::vec3(0,3,0);
	CameraLook = glm::vec3(0,3,-1);
}

void Camera::Setup(GLuint ProgObj)
{
	ProgObjLocal = ProgObj;
	glUseProgram(ProgObjLocal);
	UniPerspectiveMatrix = glGetUniformLocation(ProgObjLocal, "cameraToClipMatrix");
	UniWorldToCamera = glGetUniformLocation(ProgObjLocal, "WorldToCamera");
	glUseProgram(0);
}

void Camera::CreatePerspective(int Width, int Height)
{
	float fzNear = 1;
	float fzFar = 2000.0;
	glutil::MatrixStack modelMatrix;
	modelMatrix.Perspective(60, (Width / (float) Height), fzNear, fzFar);
	
	mPerspectiveMatrix = modelMatrix.Top();
	glUseProgram(ProgObjLocal);
	glUniformMatrix4fv(UniPerspectiveMatrix, 1, GL_FALSE, glm::value_ptr(mPerspectiveMatrix));
	glUseProgram(0);
}

void Camera::CreateCamera()
{	
	glutil::MatrixStack modelMatrix;
	modelMatrix.LookAt(CameraLoc, CameraLook, glm::vec3(0,1,0));
	
	mWorldToCamera = modelMatrix.Top();
	glUseProgram(ProgObjLocal);
	glUniformMatrix4fv(UniWorldToCamera, 1, GL_FALSE, glm::value_ptr(mWorldToCamera));
	glUseProgram(0);
	
}

void Camera::SetCameraLoc(glm::vec3 movementVec)
{
	//CameraLoc += movementVec;
	//CameraLook += movementVec;

	//to move the camera in the looking direction
	
	float Xvec = CameraLook.x - CameraLoc.x;
	float Zvec = CameraLook.z - CameraLoc.z; 

	if(movementVec.z < 0) // move forwards (for now)
	{
		glm::vec3 Move(-(Xvec/(Xvec+Zvec)),0,-(Zvec/(Xvec+Zvec)));
		CameraLoc += Move;
		CameraLook += Move;
	}
	else if(movementVec.z > 0) // move forwards (for now)
	{
		glm::vec3 Move((Xvec/(Xvec+Zvec)),0,(Zvec/(Xvec+Zvec)));
		CameraLoc += Move;
		CameraLook += Move;
	}
	else if(movementVec.x > 0)
	{
		glm::vec3 Move((Zvec/(Xvec+Zvec)),0,-(Xvec/(Xvec+Zvec)));
		CameraLoc += Move;
		CameraLook += Move;
	}
	else if(movementVec.x < 0)
	{
		glm::vec3 Move(-(Zvec/(Xvec+Zvec)),0,(Xvec/(Xvec+Zvec)));
		CameraLoc += Move;
		CameraLook += Move;
	}
}

void Camera::SetCameraLook(glm::vec3 movementVec)
{
	/*if((CameraLook.x > 0) && (movementVec.x > 0))
	{
		CameraLook += (movementVec +glm::vec3(0,0,-0.1));
	}
	else if((CameraLook.x > 0) && (movementVec.x < 0))
	{
		CameraLook += (movementVec +glm::vec3(0,0,0.1));
	}
	else if((CameraLook.x < 0) && (movementVec.x < 0))
	{
		CameraLook += (movementVec +glm::vec3(0,0,-0.1));
	}
	else if((CameraLook.x < 0) && (movementVec.x > 0))
	{
		CameraLook += (movementVec +glm::vec3(0,0,0.1));
	}
	else
	{
		CameraLook += movementVec;
	}*/
	
	
	CameraLook.x += movementVec.x;
}

Camera::~Camera(void)
{
}

boost::scoped_ptr<Camera>* Camera::GetInstance(void)
{
	if(pSingleton.get() == NULL)
	{
		pSingleton.reset(new Camera);
	}
	return &pSingleton;
}