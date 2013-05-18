#pragma once
#include "stdafx.h"
#include "TextureLoader.h"

class HeightMap
{
public:
	HeightMap(void);
	~HeightMap(void);

	void Load(std::string filename);
	void ComputeFloats();
	void SetHeight(int x, int z, float h);

	float * GetMap();
	int GetNumberHeights();
private:
	float** pHeights;
	float* Map;
	glm::vec3** vNormals;

	int h;
	int w;

	int NumberHeights;
};

