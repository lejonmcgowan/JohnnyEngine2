#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 model = mat4(1.0), view = mat4(1.0), projection = mat4(1.0);

out vec2 vPosition;
out vec4 vColor;

void main()
{
    vColor = color;
    vPosition = vec2(model * vec4(position,1.0f));
    gl_Position = projection * view * model * vec4(position,1.0f);
}