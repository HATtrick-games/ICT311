#version 330

layout(location = 0) in vec4 position;

smooth out vec4 theColor;

uniform vec3 Offset;
uniform mat4 cameraToClipMatrix;

void main()
{
	vec4 cameraPos = position + vec4(Offset.x, Offset.y, Offset.z, 0.0);
	gl_Position = cameraToClipMatrix * cameraPos;
	
	theColor = vec4(1.0,0.0,0.0,0.0);
	
	// Pass the texture coordinates straight through to the frag shader


}
