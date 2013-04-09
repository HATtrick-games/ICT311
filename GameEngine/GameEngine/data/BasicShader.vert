#version 330

layout(location = 0) in vec4 position;

smooth out vec4 theColor;

uniform mat4 cameraToClipMatrix;
uniform mat4 ModelToWorld;
uniform mat4 WorldToCamera;
uniform vec4 ColorOffset;

void main()
{
	vec4 Temp =  ModelToWorld * position;
	Temp = WorldToCamera * Temp;
	gl_Position = cameraToClipMatrix * Temp;
	
	theColor;
	
	// Pass the texture coordinates straight through to the frag shader


}
