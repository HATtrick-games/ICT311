#pragma once

#include <glload/gl_3_3.h>
#include <GL\freeglut.h>
#include <string>
#include "boost\smart_ptr.hpp"
#include <vector>

class Shader
{
public:	
	~Shader(void);

	static boost::scoped_ptr<Shader>* GetInstance();

	void Initialise();
	GLuint LoadShader(GLenum eShaderType, const std::string &Filename);

	const std::vector<GLuint> * GetvShaderList() {return &vShaderList;}

private:

	Shader(void);
	Shader& operator= (const Shader&);
	Shader(const Shader&);

	std::vector<GLuint> vShaderList;

	static boost::scoped_ptr<Shader> pShaderSingleton;
};

