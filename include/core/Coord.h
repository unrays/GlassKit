// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"

constexpr enum Axis : size_t {X = 0, Y = 1, Z = 2};
constexpr std::array<GLfloat, 3> DEFAULT_COORDINATE = { 0.0f, 0.0f, 0.0f };

struct Coord { 
	GLfloat _x, _y, _z;

	Coord(float x = DEFAULT_COORDINATE[X], float y = DEFAULT_COORDINATE[Y], float z = DEFAULT_COORDINATE[Z]) : _x(x), _y(y), _z(z) {}
};