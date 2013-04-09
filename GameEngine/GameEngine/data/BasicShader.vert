#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 TexCoords;

out vec2 TexCoordinates;

uniform mat4 cameraToClipMatrix;
uniform mat4 ModelToCamera;
uniform vec4 ColorOffset;

void main()
{
	vec4 Temp =  ModelToCamera * position;
	gl_Position = cameraToClipMatrix * Temp;
	
	TexCoordinates = TexCoords;
	
	// Pass the texture coordinates straight through to the frag shader


}
