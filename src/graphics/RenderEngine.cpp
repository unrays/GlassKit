// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "graphics/RenderEngine.h"

void RenderEngine::setGLFWWindowHints() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
}

void RenderEngine::initializeComponents() {
	if (!initializeGLFW()) return;

	setGLFWWindowHints();

	initializeWindow();
	if (!_window) { glfwTerminate(); return; }

	setCurrentContext();

	gladLoadOpenGLFunctions();

	setFramebufferCallback();

	initializeUserPointer();
}