// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <array>
#include <iostream>
#include <stdint.h>

enum ID : size_t { WIDTH = 0, HEIGHT = 1, REFRESH_RATE = 2 };
constexpr std::array<uint16_t, 3> MINIMUM_VALUE = { 800, 600, 1 };

class Resolution {
	private:
		uint16_t _width, _height, _refreshRate;
		float_t _aspectRatio;

	public:
		Resolution(uint16_t width = MINIMUM_VALUE[WIDTH], uint16_t height = MINIMUM_VALUE[HEIGHT], uint16_t refreshRate = MINIMUM_VALUE[REFRESH_RATE])
        : _width(width), _height(height), _refreshRate(refreshRate), _aspectRatio(static_cast<float_t>(width) / height) {}

		void editResolution(uint16_t width = MINIMUM_VALUE[WIDTH], uint16_t height = MINIMUM_VALUE[HEIGHT], uint16_t refreshRate = MINIMUM_VALUE[REFRESH_RATE]);
};