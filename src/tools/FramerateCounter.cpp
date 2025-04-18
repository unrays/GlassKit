// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "tools/FramerateCounter.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

void FramerateCounter::calculateFramerate() {
	_previousFrameTiming = _currentFrameTiming;
	_currentFrameTiming = glfwGetTime();

	_deltaFrameTiming = _currentFrameTiming - _previousFrameTiming;
	_framesPerSecond = (1000 / _deltaFrameTiming);
}

void FramerateCounter::displayFramerate() {
	std::cout << "[DEBUG] " << _framesPerSecond << " fps" << std::endl;
}