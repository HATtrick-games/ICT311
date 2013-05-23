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
	void Input();
	void Update();
	void MouseMove(int x, int y);
	void InitialiseProps();

	static boost::scoped_ptr<Game> * GetInstance();

private:
	static boost::scoped_ptr<Game> pSingleton;
	boost::scoped_ptr<Graphics> *pGraphicsEng;

	/**
	 * \brief	The player.
	 */

	PlayerObject* Player;
	GameObject* Obj;

	/**
	 * \brief	The plane.
	 */

	GroundObject* plane;
	GroundObject* plane1;

	/**
	 * \brief	The second plane.
	 */

	GroundObject* plane2;
	GroundObject* plane3;

	/**
	 * \brief	The fourth plane.
	 */

	GroundObject* plane4;
	CollisionHeightMap* GroundCollide;

	/**
	 * \brief	The graphics eng.
	 */

	Graphics* GraphicsEng;
	list<GameObject*>::iterator i;

	/**
	 * \brief	The property objects.
	 */

	list<GameObject*> PropObjects;
	GameObject * TestProp;

	/**
	 * \brief	The second rock.
	 */

	GameObject * Rock2;
	GameObject * Skybox;

	/**
	 * \brief	The knight.
	 */

	AIObject * Knight;
	AIObject * Knight2;
	AIObject* Enemy1;

	/**
	 * \brief	The second enemy.
	 */

	AIObject* Enemy2;
	HeightMap * Terrain;

	/**
	 * \brief	The counter.
	 */

	int Counter;
	int VelocityZ;

	/**
	 * \brief	The velocity x coordinate.
	 */

	int VelocityX;

	bool Patrol;
	std::vector<GameObject *> Props;
};

