#pragma once

#include <GL\freeglut.h>
#include <string>
#include "boost\smart_ptr.hpp"

class Shader
{
public:
	Shader(void);
	~Shader(void);

	static boost::scoped_ptr<Shader>* GetInstance();

	GLuint LoadShader(GLenum eShaderType, const std::string &Filename);

private:

	static boost::scoped_ptr<Shader> pShaderSingleton;
};

