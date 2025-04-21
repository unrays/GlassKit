// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "core/Language.h"

void Language::changeLanguage(LanguageMap newLanguage) { _language = newLanguage; }

std::string Language::toString() { return ConvertLanguageToString(_language); }

LanguageMap Language::getLanguageEnum() { return _language; }