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

	/*

	4:17 PM - Captain Midnight: #include <Windows.h>
#include "wtypes.h"
4:17 PM - Captain Midnight: screenwidth = 0;
screenheight = 0;
screenwidth = GetSystemMetrics(SM_CXSCREEN);
screenheight = GetSystemMetrics(SM_CYSCREEN);
*/
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

	VertexBufferObject.resize(20);
	IndexBufferObject.resize(20);
	VAO.resize(20);
	TexBuffer.resize(20);
}
GLuint OpenGL::GettheProgram()
{
	return theProgram;
}

/*int OpenGL::GetGraphics()
{
	std::cout << theProgram;
	return theProgram;
}*/

void OpenGL::Update()
{
	float timer = glutGet(GLUT_ELAPSED_TIME);
	if((timer/33.3)-1 >= (Time/33.3))
	{
		glutPostRedisplay();
		Time += 33.3;
	}
	
	(*Game::GetInstance())->Update();
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

void OpenGL::RenderModel(GameObject * GameObj)
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	int Index = GameObj->GetMesh()->GetIdentifier();
	glUseProgram(theProgram);

	if(GameObj->GetIsAnimating())
	{
		int NextFrame;
		int CurrentFrame;
		CurrentFrame = GameObj->GetAnimations()->GetCurrentFrame();
		float * AnimationBuffer;
		float Dif;
		float Timer = glutGet(GLUT_ELAPSED_TIME);
		
		if(GameObj->GetAnimations()->GetBoolWalk())
		{
			
			if(!GameObj->GetAnimations()->GetPreviousAnimations())
			{
				GameObj->GetAnimations()->SetTime(Timer);
			}

			if((Timer-GameObj->GetAnimations()->GetTime()) > 1000)
			{
				CurrentFrame++;
				GameObj->GetAnimations()->SetTime(Timer);
			}


			if(CurrentFrame >= GameObj->GetAnimations()->GetTotalFrames()-1)
			{

				CurrentFrame = 0;
			}

			GameObj->GetAnimations()->SetCurrentFrame(CurrentFrame);

			NextFrame = (CurrentFrame + 1);
			std::cout << CurrentFrame;

			AnimationBuffer = new float[GameObj->GetAnimations()->GetWalk(CurrentFrame)->GetNumVert()];
			
			for(int i=0; i < GameObj->GetAnimations()->GetWalk(CurrentFrame)->GetNumVert(); i++)
			{
				Dif = GameObj->GetAnimations()->GetWalk(NextFrame)->GetVertexArray()[i] - GameObj->GetAnimations()->GetWalk(CurrentFrame)->GetVertexArray()[i];
				Dif =  Dif*((Timer - GameObj->GetAnimations()->GetTime())/1000);
		
				AnimationBuffer[i] = GameObj->GetAnimations()->GetWalk(CurrentFrame)->GetVertexArray()[i] + Dif;
			}		
		}

		if(!GameObj->GetAnimations()->GetPreviousAnimations())
		{
			glGenVertexArrays(1, &AnimationVAO);
			glGenBuffers(1, &AnimationVBO);
			glGenBuffers(1, &AnimationTBO);
		}

		glBindVertexArray(AnimationVAO);

		glBindBuffer(GL_ARRAY_BUFFER, AnimationVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(GameObj->GetMesh()->GetNumVert()), AnimationBuffer, GL_STREAM_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		
		if(!GameObj->GetAnimations()->GetPreviousAnimations())
		{
			glBindBuffer(GL_ARRAY_BUFFER, AnimationTBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(GameObj->GetMesh()->GetNumTextures()), GameObj->GetMesh()->GetUVArray(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
			(*TextureLoader::GetInstance())->Load(GameObj->GetMesh()->GetTexPath(), Index);
		}

		glBindVertexArray(0);

		glm::mat4 ModelMat = CreateModelTransformMatrix(GameObj->GetPosition(),(GameObj->GetScale()),(GameObj->GetRotation()));

		glBindVertexArray(AnimationVAO);

		glUniform1i(UniTex, 0);
		glBindTexture(GL_TEXTURE_2D,(*TextureLoader::GetInstance())->GetTexHandle(Index));
		glActiveTexture(GL_TEXTURE0);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glUniformMatrix4fv(UniModelToCameraMatrix,1,GL_FALSE, glm::value_ptr(ModelMat));

		glDrawArrays(GL_TRIANGLES, 0, GameObj->GetMesh()->GetNumVert());

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glBindVertexArray(0);
		glUseProgram(0);


		GameObj->GetAnimations()->SetPreviousAnimations(true);
		
		delete[] AnimationBuffer;
	}
	else
	{
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
			glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(GameObj->GetMesh()->GetNumVert()), GameObj->GetMesh()->GetVertexArray(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
				
			glBindBuffer(GL_ARRAY_BUFFER, TexBuffer[Index]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(GameObj->GetMesh()->GetNumTextures()), GameObj->GetMesh()->GetUVArray(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
			(*TextureLoader::GetInstance())->Load(GameObj->GetMesh()->GetTexPath(), Index);
		
			glBindVertexArray(0);
		}

		glm::mat4 ModelMat = CreateModelTransformMatrix(GameObj->GetPosition(),(GameObj->GetScale()),(GameObj->GetRotation()));

		glBindVertexArray(VAO[Index]);

		glUniform1i(UniTex, 0);
		glBindTexture(GL_TEXTURE_2D,(*TextureLoader::GetInstance())->GetTexHandle(Index));
		glActiveTexture(GL_TEXTURE0);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glUniformMatrix4fv(UniModelToCameraMatrix,1,GL_FALSE, glm::value_ptr(ModelMat));

		glDrawArrays(GL_TRIANGLES, 0, GameObj->GetMesh()->GetNumVert());

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glBindVertexArray(0);
		glUseProgram(0);
	}
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


void OpenGL::SetLook(glm::vec3 look)
{
	(*Camera::GetInstance())->SetLookAt(look);
}

void OpenGL::SetCam(glm::vec3 location)
{
	(*Camera::GetInstance())->SetLocation(location);
}



void OpenGL::RenderTerrain(HeightMap * Terrain)
{
	glDisable(GL_CULL_FACE);
	int Index = 0;
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
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(Terrain->GetNumberHeights()), Terrain->GetMap(), GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, TexBuffer[Index]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(Terrain->GetNumberTex()), Terrain->GetUVW(), GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
		(*TextureLoader::GetInstance())->Load("HeightmapTexture.bmp", Index);
	}
	glm::mat4 ModelMat = CreateModelTransformMatrix(glm::vec3(-500,-5,-500),glm::vec3(8,8,8),glm::vec3(0,0,0));

	glBindVertexArray(VAO[Index]);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glUniformMatrix4fv(UniModelToCameraMatrix,1,GL_FALSE, glm::value_ptr(ModelMat));

	glUniform1i(UniTex, 0);
	glBindTexture(GL_TEXTURE_2D,(*TextureLoader::GetInstance())->GetTexHandle(Index));
	glActiveTexture(GL_TEXTURE0);

	glDrawArrays(GL_TRIANGLES, 0, Terrain->GetNumberHeights());
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
	glUseProgram(0);
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

int OpenGL::GetGraphics()
{
	return theProgram;
}