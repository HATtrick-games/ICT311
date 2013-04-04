#pragma once

#include "IAsset.h"
#include "Texture.h"
#include <iostream>
#include <glm/glm.hpp>

class Terrain :
	public IAsset
{
public:
	Terrain(void);
	~Terrain(void);

	virtual void Load();

	unsigned int GetWidth();
	unsigned int GetLength();

	float GetHeight(int x, int z);
	glm::vec3 GetNormal(int x, int z);

	void ComputeNormals();
private:
	unsigned int iWidth, iLength;
	float** pHeights;
	glm::vec3** vNormals;
	bool bNormalsComputed;

	float fScale;

	void SetHeight(int x, int z, float h);
};

