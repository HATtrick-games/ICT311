/**
 * \file	OpenGL.h
 *
 * \brief	Declares the open gl class.
 */

#pragma once

#include "OGLTexture.h"
#include "Graphics.h"
#include "Shader.h"
#include "Camera.h"
#include "Game.h"
#include "AngleMath.h"
#include "GameSettings.h"
#include <GL\freeglut.h>
#include <glload\gll.hpp>
#include <glutil\glutil.h>
#include <boost\smart_ptr.hpp>

#include <vector>
#include <iostream>

/**
 * \class	OpenGL
 *
 * \brief	Open gl.
 *
 * \author	Hamish Carrier
 * \date	4/10/2013
 */

class OpenGL :public Graphics
{
public:

	/**
	 * \fn	static boost::scoped_ptr<Graphics> * OpenGL::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<Graphics> * GetInstance();

	/**
	 * \fn	OpenGL::~OpenGL(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	~OpenGL(void);

	//Virtual functions
	void Init(); // Used to intialise freeglut and call setup for the opengl context and window.

	/**
	 * \fn	void OpenGL::RenderModel(Mesh * MeshObj, GameObject * GameObj, int Index);
	 *
	 * \brief	Renders the model.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param [in,out]	MeshObj	If non-null, the mesh object.
	 * \param [in,out]	GameObj	If non-null, the game object.
	 * \param	Index		   	Zero-based index of the.
	 */

	void RenderModel(Mesh * MeshObj, GameObject * GameObj, int Index);

	/**
	 * \fn	void OpenGL::RenderTerrain(Terrain * TerrainObj);
	 *
	 * \brief	Renders the terrain described by TerrainObj.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param [in,out]	TerrainObj	If non-null, the terrain object.
	 */

	void RenderTerrain(Terrain * TerrainObj);

	/**
	 * \fn	void OpenGL::Reshape(int width, int height);
	 *
	 * \brief	Reshapes.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	width 	The width.
	 * \param	height	The height.
	 */

	void Reshape(int width, int height);

	/**
	 * \fn	void OpenGL::Display();
	 *
	 * \brief	Displays this object.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	void Display();

	/**
	 * \fn	void OpenGL::DisplayTimer(int value);
	 *
	 * \brief	Displays a timer described by value.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	value	The value.
	 */

	void DisplayTimer(int value);

	//OpenGL specific functions
	void SetupProgram();

	/**
	 * \fn	GLuint OpenGL::CreateProgramObject(const std::vector<GLuint>* shaderList);
	 *
	 * \brief	Creates program object.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	shaderList	List of shaders.
	 *
	 * \return	The new program object.
	 */

	GLuint CreateProgramObject(const std::vector<GLuint>* shaderList);

	/**
	 * \fn	glm::mat4 OpenGL::CreateModelTransformMatrix(glm::vec3 Position, glm::vec3 Scale,
	 * 		glm::vec3 Orientation);
	 *
	 * \brief	Creates model transform matrix.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	Position   	The position.
	 * \param	Scale	   	The scale.
	 * \param	Orientation	The orientation.
	 *
	 * \return	The new model transform matrix.
	 */

	glm::mat4 CreateModelTransformMatrix(glm::vec3 Position, glm::vec3 Scale, glm::vec3 Orientation);

	/**
	 * \fn	void OpenGL::InitialiseVAO();
	 *
	 * \brief	Initialises the vao.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	void InitialiseVAO();
	
private:

	/**
	 * \fn	OpenGL::OpenGL(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	OpenGL(void); // Used to intialise and setup anything required before freeglut sets up the window

	/**
	 * \fn	OpenGL& OpenGL::operator= (const OpenGL&);
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

	OpenGL& operator= (const OpenGL&);

	/**
	 * \fn	OpenGL::OpenGL(const OpenGL&);
	 *
	 * \brief	Copy constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	parameter1	The first parameter.
	 */

	OpenGL(const OpenGL&);

	/**
	 * \brief	Zero-based index of the display mode.
	 */

	unsigned int iDisplayMode;

	/**
	 * \brief	Zero-based index of the main window.
	 */

	int iMainWindow;

	/**
	 * \brief	The prog object.
	 */

	GLuint ProgObj;

	/**
	 * \brief	The vertex buffer object.
	 */

	std::vector<GLuint> VertexBufferObject;

	/**
	 * \brief	The index buffer object.
	 */

	std::vector<GLuint> IndexBufferObject;

	/**
	 * \brief	The vao.
	 */

	std::vector<GLuint> Vao;

	/**
	 * \brief	The terrain buffer object.
	 */

	GLuint TerrainBufferObject;

	/**
	 * \brief	(uniform) offset to be passed and used in the vertex shader.
	 */

	GLuint UniModelToCameraMatrix;

	/**
	 * \brief	The uni perspective matrix.
	 */

	GLuint UniPerspectiveMatrix;

	/**
	 * \brief	The uni base texture.
	 */

	GLuint UniBaseTexture;

	/**
	 * \brief	singleton stuff.
	 */

	static boost::scoped_ptr<Graphics> pOpenGLsingleton;

	/**
	 * \brief	The initialise.
	 */

	boost::scoped_ptr<GameSettings>* Ini;

	/**
	 * \fn	static void OpenGL::ReshapeCallback(int width, int height)
	 *
	 * \brief	Callback, called when the reshape.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	width 	The width.
	 * \param	height	The height.
	 */

	static void ReshapeCallback(int width, int height)
	{
		pOpenGLsingleton->Reshape(width, height);
	}	

	/**
	 * \fn	static void OpenGL::DisplayCallback()
	 *
	 * \brief	Displays a callback.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	static void DisplayCallback()
	{
		pOpenGLsingleton->Display();
	}

	/**
	 * \fn	static void OpenGL::DisplayTimerCallback(int value)
	 *
	 * \brief	Displays a timer callback described by value.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	value	The value.
	 */

	static void DisplayTimerCallback(int value)
	{
		pOpenGLsingleton->DisplayTimer(value);
	}
};


