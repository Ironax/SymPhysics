#include <iostream>
#include <World.h>

#include "Rendering/display.h"

Display display;

int main()
{
	display.CreateWindow("Sym", 900, 600);
	display.Init();

	Sym::World world;
	world.Init();

	bool m_running = true;
	while (m_running)
	{
		display.Render();
		if (glfwGetKey(display.m_glWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			m_running = false;
	}
	return 0;
}
