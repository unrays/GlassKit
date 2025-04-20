// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once

class Coord { 
public:
	float _x, _y, _z;

	Coord(float x = 0.0f, float y = 0.0f, float z = 0.0f) : _x(x), _y(y), _z(z) {}
	float calculateDistance(const Coord& pointA, const Coord& pointB);
};