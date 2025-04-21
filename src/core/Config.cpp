// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "core/Config.h"

void Config::editResolution(uint16_t width, uint16_t height, uint16_t refreshRate) {
	_resolution.editResolution(width, height, refreshRate);
}

void Config::editLanguage(LanguageMap newLanguage) { _language.ChangeLanguage(newLanguage); }
