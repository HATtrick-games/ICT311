/**
 * \file	Animation.h
 *
 * \brief	Declares the animation class.
 */

#pragma once
#include "stdafx.h"
#include "Mesh.h"
#include "TextureLoader.h"

/**
 * \enum	AnimationType
 *
 * \brief	Values that represent AnimationType.
 */

enum AnimationType 
{
	TWalk = 0, 
	///< An enum constant representing the attack option
	TAttack = 1
};

/**
 * \class	Animation
 *
 * \brief	Animation.
 *
 * \author	Chaokel
 * \date	23/05/2013
 */

class Animation
{
public:

	/**
	 * \fn	Animation::Animation(GLuint Program);
	 *
	 * \brief	Constructor.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param	Program	The program.
	 */

	Animation(GLuint Program);

	/**
	 * \fn	Animation::~Animation(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 */

	~Animation(void);

	/**
	 * \fn	void Animation::AddAnimation(Mesh * Keyframe, AnimationType Type);
	 *
	 * \brief	Adds a keyframe of TYPE walk/attack to the animation buffer.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param [in,out]	Keyframe	If non-null, the keyframe.
	 * \param	Type				The type.
	 */

	void AddAnimation(Mesh * Keyframe, AnimationType Type);

	/**
	 * \fn	bool Animation::GetBoolWalk();
	 *
	 * \brief	checks if walk animation is available.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool GetBoolWalk();

	/**
	 * \fn	bool Animation::GetBoolAttack();
	 *
	 * \brief	checks if attack animation available.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool GetBoolAttack();

	/**
	 * \fn	int Animation::GetCurrentFrame();
	 *
	 * \brief	Gets current frame.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \return	The current frame.
	 */

	int GetCurrentFrame();

	/**
	 * \fn	void Animation::SetCurrentFrame(int newFrame)
	 *
	 * \brief	Sets current frame.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param	newFrame	The new frame.
	 */

	void SetCurrentFrame(int newFrame){CurrentFrame = newFrame;}

	/**
	 * \fn	Mesh * Animation::GetWalk(int Frame);
	 *
	 * \brief	Gets a walk.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param	Frame	The frame.
	 *
	 * \return	null if it fails, else the walk.
	 */

	Mesh * GetWalk(int Frame);

	/**
	 * \fn	int Animation::GetTotalFrames();
	 *
	 * \brief	Gets total frames of animation.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \return	The total frames.
	 */

	int GetTotalFrames();

	/**
	 * \fn	float Animation::GetTime();
	 *
	 * \brief	Gets the time since last animation.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \return	The time.
	 */

	float GetTime();

	/**
	 * \fn	bool Animation::GetPreviousAnimations();
	 *
	 * \brief	Checks if it has been previously animating.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool GetPreviousAnimations();

	/**
	 * \fn	void Animation::SetPreviousAnimations(bool Toggle);
	 *
	 * \brief	Sets previous animations.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param	Toggle	true to toggle.
	 */

	void SetPreviousAnimations(bool Toggle);
	void SetTime(float newTime);
	void IncrementCurrentFrame();
	void ResetCurrentFrame();
	void ToggleBoolWalk();
	void ToggleBoolAttack();

private:
	std::map<int, Mesh*> Walk;

	std::vector<GLuint> VertexBufferObject;

	/**
	 * \brief	The vao.
	 */

	std::vector<GLuint> VAO;
	std::vector<GLuint> IndexBufferObject;

	/**
	 * \brief	Buffer for tex data.
	 */

	std::vector<GLuint> TexBuffer;

	int Index;

	/**
	 * \brief	The current frame.
	 */

	int CurrentFrame;
	int TotalFrames;

	/**
	 * \brief	The time.
	 */

	float Time;

	GLuint Prog;

	/**
	 * \brief	true to walk.
	 */

	bool BoolWalk;
	bool BoolAttack;

	/**
	 * \brief	true to previous animations.
	 */

	bool PreviousAnimations;
};

