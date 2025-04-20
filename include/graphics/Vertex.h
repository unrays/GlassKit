// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "core/Coord.h"
#include "core/Color.h"

class Vertex {
public:
    float _x, _y;
    float _r, _g, _b;

    Vertex(float x, float y) : _x(x), _y(y) {} // Temporary
    Vertex(Coord coord, Color color = Color()) : _x(coord._x), _y(coord._y), _r(color._r), _g(color._g), _b(color._b) {}
};