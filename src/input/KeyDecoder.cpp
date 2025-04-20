// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "input/KeyDecoder.h"

char KeyDecoder::convertInputKey(int& key) {
    auto it = _map.find(key);
    if (it != _map.end()) {
        return it->second;
    }
    else {
        return '\0';
    }
}

KeyState KeyDecoder::convertInputState(int& action) {
    auto it = _stateMap.find(action);
    if (it != _stateMap.end()) {
        return it->second;
    }
    return KeyState::Released;
}