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

std::vector<Shape> Shapes;

int main()
{
    //const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    //Config configuration(Resolution(mode->width, mode->height, mode->refreshRate), Language("English"));
    glfwInit();
    RenderEngine renderEngine = RenderEngine(Config(Resolution(), Language("English")));
    renderEngine.initializeComponents();

    GLFWwindow* window = renderEngine.temporaryWindowGetter();
    FramerateCounter framerateCounter = renderEngine.temporaryFramerateCounterGetter();

    InputManager inputManager;
    
    Shape s1;
    static float offsetX = 0;
    static float offsetY = 0;
    
    Clock clock;
    const float speed = 0.5f;

    while (!glfwWindowShouldClose(window))
    {
        renderEngine.processInput();


        clock.update();

        double dt = clock.deltaTime();

        glClear(GL_COLOR_BUFFER_BIT);

        framerateCounter.calculateFramerate();
        framerateCounter.displayFramerate();

        glfwSetKeyCallback(window, InputManager::KeyPressHandler);

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


        renderEngine.temporarySwapBufferCall();
    }

    renderEngine.terminateExecution();

    return 0;
}