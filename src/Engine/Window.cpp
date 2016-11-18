#include "Window.h"

void Window::Create(int Width, int Height, bool bFullscreen, const char* Name)
{
	GLFWmonitor* monitor = NULL;

	// take monitor highest resolution if fullscreen is required

	if (bFullscreen)
	{
		monitor = glfwGetPrimaryMonitor();

		int mode_count;
		const GLFWvidmode* modes = glfwGetVideoModes(monitor, &mode_count);

		Width = modes[mode_count - 1].width;
		Height = modes[mode_count - 1].height;
	}

	WindowHandle = glfwCreateWindow(Width, Height, Name, monitor, NULL);
}