#include "StdAfx.h"
#include "Animation.h"


Animation::Animation(GLuint Program)
{
	Index = 0;
	CurrentFrame = 0;
	TotalFrames = 0;
	Time = 0;
	PreviousAnimations = false;

	VertexBufferObject.resize(20);
	IndexBufferObject.resize(20);
	VAO.resize(20);
	TexBuffer.resize(20);
	Prog = Program;
}


Animation::~Animation(void)
{
}

void Animation::AddAnimation(Mesh* Keyframe, AnimationType Type)
{
	if(Type == TWalk)
	{
		Walk[Index] = Keyframe;
		TotalFrames++;
		Index++;
		/*if(VAO[Index] == 0)
		{
			glUseProgram(Prog);
			VertexBufferObject.push_back(0);
			IndexBufferObject.push_back(0);
			VAO.push_back(0);
			TexBuffer.push_back(0);

			glGenVertexArrays(1, &VAO[Index]);
			glGenBuffers(1, &VertexBufferObject[Index]);
			glGenBuffers(1, &TexBuffer[Index]);

			glBindVertexArray(VAO[Index]);

			glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject[Index]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(Keyframe->GetNumVert()), Keyframe->GetVertexArray(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
				
			glBindBuffer(GL_ARRAY_BUFFER, TexBuffer[Index]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(Keyframe->GetNumTextures()), Keyframe->GetUVArray(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
			(*TextureLoader::GetInstance())->Load(Keyframe->GetTexPath(), Index);
		
			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
			glBindVertexArray(0);
			glUseProgram(0);
			
		}*/
	}
}

bool Animation::GetBoolWalk()
{
	return BoolWalk;
}

bool Animation::GetBoolAttack()
{
	return BoolAttack;
}

void Animation::ToggleBoolWalk()
{
	BoolWalk = !BoolWalk;
}

void Animation::ToggleBoolAttack()
{
	BoolAttack = !BoolAttack;
}

int Animation::GetCurrentFrame()
{
	return CurrentFrame;
}

void Animation::IncrementCurrentFrame()
{
	CurrentFrame++;
}

void Animation::ResetCurrentFrame()
{
	CurrentFrame = 0;
}

Mesh* Animation::GetWalk(int Frame)
{
	return Walk[Frame];
}

int Animation::GetTotalFrames()
{
	return TotalFrames;
}

float Animation::GetTime()
{
	return Time;
}

void Animation::SetTime(float newTime)
{
	Time = newTime;
}

bool Animation::GetPreviousAnimations()
{
	return PreviousAnimations;
}

void Animation::SetPreviousAnimations(bool Toggle)
{
	PreviousAnimations = Toggle;
}