#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Utility.h"
#include "Entity.h"
#include "Vector2.h"
#include "Time.h"

void onInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
    std::cout << key << std::endl;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WIDTH, HEIGHT, "engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, onInput);

    EASSERT(glewInit() == GLEW_OK, "checking GLEW_OK");

    Entity x; 
    x.position = Vector2(0.f, 50.f);
    x.initialize();
    
    Entity y;
    y.position = Vector2(0, 200.f);
    y.initialize();

    Entity z;
    z.position = Vector2(10.f, 10.f);
    z.initialize();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {   
        glClear(GL_COLOR_BUFFER_BIT);

        double DELTA_SECONDS = Time::getDeltaSeconds();

        x.position.x += 110 * DELTA_SECONDS;
        x.render();

        y.position.y += 100 * DELTA_SECONDS;
        y.render();

        z.position.x += 50 * DELTA_SECONDS;
        z.position.y += 50 * DELTA_SECONDS;
        z.render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
