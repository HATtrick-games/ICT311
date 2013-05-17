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

	glDisable(GL_CULL_FACE);

	//Setup depth buffer
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);
	//glEnable(GL_DEPTH_CLAMP);

	//Register graphic specific callback functions
	glutReshapeFunc(OpenGL::ReshapeCallback);
	glutDisplayFunc(OpenGL::DisplayCallback);
	glutTimerFunc(1000.0/30.0, OpenGL::DisplayTimerCallback, 0);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
}

void OpenGL::SetupProgram()
{
	(*Shader::GetInstance())->Initialise();
	std::vector<GLuint> * shaderlist = (*Shader::GetInstance())->GetvShaderList(); // Hopefully this returns the shaderlist correctly - untested
	ProgObj = CreateProgramObject(shaderlist);

	(*Camera::GetInstance())->UpdateProgObj(ProgObj);
	(*Camera::GetInstance())->SetupCamera();

	glUseProgram(ProgObj);
	//UniOffset = glGetUniformLocation(ProgObj, "Offset");
	UniModelToCameraMatrix = glGetUniformLocation(ProgObj, "ModelToWorld");
	UniBaseTexture = glGetUniformLocation(ProgObj, "tex");
	glUniform1i(UniBaseTexture, 0);
	glUseProgram(0);

	VertexBufferObject.push_back(0);
	IndexBufferObject.push_back(0);
	Vao.push_back(0);
	
	//remove later---------------------------------------------


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
	//glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glutil::MatrixStack modelMatrix;
	glutil::MatrixStack modelMatrix1;
	{
	glutil::PushStack push(modelMatrix);
	(*Camera::GetInstance())->SetupCameraToClipMatrix(modelMatrix);
	}
	{
	glutil::PushStack push(modelMatrix1);
	(*Camera::GetInstance())->CreateCamera(modelMatrix1);
	}
	
	(*Game::GetInstance())->Update(1000.0/120.0);
	(*Game::GetInstance())->Draw();

	glutSwapBuffers();
}

void OpenGL::RenderModel(Mesh * MeshObj, GameObject * GameObj, int Index)
{

	if(Vao[Index] == 0)
	{
		VertexBufferObject.push_back(0);
		IndexBufferObject.push_back(0);
		Vao.push_back(0);
		glGenBuffers(1, &VertexBufferObject[Index]);
		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject[Index]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)* 3 *(MeshObj->GetVertices()->capacity()), &((MeshObj->GetVertices())[0]), GL_STATIC_DRAW);

		glGenBuffers(1, &IndexBufferObject[Index]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferObject[Index]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * (MeshObj->GetnumIndicies()), &((MeshObj->GetIndicies())[0]), GL_STATIC_DRAW);
				
		glGenVertexArrays(1, &Vao[Index]);
		glBindVertexArray(Vao[Index]);

		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject[Index]);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		(*OGLTexture::GetInstance())->BindTexture(MeshObj->GetTextures(Index), Index); 
		(*OGLTexture::GetInstance())->CreateTexCoordBuffer((MeshObj->GetTexCoords()), MeshObj->GetTexCoords()->capacity());
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferObject[Index]);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER,0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

	}
	
	glUseProgram(ProgObj);
	glBindVertexArray(Vao[Index]);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, (*OGLTexture::GetInstance())->GetTexHandle(Index));

	glm::mat4 ModelMat = CreateModelTransformMatrix(glm::vec3(GameObj->GetPosition().x, GameObj->GetPosition().y, GameObj->GetPosition().z),glm::vec3(2,1,1),glm::vec3(0,0,0));

	glUniformMatrix4fv(UniModelToCameraMatrix,1,GL_FALSE, glm::value_ptr(ModelMat));
	glDrawElements(GL_TRIANGLES, MeshObj->GetnumIndicies(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glUseProgram(0);	
}

void OpenGL::RenderTerrain(Terrain * TerrainObj)
{
	glUseProgram(ProgObj);
	glGenBuffers(1, &TerrainBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, TerrainBufferObject);
	
	for(int z = 0; z < TerrainObj->GetLength() - 1; z++) {
		//Makes OpenGL draw a triangle at every three consecutive vertices
		for(int x = 0; x < TerrainObj->GetWidth(); x++) {
			glm::vec3 normal = TerrainObj->GetNormal(x, z);
			//glNormal3f(normal[0], normal[1], normal[2]);
			//glVertex3f(x, ter->GetHeight(x, z), z);
			normal = TerrainObj->GetNormal(x, z + 1);
			//glNormal3f(normal[0], normal[1], normal[2]);
			//glVertex3f(x, ter->GetHeight(x, z + 1), z + 1);
		}
	}
}

void OpenGL::DisplayTimer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(1000.0/30.0, OpenGL::DisplayTimerCallback, 0);
}

glm::mat4 OpenGL::CreateModelTransformMatrix(glm::vec3 Position, glm::vec3 Scale, glm::vec3 Orientation)
{
	glutil::MatrixStack ModelTransform;
	glutil::PushStack push(ModelTransform);

	ModelTransform.Translate(Position);
		ModelTransform.Scale(Scale);
	return ModelTransform.Top();
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
