/**
 * \file	Camera.h
 *
 * \brief	Declares the camera class.
 */

#pragma once
#include "stdafx.h"
#include "OpenGL.h"

/**
 * \class	Camera
 *
 * \brief	Camera.
 *
 * \author	Chaokel
 * \date	22/05/2013
 */

class Camera
{
public:
	Camera(void);
	~Camera(void);

	/**
	 * \fn	void Camera::Setup(GLuint ProgObjLocal);
	 *
	 * \brief	Setups the given prog object local.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	ProgObjLocal	The prog object local.
	 */

	void Setup(GLuint ProgObjLocal);

	/**
	 * \fn	void Camera::CreatePerspective(int Width, int Height);
	 *
	 * \brief	Creates a perspective.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	Width 	The width.
	 * \param	Height	The height.
	 */

	void CreatePerspective(int Width, int Height);

	/**
	 * \fn	void Camera::CreateCamera();
	 *
	 * \brief	Creates the camera.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	void CreateCamera();

	/**
	 * \fn	void Camera::SetCameraLoc(glm::vec3 movementVec);
	 *
	 * \brief	Sets camera location.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	movementVec	The movement vector.
	 */

	void SetCameraLoc(glm::vec3 movementVec);

	/**
	 * \fn	void Camera::SetCameraLook(glm::vec3 movementVec);
	 *
	 * \brief	Sets camera look.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	movementVec	The movement vector.
	 */

	void SetCameraLook(glm::vec3 movementVec);

	/**
	 * \fn	void Camera::SetLocation(glm::vec3 Location);
	 *
	 * \brief	Sets a location.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	Location	The location.
	 */

	void SetLocation(glm::vec3 Location);

	/**
	 * \fn	void Camera::SetLookAt(glm::vec3 LookAt);
	 *
	 * \brief	Sets look at.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	LookAt	The look at.
	 */

	void SetLookAt(glm::vec3 LookAt);

	/**
	 * \fn	static boost::scoped_ptr<Camera>* Camera::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<Camera>* GetInstance();
private:

	/**
	 * \brief	The prog object local.
	 */

	GLuint ProgObjLocal;

	/**
	 * \brief	The uni perspective matrix.
	 */

	GLuint UniPerspectiveMatrix;

	/**
	 * \brief	The uni world to camera.
	 */

	GLuint UniWorldToCamera;

	/**
	 * \brief	The perspective matrix.
	 */

	glm::mat4 mPerspectiveMatrix;

	/**
	 * \brief	The world to camera.
	 */

	glm::mat4 mWorldToCamera;

	/**
	 * \brief	The camera location.
	 */

	glm::vec3 CameraLoc;

	/**
	 * \brief	The camera look.
	 */

	glm::vec3 CameraLook;

	/**
	 * \brief	The singleton.
	 */

	static boost::scoped_ptr<Camera> pSingleton;
};

