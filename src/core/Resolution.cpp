// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "core/Resolution.h"
#include <tuple>

void Resolution::editResolution(uint16_t width, uint16_t height, uint16_t refreshRate) { _width = width; _height = height; _refreshRate = refreshRate; }