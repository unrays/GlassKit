// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "core/Coord.h"
#include "core/Color.h"

struct Vertex {
    Coord _coordinates;
    Color _color;

    Vertex(Coord coord = Coord(), Color color = Color()) : _coordinates(coord), _color(color) {}
};