#include "display.h"

int Display::CreateWindow(std::string name, int width, int height)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needded
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 
	m_glWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

	if (m_glWindow == NULL) {
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(m_glWindow);

}

int Display::Init()
{
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	m_renderer.SetWindow(m_glWindow);

	return 0;
}

void Display::Render()
{
	glfwSetInputMode(m_glWindow, GLFW_STICKY_KEYS, GL_TRUE);
	{
		m_renderer.Draw();
		glfwPollEvents();
	}
}