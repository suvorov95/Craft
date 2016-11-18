#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:

	void Create(int Width, int Height, bool bFullscreen, const char* Name);

	GLFWwindow* WindowHandle;

};