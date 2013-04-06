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
	//GraphicsEngFact GraphicsFact;
	//boost::scoped_ptr<Graphics> *pGraphicsEng;
	
	//pGraphicsEng = GraphicsFact.CreateEngine("OpenGL");

	//(*pGraphicsEng)->Init();
	/*
	std::vector<glm::vec3> NewVec;
	NewVec.push_back(glm::vec3(4,1,2));
	NewVec.push_back(glm::vec3(4,1,2));
	NewVec.push_back(glm::vec3(4,1,2));
	NewVec.resize(5);
	std::cout << sizeof(NewVec) * NewVec.capacity();*/

	(*Game::GetInstance())->Initialise();


	return 0;
}