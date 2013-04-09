#version 330

uniform sampler2D tex;

in vec2 TexCoords;

out vec4 outputColor;

void main()
{

	outputColor = texture(tex,TexCoords);
}
