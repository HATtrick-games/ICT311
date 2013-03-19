#include "Shader.h"

boost::scoped_ptr<Shader> Shader::pShaderSingleton(NULL);

Shader::Shader(void)
{
}


Shader::~Shader(void)
{
}

void Shader::Initialise()
{
	vShaderList.push_back(LoadShader(GL_VERTEX_SHADER, "BasicShader.vert")); // change later to specify shader location through ini or script?
	vShaderList.push_back(LoadShader(GL_FRAGMENT_SHADER, "BasicShader.frag")); // ^^^^^
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