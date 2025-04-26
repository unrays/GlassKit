// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#pragma once
#include "common.h"
#include "graphics.h"
#include "core/Coord.h"
#include "Shader.h"

class Camera {
private:
	glm::vec3 _position, _target, _up;
	glm::mat4 _view, _projection;
	float _radius, _angle, _angleSpeed;
	float _moveSpeed, _minRadius, _maxRadius;

public:
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float radius, float angle, float angleSpeed);

	void orientCamera(glm::mat4& view);

	void applyCameraView(Shader& shader);

	void move(Shader& shader, float deltaTime);
};
