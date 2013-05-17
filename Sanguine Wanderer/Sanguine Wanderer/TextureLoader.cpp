#include "StdAfx.h"
#include "TextureLoader.h"

boost::scoped_ptr<TextureLoader> TextureLoader::pSingleton(NULL);

TextureLoader::TextureLoader(void)
{
}

void TextureLoader::Load(std::string Path, int index)
{
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP* dib(0);

	fif = FreeImage_GetFileType(Path.c_str(), 0); // Check the file signature and deduce its format

	if(fif == FIF_UNKNOWN) // If still unknown, try to guess the file format from the file extension
		fif = FreeImage_GetFIFFromFilename(Path.c_str());
	
	if(fif == FIF_UNKNOWN) // If still unkown, return failure
		std::cout << "Error 1";

	if(FreeImage_FIFSupportsReading(fif)) // Check if the plugin has reading capabilities and load the file
		dib = FreeImage_Load(fif, Path.c_str());
	if(!dib)
		std::cout << "Error 2";

	BYTE* bDataPointer = FreeImage_GetBits(dib); // Retrieve the image data
	
	unsigned int iWidth = FreeImage_GetWidth(dib); // Get the image width and height
	unsigned int iHeight = FreeImage_GetHeight(dib);
	unsigned int iBPP = FreeImage_GetBPP(dib);

	// If somehow one of these failed (they shouldn't), return failure
	if(bDataPointer == NULL || iWidth == 0 || iHeight == 0)
		std::cout << "Error 3";

	TextureHandle.push_back(0);
	TextureSampler.push_back(0);
	/*
	// Generate an OpenGL texture ID for this texture
	glGenTextures(1, &TextureHandle[index]);
	glBindTexture(GL_TEXTURE_2D, TextureHandle[index]);
	
	//int iFormat = iBPP == 24 ? GL_BGR : iBPP == 8 ? GL_LUMINANCE : 0;
	int iInternalFormat = iBPP == 24 ? GL_RGB : GL_DEPTH_COMPONENT; 

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iWidth, iHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, bDataPointer);

	glGenerateMipmap(GL_TEXTURE_2D);

	FreeImage_Unload(dib);

	glGenSamplers(1, &TextureSampler[index]);
	*/
	glGenTextures(1, &TextureHandle[index]);
	glBindTexture(GL_TEXTURE_2D, TextureHandle[index]); // Bind the ID texture specified by the 2nd parameter

    // The next commands sets the texture parameters
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // If the u,v coordinates overflow the range 0,1 the image is repeated
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // The magnification function ("linear" produces better results)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); //The minifying function


    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); // We don't combine the color with the original surface color, use only the texture map.

	//error = glGetError();

    // Finally we define the 2d texture
    //glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iWidth, iHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, bDataPointer);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 4);

    // And create 2d mipmaps for the minifying function
    //gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
	glGenerateMipmap(GL_TEXTURE_2D);
}

GLuint TextureLoader::GetTexHandle(int index)
{
	return TextureHandle[index];
}

GLuint TextureLoader::GetTexBuffer(int index)
{
	return TexBuffer[index];
}

GLuint TextureLoader::GetTextureSampler(int index)
{
	return TextureSampler[index];
}

boost::scoped_ptr<TextureLoader>* TextureLoader::GetInstance()
{
	if(pSingleton.get() == NULL)
	{
		pSingleton.reset(new TextureLoader);
	}
	return &pSingleton;
}

void TextureLoader::CreateTexCoordBuffer(float* texCoords, int size, int index)
{
	TexBuffer.push_back(0);
	glGenBuffers(1, &TexBuffer[index]);
	glBindBuffer(GL_ARRAY_BUFFER, TexBuffer[index]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*size, texCoords, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

TextureLoader::~TextureLoader(void)
{
}
