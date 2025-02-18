#version 460 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColor;

out vec3 color;

void main() {
    gl_Position = vec4(aPos, 0.f, 1.f);
    color = aColor;
}
