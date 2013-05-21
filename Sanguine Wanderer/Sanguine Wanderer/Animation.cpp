#include "StdAfx.h"
#include "Animation.h"


Animation::Animation(void)
{
	Index = 0;
	VertexBufferObject.resize(20);
	IndexBufferObject.resize(20);
	VAO.resize(20);
	TexBuffer.resize(20);
}


Animation::~Animation(void)
{
}

void Animation::AddAnimation(Mesh* Keyframe, AnimationType Type)
{
	if(Type == TWalk)
	{
		Walk.push_back(Keyframe);
		if(VAO[Index] == 0)
		{
			//glUseProgram((*OpenGL::GetInstance())->GetGraphics());
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
		}
	}
}
