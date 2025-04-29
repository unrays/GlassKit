// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "graphics/RenderEngine.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void RenderEngine::setGLFWWindowHints() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    glfwWindowHint(GLFW_RED_BITS, _currentVideoMode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, _currentVideoMode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, _currentVideoMode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, _currentVideoMode->refreshRate);
}

void RenderEngine::setOpenGLRenderSettings() {
    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
    glEnable(GL_COLOR_MATERIAL);

    glDepthFunc(GL_LESS);
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
    

    processInput();

    updateSimulation();

    handleRenderCycle();
}

void RenderEngine::processInput() {
    _inputManager.processInputBuffer();
    
    if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(_window, true);
}

void RenderEngine::renderShaderFrame() {
}
