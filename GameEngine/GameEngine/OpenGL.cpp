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
	}

	//Setup Program / shader contexts here
	glload::LoadFunctions(); // load in the functions specified by the current opengl context version
	
	SetupProgram();

	if(!glload::IsVersionGEQ(3,3))
	{
		//throw error, opengl 3.3 isn't supported on current device.
	}



	//Register callback functions
	glutReshapeFunc(OpenGL::ReshapeCallback);
	glutDisplayFunc(OpenGL::DisplayCallback);

	glutMainLoop();
}

void OpenGL::SetupProgram()
{
	(*Shader::GetInstance())->Initialise();
	std::vector<GLuint> * shaderlist = (*Shader::GetInstance())->GetvShaderList(); // Hopefully this returns the shaderlist correctly - untested
	ProgObj = CreateProgramObject(shaderlist);
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
	}
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

boost::scoped_ptr<Graphics> * OpenGL::GetInstance()
{
	if(pOpenGLsingleton.get() == NULL)
	{
		pOpenGLsingleton.reset(new OpenGL);
	}
	
	return &pOpenGLsingleton;
}
