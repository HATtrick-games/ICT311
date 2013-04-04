#pragma once

#include <map>
#include <string>
#include "IAsset.h"
#include "GameAssetFactory.h"

using namespace std;

/**
 * \class	AssetManager
 *
 * \brief	Manager for assets.
 */

class AssetManager
{
public:

	/**
	 * \fn	AssetManager::AssetManager(void);
	 *
	 * \brief	Default constructor.
	 */
	AssetManager(void);

	/**
	 * \fn	AssetManager::~AssetManager(void);
	 *
	 * \brief	Destructor.
	 */
	~AssetManager(void);

	/**
	 * \fn	bool AssetManager::AddAsset(string filename, string type);
	 *
	 * \brief	Adds an asset to 'type'.
	 *
	 * \param	filename	Filename of the file.
	 * \param	type		The type.
	 *
	 * \return	true if it succeeds, false if it fails.
	 */
	bool AddAsset(string filename, string type);

	/**
	 * \fn	IAsset* AssetManager::GetAsset(string filename);
	 *
	 * \brief	Gets an asset.
	 *
	 * \param	filename	Filename of the file.
	 *
	 * \return	null if it fails, else the asset.
	 */
	IAsset* GetAsset(string filename);

	/**
	 * \fn	bool AssetManager::RemoveAsset(string filename);
	 *
	 * \brief	Removes the asset described by filename.
	 *
	 * \param	filename	Filename of the file.
	 *
	 * \return	true if it succeeds, false if it fails.
	 */
	void RemoveAsset(string filename);

	/**
	 * \fn	bool AssetManager::RemoveAllAssets();
	 *
	 * \brief	Removes all assets.
	 *
	 * \return	true if it succeeds, false if it fails.
	 */
	bool RemoveAllAssets();
private:
	map<string, IAsset*> mGameAssets;   //!< The game assets
};

