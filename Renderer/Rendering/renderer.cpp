#include "renderer.h"
#include "render_object.h"

#include <algorithm>

rendering::Renderer::Renderer()
{
}

rendering::Renderer::~Renderer()
{

}

void rendering::Renderer::SetWindow(GLFWwindow * window)
{
	m_glWindow = window;
	glClearColor(
		backGroundColor.x, 
		backGroundColor.y, 
		backGroundColor.z, 
		backGroundColor.w);
}

void rendering::Renderer::Draw()
{
	if (!m_glWindow)
		return;

	// Clear the screen.
	glClear(GL_COLOR_BUFFER_BIT);

	for (RenderObject* renderObject : m_renderObjects)
	{
		if (renderObject)
			renderObject->Draw();
	}

	// Swap buffers
	glfwSwapBuffers(m_glWindow);
}


void rendering::Renderer::AddRenderObject(RenderObject * object)
{
	if (object)
		m_renderObjects.push_back(object);
}

void rendering::Renderer::RemoveRenderObject(RenderObject * object)
{
	m_renderObjects.erase(std::remove(m_renderObjects.begin(), m_renderObjects.end(), object));
}
