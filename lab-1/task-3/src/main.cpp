#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.h"

void framebuffer_size_callback(GLFWwindow *window, const int width, const int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (gladLoadGL(glfwGetProcAddress) == 0) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    const Shader shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");

    // Вершины треугольника
    float vertices[] = {
        // Позиции          // Цвета
        0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Верхняя вершина (красный)
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Левая вершина (зеленый)
        0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Правая вершина (синий)
    };

    unsigned int indices[] = {
        0, 1, 2  // Индексы для треугольника
    };

    // Создание VAO, VBO и EBO
    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Привязка VAO
    glBindVertexArray(VAO);

    // Привязка VBO и загрузка данных
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Привязка EBO и загрузка данных
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Настройка указателей на вершины
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  // Вершины

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);  // Цвета

    // Развязываем VAO
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Очистка и завершение
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glfwTerminate();
    return 0;
}
