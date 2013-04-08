#include "OGLTexture.h"

OGLTexture::OGLTexture(Texture& tex, MinMagFilter mmFilter /* = MINMAG_LINEAR */, WrapMode wrap /* = WRAP_CLAMP_TO_EDGE */)

{
	texture = &tex;

	fWidth = (float)texture->GetWidth();
	fHeight = (float)texture->GetHeight();

	glGenTextures(1, &iObject);
	glBindTexture(GL_TEXTURE_2D, iObject);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mmFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mmFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, fWidth, fHeight, 0, GL_RGB,
		GL_UNSIGNED_BYTE, texture->GetData());
	glBindTexture(GL_TEXTURE_2D, 0);
}


OGLTexture::~OGLTexture(void)
{
	glDeleteTextures(1, &iObject);
}

GLuint OGLTexture::SetActive()
{
	GLuint id = GL_TEXTURE0 + texture->GetIdentifier();
	glActiveTexture(id);
	glBindTexture(GL_TEXTURE_2D, iObject);

	return id;
}

void OGLTexture::UnbindAll()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}