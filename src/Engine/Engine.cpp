#include <iostream>
#include <exception>

#include "Engine.h"

void FbSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Engine::Init()
{
    try {
        if (glfwInit() == 0)
            throw std::runtime_error("Failed to initialize GLFW");
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        m_window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Chimera Engine", NULL, NULL);

        if (m_window == nullptr)
            throw std::runtime_error("Failed to create GLFW window");

        glfwMakeContextCurrent(m_window);
        glfwSetFramebufferSizeCallback(m_window, FbSizeCallback);

        if (gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)) == 0)
            throw std::runtime_error("Failed to initialize GLAD");
    }
    catch(std::exception const& e) {
        std::cerr << e.what() << std::endl;
        glfwTerminate();
        exit(-1);
    }
}

void Engine::Run()
{
    while (!glfwWindowShouldClose(m_window))
    {
        ProcessInput();

        // Clear frame buffer
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}

void Engine::ProcessInput()
{
    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
}
