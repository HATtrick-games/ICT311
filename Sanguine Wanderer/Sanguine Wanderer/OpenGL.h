/**
 * \file	OpenGL.h
 *
 * \brief	Declares the open gl class.
 */

#pragma once
#include "stdafx.h"
#include "Camera.h"
#include "Graphics.h"
#include "Shader.h"
#include "Mesh.h"
#include "TextureLoader.h"
#include "HeightMap.h"
#include "Game.h"

/**
 * \class	OpenGL
 *
 * \brief	Open gl.
 *
 * \author	Chaokel
 * \date	22/05/2013
 */

class OpenGL : public Graphics
{
public:
	OpenGL(void);
	~OpenGL(void);

	/**
	 * \fn	static boost::scoped_ptr<Graphics> * OpenGL::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<Graphics> * GetInstance();

	/**
	 * \fn	void OpenGL::Initialise();
	 *
	 * \brief	Initialises this object.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	void Initialise();

	/**
	 * \fn	void OpenGL::SetupProgram();
	 *
	 * \brief	Sets up the program.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	void SetupProgram();

	/**
	 * \fn	void OpenGL::InitialiseProgram();
	 *
	 * \brief	Initialises the program.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	void InitialiseProgram();

	/**
	 * \fn	GLuint OpenGL::GettheProgram();
	 *
	 * \brief	Gets the program.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	Handle to program.
	 */

	GLuint GettheProgram();

	/**
	 * \fn	GLuint OpenGL::GetoffsetUniform();
	 *
	 * \brief	Gets the offset uniform.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	offset handle.
	 */

	GLuint GetoffsetUniform();

	/**
	 * \fn	GLuint OpenGL::GetvertexBufferObject();
	 *
	 * \brief	Gets the getvertex buffer object.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	handle to the VBO.
	 */

	GLuint GetvertexBufferObject();

	/**
	 * \fn	glm::mat4 OpenGL::CreateModelTransformMatrix(glm::vec3 Position, glm::vec3 Scale,
	 * 		glm::vec3 Orientation);
	 *
	 * \brief	Creates model transform matrix.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	Position   	The position.
	 * \param	Scale	   	The scale.
	 * \param	Orientation	The orientation.
	 *
	 * \return	The new model transform matrix.
	 */

	glm::mat4 CreateModelTransformMatrix(glm::vec3 Position, glm::vec3 Scale, glm::vec3 Orientation);

	/**
	 * \fn	int OpenGL::GetnumVertex();
	 *
	 * \brief	Gets the number of vertex.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	number of vertex.
	 */

	int GetnumVertex();

	/**
	 * \fn	void OpenGL::InitialiseVertexBuffer();
	 *
	 * \brief	Initialises the vertex buffer.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	void InitialiseVertexBuffer();

	/**
	 * \fn	void OpenGL::Reshape(int width, int height);
	 *
	 * \brief	Reshapes the window.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	width 	The width.
	 * \param	height	The height.
	 */

	void Reshape(int width, int height);

	/**
	 * \fn	void OpenGL::Display();
	 *
	 * \brief	Handles all rendering, callback to opengl display function.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	void Display();

	/**
	 * \fn	void OpenGL::Update();
	 *
	 * \brief	Updates this object.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	void Update();

	/**
	 * \fn	GLuint OpenGL::CreateProgram(const std::vector<GLuint> &shaderList);
	 *
	 * \brief	Creates a program.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	shaderList	List of shaders.
	 *
	 * \return	The new program.
	 */

	GLuint CreateProgram(const std::vector<GLuint> &shaderList);

	/**
	 * \fn	void OpenGL::SetCam(glm::vec3 location);
	 *
	 * \brief	Sets a camera location.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	location	The camera location.
	 */

	void SetCam(glm::vec3 location);

	/**
	 * \fn	void OpenGL::SetLook(glm::vec3 look);
	 *
	 * \brief	Sets a camera look at.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	look	The camera look at.
	 */

	void SetLook(glm::vec3 look);

	/**
	 * \fn	void OpenGL::MoveCamera(bool Type, glm::vec3 Direction);
	 *
	 * \brief	Move camera.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	Type	 	Look at or location.
	 * \param	Direction	The direction.
	 */

	void MoveCamera(bool Type, glm::vec3 Direction);

	/**
	 * \fn	void OpenGL::RenderModel(GameObject * GameObj);
	 *
	 * \brief	Renders the model described by GameObj.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param [in,out]	GameObj	If non-null, the game object.
	 */

	void RenderModel(GameObject * GameObj);

	/**
	 * \fn	void OpenGL::RenderTerrain(HeightMap* Terrain);
	 *
	 * \brief	Renders the terrain described by Terrain.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param [in,out]	Terrain	If non-null, the terrain.
	 */

	void RenderTerrain(HeightMap* Terrain);

	/**
	 * \fn	void OpenGL::Start();
	 *
	 * \brief	Starts the mainloop.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	void Start();

	/**
	 * \fn	int OpenGL::GetGraphics();
	 *
	 * \brief	Gets the graphics.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The graphics.
	 */

	int GetGraphics();

private:

	/**
	 * \brief	the program.
	 */

	GLuint theProgram;

	/**
	 * \brief	Zero-based index of the main window.
	 */

	int iMainWindow;

	/**
	 * \brief	Number of vertices.
	 */

	int numVertex;

	/**
	 * \brief	The uni model to camera matrix.
	 */

	GLuint UniModelToCameraMatrix;

	/**
	 * \brief	The uni tex.
	 */

	GLuint UniTex;

	int Counter;

	/**
	 * \brief	The time.
	 */

	float Time;

	/**
	 * \brief	The vertex buffer object.
	 */

	std::vector<GLuint> VertexBufferObject;

	/**
	 * \brief	The vertex array object.
	 */

	std::vector<GLuint> VAO;

	/**
	 * \brief	The index buffer object.
	 */

	std::vector<GLuint> IndexBufferObject;

	/**
	 * \brief	Buffer for tex data.
	 */

	std::vector<GLuint> TexBuffer;

	/**
	 * \brief	The animation vbo.
	 */

	GLuint AnimationVBO;

	/**
	 * \brief	The animation vao.
	 */

	GLuint AnimationVAO;

	/**
	 * \brief	The animation tbo.
	 */

	GLuint AnimationTBO;

	/**
	 * \brief	The singleton.
	 */

	static boost::scoped_ptr<Graphics> pSingleton;

	/**
	 * \fn	static void OpenGL::ReshapeCallback(int width, int height)
	 *
	 * \brief	Callback, called when reshaping.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	width 	The width.
	 * \param	height	The height.
	 */

	static void ReshapeCallback(int width, int height)
	{
		pSingleton->Reshape(width, height);
	}

	/**
	 * \fn	static void OpenGL::DisplayCallback()
	 *
	 * \brief	 the display callback.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	static void DisplayCallback()
	{
		pSingleton->Display();
	}

	/**
	 * \fn	static void OpenGL::UpdateCallback()
	 *
	 * \brief	 the update callback.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	static void UpdateCallback()
	{
		pSingleton->Update();
	}
};

