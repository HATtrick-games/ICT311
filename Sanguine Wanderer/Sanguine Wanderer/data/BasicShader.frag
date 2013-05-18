#version 330

in vec2 texture_coordinate;

uniform sampler2D tex;

void main()
{
	//gl_FragColor = texture2D(tex,texture_coordinate);
	gl_FragColor = vec4(texture_coordinate, 0,1);
}
