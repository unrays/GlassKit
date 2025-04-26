// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include <common.h>
#include <graphics.h>
#include <graphics/Camera.h>

constexpr enum VectorChannel { Position = 0, Target = 1, Up = 2 };
constexpr std::array<glm::vec3, 3> DEFAULT_VALUES = { glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f) };

Camera::Camera(glm::vec3 position = DEFAULT_VALUES[Position], glm::vec3 target = DEFAULT_VALUES[Target], glm::vec3 up = DEFAULT_VALUES[Up], float radius = 1, float angle = 1, float angleSpeed = 1) :
		_position(position), _target(target), _up(up), _radius(radius), _angle(angle), _angleSpeed(angleSpeed) {}

void Camera::orientCamera(glm::mat4& view) { view = glm::lookAt(_position, _target, _up); } // Probablement mettre private

// Devra probablement se situer dans renderengine
void Camera::applyCameraView(Shader& shader) { // Probablement mettre private
	orientCamera(_view);

	shader.setMat4("view", _view);
}

// Le shader est temporaire ici
void Camera::move(Shader& shader, float deltaTime) {
	_angle += _angleSpeed * (deltaTime * 700 ); // Vitesse de rotation

	float x = _radius * cos(glm::radians(_angle));
	float z = _radius * sin(glm::radians(_angle));

	_position = glm::vec3(x, _position.y, z);

	applyCameraView(shader);
}