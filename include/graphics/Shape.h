// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "graphics/Vertex.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

class Shape {
    private:
	    unsigned int _VBO, _VAO;
	    int _vertexCount;

        std::vector<Vertex> _vertices;

    public:    
        void initializeShape();
        void setVertices(std::initializer_list<Vertex> vertices);
        void drawShape();
};