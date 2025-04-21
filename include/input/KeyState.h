// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once

enum class KeyState {
    Pressed,
    Released,
    Repeated,
    Unknown
};

inline KeyState convertToState(int& state) {
    switch (state) {
        case GLFW_PRESS:   return KeyState::Pressed;
        case GLFW_RELEASE: return KeyState::Released;
        case GLFW_REPEAT:  return KeyState::Repeated;
        default:           return KeyState::Unknown;
    }
}