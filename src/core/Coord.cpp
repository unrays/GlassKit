// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <iostream>
#include "core/Coord.h"

float Coord::calculateDistance(const Coord& pointA, const Coord& pointB) {
	return std::sqrt(std::pow((pointB._x - pointA._x), 2) + std::pow((pointB._y - pointA._y), 2));
}