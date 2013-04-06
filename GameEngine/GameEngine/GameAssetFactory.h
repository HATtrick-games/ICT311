#pragma once

#include <string>
#include "IAsset.h"
#include "Texture.h"
#include "Mesh.h"
#include "Terrain.h"

class GameAssetFactory
{
public:
	static IAsset* Create(std::string type);
};

