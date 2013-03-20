/*
 *
 * To be deleted and replaced by a real main at a later stage
 * simply used to test dependacies, and to check compile on other
 * classes to be included.
 *
 *
 */


#include "Graphics.h"
#include "GameSettings.h"
#include "GraphicsEngFact.h"
#include "CommonFuncs.h"

#include <boost\smart_ptr.hpp>

int main(int argc, char** argv)
{	
	GraphicsEngFact GraphicsFact;
	boost::scoped_ptr<Graphics> *pGraphicsEng;

	pGraphicsEng = GraphicsFact.CreateEngine("OpenGL");

	(*pGraphicsEng)->Init();
	


	return 0;
}