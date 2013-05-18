#include "StdAfx.h"
#include "OpenGL.h"

boost::scoped_ptr<Graphics> OpenGL::pSingleton(NULL);

OpenGL::OpenGL(void)
{
	int GLargc = 1;
	char* GLargv[1];
	GLargv[0] = _strdup("RPG");
	glutInit(&GLargc, GLargv);
	Counter = 0;
	Time = 500;
}


OpenGL::~OpenGL(void)
{
}
void OpenGL::Initialise()
{
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_MULTISAMPLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitContextVersion (3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutInitWindowSize(1280, 960);
	glutInitWindowPosition (300, 0);
	iMainWindow = glutCreateWindow ("RPG");

	if(iMainWindow <  1)
	{
		//throw error, rendering window context unable to be created
		std::cout << "Error";
	}
	
	//Setup Program / shader contexts here
	glload::LoadFunctions(); // load in the functions specified by the current opengl context version
		
	SetupProgram();

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	if(!glload::IsVersionGEQ(3, 3))
	{
		printf("Your OpenGL version is %i, %i. You must have at least OpenGL 3.3 to run this tutorial.\n",
			glload::GetMajorVersion(), glload::GetMinorVersion());
		glutDestroyWindow(iMainWindow);
	}

	glutDisplayFunc(OpenGL::DisplayCallback); 
	glutReshapeFunc(OpenGL::ReshapeCallback);
	glutIdleFunc(OpenGL::UpdateCallback);
}

void OpenGL::SetupProgram()
{
	InitialiseProgram();
	InitialiseVertexBuffer();
}

void OpenGL::InitialiseProgram()
{
	(*Shader::GetInstance())->Initialise();
	std::vector<GLuint> * shaderlist = (*Shader::GetInstance())->GetvShaderList();

	theProgram = CreateProgram((*shaderlist));

	(*Camera::GetInstance())->Setup(theProgram);
	(*Camera::GetInstance())->CreatePerspective(1280, 960);

	UniModelToCameraMatrix = glGetUniformLocation(theProgram, "ModelToWorld");
	UniTex = glGetUniformLocation(theProgram, "tex");

	VertexBufferObject.push_back(0);
	IndexBufferObject.push_back(0);
	VAO.push_back(0);
	TexBuffer.push_back(0);
}
GLuint OpenGL::GettheProgram()
{
	return theProgram;
}

void OpenGL::Update()
{
	float timer = glutGet(GLUT_ELAPSED_TIME);
	if((timer/33.3)-1 >= (Time/33.3))
	{
		glutPostRedisplay();
		Time += 33.3;
	}
}

boost::scoped_ptr<Graphics> * OpenGL::GetInstance()
{
	if(pSingleton.get() == NULL)
	{
		pSingleton.reset(new OpenGL);
	}
	return &pSingleton;
}

void OpenGL::InitialiseVertexBuffer()
{
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);
}

