// Copyright (c) 2025 Félix-Olivier Dumas. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "core/Color.h"
#include "core/Coord.h"
#include "graphics/Vertex.h"
#include "graphics/Shape.h"
#include "tools/FramerateCounter.h"
#include "tools/Timer.h"
#include "input/InputManager.h"
#include <core/Clock.h>
#include <core/Config.h>
#include <graphics/RenderEngine.h>

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
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

void test(Shape& s1, float &offsetX, float &offsetY) {
    offsetX / 100000.0f;
    offsetY / 100000.0f;

    s1.setVertices({
        Vertex(Coord(0.020f + offsetX, 0.020f + offsetY), Color(1.0f, 0.0f, 0.0f)),
        Vertex(Coord(0.020f + offsetX, -0.020f - offsetY), Color(1.0f, 0.0f, 0.0f)),
        Vertex(Coord(-0.020f - offsetX, -0.020f - offsetY), Color(1.0f, 0.0f, 0.0f)),
        Vertex(Coord(-0.020f - offsetX, 0.020f + offsetY), Color(1.0f, 0.0f, 0.0f))
        });
}

//std::unique_ptr<Timer> runtimeDuration = nullptr;
std::unique_ptr<FramerateCounter> framerate = nullptr;

void initializeEnvironment() {
    //runtimeDuration = std::make_unique<Timer>();
    framerate = std::make_unique<FramerateCounter>();
}

GLFWwindow* initializeWindow(const GLuint& width, const GLuint& height, const GLuint& framerate )
{
    return glfwCreateWindow(width, height, "OpenGL Engine", nullptr, nullptr);
}

std::vector<Shape> Shapes;

int main()
{
    //const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    //Config configuration(Resolution(mode->width, mode->height, mode->refreshRate), Language("English"));
    glfwInit();
    RenderEngine renderEngine = RenderEngine(Config(Resolution(), Language("English")));
    renderEngine.initializeComponents();

    GLFWwindow* window = renderEngine.temporaryWindowGetter();

    InputManager inputManager;

    initializeEnvironment();
    
    Shape s1;

    static float offsetX = 0;
    static float offsetY = 0;
    
    Clock clock;
    const float speed = 0.5f;

    while (!glfwWindowShouldClose(window))
    {
        clock.update();

        double dt = clock.deltaTime();

        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);
        
        //drawTriangle({ 0.0, 0.5 }, { -0.5, -0.5 }, { 0.5, -0.5 }, { 1.0, 1.0, 1.0 });

        //system("cls");

        glfwSwapInterval(0); // V-Sync

        framerate->calculateFramerate();
        framerate->displayFramerate();

        glfwSetKeyCallback(window, InputManager::KeyPressHandler);

        inputManager.processInputBuffer();

        /*if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
                offsetX += 0.0015;
                offsetY += 0.0015;
            }
            else {
                offsetY += 0.0025;
            }
        }
        else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            offsetY -= 0.00025;
        }
        else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            offsetX += 0.00025;
        }
        else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            offsetX -= 0.00025;
        } */

        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            offsetY += speed * dt;
            offsetX += speed * dt;
        }
        else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            offsetY -= speed * dt;
            offsetX -= speed * dt;
        }

        test(s1, offsetX, offsetY);

        s1.initializeShape();

        s1.drawShape();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    renderEngine.terminateExecution();

    return 0;
}