#pragma once
#include "engine.h"

#include <boost\smart_ptr.hpp>

/**
 * \class	Game
 *
 * \brief	Sets up the game and implements the engine functions.
 */
class Game :
	public Engine
{
public:
	Game(void);
	~Game(void);

	virtual void Initialise();

	virtual void LoadResources();

	virtual void UnloadResources();

	virtual void Update(float time);

	virtual void Draw(float time);

private:
};

int main(int argc, char** argv)
{
	boost::scoped_ptr<Game> pGame;
	pGame.reset(new Game());
	pGame->Initialise();
}