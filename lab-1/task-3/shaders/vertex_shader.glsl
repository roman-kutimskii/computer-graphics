#version 460 core

layout (location = 0) in vec3 aPos;  // Входные данные - вершины
layout (location = 1) in vec3 aColor;  // Входные данные - цвет

out vec3 ourColor;  // Передаем цвет в фрагментный шейдер

void main() {
    gl_Position = vec4(aPos, 1.0);  // Трансформация позиции вершины
    ourColor = aColor;  // Передача цвета во фрагментный шейдер
}
