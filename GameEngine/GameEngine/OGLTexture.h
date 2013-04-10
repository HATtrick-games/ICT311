/**
 * \file	OGLTexture.h
 *
 * \brief	Declares the ogl texture class.
 */

#pragma once
// #include <GL\glew.h> 
#include "Texture.h"
#include <vector>
#include <glload\gl_3_3.h>
#include <GL\freeglut.h>
#include <glm\glm.hpp>
#include <boost\scoped_ptr.hpp>

/**
 * \class	OGLTexture
 *
 * \brief	Ogl texture.
 *
 * \author	Hamish Carrier
 * \date	4/10/2013
 */

class OGLTexture
{
public:
	OGLTexture();

	/**
	 * \fn	OGLTexture::~OGLTexture()
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	~OGLTexture(){};

	/**
	 * \fn	bool OGLTexture::BindTexture(Texture * pixelBuffer, int index);
	 *
	 * \brief	Bind texture.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param [in,out]	pixelBuffer	If non-null, buffer for pixel data.
	 * \param	index			   	Zero-based index of the.
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool BindTexture(Texture * pixelBuffer, int index);

	/**
	 * \fn	GLuint* OGLTexture::CreateTexCoordBuffer(std::vector<glm::vec2>*, int size);
	 *
	 * \brief	Creates tex coordinate buffer.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param [in,out]	parameter1	If non-null, the first parameter.
	 * \param	size			  	The size.
	 *
	 * \return	null if it fails, else the new tex coordinate buffer.
	 */

	GLuint* CreateTexCoordBuffer(std::vector<glm::vec2>*, int size);

	/**
	 * \fn	GLuint OGLTexture::GetTexHandle(int index);
	 *
	 * \brief	Gets tex handle.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	index	Zero-based index of the.
	 *
	 * \return	The tex handle.
	 */

	GLuint GetTexHandle(int index);

	/**
	 * \fn	static boost::scoped_ptr<OGLTexture>* OGLTexture::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<OGLTexture>* GetInstance();
private:

	/**
	 * \brief	Handle of the texture.
	 */

	std::vector<GLuint> TextureHandle;

	/**
	 * \brief	Buffer for tex data.
	 */

	GLuint TexBuffer;

	/**
	 * \brief	The tex singleton.
	 */

	static boost::scoped_ptr<OGLTexture> pTexSingleton;

/**
 * \property	}
 *
 * \brief	Gets or sets the. 
 *
 * \value	.
 */

};




















/*

#include "Texture.h"
#include <GL/glew.h>

typedef enum MinMagFilter
{
	MINMAG_LINEAR = GL_LINEAR,
	MINMAG_NEAREST = GL_NEAREST
};

typedef enum WrapMode
{
	WRAP_REPEAT = GL_REPEAT,
	WRAP_MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
	WRAP_CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
	WRAP_CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER,
};

class OGLTexture
{
public:
	OGLTexture(Texture& tex, MinMagFilter mmFilter = MINMAG_LINEAR, WrapMode wrap =  WRAP_CLAMP_TO_EDGE);

	~OGLTexture(void);

	GLuint SetActive();

	void UnbindAll();
private:
	Texture* texture;

	GLuint iObject;
	GLfloat fWidth;
	GLfloat fHeight;

	// Copying disabled
	OGLTexture(const OGLTexture&);
	const OGLTexture& operator=(const OGLTexture&);
};*/
