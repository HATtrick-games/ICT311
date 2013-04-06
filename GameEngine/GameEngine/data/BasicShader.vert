#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 color;

smooth vec2 colorOut;

uniform vec3 Offset;
uniform mat4 PerspectiveMatrix;

void main()
{
	vec4 cameraPos = position + vec4(Offset.x, Offset.y, Offset.z, 0.0);
	gl_Position = PerspectiveMatrix * cameraPos;
	
	
	// Pass the texture coordinates straight through to the frag shader
	colorOut = color;

}
