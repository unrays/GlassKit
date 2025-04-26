// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"

constexpr enum ColorChannel { R = 0, G = 1, B = 2, A = 3 };
constexpr std::array<GLfloat, 4> MINIMUM_VALUE = { 0.0f, 0.0f, 0.0f, 0.0f };

struct Color {
	GLfloat _r, _g, _b, _a;

	Color(GLfloat r = MINIMUM_VALUE[R], GLfloat g = MINIMUM_VALUE[G], GLfloat b = MINIMUM_VALUE[B], GLfloat a = MINIMUM_VALUE[A]) : _r(r), _g(g), _b(b), _a(a) {}
};