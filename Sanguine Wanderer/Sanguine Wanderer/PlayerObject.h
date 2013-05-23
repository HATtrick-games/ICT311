/**
 * \file	PlayerObject.h
 *
 * \brief	Declares the player object class.
 */

#include"GameObject.h"
#include <math.h> 

/**
 * \class	PlayerObject
 *
 * \brief	Player object.
 *
 * \author	Wise Bear
 * \date	5/23/2013
 */

class  PlayerObject : public GameObject
{
public:
	/**
	*\brief default constructer
	*
	*/
	PlayerObject();

	/**
	*\brief overriden constructer takes in starting locations
	*
	*/
	PlayerObject(glm::vec3 StartingLocation, glm::vec3 StartingLookAt, glm::vec3 StartingUpVector);
	
	/**
	*\brief updates the player 
	*
	*/
	void Update(float y);

	/**
	*\brief moves the player in the direction corresponding to the integer passed in
	*
	*/
	void MovePlayer(int direction);

	/**
	*\brief stops the player
	*
	*/
	void StopPlayer();

	/**
	*\brief rotates the player right
	*
	*/
	void RotateRight();

	/**
	*\brief rotates the player left
	*
	*/
	void RotateLeft();

	/**
	*\brief passes in the mouse location to move the player camera
	*
	*/
	void MouseMove(int x, int y);

	/**
	 * \fn	void PlayerObject::Jump();
	 *
	 * \brief	Jumps this object.
	 *
	 * \author	Wise Bear
	 * \date	5/23/2013
	 */

	void Jump();

	/**
	 * \fn	int PlayerObject::GetHealth()
	 *
	 * \brief	Gets the health.
	 *
	 * \author	Wise Bear
	 * \date	5/23/2013
	 *
	 * \return	The health.
	 */

	int GetHealth(){return Health;};

	/**
	*\brief sets the player health
	*
	*/
	void SetHealth(int set){Health = set;};

	/**
	 * \fn	glm::vec3 PlayerObject::GetLookAt();
	 *
	 * \brief	Gets look at.
	 *
	 * \author	Wise Bear
	 * \date	5/23/2013
	 *
	 * \return	The look at.
	 */

	glm::vec3 GetLookAt();

	/**
	 * \fn	glm::vec3 PlayerObject::GetUpVector();
	 *
	 * \brief	Gets up vector.
	 *
	 * \author	Wise Bear
	 * \date	5/23/2013
	 *
	 * \return	The up vector.
	 */

	glm::vec3 GetUpVector();

	
protected:
	/**
	*\brief location the player is looking at
	*
	*/
	glm::vec3 LookAtLocation;

	/**
	*\brief up vector for player camera
	*
	*/
	glm::vec3 UpVector;

	
private:
	/**
	*\brief Player health
	*
	*/
	int Health;

	/**
	*\brief width of the screen
	*
	*/
	int screenwidth;

	/**
	*\brief height of the screen
	*
	*/
	int screenheight;

	/**
	 * \brief	The xorigin.
	 */

	int xorigin;

	/**
	*\brief y value of camera origin
	*
	*/
	int yorigin;

	/**
	 * \brief	The windowx.
	 */

	int windowx;

	/**
	*\brief the window y
	*
	*/
	int windowy;

	/**
	 * \brief	The angle.
	 */

	float angle;

	/**
	*\brief angle used to rotate camera up
	*
	*/
	float yangle;

	/**
	 * \property	float lx, lz,ly
	 *
	 * \brief	Gets the ly.
	 *
	 * \return	The ly.
	 */

	float lx, lz,ly;

	/**
	*\brief sets all the movement vectors relative to the vector between player pos and look at
	*
	*/
	void SetVectors();

	/**
	 * \brief	The forward vector.
	 */

	glm::vec2 ForwardVector;

	/**
	*\brief the sideways vector
	*
	*/
	glm::vec2 SidewaysVector;

	/**
	 * \brief	The diagonal forward right vector.
	 */

	glm::vec2 DiagonalForwardRightVector;

	/**
	*\brief the diagonal forward left vector
	*
	*/
	glm::vec2 DiagonalForwardLeftVector;

};