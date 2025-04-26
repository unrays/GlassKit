// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"

//const GLFWvidmode* DEFAULT_RESOLUTION = glfwGetVideoMode(glfwGetPrimaryMonitor()); // Voir plus tard

constexpr enum ID : size_t { WIDTH = 0, HEIGHT = 1, REFRESH_RATE = 2 };
constexpr std::array<GLuint, 3> MINIMUM_RESOLUTION = { 1024, 768, 60 };

class Resolution {
private:
    GLuint _width, _height, _refreshRate;
    float_t _aspectRatio;

public:
    Resolution(GLuint width = MINIMUM_RESOLUTION[WIDTH], GLuint height = MINIMUM_RESOLUTION[HEIGHT], GLuint refreshRate = MINIMUM_RESOLUTION[REFRESH_RATE])
        : _width(width), _height(height), _refreshRate(refreshRate), _aspectRatio(static_cast<float_t>(width) / height) {}

    void editResolution(GLuint width = MINIMUM_RESOLUTION[WIDTH], GLuint height = MINIMUM_RESOLUTION[HEIGHT], GLuint refreshRate = MINIMUM_RESOLUTION[REFRESH_RATE]);

    void printResolution() const; // Deprecated

    GLuint getWidth()       const { return _width; };
    GLuint getHeight()      const { return _height; };
    GLuint getRefreshrate() const { return _refreshRate; };
    float_t getAspectRatio()  const { return _aspectRatio; }

    //std::array<uint16_t, 3> getResolutionValues() const { return { _width, _height, _refreshRate }; } // Deprecated
};