#pragma once
#include "stdafx.h"
#include "TextureLoader.h"

class HeightMap
{
public:
	HeightMap(void);
	~HeightMap(void);

	void Load(std::string filename);
	void SetHeight(int x, int z, float h);

	float * GetMap();
	float * GetUVW();
	int GetNumberHeights();
	int GetNumberTex();
private:
	float** pHeights;
	float* Map;
	glm::vec3** vNormals;
	float * Heights;
	float * UVW;
	int NumberTex;

	int h;
	int w;

	int NumberHeights;
};

