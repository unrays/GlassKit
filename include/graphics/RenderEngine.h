// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "core/Config.h"
#include "input/InputManager.h"
#include <vector>
#include <tools/Timer.h>
#include <tools/FramerateCounter.h>

class RenderEngine {
	private:
		GLFWwindow* _window;
		Config _configuration;
		InputManager _inputManager;

		Timer _runtimeTimer;
		FramerateCounter _framerateCounter;

		GLuint _simulationSpeed;

	public:
		RenderEngine(const Config& config) : _configuration(config), _window(nullptr) {} // Prochaine étape

		void initializeComponents();
		

		static void framebufferSizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

		
		void initializeGLFWWindowSettings()				 { initializeGLFW(); initializeWindow(); };
			 void initializeWindow()					 { _window = glfwCreateWindow(_configuration.getResolution().getWidth(), _configuration.getResolution().getHeight(), "OpenGL Window", nullptr, nullptr); }
			 bool initializeGLFW()						 { return glfwInit(); }

		void initializeRuntimeComponents()				 { startExecutionTimer(); };
			 void startExecutionTimer()					 { _runtimeTimer.start(); }

		void showStartupInfo()							 { displayHardwareInfo(); }
		     void displayHardwareInfo();				 // À compartimenter en petites fonctions ou dans les classes

		void initializeRenderSettings()					 { setCurrentContext(); gladLoadOpenGLFunctions(); applyVSyncSetting(false); }
			 void setCurrentContext()					 { glfwMakeContextCurrent(_window); }
			 void gladLoadOpenGLFunctions()				 { gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); }
			 void applyVSyncSetting(bool enabled = true) { glfwSwapInterval(enabled ? 1 : 0); }

		void configureGLFWWindowSettings()				 { setFramebufferCallback(); initializeUserPointer(); setGLFWWindowHints(); };
			 void setFramebufferCallback()				 { glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback); }
			 void initializeUserPointer()				 { glfwSetWindowUserPointer(_window, &_inputManager); }
			 void setGLFWWindowHints();

		void terminateExecution()						 { endExecutionTimer(); destroyWindowAndTerminate(); }
			 void endExecutionTimer()		             { _runtimeTimer.stop(); };
			 void destroyWindowAndTerminate()		     { glfwDestroyWindow(_window); glfwTerminate(); }


		void updateRenderingContext()					 { processWindowEvents(); updateBuffer(); };
			 void processWindowEvents()					 { glfwPollEvents(); };
			 void updateBuffer()						 { glfwSwapBuffers(_window); };

			 
		/* Temporary functions for transition purpose */
		GLFWwindow* temporaryWindowGetter() { return _window; };
		FramerateCounter temporaryFramerateCounterGetter() { return _framerateCounter; };
		void temporarySwapBufferCall() { glfwSwapBuffers(_window); glfwPollEvents(); };

		

		void update();
		void renderFrame();
		void processInput();
};