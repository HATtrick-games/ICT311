#pragma once

#include <string>

/**
 * \class	IAsset
 *
 * \brief	Used to represent assets.
 * \author	Timothy Veletta
 */
class IAsset
{
public:

	/**
	 * \fn	IAsset::IAsset();
	 *
	 * \brief	Default constructor.
	 */
	IAsset();

	/**
	 * \fn	void IAsset::SetFile(std::string file);
	 *
	 * \brief	Sets the asset file.
	 *
	 * \param	file	The file.
	 */
	void SetFile(std::string file);

	/**
	 * \fn	std::string IAsset::GetFile();
	 *
	 * \brief	Gets the file.
	 *
	 * \return	The file.
	 */
	std::string GetFile();

	/**
	 * \fn	int IAsset::GetIdentifier();
	 *
	 * \brief	Gets the identifier.
	 *
	 * \return	The identifier.
	 */
	int GetIdentifier();

	/**
	 * \fn	virtual void IAsset::Load() = 0;
	 *
	 * \brief	Loads this object.
	 */
	virtual void Load() = 0;
protected:
	std::string sFilepath;  //!< The filepath
	int iIdentifier;	//!< Zero-based index of the identifier
private:
	static int iCounter;	//!< Zero-based index of the counter
};

