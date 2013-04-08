#include "OpenGL.h"

boost::scoped_ptr<Graphics> OpenGL::pOpenGLsingleton(NULL);
//#ifdef LOAD_X11
//#define APIENTRY //Not used i think. Remove later after proper check
//#endif

OpenGL::OpenGL(void)
{
	int GLargc = 1;
	char* GLargv[1];
	GLargv[0] = _strdup("RPG");
	glutInit(&GLargc, GLargv);
	iDisplayMode = GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_RGBA;

	Ini = GameSettings::GetInstance();
	(*Ini)->GetiWindowWidth();
	(*Ini)->GetiWindowHeight();
}


OpenGL::~OpenGL(void)
{
}

void OpenGL::Init()
{
	glutInitDisplayMode(iDisplayMode);

	//Set OpenGL context to 3.3 using core profile (all previously deprecated functions are removed/unusable)
	glutInitContextVersion (3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS); //return control to the program on window close, to be able to appropriately release memory

	glutInitWindowSize((*Ini)->GetiWindowWidth(), (*Ini)->GetiWindowHeight());
	glutInitWindowPosition (300, 0);
	iMainWindow = glutCreateWindow("RPG");

	if(iMainWindow <  1)
	{
		//throw error, rendering window context unable to be created
		std::cout << "Error";
	}
	
	//Setup Program / shader contexts here
	glload::LoadFunctions(); // load in the functions specified by the current opengl context version
	
	
	SetupProgram();

	if(!glload::IsVersionGEQ(3,3))
	{
		//throw error, opengl 3.3 isn't supported on current device.
		std::cout << "Error";
	}

	//Setup depth buffer
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);

	//Register graphic specific callback functions
	glutReshapeFunc(OpenGL::ReshapeCallback);
	glutDisplayFunc(OpenGL::DisplayCallback);

}

void OpenGL::SetupProgram()
{
	(*Shader::GetInstance())->Initialise();
	std::vector<GLuint> * shaderlist = (*Shader::GetInstance())->GetvShaderList(); // Hopefully this returns the shaderlist correctly - untested
	ProgObj = CreateProgramObject(shaderlist);

	(*Camera::GetInstance())->UpdateProgObj(ProgObj);
	(*Camera::GetInstance())->SetupCamera();
	//(*Camera::GetInstance())->CreateCamera();

	glUseProgram(ProgObj);
	UniOffset = glGetUniformLocation(ProgObj, "Offset");
	//UniTransformMatrix = glGetUniformLocation(ProgObj, "TransformMatrix");
	glUseProgram(0);

	VertexBufferObject.push_back(0);
	IndexBufferObject.push_back(0);
	Vao.push_back(0);
}

void OpenGL::InitialiseVAO()
{

}

GLuint OpenGL::CreateProgramObject(const std::vector<GLuint>* shaderList)
{
	try
	{
		GLuint ProgramObj = glutil::LinkProgram((*shaderList));
		std::for_each(shaderList->begin(), shaderList->end(), glDeleteShader);
		return ProgramObj;
	}
	catch(std::exception &e)
	{
		//return error stating that program object was unable to be created with shaders.
		std::cout << "Error";
	}
}

