
#include"GameObject.h"

class  PlayerObject : public GameObject
{
public:
	PlayerObject();
	PlayerObject(glm::vec3 StartingLocation, glm::vec3 StartingLookAt, glm::vec3 StartingUpVector);
	void Update();
	void MovePlayer(int direction);
	void StopPlayer(int direction);
protected:
	glm::vec3 LookAtLocation;
	glm::vec3 UpVector;

	
private:

};