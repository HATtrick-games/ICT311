/**
 * \file	AIMovement.h
 *
 * \brief	Declares the ai movement class.
**/

#pragma once

#include "Vector2D.h"

/**
 * \def	PI
 *
 * \brief	A macro that defines pi.
**/

#define PI 3.14159265

/**
 * \class	AIMovement
 *
 * \brief	Defines AI movement functions.
**/
class AIMovement
{
public:

	/**
	 * \fn	AIMovement::AIMovement(void)
	 *
	 * \brief	Default constructor.
	**/
	AIMovement(void) {  }

	/**
	 * \fn	AIMovement::~AIMovement(void)
	 *
	 * \brief	Destructor.
	**/
	~AIMovement(void) { };

	/**
	 * \fn	bool AIMovement::MoveTo(Vector2D& currentPosition,
	 * 		const Vector2D& targetPosition, Vector2D& currentVelocity,
	 * 		double timeElapsed, double offset);
	 *
	 * \brief	Given the current position and a target, moves the AI object
	 * 			towards the target.
	 *
	 * \param [in,out]	currentPosition	The current position.
	 * \param	targetPosition		   	Target position.
	 * \param [in,out]	currentVelocity	The current velocity.
	 * \param	timeElapsed			   	The time elapsed.
	 * \param	offset				   	The offset.
	 *
	 * \return	true if it succeeds, false if it fails.
	**/
	bool MoveTo(Vector2D& currentPosition, const Vector2D& targetPosition, 
		Vector2D& currentVelocity, double timeElapsed, double offset);

	/**
	 * \fn	void AIMovement::ChaseTarget(Vector2D& aiObjectXZ,
	 * 		Vector2D& aiObjectVelocity, Vector2D& targetXZ, float timeElapsed);
	 *
	 * \brief	Chase target.
	 *
	 * \param [in,out]	aiObjectXZ			The ai object xz.
	 * \param [in,out]	aiObjectVelocity	The ai object velocity.
	 * \param [in,out]	targetXZ			Target xz.
	 * \param	timeElapsed					The time elapsed.
	**/
	void ChaseTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, float timeElapsed);

	/**
	 * \fn	void AIMovement::PursueTarget(Vector2D& aiObjectXZ,
	 * 		Vector2D& aiObjectVelocity, Vector2D& targetXZ,
	 * 		Vector2D& targetVelocity, float timeElapsed);
	 *
	 * \brief	Pursue target.
	 *
	 * \param [in,out]	aiObjectXZ			The ai object xz.
	 * \param [in,out]	aiObjectVelocity	The ai object velocity.
	 * \param [in,out]	targetXZ			Target xz.
	 * \param [in,out]	targetVelocity  	Target velocity.
	 * \param	timeElapsed					The time elapsed.
	**/
	void PursueTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, Vector2D& targetVelocity, float timeElapsed);

	/**
	 * \fn	bool AIMovement::FleeTarget(Vector2D& aiObjectXZ,
	 * 		Vector2D& aiObjectVelocity, Vector2D& targetXZ,
	 * 		Vector2D& targetVelocity, float fleeSpeed, float panicDistance,
	 * 		float timeElapsed);
	 *
	 * \brief	Flee target.
	 *
	 * \param [in,out]	aiObjectXZ			The ai object xz.
	 * \param [in,out]	aiObjectVelocity	The ai object velocity.
	 * \param [in,out]	targetXZ			Target xz.
	 * \param [in,out]	targetVelocity  	Target velocity.
	 * \param	fleeSpeed					The flee speed.
	 * \param	panicDistance				The panic distance.
	 * \param	timeElapsed					The time elapsed.
	 *
	 * \return	true if it succeeds, false if it fails.
	**/
	bool FleeTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, Vector2D& targetVelocity, float fleeSpeed, float panicDistance, float timeElapsed);

	/**
	 * \fn	bool AIMovement::EvadeTarget(Vector2D& aiObjectXZ,
	 * 		Vector2D& aiObjectVelocity, Vector2D& targetXZ,
	 * 		Vector2D& targetVelocity, float timeElapsed);
	 *
	 * \brief	Evade target.
	 *
	 * \param [in,out]	aiObjectXZ			The ai object xz.
	 * \param [in,out]	aiObjectVelocity	The ai object velocity.
	 * \param [in,out]	targetXZ			Target xz.
	 * \param [in,out]	targetVelocity  	Target velocity.
	 * \param	timeElapsed					The time elapsed.
	 *
	 * \return	true if it succeeds, false if it fails.
	**/
	bool EvadeTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, Vector2D& targetVelocity, float timeElapsed);

	/**
	 * \fn	bool AIMovement::CanSeeTarget(Vector2D& aiObjectXZ,
	 * 		Vector2D& aiObjectVelocity, Vector2D& targetXZ, float coneDistance,
	 * 		float fov);
	 *
	 * \brief	Determine if we can see target.
	 *
	 * \param [in,out]	aiObjectXZ			The ai object xz.
	 * \param [in,out]	aiObjectVelocity	The ai object velocity.
	 * \param [in,out]	targetXZ			Target xz.
	 * \param	coneDistance				The cone distance.
	 * \param	fov							The fov.
	 *
	 * \return	true if we can see target, false if not.
	**/
	bool CanSeeTarget(Vector2D& aiObjectXZ, Vector2D& aiObjectVelocity, Vector2D& targetXZ, float coneDistance, float fov);

	/**
	 * \fn	void AIMovement::SetWander(double radius, double distance,
	 * 		double jitter);
	 *
	 * \brief	Sets a wander.
	 *
	 * \param	radius  	The radius.
	 * \param	distance	The distance.
	 * \param	jitter  	The jitter.
	**/
	void SetWander(double radius, double distance, double jitter);

	/**
	 * \fn	bool AIMovement::Wander(Vector2D& position, Vector2D& velocity,
	 * 		double deltaT);
	 *
	 * \brief	Wanders.
	 *
	 * \param [in,out]	position	The position.
	 * \param [in,out]	velocity	The velocity.
	 * \param	deltaT				The delta t.
	 *
	 * \return	true if it succeeds, false if it fails.
	**/
	bool Wander(Vector2D& position, Vector2D& velocity, double deltaT);
private:
	double radToDeg(double rad);

	Vector2D wanderTarget;  //!< The wander target
	double wanderRadius;	//!< The wander radius
	double wanderDistance;  //!< The wander distance
	double wanderJitter;	//!< The wander jitter

	double RandFloat();
	double RandClamped();
};

