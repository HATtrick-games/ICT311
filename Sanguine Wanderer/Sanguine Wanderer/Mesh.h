#pragma once
#include "stdafx.h"
#include "IAsset.h"

class Mesh : public IAsset
{
public:

	Mesh(void);

	void Load();
	void InitMesh(const aiScene* pScene, const std::string& sFilepath);

	int GetNumTextures();
	int GetNumVert();


	float * GetVertexArray();
	float * GetUVArray();

	std::string GetTexPath();

	~Mesh(void);
private:
	float * VertexArray;
	float * NormalArray;
	float * UVArray;

	int numTriangles;
	int numVert;
	int numTextures;

	std::string TexPath;
};

