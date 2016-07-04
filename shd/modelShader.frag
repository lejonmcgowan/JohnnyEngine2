#version 330 core

in vec2 TexCoords;

out vec4 color;

uniform sampler2D diffuseTexture1;

void main()
{
    color = vec4(texture(diffuseTexture1, TexCoords));
}