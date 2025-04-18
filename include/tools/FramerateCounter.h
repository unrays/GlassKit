// Copyright (c) 2025 F�lix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

class FramerateCounter {
	private:
		double _previousFrameTiming = glfwGetTime();
		double _currentFrameTiming;
		double _deltaFrameTiming;
		double _framesPerSecond;
		double _frameAccumulator;

	public:
		void calculateFramerate();
		void displayFramerate();
};
