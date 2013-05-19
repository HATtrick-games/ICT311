
#include"GameObject.h"
#include <math.h> 
class  PlayerObject : public GameObject
{
public:
	PlayerObject();
	PlayerObject(glm::vec3 StartingLocation, glm::vec3 StartingLookAt, glm::vec3 StartingUpVector);
	void Update();
	void MovePlayer(int direction);
	void StopPlayer();
	void RotateRight();
	void RotateLeft();

	glm::vec3 GetLookAt();
	glm::vec3 GetUpVector();

	
protected:
	glm::vec3 LookAtLocation;
	glm::vec3 UpVector;

	
private:
	float angle;
	float lx, lz;
	void SetVectors();
	glm::vec2 ForwardVector;
	glm::vec2 SidewaysVector;
	glm::vec2 DiagonalForwardRightVector;

};