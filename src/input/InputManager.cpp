// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "input/InputManager.h"
#include "input/Key.h"

std::vector<Key> InputManager::_inputBuffer;

void InputManager::KeyPressHandler(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS or action == GLFW_REPEAT) {
        auto pressedKey = Key(key, action);

        //std::cout << "[DEBUG] Key Pressed!" << std::endl;
        _inputBuffer.push_back(pressedKey);
    }
}

void InputManager::processInputBuffer() {
    for (auto it = _inputBuffer.begin(); it != _inputBuffer.end(); ) {
        const Key& pressedKey = *it;

        if (pressedKey._key == KeyMap::A) {
            std::cout << "\nA Key pressed!" << std::endl;
        }

        if (pressedKey._key == KeyMap::D) {
            std::cout << "\nD Key pressed!" << std::endl;
        }

        it = _inputBuffer.erase(it); // Repenser la logique, ça sert un peu moyen
    }
}