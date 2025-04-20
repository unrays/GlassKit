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
    //    glVertex2f(v1.x, v1.y); // Sommet supérieur
    //    glVertex2f(v2.x, v2.y); // Sommet inférieur gauche
    //    glVertex2f(v3.x, v3.y); // Sommet inférieur droit
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

std::vector<Shape> Shapes;

int main()
{
    if (!glfwInit()) return -1;

    auto runtimeDuration = new Timer();

    runtimeDuration->start();

    initializeEnvironment();

    //std::unordered_map<std::string, int> render_queue;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL); // pour 3d

    GLFWwindow* window = initializeWindow();
    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    /* ========================================= */
    
    Shape s1;
    Shape s2;

    s1.setVertices({
    Vertex(Coord(0.0f, 0.0f)), // centre

    Vertex(Coord(0.0f, 0.5f)),     // pointe en haut
    Vertex(Coord(0.118f, 0.154f)), // creux haut droit

    Vertex(Coord(0.475f, 0.154f)), // pointe droite
    Vertex(Coord(0.191f, -0.059f)),// creux bas droit

    Vertex(Coord(0.293f, -0.404f)),// pointe bas droite
    Vertex(Coord(0.0f, -0.2f)),    // creux bas

    Vertex(Coord(-0.293f, -0.404f)),// pointe bas gauche
    Vertex(Coord(- 0.191f, -0.059f)),// creux bas gauche

    Vertex(Coord(- 0.475f, 0.154f)), // pointe gauche
    Vertex(Coord(- 0.118f, 0.154f)), // creux haut gauche

    Vertex(Coord(0.0f, 0.5f))       // boucle
        });


    s1.initializeShape();

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

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);
        
        //drawTriangle({ 0.0, 0.5 }, { -0.5, -0.5 }, { 0.5, -0.5 }, { 1.0, 1.0, 1.0 });

        //system("cls");

        //glfwSwapInterval(1); // V-Sync

        framerate->calculateFramerate();
        framerate->displayFramerate();

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