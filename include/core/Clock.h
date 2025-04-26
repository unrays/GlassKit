// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"

class Clock {
	private:
		double _lastTime = glfwGetTime(), _deltaTime = 0.0;

	public:
		Clock();

		void update();
		double deltaTime();
};