// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "core/Config.h"
#include <vector>

class RenderEngine {
	private:
		Config _configuration;
		GLFWwindow* _window;

	public:
		void initializeComponents();
		void initializeWindow();

		static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

		void update();
		void renderFrame();
			void processInput();
};