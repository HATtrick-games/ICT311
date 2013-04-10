/**
 * \file	Graphics.h
 *
 * \brief	Declares the graphics class.
 */

#pragma once

#include <string>

#include "Mesh.h"
#include "Terrain.h"
#include "GameObject.h"

/**
 * \class	Graphics
 *
 * \brief	Graphics.
 *
 * \author	Hamish Carrier
 * \date	4/10/2013
 */

class Graphics abstract
{
public:

	virtual void Init() = 0;

	/**
	 * \fn	virtual void abstract::RenderModel(Mesh * MeshObj, GameObject * GameObj, int Index) = 0;
	 *
	 * \brief	Renders the model.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param [in,out]	MeshObj	If non-null, the mesh object.
	 * \param [in,out]	GameObj	If non-null, the game object.
	 * \param	Index		   	Zero-based index of the.
	 */

	virtual void RenderModel(Mesh * MeshObj, GameObject * GameObj, int Index) = 0;

	/**
	 * \fn	virtual void abstract::RenderTerrain(Terrain * TerrainObj) = 0;
	 *
	 * \brief	Renders the terrain described by TerrainObj.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param [in,out]	TerrainObj	If non-null, the terrain object.
	 */

	virtual void RenderTerrain(Terrain * TerrainObj) = 0;

	/**
	 * \fn	virtual void abstract::Reshape(int width, int height) = 0;
	 *
	 * \brief	Reshapes.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
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
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	virtual void Display() = 0;

	/**
	 * \fn	virtual void abstract::DisplayTimer(int value) = 0;
	 *
	 * \brief	Displays a timer described by value.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	value	The value.
	 */

	virtual void DisplayTimer(int value) = 0;
private:

};
