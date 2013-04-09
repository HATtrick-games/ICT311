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
	CameraPosition.x = 0;
	CameraPosition.y = 0;
	CameraPosition.z = 0;
	CameraLookAt.x = 0;
	CameraLookAt.y = 0;
	CameraLookAt.z = -10;
	SetupCameraToClipMatrix();
	CalcWorldToCameraMatrix(CameraPosition, CameraLookAt, glm::vec3(0,1,0));
	glUseProgram(ProgObjLocal);
	UniWorldToCamera = glGetUniformLocation(ProgObjLocal, "WorldToCamera");
	glUseProgram(0);
	CreateCamera();
}

void Camera::SetupCameraToClipMatrix()
{
	fCameraScale = CalcCameraScale(60);
	fzNear = 1;
	fzFar = 100;

	glm::mat4 temp(0);
	fPerspectiveMatrix = temp;
	//memset(fPerspectiveMatrix, 0, sizeof(float) * 16); //set all values to 0

	fPerspectiveMatrix[0].x = fCameraScale;//scale*Xcamera
	fPerspectiveMatrix[1].y = fCameraScale; //scale*Ycamera
	fPerspectiveMatrix[2].z = (fzFar + fzNear) / (fzNear - fzFar); //z perspective transform
	fPerspectiveMatrix[2].w = -1.0f;
	fPerspectiveMatrix[3].z = (2 * fzFar * fzNear) / (fzNear - fzFar); //z perspective transform

	glUseProgram(ProgObjLocal);
	UniPerspectiveMatrix = glGetUniformLocation(ProgObjLocal, "cameraToClipMatrix");
	glUseProgram(0);
}

void Camera::CalcWorldToCameraMatrix(glm::vec3 CameraPos, glm::vec3 CameraLook, glm::vec3 UpVec)
{
	glm::vec3 lookDir = glm::normalize(CameraLook - CameraPos);
	glm::vec3 upDir = glm::normalize(UpVec);

	glm::vec3 rightDir = glm::normalize(glm::cross(lookDir, upDir));
	glm::vec3 perpUpDir = glm::cross(rightDir, lookDir);

	glm::mat4 rotationalMat(1.0f);
	rotationalMat[0] = glm::vec4(rightDir, 0.0f);
	rotationalMat[1] = glm::vec4(perpUpDir, 0.0f);
	rotationalMat[2] = glm::vec4(-lookDir, 0.0f);

	rotationalMat = glm::transpose(rotationalMat);

	glm::mat4 transMat(1.0f);
	transMat[3] = glm::vec4(-CameraPos, 1.0f);

	CameraLookAtMatrix = rotationalMat * transMat;
}

void Camera::CreateCamera()
{	
	glUseProgram(ProgObjLocal);
	glUniformMatrix4fv(UniPerspectiveMatrix, 1, GL_FALSE, glm::value_ptr(fPerspectiveMatrix));
	glUniformMatrix4fv(UniWorldToCamera, 1, GL_FALSE, glm::value_ptr(CameraLookAtMatrix));
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

void Camera::CalcRelativePosition()
{
	float phi = (*AngleMath::GetInstance())->DegreeToRadian(CameraPosition.x);
	float theta = (*AngleMath::GetInstance())->DegreeToRadian(CameraPosition.y + 90);

	float fSinTheta = sinf(theta);
	float fCosTheta = cosf(theta);
	float fCosPhi = cosf(phi);
	float fSinPhi = sinf(phi);
	glm::vec3 dirToCamera(fSinTheta * fCosPhi, fCosTheta, fSinTheta * fSinPhi);
	
	CameraPosition = (dirToCamera * CameraPosition.z) + CameraLookAt;
}

void Camera::ReshapeViewport(int NewWidth, int NewHeight)
{
	fPerspectiveMatrix[0].x = fCameraScale * (NewHeight / (float)NewWidth);
	fPerspectiveMatrix[1].y = fCameraScale;

	//CreateCamera();
 
	glViewport(0, 0, (GLsizei) NewWidth, (GLsizei) NewHeight);
}

void Camera::UpdateProgObj(GLuint ProgObj)
{
	ProgObjLocal = ProgObj;
}

glm::vec3 Camera::GetCameraPosition() const
{
	return CameraPosition;
}

glm::vec3 Camera::GetCameraLookAt() const
{
	return CameraLookAt;
}

void Camera::SetCameraPosition(glm::vec3 newPosition)
{
	CameraPosition = newPosition;
}

void Camera::SetCameraLookAt(glm::vec3 newLookAt)
{
	CameraLookAt = newLookAt;
	//CalcRelativePosition();
	CalcWorldToCameraMatrix(CameraPosition, CameraLookAt, glm::vec3(0,1,0));
}

boost::scoped_ptr<Camera>* Camera::GetInstance(void)
{
	if(pCameraSingleton.get() == NULL)
	{
		pCameraSingleton.reset(new Camera);
	}
	return &pCameraSingleton;
}