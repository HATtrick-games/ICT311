#include "OGLTexture.h"

boost::scoped_ptr<OGLTexture> OGLTexture::pTexSingleton(NULL);

OGLTexture::OGLTexture()
{

}


bool OGLTexture::BindTexture(Texture * TextureObj, int index)
{
	TextureHandle.push_back(0);
	glGenTextures(1, &TextureHandle[index]);
	glBindTexture(GL_TEXTURE_2D, TextureHandle[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	std::cout << TextureObj->GetWidth() << " | " << TextureObj->GetHeight() << " | " << TextureObj->GetData();

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TextureObj->GetWidth(), TextureObj->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, TextureObj->GetData());
	glBindTexture(GL_TEXTURE_2D, 0 );

	return true;
}

GLuint* OGLTexture::CreateTexCoordBuffer(std::vector<glm::vec2>* texCoords, int size)
{
	glGenBuffers(1, &TexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, TexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*2*size, &(*texCoords)[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	return &TexBuffer;
}

GLuint OGLTexture::GetTexHandle(int index)
{
	return TextureHandle[index];
}


boost::scoped_ptr<OGLTexture>* OGLTexture::GetInstance()
{
	if(pTexSingleton.get() == NULL)
	{
		pTexSingleton.reset(new OGLTexture);
	}
	return &pTexSingleton;
}
















//OGLTexture::OGLTexture(Texture& tex, MinMagFilter mmFilter /* = MINMAG_LINEAR */, WrapMode wrap /* = WRAP_CLAMP_TO_EDGE */)

/*
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
*/