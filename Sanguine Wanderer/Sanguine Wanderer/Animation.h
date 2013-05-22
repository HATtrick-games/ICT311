#pragma once
#include "stdafx.h"
#include "Mesh.h"
#include "TextureLoader.h"

enum AnimationType 
{
	TWalk = 0, 
	TAttack = 1
};

class Animation
{
public:
	Animation(GLuint Program);
	~Animation(void);

	void AddAnimation(Mesh * Keyframe, AnimationType Type);

	bool GetBoolWalk();
	bool GetBoolAttack();
	int GetCurrentFrame();
	void SetCurrentFrame(int newFrame){CurrentFrame = newFrame;}
	Mesh * GetWalk(int Frame);
	int GetTotalFrames();
	float GetTime();
	bool GetPreviousAnimations();

	void SetPreviousAnimations(bool Toggle);
	void SetTime(float newTime);
	void IncrementCurrentFrame();
	void ResetCurrentFrame();
	void ToggleBoolWalk();
	void ToggleBoolAttack();

private:
	std::map<int, Mesh*> Walk;

	std::vector<GLuint> VertexBufferObject;
	std::vector<GLuint> VAO;
	std::vector<GLuint> IndexBufferObject;
	std::vector<GLuint> TexBuffer;

	int Index;
	int CurrentFrame;
	int TotalFrames;
	float Time;

	GLuint Prog;
	bool BoolWalk;
	bool BoolAttack;
	bool PreviousAnimations;
};

