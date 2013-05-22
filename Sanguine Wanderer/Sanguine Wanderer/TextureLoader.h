/**
 * \file	TextureLoader.h
 *
 * \brief	Declares the texture loader class.
 */

#pragma once
#include "stdafx.h"

/**
 * \class	TextureLoader
 *
 * \brief	Texture loader.
 *
 * \author	Chaokel
 * \date	22/05/2013
 */

class TextureLoader
{
public:
	TextureLoader(void);
	~TextureLoader(void);

	/**
	 * \fn	void TextureLoader::Load(std::string Path, int Index);
	 *
	 * \brief	Loads the given file.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	Path 	Full pathname of the file.
	 * \param	Index	Zero-based index of the current mesh.
	 */

	void Load(std::string Path, int Index);

	/**
	 * \fn	bool TextureLoader::loadBitmap(string filename, FIBITMAP* &bitmap);
	 *
	 * \brief	Loads a bitmap.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	filename	  	Filename of the file.
	 * \param [in,out]	bitmap	[in,out] If non-null, the bitmap.
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool loadBitmap(string filename, FIBITMAP* &bitmap);

	/**
	 * \fn	GLuint TextureLoader::GetTexHandle(int index);
	 *
	 * \brief	Gets tex handle.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	index	Zero-based index of the texture handles.
	 *
	 * \return	The tex handle.
	 */

	GLuint GetTexHandle(int index);

	/**
	 * \fn	GLuint TextureLoader::GetTexBuffer(int index);
	 *
	 * \brief	Gets tex buffer.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	index	Zero-based index of the buffers.
	 *
	 * \return	The tex buffer.
	 */

	GLuint GetTexBuffer(int index);

	/**
	 * \fn	GLuint TextureLoader::GetTextureSampler(int index);
	 *
	 * \brief	Gets texture sampler.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	index	Zero-based index of the samplers.
	 *
	 * \return	The texture sampler.
	 */

	GLuint GetTextureSampler(int index);

	/**
	 * \fn	void TextureLoader::FreeBuffer(int index);
	 *
	 * \brief	Free buffer.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	index	Zero-based index of the buffer.
	 */

	void FreeBuffer(int index);

	/**
	 * \fn	static boost::scoped_ptr<TextureLoader>* TextureLoader::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<TextureLoader>* TextureLoader::GetInstance();

	/**
	 * \fn	void TextureLoader::CreateTexCoordBuffer(float* texCoords, int size, int index);
	 *
	 * \brief	Creates tex coordinate buffer.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param [in,out]	texCoords	If non-null, the tex coords.
	 * \param	size			 	The size.
	 * \param	index			 	Index of texture being created.
	 */

	void TextureLoader::CreateTexCoordBuffer(float* texCoords, int size, int index);
private:

	/**
	 * \brief	Handle to Buffer for tex data.
	 */

	std::vector<GLuint> TexBuffer;

	/**
	 * \brief	Handle of the textures.
	 */

	std::vector<GLuint> TextureHandle;

	/**
	 * \brief	The texture sampler.
	 */

	std::vector<GLuint> TextureSampler;

	/**
	 * \brief	The singleton.
	 */

	static boost::scoped_ptr<TextureLoader> pSingleton;
};

