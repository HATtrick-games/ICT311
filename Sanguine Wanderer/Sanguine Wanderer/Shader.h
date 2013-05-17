#pragma once
#include "stdafx.h"

class Shader
{
public:
	~Shader(void);

	void Initialise();

	GLuint LoadShader(GLenum eShaderType, const std::string &sFilename);
	std::string CheckFile(const std::string &sInitialName);
	std::vector<GLuint>* const GetvShaderList();
	static boost::scoped_ptr<Shader>* GetInstance();
protected:

private:
	std::vector<GLuint> vShaderList;
	static boost::scoped_ptr<Shader> pSingleton;

	Shader(void);
	
};