void OpenGL::Display()
{
	glClearColor(0.65f, 0.8f, 1.0f, 0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	(*Game::GetInstance())->Draw();
	glutSwapBuffers();
}

void OpenGL::RenderModel(Mesh * MeshObj, GameObject * GameObj, int Index)
{

	if(Vao[Index] == 0)
	{
		glGenVertexArrays(1, &Vao[Index]);
		glBindVertexArray(Vao[Index]);

		glGenBuffers(1, &VertexBufferObject[Index]);
		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject[Index]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)* 3 *(MeshObj->GetVertices()->capacity()), &((MeshObj->GetVertices())[0]), GL_STATIC_DRAW);
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		glGenBuffers(1, &IndexBufferObject[Index]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferObject[Index]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * (MeshObj->GetnumIndicies()), &((MeshObj->GetIndicies())[0]), GL_STATIC_DRAW);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		//glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject[Index]);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		//(*OGLTexture::GetInstance())->CreateTexCoordBuffer((MeshObj->GetTexCoords()), MeshObj->GetTexCoords()->capacity());
		std::cout << std::endl << std::endl;
		for(unsigned int i = 0; i < (*MeshObj->GetVertices()).size(); i++)
		{
		std::cout << &((*MeshObj->GetTexCoords())[i].x) << " | " << (*MeshObj->GetTexCoords())[i].x << " | " << (*MeshObj->GetTexCoords())[i].y <<" | " << i << std::endl;
		}
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferObject[Index]);
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER,0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
		//create room for another model
		VertexBufferObject.push_back(0);
		IndexBufferObject.push_back(0);
		Vao.push_back(0);
	
			std::cout << std::endl << std::endl;
	std::cout << sizeof(unsigned int) * (MeshObj->GetnumIndicies()) << std::endl;
	//for(unsigned int i = 0; i < (*MeshObj->GetVertices()).size(); i++)
	//{
		//std::cout << &((*MeshObj->GetVertices())[i].x) << " | " << (*MeshObj->GetVertices())[i].x << " | " << (*MeshObj->GetVertices())[i].y <<" | " << (*MeshObj->GetVertices())[i].z << " | "<< i << std::endl;
	//std::cout << &((*MeshObj->GetVertices())[i].y) << " | " << (*MeshObj->GetVertices())[i].y << " | "<< i << std::endl;
	//std::cout << &((*MeshObj->GetVertices())[i].z) << " | " << (*MeshObj->GetVertices())[i].z << " | "<< i << std::endl;
	//}

	//for(unsigned int i = 0; i < (*MeshObj->GetIndicies()).size(); i++)
	//	std::cout << &((MeshObj->GetIndicies())[i]) << " | " << (*MeshObj->GetIndicies())[i] << " | "<< i << std::endl;

	}

	/*for(unsigned int i = 0; i < (*MeshObj->GetVertices()).size(); i++)
	{
		std::cout <<"VERT:" << ((*MeshObj->GetVertices())[i].x);
		std::cout <<", " << ((*MeshObj->GetVertices())[i].y);
		std::cout <<", " << ((*MeshObj->GetVertices())[i].z) << std::endl;
		std::cout << "Index:" << ((*MeshObj->GetIndicies())[i]);
		if(i+1 < (*MeshObj->GetVertices()).size())
		{
			std::cout << ", " << ((*MeshObj->GetIndicies())[i+1]);
			if (i+2 < (*MeshObj->GetVertices()).size())
			{
				std::cout << ", " << ((*MeshObj->GetIndicies())[i+2]) << std::endl;
			}
		}
	}*/

	//(*Camera::GetInstance())->SetCameraScale(0.25);

	glUseProgram(ProgObj);
	glBindVertexArray(Vao[Index]);
	
	glUniform3f(UniOffset, 5.0, 0.0, -1.0);
	//glUniformMatrix4fv(UniTransformMatrix,1,GL_FALSE, glm::value_ptr(CreateModelTransformMatrix(glm::vec3(GameObj->GetPosition().x, GameObj->GetPosition().y, GameObj->GetPosition().z),glm::vec3(1,1,1),glm::vec3(0,0,0))));
	glDrawElements(GL_TRIANGLES, MeshObj->GetnumIndicies(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glUseProgram(0);	
}

void OpenGL::RenderTerrain(Terrain * TerrainObj)
{
	glUseProgram(ProgObj);
	glGenBuffers(1, &TerrainBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, TerrainBufferObject);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(TerrainObj->vVertices), TerrainObj->vVertices, GL_STATIC_DRAW);
}

void OpenGL::DisplayTimer(int value)
{
	glutTimerFunc(1000/60, OpenGL::DisplayTimerCallback, ++value);
	glutPostRedisplay();
}

glm::mat4 OpenGL::CreateModelTransformMatrix(glm::vec3 Position, glm::vec3 Scale, glm::vec3 Orientation)
{
	glm::mat4 TransformMat(1.0f);
	TransformMat[0].x = Scale.x;
	TransformMat[1].y = Scale.y;
	TransformMat[2].z = Scale.z;
	TransformMat[3] = glm::vec4(Position, 1.0f);
	return TransformMat;
}

void OpenGL::Reshape(int width, int height)
{
	(*Camera::GetInstance())->ReshapeViewport(width, height);
}

boost::scoped_ptr<Graphics> * OpenGL::GetInstance()
{
	if(pOpenGLsingleton.get() == NULL)
	{
		pOpenGLsingleton.reset(new OpenGL);
	}
	
	return &pOpenGLsingleton;
}
