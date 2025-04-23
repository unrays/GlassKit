// Copyright (c) 2025 F�lix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "core/Config.h"
#include "input/InputManager.h"
#include <vector>
#include <tools/Timer.h>

class RenderEngine {
	private:
		GLFWwindow* _window;
		Config _configuration;
		InputManager _inputManager;
		Timer _runtimeTimer;

	public:
		RenderEngine(const Config& config) : _configuration(config), _window(nullptr) {} // Prochaine �tape

		void initializeComponents();
		void setGLFWWindowHints();

		static void framebufferSizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

		void startExecutionTimer() { _runtimeTimer.start(); }

		bool initializeGLFW() { return glfwInit(); }
		void initializeWindow() { _window = glfwCreateWindow(_configuration.getResolution().getWidth(), _configuration.getResolution().getHeight(), "OpenGL Window", nullptr, nullptr); }
		void setCurrentContext() { glfwMakeContextCurrent(_window); }
		void gladLoadOpenGLFunctions() { gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); }
		void setFramebufferCallback() { glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback); }
		void initializeUserPointer() { glfwSetWindowUserPointer(_window, &_inputManager); }

		GLFWwindow* temporaryWindowGetter() { return _window; };

		void terminateExecution();

		void endExecutionTimer();

		void displayHardwareInfo();

		void update();
		void renderFrame();
			void processInput();
};