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

    startExecutionTimer();

    displayHardwareInfo();

	setGLFWWindowHints();

	initializeWindow();
	if (!_window) { glfwTerminate(); return; }

	setCurrentContext();

	gladLoadOpenGLFunctions();

	setFramebufferCallback();

	initializeUserPointer();
}

void RenderEngine::terminateExecution() {
    glfwDestroyWindow(_window); glfwTerminate();
    endExecutionTimer();
}

void RenderEngine::endExecutionTimer() { // Voir si je peux simplement le mettre dans terminateExecution()...
    _runtimeTimer.stop();
    std::cout << "\nTotal execution time: " << _runtimeTimer.elapsedTime().count() << " ms\n";
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