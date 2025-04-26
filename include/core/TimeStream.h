// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"
#include "Time.h"

class TimeStream {
private:
	double _previousTime;
	double _currentTime;
	double _ellapsedTime;
	void updateStream();

public:
	TimeStream();
	double getElapsedTimeSinceLastCall();
};