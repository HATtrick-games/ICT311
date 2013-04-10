#include "Camera.h"

boost::scoped_ptr<Camera> Camera::pCameraSingleton(NULL);

Camera::Camera(void)
{
	rotation = 0.0f;
}


Camera::~Camera(void)
{
}

void Camera::SetupCamera()
{
	glUseProgram(ProgObjLocal);
	UniPerspectiveMatrix = glGetUniformLocation(ProgObjLocal, "cameraToClipMatrix");
	//UniWorldToCamera = glGetUniformLocation(ProgObjLocal, "WorldToCamera");
	glUseProgram(0);
}

void Camera::SetupCameraToClipMatrix(glutil::MatrixStack &modelMatrix)
{

	//fCameraScale = CalcCameraScale(60);
	fzNear = 1;
	fzFar = 100;
	modelMatrix.Perspective(60, 1, fzNear, fzFar);
	fPerspectiveMatrix = modelMatrix.Top();
	/*glm::mat4 temp(0);
	fPerspectiveMatrix = temp;

	fPerspectiveMatrix[0].x = fCameraScale;//scale*Xcamera
	fPerspectiveMatrix[1].y = fCameraScale; //scale*Ycamera
	fPerspectiveMatrix[2].z = (fzFar + fzNear) / (fzNear - fzFar); //z perspective transform
	fPerspectiveMatrix[2].w = -1.0f;
	fPerspectiveMatrix[3].z = (2 * fzFar * fzNear) / (fzNear - fzFar); //z perspective transform*/
}



void Camera::CalcWorldToCameraMatrix(glm::vec3 CameraPos, glm::vec3 CameraLook, glm::vec3 UpVec)
{
	/*
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
	*/
}

void Camera::CreateCamera(glutil::MatrixStack &modelMatrix)
{	
	//SetupCameraToClipMatrix();
	//CalcWorldToCameraMatrix(CameraPosition, CameraLookAt, glm::vec3(0,1,0));
	modelMatrix.LookAt(CameraData->GetPlayerCameraPosition(), CameraData->GetPlayerLookAt(), glm::vec3(0,1,0));
	modelMatrix.RotateY(rotation);
	CameraLookAtMatrix = modelMatrix.Top();
	glUseProgram(ProgObjLocal);
	glUniformMatrix4fv(UniPerspectiveMatrix, 1, GL_FALSE, glm::value_ptr(fPerspectiveMatrix));
	//glUniformMatrix4fv(UniWorldToCamera, 1, GL_FALSE, glm::value_ptr(CameraLookAtMatrix));
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
	/*float phi = (*AngleMath::GetInstance())->DegreeToRadian(CameraPosition.x);
	float theta = (*AngleMath::GetInstance())->DegreeToRadian(CameraPosition.y + 90);

	float fSinTheta = sinf(theta);
	float fCosTheta = cosf(theta);
	float fCosPhi = cosf(phi);
	float fSinPhi = sinf(phi);
	glm::vec3 dirToCamera(fSinTheta * fCosPhi, fCosTheta, fSinTheta * fSinPhi);
	
	CameraPosition = (dirToCamera * CameraPosition.z) + CameraLookAt;
	*/
}

void Camera::ReshapeViewport(int NewWidth, int NewHeight)
{
	fPerspectiveMatrix[0].x = fCameraScale * (NewHeight / (float)NewWidth);
	fPerspectiveMatrix[1].y = fCameraScale;

	//CreateCamera();
 
	glViewport(0, 0, (GLsizei) NewWidth, (GLsizei) NewHeight);
}

void Camera::StorePlayerObj(PlayerObject* PlayerObj)
{
	CameraData = PlayerObj;
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

void Camera::ChangeRotation(float deg)
{
	rotation += deg;
}