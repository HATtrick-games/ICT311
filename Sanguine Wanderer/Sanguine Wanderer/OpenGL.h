#pragma once
#include "stdafx.h"
#include "Camera.h"
#include "Graphics.h"
#include "Shader.h"
#include "Mesh.h"
#include "TextureLoader.h"
#include "Game.h"

class OpenGL : public Graphics
{
public:
	OpenGL(void);
	~OpenGL(void);

	static boost::scoped_ptr<Graphics> * GetInstance();
	void Initialise();
	void SetupProgram();
	void InitialiseProgram();

	GLuint GettheProgram();
	GLuint GetoffsetUniform();
	GLuint GetvertexBufferObject();
	glm::mat4 CreateModelTransformMatrix(glm::vec3 Position, glm::vec3 Scale, glm::vec3 Orientation);
	int GetnumVertex();
	void InitialiseVertexBuffer();
	void Reshape(int width, int height);
	void Display();

	GLuint CreateProgram(const std::vector<GLuint> &shaderList);

	void MoveCamera(bool Type, glm::vec3 Direction);
	void RenderModel(int Index, Mesh * MeshObj);
	void RenderTerrain();
	void Start();

private:

	GLuint theProgram;
	int iMainWindow;
	int numVertex;
	GLuint UniModelToCameraMatrix;
	GLuint UniTex;

	float *Vert;

	std::vector<GLuint> VertexBufferObject;
	std::vector<GLuint> VAO;
	std::vector<GLuint> IndexBufferObject;

	std::vector<GLuint> TexBuffer;

	static boost::scoped_ptr<Graphics> pSingleton;

	static void ReshapeCallback(int width, int height)
	{
		pSingleton->Reshape(width, height);
	}
	static void DisplayCallback()
	{
		pSingleton->Display();
	}
};

