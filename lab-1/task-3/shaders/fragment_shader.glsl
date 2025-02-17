#version 460 core

in vec3 ourColor;  // Цвет, полученный из вершинного шейдера

out vec4 FragColor;  // Выходной цвет фрагмента

void main() {
    FragColor = vec4(ourColor, 1.0);  // Устанавливаем окончательный цвет фрагмента
}
