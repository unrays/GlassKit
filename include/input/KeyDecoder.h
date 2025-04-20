// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "KeyState.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>

class KeyDecoder {
    private:
        std::unordered_map<int, char> _map = {
            {GLFW_KEY_A, 'a'},
            {GLFW_KEY_B, 'b'},
            {GLFW_KEY_C, 'c'},
            {GLFW_KEY_D, 'd'},
            {GLFW_KEY_E, 'e'},
            {GLFW_KEY_F, 'f'},
            {GLFW_KEY_G, 'g'},
            {GLFW_KEY_H, 'h'},
            {GLFW_KEY_I, 'i'},
            {GLFW_KEY_J, 'j'},
            {GLFW_KEY_K, 'k'},
            {GLFW_KEY_L, 'l'},
            {GLFW_KEY_M, 'm'},
            {GLFW_KEY_N, 'n'},
            {GLFW_KEY_O, 'o'},
            {GLFW_KEY_P, 'p'},
            {GLFW_KEY_Q, 'q'},
            {GLFW_KEY_R, 'r'},
            {GLFW_KEY_S, 's'},
            {GLFW_KEY_T, 't'},
            {GLFW_KEY_U, 'u'},
            {GLFW_KEY_V, 'v'},
            {GLFW_KEY_W, 'w'},
            {GLFW_KEY_X, 'x'},
            {GLFW_KEY_Y, 'y'},
            {GLFW_KEY_Z, 'z'},
            {GLFW_KEY_1, '1'},
            {GLFW_KEY_2, '2'},
            {GLFW_KEY_3, '3'},
            {GLFW_KEY_4, '4'},
            {GLFW_KEY_5, '5'},
            {GLFW_KEY_6, '6'},
            {GLFW_KEY_7, '7'},
            {GLFW_KEY_8, '8'},
            {GLFW_KEY_9, '9'},
            {GLFW_KEY_0, '0'}
        };

        std::unordered_map<int, KeyState> _stateMap = {
            {GLFW_PRESS, KeyState::Pressed},
            {GLFW_RELEASE, KeyState::Released},
            {GLFW_REPEAT, KeyState::Repeated}
        };

    public:
        char convertInputKey(int& key);
        KeyState convertInputState(int& action);
};