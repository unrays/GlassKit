// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "tools/Timer.h"
#include <chrono> 
#include <iostream>

void Timer::start() {
	std::cout << "[DEBUG] Timer started..." << std::endl;
	_startTime = std::chrono::steady_clock::now();
	isRunning = true;
}

void Timer::stop() {
	if (isRunning) { // faire un try() pour signaler si on essaye d'areter un timer non demarré
		std::cout << "[DEBUG] Timer stopped" << std::endl;
		_endTime = std::chrono::steady_clock::now();
		isRunning = !isRunning;
	}
}

std::chrono::milliseconds Timer::elapsedTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(_endTime - _startTime);
}