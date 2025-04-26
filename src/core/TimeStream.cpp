// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"
#include "core/TimeStream.h"

TimeStream::TimeStream() : _previousTime(Time::getCurrentTime()) {}

double TimeStream::getElapsedTimeSinceLastCall() { updateStream(); return _ellapsedTime; }

void TimeStream::updateStream() {
	_currentTime = Time::getCurrentTime();
	_ellapsedTime = (_currentTime - _previousTime);

	std::swap(_currentTime, _previousTime);
}