void OpenGL::RenderModel(int Index, Mesh * MeshObj)
{
	glUseProgram(theProgram);
	if(VAO[Index] == 0)
	{
		VertexBufferObject.push_back(0);
		IndexBufferObject.push_back(0);
		VAO.push_back(0);
		TexBuffer.push_back(0);

		glGenVertexArrays(1, &VAO[Index]);
		glGenBuffers(1, &VertexBufferObject[Index]);
		glGenBuffers(1, &TexBuffer[Index]);

		glBindVertexArray(VAO[Index]);

		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject[Index]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*((*MeshObj).GetNumVert()), (*MeshObj).GetVertexArray(), GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
				
		glBindBuffer(GL_ARRAY_BUFFER, TexBuffer[Index]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(*MeshObj).GetNumTextures(), (*MeshObj).GetUVArray(), GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
		(*TextureLoader::GetInstance())->Load((*MeshObj).GetTexPath(), Index);
		glUniform1i(UniTex, 0);
		glActiveTexture(GL_TEXTURE0);
		glBindSampler(0, (*TextureLoader::GetInstance())->GetTextureSampler(Index));

		glBindVertexArray(0);
	}

	glm::mat4 ModelMat = CreateModelTransformMatrix(glm::vec3(0,0,-15),glm::vec3(0.1,0.1,0.1),glm::vec3(0,180,0));

	glBindVertexArray(VAO[Index]);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glUniformMatrix4fv(UniModelToCameraMatrix,1,GL_FALSE, glm::value_ptr(ModelMat));

	glDrawArrays(GL_TRIANGLES, 0, (*MeshObj).GetNumVert());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
	glUseProgram(0);	
}

void OpenGL::Reshape (int w, int h)
{
	(*Camera::GetInstance())->CreatePerspective(w, h);
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}
void OpenGL::Display()
{
	glClearColor(0.65f, 0.8f, 1.0f, 0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

	(*Camera::GetInstance())->CreateCamera();

	glUseProgram(theProgram);
	glm::mat4 ModelMat = CreateModelTransformMatrix(glm::vec3(0,0.0,0),glm::vec3(1,1,1),glm::vec3(0,0,0));
	glUniformMatrix4fv(UniModelToCameraMatrix,1,GL_FALSE, glm::value_ptr(ModelMat));

	(*Game::GetInstance())->Display();

	glutSwapBuffers();
	glutPostRedisplay();
}

glm::mat4 OpenGL::CreateModelTransformMatrix(glm::vec3 Position, glm::vec3 Scale, glm::vec3 Orientation)
{
	glutil::MatrixStack ModelTransform;
	glutil::PushStack push(ModelTransform);
	ModelTransform.Translate(Position);
	ModelTransform.RotateX(Orientation.x);
	ModelTransform.RotateY(Orientation.y);
	ModelTransform.RotateZ(Orientation.z);
	ModelTransform.Scale(Scale);

	return ModelTransform.Top();
}
void OpenGL::MoveCamera(bool Type, glm::vec3 Direction)
{
	if(Type == true) // camera location change
	{
		(*Camera::GetInstance())->SetCameraLoc(Direction);
	}
	else if(Type == false) // camera look at change
	{

	}
}
/*void OpenGL::keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		return;
	case 'w':
		{
			(*Camera::GetInstance())->SetCameraLoc(glm::vec3(0,0,-0.1));
			break;
		}
	case 's':
		{
			(*Camera::GetInstance())->SetCameraLoc(glm::vec3(0,0,0.1));
			break;
		}
	case 'a':
		{
			(*Camera::GetInstance())->SetCameraLoc(glm::vec3(-0.1,0,0));
			break;
		}
	case 'd':
		{
			(*Camera::GetInstance())->SetCameraLoc(glm::vec3(0.1,0,0));
			break;
		}
	}
}

void OpenGL::Mouse(int Button, int State, int MouseX, int MouseY)
{
	std::cout << MouseX << std::endl;
	std::cout << MouseY << std::endl;
	//1280, 960

	if(MouseX > 640)
	{
		(*Camera::GetInstance())->SetCameraLook(glm::vec3(0.1,0,0));
	}
	else if(MouseX < 640)
	{
		(*Camera::GetInstance())->SetCameraLook(glm::vec3(-0.1,0,0));
	}
	if(MouseY > 480)
	{
		(*Camera::GetInstance())->SetCameraLook(glm::vec3(0,-0.1,0));
	}
	else if(MouseY < 480)
	{
		(*Camera::GetInstance())->SetCameraLook(glm::vec3(0,0.1,0));
	}
}*/

void OpenGL::RenderTerrain()
{

}

void OpenGL::Start()
{
	glutMainLoop();
}
GLuint OpenGL::CreateProgram(const std::vector<GLuint> &shaderList)
{
	try
	{
		GLuint prog = glutil::LinkProgram(shaderList);
		std::for_each(shaderList.begin(), shaderList.end(), glDeleteShader);
		return prog;
	}
	catch(std::exception &e)
	{
		std::for_each(shaderList.begin(), shaderList.end(), glDeleteShader);
		fprintf(stderr, "%s\n", e.what());
		throw;
	}
}
