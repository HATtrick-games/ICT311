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

GLuint Shader::LoadShader(GLenum eShaderType, const std::string &sFilename)
{
	std::string sUsableFilename = CommonFunctions::CheckFile(sFilename);
	std::cout << sUsableFilename;
	std::ifstream openFile(sUsableFilename.c_str());
	std::stringstream shaderData;
	shaderData << openFile.rdbuf();
	openFile.close();

	//can probably remove this try catch block, was just used for debugging a specific issue. Overall use seems very limited.
		try
		{
			return glutil::CompileShader(eShaderType, shaderData.str());
		}
		catch(std::exception &e)
		{
			fprintf(stderr, "%s\n", e.what());
			throw;
		}
		
}

boost::scoped_ptr<Shader>* Shader::GetInstance()
{
	if(pShaderSingleton.get() == NULL)
	{
		pShaderSingleton.reset(new Shader);
	}
	return &pShaderSingleton;
}