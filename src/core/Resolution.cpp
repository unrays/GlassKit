// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "core/Resolution.h"
#include <array>
#include <iostream>
#include <numeric>
#include <tuple>

void Resolution::editResolution(GLuint width, GLuint height, GLuint refreshRate) { _width = width; _height = height; _refreshRate = refreshRate; }

void Resolution::printResolution() const {
    std::cout << "Resolution: " << _width << "x" << _height << " @ " << _refreshRate << "Hz" << std::endl;
    std::cout << "Aspect Ratio: " << _aspectRatio << std::endl;
}