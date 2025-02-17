#ifndef SHADER_H
#define SHADER_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Shader {
public:
    GLuint ID;

    Shader(const std::string &vertexFile, const std::string &fragmentFile) {
        const std::string vertexCode = getFileContents(vertexFile);
        const std::string fragmentCode = getFileContents(fragmentFile);

        const GLuint vertexShader = compileShader(vertexCode, GL_VERTEX_SHADER);
        const GLuint fragmentShader = compileShader(fragmentCode, GL_FRAGMENT_SHADER);

        ID = glCreateProgram();
        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void activate() const {
        glUseProgram(ID);
    }

    void remove() const {
        glDeleteProgram(ID);
    }

private:
    [[nodiscard]] static std::string getFileContents(const std::string &filename) {
        std::ifstream in(filename);
        if (!in.is_open()) {
            throw std::runtime_error("Failed to open shader file: " + filename);
        }

        std::ostringstream buffer;
        buffer << in.rdbuf();
        return buffer.str();
    }

    [[nodiscard]] static GLuint compileShader(const std::string &source, GLenum type) {
        const GLuint shader = glCreateShader(type);
        const char *sourceCStr = source.c_str();
        glShaderSource(shader, 1, &sourceCStr, nullptr);
        glCompileShader(shader);
        checkCompileErrors(shader, type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT");
        return shader;
    }

    static void checkCompileErrors(const GLuint shader, const std::string &type) {
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM") {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
                std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n";
            }
        } else {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
                std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n";
            }
        }
    }
};

#endif //SHADER_H
