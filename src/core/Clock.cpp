// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"
#include "core/Clock.h"

Clock::Clock() {
	_lastTime = glfwGetTime();
	_deltaTime = 0.0;
}

void Clock::update() {
	double current = glfwGetTime();
	_deltaTime = current - _lastTime;
	_lastTime = current;
}

double Clock::deltaTime() {
	return _deltaTime;
}