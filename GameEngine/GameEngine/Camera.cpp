#include "Camera.h"

boost::scoped_ptr<Camera> Camera::pCameraSingleton(NULL);

Camera::Camera(void)
{
}


Camera::~Camera(void)
{
}

void Camera::SetupCamera(void)
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

}

void Camera::CreateCamera(void)
{
	//glUniformMatrix4fv(perspectiveMatrixUnif, 1, GL_FALSE, perspectiveMatrix);
}

bool Camera::SetCameraScale(float newScale)
{
	fCameraScale = newScale;
	fPerspectiveMatrix[0] = fCameraScale;
	fPerspectiveMatrix[5] = fCameraScale;
	return true;
}

boost::scoped_ptr<Camera>* Camera::GetInstance(void)
{
	if(pCameraSingleton.get() == NULL)
	{
		pCameraSingleton.reset(new Camera);
	}
	return &pCameraSingleton;
}