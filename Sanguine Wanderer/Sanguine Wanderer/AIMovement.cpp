#include "StdAfx.h"
#include "AIMovement.h"

bool AIMovement::MoveTo(Vector2D& currentPosition, 
	const Vector2D& targetPosition, Vector2D& currentVelocity,
	double timeElapsed, double offset)
{
	// calculate the heading from current position to target
	Vector2D toTarget = targetPosition - currentPosition;
	// normalise the vector
	toTarget.Normalize();
	if(toTarget.IsZero())
	{
		return true;
	}

	// calculate the new velocity and new character position
	currentVelocity = toTarget * currentVelocity.Length();
	Vector2D displacement = currentVelocity * timeElapsed;
	Vector2D newPosition = currentPosition + displacement;

	// calculate real target position
	Vector2D realTargetPosition = targetPosition - toTarget * offset;

	// calculate the direction from new position to real target position
	Vector2D toRealTarget = realTargetPosition - newPosition;
	toRealTarget.Normalize();
	if(toRealTarget.IsZero())
	{
		currentPosition = realTargetPosition;
		return true;
	}

	float dp = toRealTarget.Dot(toTarget);
	if(dp < 0.0)
	{
		currentPosition = realTargetPosition;
		return true;
	}

	currentPosition = newPosition;
	return false;
}

void AIMovement::ChaseTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, float timeElapsed)
{
	MoveTo(aiObjectXZ, targetXZ, aiObjectVelocity, timeElapsed, 0);
}

void AIMovement::PursueTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, Vector2D& targetVelocity, float timeElapsed)
{
	double lookAheadTime;

	Vector2D toTarget = targetXZ - aiObjectXZ;

	Vector2D targetHeading = targetVelocity;
	targetHeading.Normalize();
	Vector2D aiObjectHeading = aiObjectVelocity;
	aiObjectHeading.Normalize();

	double relativeHeading = targetHeading.Dot(aiObjectHeading);

	if((toTarget.Dot(targetHeading) > 0) && relativeHeading < -0.95)
	{
		MoveTo(aiObjectXZ, targetXZ, aiObjectVelocity, timeElapsed, 0);
	}
	else
	{
		lookAheadTime = (toTarget.Length())/(targetVelocity.Length() + aiObjectVelocity.Length());
		MoveTo(aiObjectXZ, targetXZ + targetVelocity * lookAheadTime, aiObjectVelocity, timeElapsed, 0);
	}
}

bool AIMovement::FleeTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, Vector2D& targetVelocity, float fleeSpeed, float panicDistance, float timeElapsed)
{
	Vector2D fromTarget = aiObjectXZ - targetXZ;
	
	if(fromTarget.Length() > panicDistance)
	{
		return false;
	}

	fromTarget.Normalize();
	aiObjectVelocity = fromTarget * fleeSpeed;
	aiObjectXZ += aiObjectVelocity * timeElapsed;
	return true;
}

bool AIMovement::EvadeTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, Vector2D& targetVelocity, float timeElapsed)
{
	Vector2D toTarget = targetXZ - aiObjectXZ;

	double lookAheadTime = toTarget.Length() / (aiObjectVelocity.Length() + targetVelocity.Length());
	return (FleeTarget(aiObjectXZ, aiObjectVelocity, targetXZ + targetVelocity * lookAheadTime, targetVelocity, 10.0f, targetVelocity.Length(), timeElapsed));
}

bool AIMovement::CanSeeTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, float coneDistance, float fov)
{
	Vector2D toTarget = targetXZ - aiObjectXZ;

	float distance = toTarget.Length();

	if(distance > coneDistance)
		return false;

	toTarget.Normalize();
	Vector2D aiHeading = aiObjectVelocity;
	aiHeading.Normalize();

	double angle = (double)aiHeading.Dot(toTarget);
	if(angle > 1.0)
		angle = 1.0;
	else if(angle < -1.0)
		angle = -1.0;

	angle = radToDeg(acos(angle));

	if(angle <= (fov/2))
		return true;

	return false;
}

void AIMovement::SetWander(double radius, double distance, double jitter)
{
	wanderRadius = radius;
	wanderDistance = distance;
	wanderJitter = jitter;
	double theta = ((rand() / (RAND_MAX + 1.0)) * (2 * PI));
	wanderTarget.Set(wanderRadius * cos(theta), wanderRadius * sin(theta));
}

bool AIMovement::Wander(Vector2D& position, Vector2D& velocity, double deltaT)
{
	double jitterTimeSlice = wanderJitter * deltaT;
	
	wanderTarget += Vector2D(RandClamped() * jitterTimeSlice, RandClamped() * jitterTimeSlice);
	wanderTarget.Normalize();

	Vector2D heading = velocity;
	heading.Normalize();
	
	Vector2D wanderCircleWorldCenter = position + (heading * wanderDistance);
	Vector2D targetWorld = wanderCircleWorldCenter + (wanderTarget * wanderRadius);
	MoveTo(position, targetWorld, velocity, deltaT, 0);
	return true;
}

double AIMovement::radToDeg(double rad)
{
	rad *= 180.0 / PI;
	return rad;
}

double AIMovement::RandFloat()
{
	return (rand() / (RAND_MAX + 1.0));
}

double AIMovement::RandClamped()
{
	return RandFloat() - RandFloat();
}