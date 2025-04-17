// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void drawLine() // Fonction de test
{
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.1f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}

void render_loop() // Fonction de test
{
    glBegin(GL_LINES);
    glVertex2f(0, 10);
    glVertex3f(1880.0, 20.0, 0.0);
    glEnd();
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

        drawLine();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // faire class Render
    // 
    // faire class Draw
    //       shape DrawShape()
    //            return new shape();
    //
    //       Pense...
    // 
    // faire class Shape

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}