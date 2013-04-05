#version 330

in vec4 position;
in vec2 fragTexCoord;

out vec4 outputColor;

uniform vec3 Offset;
uniform mat4 PerspectiveMatrix;

uniform sampler2D tex;

void main()
{
	vec4 cameraPos = position + vec4(Offset.x, Offset.y, Offset.z, 0.0);
	gl_Position = PerspectiveMatrix * cameraPos;
	outputColor = texture(tex, fragTexCoord);
}
