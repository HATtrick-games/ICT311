/**
 * \file	Graphics.h
 *
 * \brief	Declares the graphics class.
 */

#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "HeightMap.h"

/**
 * \class	Graphics
 *
 * \brief	Graphics.
 *
 * \author	Chaokel
 * \date	23/05/2013
 */

class Graphics abstract
{
public:

	/**
	 * \fn	virtual void abstract::Initialise() = 0;
	 *
	 * \brief	Initialises this object.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 */

	virtual void Initialise() = 0;

	/**
	 * \fn	virtual void abstract::Reshape(int width, int height) = 0;
	 *
	 * \brief	Reshapes.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param	width 	The width.
	 * \param	height	The height.
	 */

	virtual void Reshape(int width, int height) = 0;

	/**
	 * \fn	virtual void abstract::Display() = 0;
	 *
	 * \brief	Displays this object.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 */

	virtual void Display() = 0;

	/**
	 * \fn	virtual void abstract::Update() = 0;
	 *
	 * \brief	Updates this object.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 */

	virtual void Update() = 0;

	/**
	 * \fn	virtual void abstract::RenderModel(GameObject * GameObj) = 0;
	 *
	 * \brief	Renders the model described by GameObj.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param [in,out]	GameObj	If non-null, the game object.
	 */

	virtual void RenderModel(GameObject * GameObj) = 0;

	/**
	 * \fn	virtual void abstract::RenderTerrain(HeightMap* Terrain) = 0;
	 *
	 * \brief	Renders the terrain described by Terrain.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param [in,out]	Terrain	If non-null, the terrain.
	 */

	virtual void RenderTerrain(HeightMap* Terrain) = 0;

	/**
	 * \fn	virtual void abstract::Start() = 0;
	 *
	 * \brief	Starts this object.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 */

	virtual void Start() = 0;

	/**
	 * \fn	virtual void abstract::MoveCamera(bool Type, glm::vec3 Direction) = 0;
	 *
	 * \brief	Move camera.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param	Type	 	true to type.
	 * \param	Direction	The direction.
	 */

	virtual void MoveCamera(bool Type, glm::vec3 Direction) = 0;

	/**
	 * \fn	virtual void abstract::SetCam(glm::vec3 location) = 0;
	 *
	 * \brief	Sets a camera.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param	location	The location.
	 */

	virtual void SetCam(glm::vec3 location) = 0;

	/**
	 * \fn	virtual void abstract::SetLook(glm::vec3 look) = 0;
	 *
	 * \brief	Sets a camera look at.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param	look The look.
	 */

	virtual void SetLook(glm::vec3 look) = 0;

	/**
	 * \fn	virtual int abstract::GetGraphics() = 0;
	 *
	 * \brief	Gets the graphics.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \return	The graphics.
	 */

	virtual int GetGraphics() = 0;

protected:

private:

};