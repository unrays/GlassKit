// Copyright (c) 2025 F�lix-Olivier Dumas. All rights reserved.
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
    //glBegin(GL_TRIANGLES);
    //    glColor3f(1.0f, 1.0f, 1.0f);
    //    glVertex2f(v1.x, v1.y); // Sommet sup�rieur
    //    glVertex2f(v2.x, v2.y); // Sommet inf�rieur gauche
    //    glVertex2f(v3.x, v3.y); // Sommet inf�rieur droit
    //glEnd();
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
    if (!glfwInit()) return -1;

    /* ======================================================================= */

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    //Config configuration(Resolution(mode->width, mode->height, mode->refreshRate), Language("English"));
    Config configuration(Resolution(), Language("English"));

    Resolution configuratedResolution = configuration.getResolution();
    Language configuratedLanguage = configuration.getLanguage();

    std::array<uint16_t, 3> configuratedResolutionArray = configuratedResolution.getResolutionValues();

    std::cout << "[ Resolution Details ]" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Width       : " << configuratedResolutionArray[0] << " px" << std::endl;
    std::cout << "Height      : " << configuratedResolutionArray[1] << " px" << std::endl;
    std::cout << "Refresh Rate: " << configuratedResolutionArray[2] << " Hz" << std::endl;
    std::cout << "Aspect Ratio: " << configuratedResolution.getAspectRatio() << std::endl;

    std::cout << "\n[ Language Details ]" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Current Language : " << configuratedLanguage.toString() << std::endl;

    std::cout << "\n[ Full Resolution Details ]" << std::endl;
    std::cout << "----------------------------" << std::endl;
    configuratedResolution.printResolution();

    std::cout << std::endl;

    /* ======================================================================= */

    auto runtimeDuration = new Timer();

    runtimeDuration->start();

    initializeEnvironment();

    //std::unordered_map<std::string, int> render_queue;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL); // pour 3d

    GLFWwindow* window = initializeWindow(configuratedResolutionArray[0], configuratedResolutionArray[1], configuratedResolutionArray[2]);
    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    /* ========================================= */
    
    Shape s1;
    Shape s2;

    //s1.setVertices({
    //Vertex(Coord(0.0f, 0.0f)), // centre

    //Vertex(Coord(0.0f, 0.5f)),     // pointe en haut
    //Vertex(Coord(0.118f, 0.154f)), // creux haut droit

    //Vertex(Coord(0.475f, 0.154f)), // pointe droite
    //Vertex(Coord(0.191f, -0.059f)),// creux bas droit

    //Vertex(Coord(0.293f, -0.404f)),// pointe bas droite
    //Vertex(Coord(0.0f, -0.2f)),    // creux bas

    //Vertex(Coord(-0.293f, -0.404f)),// pointe bas gauche
    //Vertex(Coord(- 0.191f, -0.059f)),// creux bas gauche

    //Vertex(Coord(- 0.475f, 0.154f)), // pointe gauche
    //Vertex(Coord(- 0.118f, 0.154f)), // creux haut gauche

    //Vertex(Coord(0.0f, 0.5f))       // boucle
    //    });


    //s1.initializeShape();


    s2.setVertices({
        Vertex(1.0f, 0.5f),
        Vertex(0.5f, -0.5f),
        Vertex(1.5f, -0.5f)
    });

    s2.initializeShape();

    /*unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);*/

    /* ========================================= */

    static float offsetX = 0;
    static float offsetY = 0;

    InputManager inputManager;
    glfwSetWindowUserPointer(window, &inputManager);
    
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

        // Faire une classe INPUT qui compartimente la logique



        s1.initializeShape();

        s1.drawShape();
        //s2.drawShape();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    runtimeDuration->stop();

    std::cout << "[DEBUG] Total execution time: " << runtimeDuration->elapsedTime().count() << " ms";

    return 0;
}