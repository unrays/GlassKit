// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

struct Vertex {
    float x;
    float y;
};

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void drawTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3) // Fonction de test
{
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(v1.x, v1.y); // Sommet supérieur
        glVertex2f(v2.x, v2.y); // Sommet inférieur gauche
        glVertex2f(v3.x, v3.y); // Sommet inférieur droit
    glEnd();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    std::unordered_map<std::string, int> render_queue; // Remplacer int par une type plus globalisé

    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Engine", nullptr, nullptr);
    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        drawTriangle({ 0.0, 0.5 }, { -0.5, -0.5 }, { 0.5, -0.5 });

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}