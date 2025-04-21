// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

class RenderEngine {
	private:
		GLFWwindow* _window;

	public:
		void initialize();
			void initializeWindow();
		void update();
		void renderFrame();
};