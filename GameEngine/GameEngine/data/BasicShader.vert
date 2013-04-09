#version 330

layout(location = 0) in vec4 position;

smooth out vec4 theColor;

uniform mat4 cameraToClipMatrix;
uniform mat4 ModelToCamera;
uniform vec4 ColorOffset;

void main()
{
	vec4 cameraPos =  ModelToCamera * position;
	gl_Position = cameraToClipMatrix * cameraPos;
	
	theColor;
	
	// Pass the texture coordinates straight through to the frag shader


}
