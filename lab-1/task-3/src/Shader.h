#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <glad/gl.h>

class Shader {
public:
    Shader(const std::string &vertexPath, const std::string &fragmentPath) {
        const auto vertexSource = readFile(vertexPath);
        const auto fragmentSource = readFile(fragmentPath);

        shaderProgram = createShaderProgram(vertexSource, fragmentSource);
    }

    ~Shader() {
        glDeleteProgram(shaderProgram);
    }

    void use() const {
        glUseProgram(shaderProgram);
    }

private:
    GLuint shaderProgram;

    std::string readFile(const std::string &filePath) {
        const std::ifstream file(filePath);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    GLuint compileShader(const std::string &source, GLenum shaderType) {
        const GLuint shader = glCreateShader(shaderType);
        const char *shaderSource = source.c_str();
        glShaderSource(shader, 1, &shaderSource, nullptr);
        glCompileShader(shader);

        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "Shader compilation failed: " << infoLog << std::endl;
        }

        return shader;
    }

    GLuint createShaderProgram(const std::string &vertexSource, const std::string &fragmentSource) {
        const GLuint vertexShader = compileShader(vertexSource, GL_VERTEX_SHADER);
        const GLuint fragmentShader = compileShader(fragmentSource, GL_FRAGMENT_SHADER);

        const GLuint program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        GLint success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(program, 512, nullptr, infoLog);
            std::cerr << "Shader program linking failed: " << infoLog << std::endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return program;
    }
};

#endif //SHADER_H
