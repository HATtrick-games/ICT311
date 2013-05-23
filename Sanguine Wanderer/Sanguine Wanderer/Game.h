/**
 * \file	Game.h
 *
 * \brief	Declares the game class.
 */

#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "GraphicsFact.h"
#include "IAsset.h"
#include "Input.h"
#include "IKeyboard.h"
#include "PlayerObject.h"
#include "CollisionWorldSingleton.h"
#include "HeightMap.h"
#include "GroundObject.h"
#include "PropObject.h"
#include "CollisionHeightMap.h"
#include "AIScripting.h"
#include "Animation.h"
#include <list>

/**
 * \class	Game
 *
 * \brief	Game.
 *
 * \author	Hamish Carrier
 * \date	5/23/2013
 */

class Game
{
public:
	 Game();
	~Game(void);

	void Display();

	/**
	 * \fn	void Game::Init();
	 *
	 * \brief	Initialises this object.
	 *
	 * \author	Hamish Carrier
	 * \date	5/23/2013
	 */

	void Init();

	/**
	*\brief calls input functions and checks what keys are down.
	*
	*/
	void Input();

	/**
	*\brief updates all objects that require it
	*
	*/
	void Update();
	/**
	*\brief activated by mouse movement, calls player camera movement functions
	*
	*/
	void MouseMove(int x, int y);

	/**
	*\brief sets up in game objects
	*
	*/
	void InitialiseProps();

	/**
	*\brief returns an instance of game
	*
	*/
	static boost::scoped_ptr<Game> * GetInstance();

private:
	static boost::scoped_ptr<Game> pSingleton;
	boost::scoped_ptr<Graphics> *pGraphicsEng;

	/**
	 * \brief	The player.
	 */

	PlayerObject* Player;

	/**
	*\brief a game object
	*
	*/
	GameObject* Obj;

	/**
	 * \brief	The plane.
	 */

	GroundObject* plane;
	/**
	*\brief a ground object
	*
	*/
	GroundObject* plane1;

	/**
	 * \brief	The second plane.
	 */

	GroundObject* plane2;
	/**
	*\brief a ground object
	*
	*/
	GroundObject* plane3;

	/**
	 * \brief	The fourth plane.
	 */

	GroundObject* plane4;

	/**
	*\brief the collision height map
	*
	*/
	CollisionHeightMap* GroundCollide;

	/**
	 * \brief	The graphics eng.
	 */

	Graphics* GraphicsEng;
	/**
	*\brief game object list iterator
	*
	*/
	list<GameObject*>::iterator i;

	/**
	 * \brief	The property objects.
	 */

	list<GameObject*> PropObjects;
	/**
	*\brief a prop used for testing
	*
	*/
	GameObject * TestProp;

	/**
	 * \brief	The second rock.
	 */

	GameObject * Rock2;
	/**
	*\brief object that stores the skybox
	*
	*/
	GameObject * Skybox;

	/**
	 * \brief	The knight.
	 */

	AIObject * Knight;
	/**
	*\brief a second knight character
	*
	*/
	AIObject * Knight2;
	/**
	*\briefand enemy ai
	*
	*/
	AIObject* Enemy1;

	/**
	 * \brief	The second enemy.
	 */

	AIObject* Enemy2;
	/**
	*\brief Heightmap storage class
	*
	*/
	HeightMap * Terrain;

	/**
	 * \brief	The counter.
	 */

	int Counter;

	/**
	*\brief Z velocity
	*
	*/
	int VelocityZ;

	/**
	 * \brief	The velocity x coordinate.
	 */

	int VelocityX;

	/**
	*\brief patrol toggle boolean
	*
	*/
	bool Patrol;

	/**
	*\brief vector of prop objects for scenery
	*
	*/
	std::vector<GameObject *> Props;
};

