#pragma once

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
};