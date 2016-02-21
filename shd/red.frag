#version 330 core

in vec2 vPosition;

uniform vec2 lightPos;

void main()
{
    float intensity = 100.0 / length(lightPos - gl_FragCoord.xy);
	gl_FragColor = /*intensity * */ vec4(1.0, 0.0, 0.0, 1.0);
}
