// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"
#include "core/Time.h"

double Time::getCurrentTime() { return glfwGetTime(); }