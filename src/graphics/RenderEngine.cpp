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

    updateRenderingContext();
}

void RenderEngine::processInput() {
    _inputManager.processInputBuffer();
    
    if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(_window, true);
}

void RenderEngine::displayHardwareInfo() { // Diviser dans les classes pour éliminer les getters et setters
    std::cout << "[ Resolution Details ]" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Width       : " << _configuration.getResolution().getWidth() << " px" << std::endl;
    std::cout << "Height      : " << _configuration.getResolution().getHeight() << " px" << std::endl;
    std::cout << "Refresh Rate: " << _configuration.getResolution().getRefreshrate() << " Hz" << std::endl;
    std::cout << "Aspect Ratio: " << _configuration.getResolution().getAspectRatio() << std::endl;

    std::cout << "\n[ Language Details ]" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Current Language : " << _configuration.getLanguage().toString() << std::endl;

    std::cout << "\n[ Full Resolution Details ]" << std::endl;
    std::cout << "----------------------------" << std::endl;
    _configuration.getResolution().printResolution();

    std::cout << std::endl;
}