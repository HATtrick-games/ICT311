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
	Animation(void);
	~Animation(void);

	void AddAnimation(Mesh * Keyframe, AnimationType Type);

private:
	std::vector<Mesh*> Walk;

	std::vector<GLuint> VertexBufferObject;
	std::vector<GLuint> VAO;
	std::vector<GLuint> IndexBufferObject;
	std::vector<GLuint> TexBuffer;

	int Index;

	bool BoolWalk;
	bool BoolAttack;
};

