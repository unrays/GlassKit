// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "core/Config.h"

void Config::editResolution(uint16_t width, uint16_t height, uint16_t refreshRate) { _resolution.editResolution(width, height, refreshRate); }

void Config::editLanguage(LanguageMap newLanguage) { _language.changeLanguage(newLanguage); }

void Config::displayHardwareInfo() { // Potentiellement deplacer dans une classe Log
    std::cout << "[ Resolution Details ]" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Width       : " << _resolution.getWidth() << " px" << std::endl;
    std::cout << "Height      : " << _resolution.getHeight() << " px" << std::endl;
    std::cout << "Refresh Rate: " << _resolution.getRefreshrate() << " Hz" << std::endl;
    std::cout << "Aspect Ratio: " << _resolution.getAspectRatio() << std::endl;

    std::cout << "\n[ Language Details ]" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Current Language : " << _language.toString() << std::endl;

    std::cout << "\n[ Full Resolution Details ]" << std::endl;
    std::cout << "----------------------------" << std::endl;
    _resolution.printResolution();

    std::cout << std::endl;
}