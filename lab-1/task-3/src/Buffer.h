#ifndef BUFFER_H
#define BUFFER_H

#include <glad/gl.h>

class VBO {
public:
    GLuint ID;

    VBO(GLfloat *vertices, GLsizeiptr size) {
        glGenBuffers(1, &ID);
        bind();
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    void bind() {
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }

    void unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void remove() {
        glDeleteBuffers(1, &ID);
    }
};

class VAO {
public:
    GLuint ID;

    VAO() {
        glGenVertexArrays(1, &ID);
    }

    void linkAttrib(VBO vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, GLvoid *offset) {
        vbo.bind();
        glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(layout);
        vbo.unbind();
    }

    void bind() {
        glBindVertexArray(ID);
    }

    void unbind() {
        glBindVertexArray(0);
    }

    void remove() {
        glDeleteVertexArrays(1, &ID);
    }
};

class EBO {
public:
    GLuint ID;

    EBO(GLuint *indices, GLsizeiptr size) {
        glGenBuffers(1, &ID);
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    }

    void bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    }

    void unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void remove() const {
        glDeleteBuffers(1, &ID);
    }
};

#endif //BUFFER_H
