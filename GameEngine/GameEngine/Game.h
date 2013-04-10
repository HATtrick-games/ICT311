#pragma once

#include "AssetManager.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "Graphics.h"
#include "GameSettings.h"
#include "GraphicsEngFact.h"
#include "CommonFuncs.h"
#include "Input.h"
#include "ScriptingEngine.h"
#include "CollisionWorldSingleton.h"

#include <iostream>

#include <boost\smart_ptr.hpp>

typedef std::map<std::string, GameObject*>::iterator objectMapIterator;

/**
 * \class	Game
 *
 * \brief	Sets up the game and implements the engine functions.
 * 			
 * \author Hamish Carrier, Timothy Veletta, Arran Ford
 */
class Game 
{
public:

	/**
	 * \fn	Game::Game(void);
	 *
	 * \brief	Default constructor.
	 */
	Game(void);

	/**
	 * \fn	Game::~Game(void);
	 *
	 * \brief	Destructor.
	 */
	~Game(void);

	/**
	 * \fn	void Game::Initialise();
	 *
	 * \brief	Initialises this object.
	 */
	void Initialise();

	/**
	 * \fn	void Game::LoadResources();
	 *
	 * \brief	Loads the resources.
	 */
	void LoadResources();

	/**
	 * \fn	void Game::UnloadResources();
	 *
	 * \brief	Unload resources.
	 */
	void UnloadResources();

	/**
	 * \fn	void Game::Update(float time);
	 *
	 * \brief	Updates all the objects within the scene.
	 *
	 * \param	time	The time.
	 */
	void Update(float time);

	/**
	 * \fn	void Game::Draw();
	 *
	 * \brief	Draws all the objects within the scene.
	 */
	void Draw();

	/**
	 * \fn	static boost::scoped_ptr<Game> * Game::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \return	null if it fails, else the instance.
	 */
	static boost::scoped_ptr<Game> * GetInstance();

	/**
	 * \fn	void Game::AddGameObject(std::string id, GameObject* obj);
	 *
	 * \brief	Adds a game object to map of game objects.
	 *
	 * \param	id		   	The identifier.
	 * \param [in,out]	obj	If non-null, the object.
	 */
	void AddGameObject(std::string id, GameObject* obj);

	/**
	 * \fn	void Game::RemoveGameObject(std::string id);
	 *
	 * \brief	Removes the game object described by ID.
	 *
	 * \param	id	The identifier.
	 */
	void RemoveGameObject(std::string id);

private:
	boost::scoped_ptr<Graphics>* pGraphicsEng;

	static boost::scoped_ptr<Game> pGame;   //!< The game

	std::map<std::string, GameObject*> mGameObjects;	//!< The game objects

	/*** DELETE UPON COMPLETE ***/
	GameObject* testObject;
	PlayerObject* Camera;
	GameObject* testObject1;
	Mesh* boxMesh;
	Mesh* boxMesh1;
	Mesh* boxMesh2;
};
/*
int main(int argc, char** argv)
{
	(*Game::GetInstance())->Initialise();
}*/