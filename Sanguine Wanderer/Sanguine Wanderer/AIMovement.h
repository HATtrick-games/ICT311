#pragma once
class AIMovement
{
public:
	AIMovement(void);
	~AIMovement(void);

	bool MoveTo(glm::vec3& currentPosition, const glm::vec3& targetPosition, 
		glm::vec3& currentVelocity, double timeElapsed, double offset);


};

