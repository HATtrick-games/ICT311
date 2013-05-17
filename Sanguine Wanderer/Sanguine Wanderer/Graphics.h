#pragma once

#include "stdafx.h"
#include "Mesh.h"

class Graphics abstract
{
public:

	virtual void Initialise() = 0;
	
	virtual void Reshape(int width, int height) = 0;

	virtual void Display() = 0;

	virtual void RenderModel(int Index, Mesh * MeshObj) = 0;

	virtual void RenderTerrain() = 0;

	virtual void Start() = 0;
	
	virtual void MoveCamera(bool Type, glm::vec3 Direction) = 0;

	//virtual void Idle() = 0; // Remove if not used.

	//virtual void FPSTimer() = 0; // Remove if not used.

protected:

private:

};