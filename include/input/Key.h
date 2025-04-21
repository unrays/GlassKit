// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "KeyMap.h"
#include "KeyState.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>

struct Key {
    KeyMap _key;
    KeyState _state;

    Key(int& key, int& action) : _key(convertToKey(key)), _state(convertKeyStateToEnum(action)) {};
};