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
	fCameraScale = 0;
	fzNear = 1;
	fzFar = 3;

	memset(fPerspectiveMatrix, 0, sizeof(float) * 16); //set all values to 0

	fPerspectiveMatrix[0] = fCameraScale;//scale*Xcamera
	fPerspectiveMatrix[5] = fCameraScale; //scale*Ycamera
	fPerspectiveMatrix[10] = (fzFar + fzNear) / (fzNear - fzFar); //z perspective transform
	fPerspectiveMatrix[14] = (2 * fzFar * fzNear) / (fzNear - fzFar); //z perspective transform
	fPerspectiveMatrix[11] = -1.0f; //w negative Zcamera

	glUseProgram(ProgObjLocal);
	UniPerspectiveMatrix = glGetUniformLocation(ProgObjLocal, "perspectiveMatrix");
	glUseProgram(0);
}

void Camera::CreateCamera()
{	
	glUseProgram(ProgObjLocal);
	glUniformMatrix4fv(UniPerspectiveMatrix, 1, GL_FALSE, fPerspectiveMatrix);
	glUseProgram(0);
}

void Camera::SetCameraScale(float newScale)
{
	fCameraScale = newScale;
	fPerspectiveMatrix[0] = fCameraScale;
	fPerspectiveMatrix[5] = fCameraScale;
}

void Camera::ReshapeViewport(int NewWidth, int NewHeight)
{
	fPerspectiveMatrix[0] = fCameraScale * (NewHeight / (float)NewWidth);
	fPerspectiveMatrix[5] = fCameraScale;

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