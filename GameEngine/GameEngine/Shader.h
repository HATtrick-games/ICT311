/**
 * \file	Shader.h
 *
 * \brief	Declares the shader class.
 */

#pragma once

#include <glload/gl_3_3.h>
//#include <GL\glew.h>
#include <glutil/Shader.h>
#include <GL\freeglut.h>

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "boost\smart_ptr.hpp"
#include "CommonFuncs.h"

/**
 * \class	Shader
 *
 * \brief	Shader.
 *
 * \author	Hamish Carrier
 * \date	4/10/2013
 */

class Shader
{
public:	

	/**
	 * \fn	Shader::~Shader(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	~Shader(void);

	/**
	 * \fn	static boost::scoped_ptr<Shader>* Shader::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<Shader>* GetInstance();

	/**
	 * \fn	void Shader::Initialise();
	 *
	 * \brief	Initialises this object.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	void Initialise();

	/**
	 * \fn	GLuint Shader::LoadShader(GLenum eShaderType, const std::string &sFilename);
	 *
	 * \brief	Loads a shader.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	eShaderType	Type of the shader.
	 * \param	sFilename  	Filename of the file.
	 *
	 * \return	The shader.
	 */

	GLuint LoadShader(GLenum eShaderType, const std::string &sFilename);

	/**
	 * \fn	std::vector<GLuint> * const Shader::GetvShaderList()
	 *
	 * \brief	Gets the getv shader list.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	.
	 */

	std::vector<GLuint> * const GetvShaderList() {return &vShaderList;}

private:

	/**
	 * \fn	Shader::Shader(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	Shader(void);

	/**
	 * \fn	Shader& Shader::operator= (const Shader&);
	 *
	 * \brief	Assignment operator.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	parameter1	The first parameter.
	 *
	 * \return	A shallow copy of this object.
	 */

	Shader& operator= (const Shader&);

	/**
	 * \fn	Shader::Shader(const Shader&);
	 *
	 * \brief	Copy constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	parameter1	The first parameter.
	 */

	Shader(const Shader&);

	/**
	 * \brief	List of shaders.
	 */

	std::vector<GLuint> vShaderList;

	/**
	 * \brief	The shader singleton.
	 */

	static boost::scoped_ptr<Shader> pShaderSingleton;
};

