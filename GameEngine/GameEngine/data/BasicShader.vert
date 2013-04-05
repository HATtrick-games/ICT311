#version 330

layout(location = 0) in vec4 position;
in vec2 vertTexCoord;

out vec2 fragTexCoord;

void main()
{
	// Pass the texture coordinates straight through to the frag shader
	fragTexCoord = vertTexCoord;

	gl_Position = position;
}
