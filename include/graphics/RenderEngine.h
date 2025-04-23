// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "core/Config.h"
#include "input/InputManager.h"
#include <vector>

class RenderEngine {
	private:
		GLFWwindow* _window;
		Config _configuration;
		InputManager _inputManager;

	public:
		RenderEngine(const Config& config) : _configuration(config), _window(nullptr) {} // Prochaine étape

		void initializeComponents();
		void setGLFWWindowHints();

		static void framebufferSizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

		bool initializeGLFW() { return glfwInit(); }
		void initializeWindow() { _window = glfwCreateWindow(_configuration.getResolution().getWidth(), _configuration.getResolution().getHeight(), "OpenGL Engine", nullptr, nullptr); }
		void setCurrentContext() { glfwMakeContextCurrent(_window); }
		void gladLoadOpenGLFunctions() { gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); }
		void setFramebufferCallback() { glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback); }
		void initializeUserPointer() { glfwSetWindowUserPointer(_window, &_inputManager); }

		GLFWwindow* temporaryWindowGetter() { return _window; };

		void displayHardwareInfo();

		void update();
		void renderFrame();
			void processInput();
};