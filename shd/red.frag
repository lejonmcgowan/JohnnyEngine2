#version 330 core

in vec2 vPosition;
in vec4 vColor;

uniform vec2 lightPos;

void main()
{
    float intensity = 0.1 / length(vPosition - lightPos);
	gl_FragColor = intensity * vColor;
}
