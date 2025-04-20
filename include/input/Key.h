// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "KeyDecoder.h"
#include "KeyState.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>

struct Key {
    KeyDecoder _decoder;
    KeyState _state;
    char _key;

    Key(int& key, int& action) : _key(_decoder.convertInputKey(key)), _state(_decoder.convertInputState(action)) {};
};