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
	_framesPerSecond = 1.0 / _deltaFrameTiming;
	_frameAccumulator += _deltaFrameTiming;
}

void FramerateCounter::displayFramerate() {
	if (_frameAccumulator < 1.0) return;

	std::cout << "[DEBUG] " << std::round(_framesPerSecond) << " fps" << std::endl;
	_frameAccumulator = 0;
}