#pragma once

#include "renderer.h"

class Display
{
public:
	int CreateWindow(std::string name, int width, int height);
	int Init();
	void Render();

	GLFWwindow* GlWindow() const;
	rendering::Renderer& Renderer();
private:
	GLFWwindow* m_glWindow;
	rendering::Renderer m_renderer;
};