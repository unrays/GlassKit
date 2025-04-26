// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"
#include "core/FramerateManager.h"

constexpr double DISPLAY_FREQUENCY = 0.25;

void FramerateManager::calculateCurrentFramerate() {
	auto ellapsedTime = _timeStream.getElapsedTimeSinceLastCall();

	_framesPerSecond = (1.0 / ellapsedTime);
	_framesAccumulator += ellapsedTime;
}

void FramerateManager::displayFramerate() {
	if (_framesAccumulator < DISPLAY_FREQUENCY) return;

	std::cout << "\rFramerate: " << std::round(_framesPerSecond) << " fps" << std::flush;
	_framesAccumulator = 0;
}