#pragma once
#include "stdafx.h"

class Shader
{
public:
	~Shader(void);

	/**
	 * \fn	void Shader::Initialise();
	 *
	 * \brief	Initialises this object.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	void Initialise();

	/**
	 * \fn	GLuint Shader::LoadShader(GLenum eShaderType, const std::string &sFilename);
	 *
	 * \brief	Loads a shader.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	eShaderType	Type of the shader.
	 * \param	sFilename  	Filename of the file.
	 *
	 * \return	The shader.
	 */

	GLuint LoadShader(GLenum eShaderType, const std::string &sFilename);

	/**
	 * \fn	std::string Shader::CheckFile(const std::string &sInitialName);
	 *
	 * \brief	Check file.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	sInitialName	Name of the initial.
	 *
	 * \return	string.
	 */

	std::string CheckFile(const std::string &sInitialName);

	/**
	 * \fn	std::vector<GLuint>* const Shader::GetvShaderList();
	 *
	 * \brief	Gets the shader list.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	shader handle pointer.
	 */

	std::vector<GLuint>* const GetvShaderList();

	/**
	 * \fn	static boost::scoped_ptr<Shader>* Shader::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<Shader>* GetInstance();
protected:

private:

	/**
	 * \brief	List of shaders.
	 */

	std::vector<GLuint> vShaderList;

	/**
	 * \brief	The singleton.
	 */

	static boost::scoped_ptr<Shader> pSingleton;

	Shader(void);
	
};

