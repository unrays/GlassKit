// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "graphics/Vertex.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "graphics/Shader.h"

class Shape {
    private:
	    GLuint _VBO, _VAO, _EBO;
        GLuint _vertexCount;

        std::vector<Vertex> _vertices;

    public:    
        ~Shape() {
            glDeleteBuffers(1, &_VBO);
            glDeleteVertexArrays(1, &_VAO);
            glDeleteBuffers(1, &_EBO);
        }

        void initializeShape();
        void setVertices(std::initializer_list<Vertex> vertices);
        void drawShape(Shader shader);
};