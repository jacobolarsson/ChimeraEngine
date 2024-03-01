#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

constexpr int WIN_WIDTH = 800;
constexpr int WIN_HEIGHT = 600;

class Engine
{
public:
	Engine() : m_window(nullptr) {}
	~Engine() { glfwTerminate(); }

	void Init();
	void Run();

private:
	void ProcessInput();

	GLFWwindow* m_window;
};