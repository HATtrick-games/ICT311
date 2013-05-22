#pragma once

#include "Vector2D.h"
#define PI 3.14159265

class AIMovement
{
public:
	AIMovement(void) {  }
	~AIMovement(void) { };
	
	bool MoveTo(Vector2D& currentPosition, const Vector2D& targetPosition, 
		Vector2D& currentVelocity, double timeElapsed, double offset);

	void ChaseTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, float timeElapsed);

	void PursueTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, Vector2D& targetVelocity, float timeElapsed);

	bool FleeTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, Vector2D& targetVelocity, float fleeSpeed, float panicDistance, float timeElapsed);

	bool EvadeTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, Vector2D& targetVelocity, float timeElapsed);

	bool CanSeeTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, float coneDistance, float fov);

	void SetWander(double radius, double distance, double jitter);

	bool Wander(Vector2D& position, Vector2D& velocity, double deltaT);
private:
	double radToDeg(double rad);

	Vector2D wanderTarget;
	double wanderRadius;
	double wanderDistance;
	double wanderJitter;

	double RandFloat();
	double RandClamped();
};

