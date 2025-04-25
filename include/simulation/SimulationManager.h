// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <core/Clock.h>

constexpr GLuint DEFAULT_SIMULATION_SPEED = 1;

class SimulationManager { // Un peu SUS comme classe, son rôle n'est pas clair... à refaire...
	private:
		GLfloat _simulationSpeed; // Regrouper le clock dans lui, clock sert6 s rien ou changer son nom
		Clock _timeCalculator;


	public:
		SimulationManager(Clock timeCalculator, GLfloat simulationSpeed = DEFAULT_SIMULATION_SPEED) : _timeCalculator(timeCalculator), _simulationSpeed(simulationSpeed) {};

		void update() { _timeCalculator.update(); };

		double getDeltaTime() { return _timeCalculator.deltaTime(); };
		GLfloat getSimulationSpeed() { return _simulationSpeed; };
};