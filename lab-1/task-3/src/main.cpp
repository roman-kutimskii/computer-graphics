#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Buffer.h"
#include "Shader.h"

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

    GLfloat vertices[] = {
        -0.5f, 0.5f, 0.0f, 0.0f, 128 / 255.0f, 255 / 255.0f,
        0.5f, 0.5f, 0.0f, 255 / 255.0f, 0 / 255.0f, 0 / 255.0f,
        0.5f, -0.5f, 0.0f, 0 / 255.0f, 153 / 255.0f, 0 / 255.0f,
        -0.5f, -0.5f, 0.0f, 255 / 255.0f, 255 / 255.0f, 51 / 255.0f
    };

    GLuint indexes[] = {
        0, 1, 2, 3
    };

    const Shader shader("shaders/vertex.glsl", "shaders/fragment.glsl");

    VAO vao;
    vao.bind();
    VBO vbo(vertices, sizeof(vertices));
    const EBO ebo(indexes, sizeof(indexes));
    vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *) nullptr);
    vao.linkAttrib(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), reinterpret_cast<void *>(3 * sizeof(float)));
    vao.unbind();
    vbo.unbind();
    ebo.unbind();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        vao.bind();

        glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    vao.remove();
    vbo.remove();
    ebo.remove();

    glfwTerminate();
    return 0;
}
