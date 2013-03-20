/*
 *
 * To be deleted and replaced by a real main at a later stage
 * simply used to test dependacies, and to check compile on other
 * classes to be included.
 *
 *
 */

//#include <GL\freeglut.h> // Note that this is the GL folder found in the project solution, not the GL folder on C:
#include "Graphics.h"
#include "GameSettings.h"
#include "GraphicsEngFact.h"
#include "Keyboard.h"

#include <boost\smart_ptr.hpp>

int main(int argc, char** argv)
{	
	GraphicsEngFact GraphicsFact;
	boost::scoped_ptr<Graphics> *pGraphicsEng;

	// Input Objects
	boost::scoped_ptr<Keyboard> *pKeyboard;
	
	pGraphicsEng = GraphicsFact.CreateEngine("OpenGL");

	(*pGraphicsEng)->Init();
	
	return 0;
}