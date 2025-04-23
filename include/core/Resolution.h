// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <array>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <numeric>
#include <string>

//const GLFWvidmode* DEFAULT_RESOLUTION = glfwGetVideoMode(glfwGetPrimaryMonitor()); // Voir plus tard

enum ID : size_t { WIDTH = 0, HEIGHT = 1, REFRESH_RATE = 2 };
constexpr uint16_t MINIMUM_RESOLUTION[3] = { 1024, 768, 60 };

class Resolution {
private:
    uint16_t _width, _height, _refreshRate;
    float_t _aspectRatio;

public:
    Resolution(uint16_t width = MINIMUM_RESOLUTION[WIDTH], uint16_t height = MINIMUM_RESOLUTION[HEIGHT], uint16_t refreshRate = MINIMUM_RESOLUTION[REFRESH_RATE])
        : _width(width), _height(height), _refreshRate(refreshRate), _aspectRatio(static_cast<float_t>(width) / height) {}

    void editResolution(uint16_t width = MINIMUM_RESOLUTION[WIDTH], uint16_t height = MINIMUM_RESOLUTION[HEIGHT], uint16_t refreshRate = MINIMUM_RESOLUTION[REFRESH_RATE]);

    void printResolution() const;

    uint16_t getWidth()       const { return _width; };
    uint16_t getHeight()      const { return _height; };
    uint16_t getRefreshrate() const { return _refreshRate; };
    float_t getAspectRatio()  const { return _aspectRatio; }

    std::array<uint16_t, 3> getResolutionValues() const { return { _width, _height, _refreshRate }; } // Deprecated
};