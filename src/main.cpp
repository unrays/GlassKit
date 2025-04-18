// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "tools/Timer.h"
#include "tools/FramerateCounter.h"
#include "graphics/Coord.h"
#include "graphics/Vertex.h"
#include "graphics/Color.h"

struct window { // Reformuler en classe...
    int width;
    int height;
    /* ... */
};

struct config { // Reformuler en classe...

};

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void drawTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3, const Color& c) // Fonction de test
{
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(v1.x, v1.y); // Sommet supérieur
        glVertex2f(v2.x, v2.y); // Sommet inférieur gauche
        glVertex2f(v3.x, v3.y); // Sommet inférieur droit
    glEnd();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void checkGLFW()
{

}

void render() {

}

//std::unique_ptr<Timer> runtimeDuration = nullptr;
std::unique_ptr<FramerateCounter> framerate = nullptr;

void initializeEnvironment() {
    //runtimeDuration = std::make_unique<Timer>();
    framerate = std::make_unique<FramerateCounter>();
}

GLFWwindow* initializeWindow()
{
    return glfwCreateWindow(800, 600, "OpenGL Engine", nullptr, nullptr);
}

int main()
{
    if (!glfwInit()) return -1;

    auto runtimeDuration = new Timer();

    runtimeDuration->start();

    initializeEnvironment();

    //std::unordered_map<std::string, int> render_queue;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL); // pour 3d

    GLFWwindow* window = initializeWindow();
    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        
        drawTriangle({ 0.0, 0.5 }, { -0.5, -0.5 }, { 0.5, -0.5 }, { 1.0, 1.0, 1.0 });

        system("cls");

        framerate->calculateFramerate();
        framerate->displayFramerate();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    runtimeDuration->stop();

    std::cout << "[DEBUG] Total execution time: " << runtimeDuration->elapsedTime().count() << " ms";

    return 0;
}