#include "Camera.h"

boost::scoped_ptr<Camera> Camera::pCameraSingleton(NULL);

Camera::Camera(void)
{
}


Camera::~Camera(void)
{
}

void Camera::SetupCamera()
{
	fCameraScale = CalcCameraScale(45);
	fzNear = 1;
	fzFar = 3;

	//memset(fPerspectiveMatrix, 0, sizeof(float) * 16); //set all values to 0

	fPerspectiveMatrix[0].x = fCameraScale;//scale*Xcamera
	fPerspectiveMatrix[1].y = fCameraScale; //scale*Ycamera
	fPerspectiveMatrix[2].z = (fzFar + fzNear) / (fzNear - fzFar); //z perspective transform
	fPerspectiveMatrix[2].w = -1.0f;
	fPerspectiveMatrix[3].z = (2 * fzFar * fzNear) / (fzNear - fzFar); //z perspective transform

	glUseProgram(ProgObjLocal);
	UniPerspectiveMatrix = glGetUniformLocation(ProgObjLocal, "cameraToClipMatrix");

	glUseProgram(0);
	CreateCamera();
}

void Camera::CreateCamera()
{	
	glUseProgram(ProgObjLocal);
	glUniformMatrix4fv(UniPerspectiveMatrix, 1, GL_FALSE, glm::value_ptr(fPerspectiveMatrix));
	glUseProgram(0);
}

float Camera::CalcCameraScale(float newfov)
{
	float fov = (*AngleMath::GetInstance())->DegreeToRadian(newfov);

	return 1.0f / tan(fov / 2.0f);
}

void Camera::SetCameraFov(float newFov)
{
	fCameraScale = CalcCameraScale(newFov);
	fPerspectiveMatrix[0].x = fCameraScale;
	fPerspectiveMatrix[1].y = fCameraScale;
}
void Camera::ReshapeViewport(int NewWidth, int NewHeight)
{
	fPerspectiveMatrix[0].x = fCameraScale * (NewHeight / (float)NewWidth);
	fPerspectiveMatrix[1].y = fCameraScale;

	CreateCamera();
 
	glViewport(0, 0, (GLsizei) NewWidth, (GLsizei) NewHeight);
}

void Camera::UpdateProgObj(GLuint ProgObj)
{
	ProgObjLocal = ProgObj;
}

boost::scoped_ptr<Camera>* Camera::GetInstance(void)
{
	if(pCameraSingleton.get() == NULL)
	{
		pCameraSingleton.reset(new Camera);
	}
	return &pCameraSingleton;
}