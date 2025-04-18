// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <chrono>

class Timer
{
	private:
		std::chrono::steady_clock::time_point _startTime;
		std::chrono::steady_clock::time_point _endTime;
		bool isRunning;

	public:
		void start();
		void stop();
		std::chrono::milliseconds elapsedTime();
};