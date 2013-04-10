#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <assert.h>
#include "IAsset.h"

/**
 * \class	Texture
 *
 * \brief	Sets up a 24 bit BMP Texture.
 * 
 * \author	Timothy Veletta, Hamish Carrier
 */

class Texture:
	public IAsset
{
public:

	/**
	 * \fn	Texture::Texture(void);
	 *
	 * \brief	Default constructor.
	 */
	Texture(void);

	/**
	 * \fn	Texture::~Texture(void);
	 *
	 * \brief	Destructor.
	 */
	~Texture(void);

	/**
	 * \fn	virtual void Texture::Load();
	 *
	 * \brief	Loads this object.
	 */
	virtual void Load();

	/**
	 * \fn	unsigned int Texture::GetDataPos();
	 *
	 * \brief	Gets data position.
	 *
	 * \return	The data position.
	 */
	unsigned int GetDataPos();

	/**
	 * \fn	unsigned int Texture::GetWidth();
	 *
	 * \brief	Gets the width.
	 *
	 * \return	The width.
	 */
	unsigned int GetWidth();

	/**
	 * \fn	unsigned int Texture::GetHeight();
	 *
	 * \brief	Gets the height.
	 *
	 * \return	The height.
	 */
	unsigned int GetHeight();

	/**
	 * \fn	unsigned int Texture::GetImageSize();
	 *
	 * \brief	Gets image size.
	 *
	 * \return	The image size.
	 */
	unsigned int GetImageSize();

	/**
	 * \fn	std::vector<char> Texture::GetData() const;
	 *
	 * \brief	Gets the data.
	 *
	 * \return	The data.
	 */
	std::vector<char> GetData() const;

	/**
	 * \fn	std::vector<char>* Texture::GetAddress();
	 *
	 * \brief	Gets the address.
	 *
	 * \return	null if it fails, else the address.
	 */
	std::vector<char>* GetAddress();
private:
	// Data read from the header
	unsigned int iDataPos;  //!< Zero-based index of the data position
	unsigned int iWidth;	//!< Zero-based index of the width
	unsigned int iHeight;   //!< Zero-based index of the height
	unsigned int iImageSize;	//!< Size of the image
	// RGB Data
	std::vector<char> cData;	//!< The data

	int readInt(std::ifstream& input);
	short readShort(std::ifstream& input);
};

