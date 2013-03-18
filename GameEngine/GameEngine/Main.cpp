/*
 *
 * To be deleted and replaced by a real main at a later stage
 * simply used to test dependacies, and to check compile on other
 * classes to be included.
 *
 *
 */

#include <GL\freeglut.h> // Note that this is the GL folder found in the project solution, not the GL folder on C:
#include "Graphics.h"
#include "GameSettings.h"
#include "GraphicsEngFact.h"


int main(int argc, char** argv)
{	
	GraphicsEngFact GraphicsFact;
	Graphics *GraphicsEng;

	GraphicsEng = GraphicsFact.CreateEngine("OpenGL");

	GraphicsEng->Init();

	return 0;
}