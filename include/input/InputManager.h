// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <iostream>
#include <unordered_map>

class InputManager {
	private:
		static std::vector<Key> _inputBuffer;

        

	public:
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void processPressedKey()
};