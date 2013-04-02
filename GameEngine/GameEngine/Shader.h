#pragma once

#include <glload/gl_3_3.h>
#include <glutil/Shader.h>
#include <GL\freeglut.h>

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "boost\smart_ptr.hpp"
#include "CommonFuncs.h"


class Shader
{
public:	
	~Shader(void);

	static boost::scoped_ptr<Shader>* GetInstance();

	void Initialise();
	GLuint LoadShader(GLenum eShaderType, const std::string &sFilename);

	std::vector<GLuint> * GetvShaderList() {return &vShaderList;}

private:

	Shader(void);
	Shader& operator= (const Shader&);
	Shader(const Shader&);

	std::vector<GLuint> vShaderList;

	static boost::scoped_ptr<Shader> pShaderSingleton;
};

