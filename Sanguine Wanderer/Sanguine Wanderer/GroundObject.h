/**
 * \file	GroundObject.h
 *
 * \brief	Declares the ground object class.
 */

#include"GameObject.h"
#include <math.h> 

/**
 * \class	GroundObject
 *
 * \brief	Ground object.
 *
 * \author	Wise Bear
 * \date	5/23/2013
 */

class  GroundObject : public GameObject
{
public: 
	/**
	*\brief default constructer
	*
	*/
	GroundObject(){};

	/**
	*\brief overriden function for setting up collision body
	*
	*/
	void InitialiseCollisionBody(glm::vec3 Pos, float x, float y, float z);
protected:
private:
};