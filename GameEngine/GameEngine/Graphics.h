#pragma once

#include <string>

#include "Mesh.h"
#include "Terrain.h"
#include "GameObject.h"

class Graphics abstract
{
public:

	virtual void Init() = 0;
	virtual void RenderModel(Mesh * MeshObj, GameObject * GameObj, int Index) = 0;
	virtual void RenderTerrain(Terrain * TerrainObj) = 0;
	virtual void Reshape(int width, int height) = 0;
	virtual void Display() = 0;
	virtual void DisplayTimer(int value) = 0;

private:

};
