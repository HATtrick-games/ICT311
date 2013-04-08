#pragma once

#include "OGLTexture.h"
#include "Graphics.h"
#include "Shader.h"
#include "Camera.h"
#include "Game.h"
#include "AngleMath.h"
#include "GameSettings.h"
#include <GL\freeglut.h>
//#include <glload\gl_3_3.h>
#include <glload\gll.hpp>
#include <boost\smart_ptr.hpp>

#include <vector>
#include <iostream>
class OpenGL :public Graphics
{
public:
	static boost::scoped_ptr<Graphics> * GetInstance();
	~OpenGL(void);

	//Virtual functions
	void Init(); // Used to intialise freeglut and call setup for the opengl context and window.
	void RenderModel(Mesh * MeshObj, GameObject * GameObj, int Index);
	void RenderTerrain(Terrain * TerrainObj);
	void Reshape(int width, int height);
	void Display();
	void DisplayTimer(int value);

	//OpenGL specific functions
	void SetupProgram();
	GLuint CreateProgramObject(const std::vector<GLuint>* shaderList);
	glm::mat4 CreateModelTransformMatrix(glm::vec3 Position, glm::vec3 Scale, glm::vec3 Orientation);
	void InitialiseVAO();
	
private:

	OpenGL(void); // Used to intialise and setup anything required before freeglut sets up the window
	OpenGL& operator= (const OpenGL&);
	OpenGL(const OpenGL&);

	unsigned int iDisplayMode;
	int iMainWindow;
	
	GLuint ProgObj;

	std::vector<GLuint> VertexBufferObject;
	std::vector<GLuint> IndexBufferObject;
	std::vector<GLuint> Vao;
	GLuint TerrainBufferObject;
	
	GLuint ColorOffset;

	GLuint UniOffset; //(uniform) offset to be passed and used in the vertex shader
	GLuint UniTransformMatrix;
	GLuint UniPerspectiveMatrix;
	//singleton stuff
	static boost::scoped_ptr<Graphics> pOpenGLsingleton;

	boost::scoped_ptr<GameSettings>* Ini;

	static void ReshapeCallback(int width, int height)
	{
		pOpenGLsingleton->Reshape(width, height);
	}	
	static void DisplayCallback()
	{
		pOpenGLsingleton->Display();
	}
	static void DisplayTimerCallback(int value)
	{
		pOpenGLsingleton->DisplayTimer(value);
	}
};


