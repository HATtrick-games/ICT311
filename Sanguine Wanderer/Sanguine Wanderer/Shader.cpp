#include "StdAfx.h"
#include "Shader.h"
boost::scoped_ptr<Shader> Shader::pSingleton(NULL);

Shader::Shader(void)
{
}

void Shader::Initialise()
{
	vShaderList.push_back(LoadShader(GL_VERTEX_SHADER, "BasicShader.vert")); // change later to specify shader location through ini or script?
	vShaderList.push_back(LoadShader(GL_FRAGMENT_SHADER, "BasicShader.frag")); // ^^^^^
}

GLuint Shader::LoadShader(GLenum eShaderType, const std::string &sFilename)
{
	std::string sUsableFilename = CheckFile(sFilename);
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

std::string Shader::CheckFile(const std::string &sInitialName)
{
	//This block of code can be duplicated to check multiple file locations, either sequentially or with the input of the location to check.
	std::string sFileName = "data\\" + sInitialName;
	std::ifstream testFile(sFileName.c_str());
	if(testFile.is_open())
	{
		return sFileName;
	}
	// if nothing returned, file unable to be opened throw error
	throw std::runtime_error("File: " + sInitialName +  " not found.");
};

std::vector<GLuint>* const Shader::GetvShaderList()
{
	return &vShaderList;
}

Shader::~Shader(void)
{
}

boost::scoped_ptr<Shader>* Shader::GetInstance()
{
	if(pSingleton.get() == NULL)
	{
		pSingleton.reset(new Shader);
	}
	return &pSingleton;
}