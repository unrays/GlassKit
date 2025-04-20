// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "input/InputManager.h"
#include "input/Key.h"

void InputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        auto pressedKey = Key(key);
        _inputBuffer.push_back(pressedKey);
    }
}

char InputManager::getPressedKey(GLFWwindow* window, int key, int scancode, int action, int mods);