#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 TexCoords;

out vec2 TexCoordinates;

uniform mat4 cameraToClipMatrix;
uniform mat4 ModelToCamera;

void main()
{
	gl_Position =  cameraToClipMatrix * (ModelToCamera * vec4(position,1.0));
	
	TexCoordinates = TexCoords;
}
