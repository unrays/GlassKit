// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "Language.h"
#include "Resolution.h"

class Config {
	private:
		Resolution _resolution;
		Language _language;

	public:
		Config() : _resolution(Resolution()), _language(Language(LanguageMap::English)) {}
		Config(Resolution resolution, Language language) : _resolution(resolution), _language(language) {}

		const Resolution& getResolution() const { return _resolution; }
		const Language& getLanguage() const { return _language; }

		void editResolution(uint16_t width, uint16_t height, uint16_t refreshRate);
		void editLanguage(LanguageMap newLanguage);
};