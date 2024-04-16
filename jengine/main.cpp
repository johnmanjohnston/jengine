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
    
    /*
    // test vector addition
    Vector2 a(2.f, 1.f); Vector2 b(5.f, 2.f);
    EASSERT((a + b).x == 7.f, "vec add x");
    EASSERT((a + b).y == 3.f, "vec add y");
    */

    // ================================================================================ //
    float positions[6] = {
        -.5f, -.5f,
        .0f, .5f,
        .5f, -.5f
    };

    float qPos[8] = {   -0.9f, 0.9f,   // top-left corner
                        -0.9f, 0.6f,   // bottom-left corner
                        -0.6f, 0.6f,   // bottom-right corner
                        -0.6f, 0.9f }; // top-right corner

    /*
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    */

    /*
    unsigned int sqBuffer;
    glGenBuffers(1, &sqBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, sqBuffer);
    glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), qPos, GL_STATIC_DRAW);
    */

    Entity x; 
    x.position = Vector2(0.f, 50.f);
    VAO vao;
    x.initialize(vao);

    Entity y;
    y.position = Vector2(0, 200.f);
    VAO a; y.initialize(a);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {   
        // calc delta time
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        double DELTA_SECONDS = Time::getDeltaSeconds();

        x.position.x += 100 * DELTA_SECONDS;
        x.render();

        y.position.y += 100 * DELTA_SECONDS;
        y.render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
