// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "graphics/RenderEngine.h"

void RenderEngine::framebufferSizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
void RenderEngine::initializeWindow() { _window = glfwCreateWindow(_configuration.getResolution().getWidth(), _configuration.getResolution().getHeight(), "OpenGL Engine", nullptr, nullptr); };

void RenderEngine::initializeComponents() {
	if (!glfwInit()) return;

	initializeWindow();
	if (!_window) { glfwTerminate(); return; }

	glfwMakeContextCurrent(_window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);
}