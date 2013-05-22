#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "HeightMap.h"

class Graphics abstract
{
public:

	virtual void Initialise() = 0;
	
	virtual void Reshape(int width, int height) = 0;

	virtual void Display() = 0;

	virtual void Update() = 0;

	virtual void RenderModel(GameObject * GameObj) = 0;

	virtual void RenderTerrain(HeightMap* Terrain) = 0;

	virtual void Start() = 0;
	
	virtual void MoveCamera(bool Type, glm::vec3 Direction) = 0;

	virtual void SetCam(glm::vec3 location) = 0;

	virtual void SetLook(glm::vec3 look) = 0;

	virtual int GetGraphics() = 0;

	//virtual void Idle() = 0; // Remove if not used.

	//virtual void FPSTimer() = 0; // Remove if not used.

protected:

private:

};