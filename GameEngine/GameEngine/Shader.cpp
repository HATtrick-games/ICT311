#include "Shader.h"

boost::scoped_ptr<Shader> Shader::pShaderSingleton(NULL);

Shader::Shader(void)
{
}


Shader::~Shader(void)
{
}

GLuint Shader::LoadShader(GLenum eShaderType, const std::string &Filename)
{
	return 1;
}

boost::scoped_ptr<Shader>* Shader::GetInstance()
{
	if(pShaderSingleton.get() == NULL)
	{
		pShaderSingleton.reset(new Shader);
	}
	return &pShaderSingleton;
}