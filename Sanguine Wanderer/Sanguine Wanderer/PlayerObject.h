
#include"GameObject.h"
#include <math.h> 
class  PlayerObject : public GameObject
{
public:
	PlayerObject();
	PlayerObject(glm::vec3 StartingLocation, glm::vec3 StartingLookAt, glm::vec3 StartingUpVector);
	void Update(int y);
	void MovePlayer(int direction);
	void StopPlayer();
	void RotateRight();
	void RotateLeft();
	void MouseMove(int x, int y);
	void Jump();
	int GetHealth(){return Health;};
	void SetHealth(int set){Health = set;};

	
	glm::vec3 GetLookAt();
	glm::vec3 GetUpVector();

	
protected:
	glm::vec3 LookAtLocation;
	glm::vec3 UpVector;

	
private:
	int Health;
	int screenwidth;
	int screenheight;
	int xorigin;
	int yorigin;
	int windowx;
	int windowy;
	float angle;
	float yangle;
	float lx, lz,ly;
	void SetVectors();
	glm::vec2 ForwardVector;
	glm::vec2 SidewaysVector;
	glm::vec2 DiagonalForwardRightVector;
	glm::vec2 DiagonalForwardLeftVector;

};