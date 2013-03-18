#include "OpenGL.h"

OpenGL* OpenGL::OpenGLsingleton = 0;
bool OpenGL::instanceFlag = false;

OpenGL::OpenGL(void)
{
	int GLargc = 1;
	char* GLargv[1];
	GLargv[0] = strdup("RPG");
	glutInit(&GLargc, GLargv);
	iDisplayMode = GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_RGBA;

	Ini = GameSettings::GetInstance();
	Ini->UpdateiWindowWidth();
	Ini->UpdateiWindowHeight();
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

	glutInitWindowSize(Ini->GetiWindowWidth(), Ini->GetiWindowHeight());
	glutInitWindowPosition (300, 0);
	iMainWindow = glutCreateWindow("RPG");

	if(iMainWindow <  1)
	{
		//throw error, rendering window context unable to be created
	}

	//Setup Program / shader contexts here
	glload::LoadFunctions(); // load in the functions specified by the current opengl context version

	if(!glload::IsVersionGEQ(3,3))
	{
		//throw error, opengl 3.3 isn't supported on current device.
	}

	//Register callback functions
	glutReshapeFunc(OpenGL::ReshapeCallback);

	glutMainLoop();
}

void OpenGL::Display()
{

}

void OpenGL::DrawModel(std::string Name)
{

}

void OpenGL::Reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
}

OpenGL * OpenGL::GetInstance()
{
	if(instanceFlag == false)
	{
		OpenGLsingleton = new OpenGL;
		instanceFlag = true;
	}
	
	return OpenGLsingleton;

}