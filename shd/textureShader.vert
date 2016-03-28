#version 330

#define POSITION	0
#define COLOR		1
#define TEXCOORD	2

layout(location = POSITION) in vec3 position;
layout(location = COLOR)    in vec3 color;
layout(location = TEXCOORD) in vec2 aTexCoord;

out vec2 texcoord;

void main()
{
	gl_Position = vec4(position, 1.0);
	texcoord = aTexCoord;
}
