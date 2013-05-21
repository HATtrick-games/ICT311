#pragma once
#include "stdafx.h"
#include "IAsset.h"
#include "CommonFunctions.h"

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
	float GetMaxX();
	float GetMaxY();
	float GetMaxZ();
	float GetMinX();
	float GetMinY();
	float GetMinZ();

	std::string GetTexPath();

	~Mesh(void);
private:
	float * VertexArray;
	float * NormalArray;
	float * UVArray;

	int numTriangles;
	int numVert;
	int numTextures;

	float MaxX;
	float MaxY;
	float MaxZ;
	float MinX;
	float MinY;
	float MinZ;

	std::string TexPath;
};

