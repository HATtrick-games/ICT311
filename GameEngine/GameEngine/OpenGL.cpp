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
	
	glutInitWindowSize(Ini->GetiWindowWidth(), Ini->GetiWindowHeight());
	glutInitWindowPosition (300, 0);
	iMainWindow = glutCreateWindow("RPG");

	glutReshapeFunc(OpenGL::ReshapeCallback);

	glutMainLoop();
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