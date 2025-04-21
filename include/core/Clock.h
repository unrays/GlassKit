// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

class Clock {
	private:
		double _lastTime = glfwGetTime();
		double _deltaTime = 0.0;

	public:
		void update();
		double deltaTime();
};