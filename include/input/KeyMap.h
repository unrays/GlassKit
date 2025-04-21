// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <iostream>
#include <unordered_map>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

enum class KeyMap {
    A, B, C, D, E, F, G, H, I, J,
    K, L, M, N, O, P, Q, R, S, T,
    U, V, W, X, Y, Z,
    NUM_0, NUM_1, NUM_2, NUM_3, NUM_4,
    NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,
    SPACE, ENTER, BACKSPACE, ESCAPE,
    LEFT_SHIFT, RIGHT_SHIFT,
    LEFT_CONTROL, RIGHT_CONTROL,
    LEFT_ALT, RIGHT_ALT,
    ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT,
    TAB,
    UNKNOWN
};

inline KeyMap convertToKey(int key) {
    static const std::unordered_map<int, KeyMap> keyMap = {
        {GLFW_KEY_A, KeyMap::A},
        {GLFW_KEY_B, KeyMap::B},
        {GLFW_KEY_C, KeyMap::C},
        {GLFW_KEY_D, KeyMap::D},
        {GLFW_KEY_E, KeyMap::E},
        {GLFW_KEY_F, KeyMap::F},
        {GLFW_KEY_G, KeyMap::G},
        {GLFW_KEY_H, KeyMap::H},
        {GLFW_KEY_I, KeyMap::I},
        {GLFW_KEY_J, KeyMap::J},
        {GLFW_KEY_K, KeyMap::K},
        {GLFW_KEY_L, KeyMap::L},
        {GLFW_KEY_M, KeyMap::M},
        {GLFW_KEY_N, KeyMap::N},
        {GLFW_KEY_O, KeyMap::O},
        {GLFW_KEY_P, KeyMap::P},
        {GLFW_KEY_Q, KeyMap::Q},
        {GLFW_KEY_R, KeyMap::R},
        {GLFW_KEY_S, KeyMap::S},
        {GLFW_KEY_T, KeyMap::T},
        {GLFW_KEY_U, KeyMap::U},
        {GLFW_KEY_V, KeyMap::V},
        {GLFW_KEY_W, KeyMap::W},
        {GLFW_KEY_X, KeyMap::X},
        {GLFW_KEY_Y, KeyMap::Y},
        {GLFW_KEY_Z, KeyMap::Z},

        {GLFW_KEY_0, KeyMap::NUM_0},
        {GLFW_KEY_1, KeyMap::NUM_1},
        {GLFW_KEY_2, KeyMap::NUM_2},
        {GLFW_KEY_3, KeyMap::NUM_3},
        {GLFW_KEY_4, KeyMap::NUM_4},
        {GLFW_KEY_5, KeyMap::NUM_5},
        {GLFW_KEY_6, KeyMap::NUM_6},
        {GLFW_KEY_7, KeyMap::NUM_7},
        {GLFW_KEY_8, KeyMap::NUM_8},
        {GLFW_KEY_9, KeyMap::NUM_9},

        {GLFW_KEY_SPACE, KeyMap::SPACE},
        {GLFW_KEY_ENTER, KeyMap::ENTER},
        {GLFW_KEY_BACKSPACE, KeyMap::BACKSPACE},
        {GLFW_KEY_ESCAPE, KeyMap::ESCAPE},

        {GLFW_KEY_LEFT_SHIFT, KeyMap::LEFT_SHIFT},
        {GLFW_KEY_RIGHT_SHIFT, KeyMap::RIGHT_SHIFT},
        {GLFW_KEY_LEFT_CONTROL, KeyMap::LEFT_CONTROL},
        {GLFW_KEY_RIGHT_CONTROL, KeyMap::RIGHT_CONTROL},
        {GLFW_KEY_LEFT_ALT, KeyMap::LEFT_ALT},
        {GLFW_KEY_RIGHT_ALT, KeyMap::RIGHT_ALT},

        {GLFW_KEY_UP, KeyMap::ARROW_UP},
        {GLFW_KEY_DOWN, KeyMap::ARROW_DOWN},
        {GLFW_KEY_LEFT, KeyMap::ARROW_LEFT},
        {GLFW_KEY_RIGHT, KeyMap::ARROW_RIGHT},

        {GLFW_KEY_TAB, KeyMap::TAB}
    };

    auto it = keyMap.find(key);
    return (it != keyMap.end()) ? it->second : KeyMap::UNKNOWN;
}
