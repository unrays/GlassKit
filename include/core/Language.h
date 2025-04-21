// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "database/LanguageMap.h"

class Language {
	private:
		LanguageMap _language;

	public:
		Language(LanguageMap language) : _language(language) {};
		Language(std::string language) : _language(ConvertLanguageToEnum(language)) {};

		void ChangeLanguage(LanguageMap newLanguage);
		std::string toString();
};
