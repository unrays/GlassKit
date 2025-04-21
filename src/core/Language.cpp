// Copyright (c) 2025 F�lix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "core/Language.h"

void Language::ChangeLanguage(LanguageMap newLanguage) { _language = newLanguage; }

std::string Language::toString() { return ConvertLanguageToString(_language); }