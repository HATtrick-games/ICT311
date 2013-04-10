#pragma once

#include <string>
#include "IAsset.h"
#include "Texture.h"
#include "Mesh.h"
#include "Terrain.h"

/**
 * \class	GameAssetFactory
 *
 * \brief	Game asset factory for creating game assets.
 */
class GameAssetFactory
{
public:

	/**
	 * \fn	static IAsset* GameAssetFactory::Create(std::string type);
	 *
	 * \brief	Creates this object.
	 *
	 * \param	type	The type.
	 *
	 * \return	null if it fails, else.
	 */
	static IAsset* Create(std::string type);
};

