// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.
// Shader class contributed by ChatGPT (OpenAI).

#pragma once
#include <string>
#include <GLAD/glad.h>
#include <iostream>
#include <stdexcept>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
    Shader();
    ~Shader();
    void use();
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;

private:
    GLuint ID;
    static const std::string vertexShaderSource;
    static const std::string fragmentShaderSource;

    void compileShader(const char* source, GLenum type, const std::string& label);
    void checkCompileErrors(GLuint handle, const std::string& type, const std::string& label);
};