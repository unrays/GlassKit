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

    glfwWindowHint(GLFW_RED_BITS, _currentVideoMode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, _currentVideoMode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, _currentVideoMode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, _currentVideoMode->refreshRate);
}

void RenderEngine::initializeComponents() {
	if (!initializeGLFW()) return; // Faire un truc pour CHECK()

    initializeGLFWWindowSettings();

    initializeRuntimeComponents();

    showStartupInfo();

	if (!_window) { glfwTerminate(); return; }

    initializeRenderSettings();

    configureGLFWWindowSettings();
}

void RenderEngine::update() {
    //glClear(GL_COLOR_BUFFER_BIT);

    processInput();

    updateSimulation();

    updateRenderingContext();
}

void RenderEngine::processInput() {
    _inputManager.processInputBuffer();
    
    if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(_window, true);
}