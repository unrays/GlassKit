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
#include "core/FramerateManager.h"
#include "tools/Timer.h"
#include "input/InputManager.h"
#include <core/Clock.h>
#include <core/Config.h>
#include <graphics/RenderEngine.h>
#include <graphics/Camera.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void test(Shape& s1) {
    float size = 0.5f;

    // Les coordonnées des 8 sommets du cube
    Coord v[8] = {
        Coord(size,  size,  size), // 0
        Coord(size, -size,  size), // 1
        Coord(-size, -size,  size), // 2
        Coord(-size,  size,  size), // 3
        Coord(size,  size, -size), // 4
        Coord(size, -size, -size), // 5
        Coord(-size, -size, -size), // 6
        Coord(-size,  size, -size)  // 7
    };

    // Définition des couleurs pour chaque face
    Color c[] = {
        Color(1, 0, 0, 1), // Rouge
        Color(0, 1, 0, 1), // Vert
        Color(0, 0, 1, 1), // Bleu
        Color(1, 1, 0, 1), // Jaune
        Color(1, 0, 1, 1), // Magenta
        Color(0, 1, 1, 1)  // Cyan
    };

    // Les faces du cube, chaque face est composée de 2 triangles
    s1.setVertices({
        // Avant
        Vertex(v[0], c[0]), Vertex(v[1], c[0]), Vertex(v[2], c[0]),
        Vertex(v[2], c[0]), Vertex(v[3], c[0]), Vertex(v[0], c[0]),

        // Arrière
        Vertex(v[4], c[1]), Vertex(v[5], c[1]), Vertex(v[6], c[1]),
        Vertex(v[6], c[1]), Vertex(v[7], c[1]), Vertex(v[4], c[1]),

        // Droite
        Vertex(v[0], c[2]), Vertex(v[1], c[2]), Vertex(v[5], c[2]),
        Vertex(v[5], c[2]), Vertex(v[4], c[2]), Vertex(v[0], c[2]),

        // Gauche
        Vertex(v[3], c[3]), Vertex(v[2], c[3]), Vertex(v[6], c[3]),
        Vertex(v[6], c[3]), Vertex(v[7], c[3]), Vertex(v[3], c[3]),

        // Haut
        Vertex(v[0], c[4]), Vertex(v[3], c[4]), Vertex(v[7], c[4]),
        Vertex(v[7], c[4]), Vertex(v[4], c[4]), Vertex(v[0], c[4]),

        // Bas
        Vertex(v[1], c[5]), Vertex(v[2], c[5]), Vertex(v[6], c[5]),
        Vertex(v[6], c[5]), Vertex(v[5], c[5]), Vertex(v[1], c[5]),
        });
}

static float speed = 0.0001;

void move_camera(glm::mat4& view, float& offsetX, float& offsetY, float deltaTime) {
    float speedFactor = 0.1f;

    view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
                       glm::vec3(offsetX, 0.0f, 0.0f),
                       glm::vec3(0.0f, 1.0f, 0.0f));
}


std::vector<Shape> Shapes;

int main()
{
    //const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    //Config configuration(Resolution(mode->width, mode->height, mode->refreshRate), Language("English"));
    glfwInit();
    RenderEngine renderEngine(Config(Resolution(), Language("English")), SimulationManager(Clock(), 0.5f));
    renderEngine.initializeComponents();

    GLFWwindow* window = renderEngine.temporaryWindowGetter();
    FramerateManager framerateManager = renderEngine.temporaryFramerateManagerGetter();

    InputManager inputManager;
    
    Shape s1;
    static float offsetX = 0;
    static float offsetY = 0;

    glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);


    Shader temporaryShader;

    temporaryShader.use();

    temporaryShader.setMat4("model", model);
    //temporaryShader.setMat4("view", view);
    temporaryShader.setMat4("projection", projection);

    /* ===================================================== */

    glm::vec3 position(1.0f, 0.0f, 5.0f);
    glm::vec3 target(0.0f, 0.0f, 0.0f);  
    glm::vec3 up(0.0f, 1.0f, 0.0f);

    float radius = 10.0f;     
    float angle = 45.0f;
    float angleSpeed = 0.05f;

    Camera myCamera(position, target, up, radius, angle, angleSpeed);

    /* ===================================================== */

    while (!glfwWindowShouldClose(window))
    {
        renderEngine.processInput();

        renderEngine.updateSimulation();

        glClear(GL_COLOR_BUFFER_BIT);

        framerateManager.calculateCurrentFramerate();
        framerateManager.displayFramerate();

        glfwSetKeyCallback(window, InputManager::KeyPressHandler);

        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            offsetY += renderEngine.temporaryGetSimulationSpeed() * renderEngine.temporaryGetDeltaTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            offsetY -= renderEngine.temporaryGetSimulationSpeed() * renderEngine.temporaryGetDeltaTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            offsetX += renderEngine.temporaryGetSimulationSpeed() * renderEngine.temporaryGetDeltaTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            offsetX -= renderEngine.temporaryGetSimulationSpeed() * renderEngine.temporaryGetDeltaTime();
        } 

        /*if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            offsetY += renderEngine.temporaryGetSimulationSpeed() * renderEngine.temporaryGetDeltaTime();
            offsetX += renderEngine.temporaryGetSimulationSpeed() * renderEngine.temporaryGetDeltaTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            offsetY -= renderEngine.temporaryGetSimulationSpeed() * renderEngine.temporaryGetDeltaTime();
            offsetX -= renderEngine.temporaryGetSimulationSpeed() * renderEngine.temporaryGetDeltaTime();
        }*/

        test(s1);
        s1.initializeShape();
        s1.drawShape(temporaryShader);

        //move_camera(view, offsetX, offsetY, renderEngine.temporaryGetDeltaTime());

        
        //myCamera.applyCameraView(temporaryShader);
        myCamera.move(temporaryShader, renderEngine.temporaryGetDeltaTime());

        //myCamera.assignCameraView();
        //myCamera.updateView(temporaryShader);

        //myCamera.processCameraView(view);
        //temporaryShader.setMat4("view", view);


        renderEngine.temporarySwapBufferCall();
    }

    renderEngine.terminateExecution();

    return 0;
}