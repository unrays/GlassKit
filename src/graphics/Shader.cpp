// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.
// Shader class contributed by ChatGPT (OpenAI).

#include "graphics/Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const std::string Shader::vertexShaderSource = R"(
#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 vertexColor;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);
    vertexColor = color;
}
)";

const std::string Shader::fragmentShaderSource = R"(
#version 330 core
in vec4 vertexColor;
out vec4 FragColor;

void main()
{
    FragColor = vertexColor;
}

)";

Shader::Shader() {
    ID = glCreateProgram();
    if (ID == 0) {
        throw std::runtime_error("ERROR::PROGRAM_CREATION_FAILED");
    }

    compileShader(vertexShaderSource.c_str(), GL_VERTEX_SHADER, "VERTEX");
    compileShader(fragmentShaderSource.c_str(), GL_FRAGMENT_SHADER, "FRAGMENT");

    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM", "LINK");

    glValidateProgram(ID);
    checkCompileErrors(ID, "PROGRAM", "VALIDATE");
}

Shader::~Shader() {
    if (ID != 0) glDeleteProgram(ID);
}

void Shader::use() {
    if (ID == 0) throw std::runtime_error("Shader not initialized");
    glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::compileShader(const char* source, GLenum type, const std::string& label) {
    GLuint shader = glCreateShader(type);
    if (shader == 0) {
        throw std::runtime_error("ERROR::SHADER_CREATION_FAILED: " + label);
    }
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    checkCompileErrors(shader, type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT", label);

    glAttachShader(ID, shader);
    glDeleteShader(shader);
}

void Shader::checkCompileErrors(GLuint handle, const std::string& type, const std::string& label) {
    GLint success;
    GLchar info[1024];
    if (type == "PROGRAM") {
        glGetProgramiv(handle, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(handle, 1024, nullptr, info);
            std::cerr << "ERROR::PROGRAM_LINKING_ERROR (" << label << ")\n" << info << "\n";
            throw std::runtime_error("Program linking failed: " + label);
        }
    }
    else {
        glGetShaderiv(handle, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(handle, 1024, nullptr, info);
            std::cerr << "ERROR::SHADER_COMPILATION_ERROR (" << label << ")\n" << info << "\n";
            throw std::runtime_error("Shader compilation failed: " + label);
        }
    }
}
