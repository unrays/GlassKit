// Copyright (c) 2025 F�lix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"
#include "TimeStream.h"

class FramerateManager {
	private:
		TimeStream _timeStream;
		double _framesAccumulator, _framesPerSecond;

	public:
		void calculateCurrentFramerate();
		void displayFramerate();
};