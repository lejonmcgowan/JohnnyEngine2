#version 330 core

layout(location = 0) in vec3 position;
uniform mat4 model = mat4(1.0), view = mat4(1.0), projection = mat4(1.0);

out vec2 vPosition;
void main()
{
    vPosition = vec2(position);
    gl_Position = projection * view * model * vec4(position,1.0f);
}