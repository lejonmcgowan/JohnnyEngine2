#version 330

in vec2 texcoord;

uniform sampler2D myTex;

void main()
{
	gl_FragColor = texture(myTex,texcoord);
}
