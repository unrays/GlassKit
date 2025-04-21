// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <string>

enum class LanguageMap {
    English,
    French,
    Spanish,
    German,
    Italian,
    Portuguese,
    Chinese,
    Japanese,
    Russian, 
    Undefined
};

inline std::string ConvertLanguageToString(LanguageMap language) {
    switch (language) {
    case LanguageMap::English:     return "English";
    case LanguageMap::French:      return "French";
    case LanguageMap::Spanish:     return "Spanish";
    case LanguageMap::German:      return "German";
    case LanguageMap::Italian:     return "Italian";
    case LanguageMap::Portuguese:  return "Portuguese";
    case LanguageMap::Chinese:     return "Chinese";
    case LanguageMap::Japanese:    return "Japanese";
    case LanguageMap::Russian:     return "Russian";
    case LanguageMap::Undefined:   return "Undefined";
    default:                       return "Unknown";
    }
}

inline LanguageMap ConvertLanguageToEnum(const std::string& language) {
         if (language == "English")    return LanguageMap::English;
    else if (language == "French")     return LanguageMap::French;
    else if (language == "Spanish")    return LanguageMap::Spanish;
    else if (language == "German")     return LanguageMap::German;
    else if (language == "Italian")    return LanguageMap::Italian;
    else if (language == "Portuguese") return LanguageMap::Portuguese;
    else if (language == "Chinese")    return LanguageMap::Chinese;
    else if (language == "Japanese")   return LanguageMap::Japanese;
    else if (language == "Russian")    return LanguageMap::Russian;
    else                               return LanguageMap::Undefined;
}
