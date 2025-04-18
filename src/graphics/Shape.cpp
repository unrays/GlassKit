// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "graphics/Shape.h"

void Shape::initializeShape() {
    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);

    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Shape::setVertices(std::initializer_list<Vertex> vertices) {
    _vertices = vertices;
}

void Shape::drawShape() {
    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
}
