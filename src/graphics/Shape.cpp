#include "graphics/Shape.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <graphics/Shader.h>

void Shape::initializeShape() {
    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);

    glBindVertexArray(_VAO);

    glGenBuffers(1, &_EBO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), _vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, _coordinates));
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, _color)); // Besoin de shaders

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
}

void Shape::setVertices(std::initializer_list<Vertex> vertices) {
    _vertices = vertices;
}

void Shape::drawShape(Shader shader) {
    shader.use();

    glBindVertexArray(_VAO);

    glDrawArrays(GL_TRIANGLE_FAN, 0, _vertices.size());

    glBindVertexArray(0);
}
