/**
 * \file	Camera.h
 *
 * \brief	Declares the camera class.
 */

#pragma once

#include "OpenGL.h"

#include "boost\smart_ptr.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "AngleMath.h"
#include <glutil/glutil.h>
#include "PlayerObject.h"

/**
 * \class	Camera
 *
 * \brief	#include <glload/gl_3_3.h>
 * 			#include <GL/freeglut.h>
 *
 * \author	Hamish Carrier
 * \date	4/10/2013
 */

class Camera
{
public:

	

	/**
	 * \fn	Camera::~Camera(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	~Camera(void);

	/**
	 * \fn	static boost::scoped_ptr<Camera>* Camera::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<Camera>* GetInstance();

	/**
	 * \fn	void Camera::SetupCamera();
	 *
	 * \brief	Sets up the camera.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	void SetupCamera();

	/**
	 * \fn	void Camera::SetupCameraToClipMatrix(glutil::MatrixStack &modelMatrix);
	 *
	 * \brief	Sets up the camera to clip matrix.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param [in,out]	modelMatrix	The model matrix.
	 */

	void SetupCameraToClipMatrix(glutil::MatrixStack &modelMatrix); //Perspective matrix setup

	/**
	 * \fn	void Camera::CreateCamera(glutil::MatrixStack &modelMatrix);
	 *
	 * \brief	Creates a camera.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param [in,out]	modelMatrix	The model matrix.
	 */

	void CreateCamera(glutil::MatrixStack &modelMatrix);

	/**
	 * \fn	void Camera::CalcWorldToCameraMatrix(glm::vec3 CameraPos, glm::vec3 CameraLook,
	 * 		glm::vec3 UpVector);
	 *
	 * \brief	Calculates the world to camera matrix.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	CameraPos 	The camera position.
	 * \param	CameraLook	The camera look.
	 * \param	UpVector  	The up vector.
	 */

	void CalcWorldToCameraMatrix(glm::vec3 CameraPos, glm::vec3 CameraLook, glm::vec3 UpVector);

	/**
	 * \fn	void Camera::CalcRelativePosition();
	 *
	 * \brief	Calculates the relative position.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	void CalcRelativePosition();

	/**
	 * \fn	void Camera::SetCameraFov(float newFov);
	 *
	 * \brief	Sets camera fov.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	newFov	The new fov.
	 */

	void SetCameraFov(float newFov);

	/**
	 * \fn	float Camera::CalcCameraScale(float newScale);
	 *
	 * \brief	Calculates the camera scale.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	newScale	The new scale.
	 *
	 * \return	The calculated camera scale.
	 */

	float CalcCameraScale(float newScale);

	/**
	 * \fn	void Camera::ReshapeViewport(int NewWidth, int NewHeight);
	 *
	 * \brief	Reshape viewport.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	NewWidth 	Width of the new.
	 * \param	NewHeight	Height of the new.
	 */

	void ReshapeViewport(int NewWidth, int NewHeight);

	/**
	 * \fn	void Camera::UpdateProgObj(GLuint ProgObj);
	 *
	 * \brief	Updates the prog object described by ProgObj.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	ProgObj	The prog object.
	 */

	void UpdateProgObj(GLuint ProgObj);

	/**
	 * \fn	void Camera::StorePlayerObj(PlayerObject* PlayerObj);
	 *
	 * \brief	Stores player object.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param [in,out]	PlayerObj	If non-null, the player object.
	 */

	void StorePlayerObj(PlayerObject* PlayerObj);

	/**
	 * \fn	glm::mat4 Camera::G()
	 *
	 * \brief	Gets the CameraLookAtMatrix.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	.
	 */

	glm::mat4 G() {return CameraLookAtMatrix;}

	/**
	 * \fn	void Camera::ChangeRotation(float deg);
	 *
	 * \brief	Change rotation.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	deg	The degrees.
	 */

	void ChangeRotation(float deg);

private:

	/**
	 * \brief	The perspective matrix.
	 */

	glm::mat4 fPerspectiveMatrix;

	/**
	 * \brief	The camera look at matrix.
	 */

	glm::mat4 CameraLookAtMatrix;

	/**
	 * \brief	The camera scale.
	 */

	float fCameraScale;

	/**
	 * \brief	The camera near depth.
	 */

	float fzNear;

	/**
	 * \brief	The camera depth.
	 */

	float fzFar;

	/**
	 * \brief	The rotation.
	 */

	float rotation;

	/**
	 * \brief	The uni perspective matrix to be passed and used in the vertex shader.
	 */

	GLuint UniPerspectiveMatrix;

	/**
	 * \brief	The uni world to camera to be passed and used in the vertex shader.
	 */

	GLuint UniWorldToCamera;

	/**
	 * \brief	The prog object local.
	 */

	GLuint ProgObjLocal;

	/**
	 * \brief	Information describing the camera.
	 */

	PlayerObject* CameraData;
	/**
	 * \fn	Camera::Camera(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	Camera(void);
	/**
	 * \brief	The camera singleton.
	 */

	static boost::scoped_ptr<Camera> pCameraSingleton;
};

