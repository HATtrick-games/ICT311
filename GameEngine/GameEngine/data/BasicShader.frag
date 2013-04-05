#version 330

layout(location = 0) in vec4 position;

out vec4 outputColor;

uniform vec3 Offset;
uniform mat4 PerspectiveMatrix;

void main()
{
	vec4 cameraPos = position + vec4(Offset.x, Offset.y, Offset.z, 0.0);
	gl_Position = PerspectiveMatrix * cameraPos;
	outputColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
