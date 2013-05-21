
#include"GameObject.h"
#include <math.h> 
class  GroundObject : public GameObject
{
public: 
	GroundObject(){};
	void InitialiseCollisionBody(glm::vec3 Pos);
protected:
private:
};