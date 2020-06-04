#pragma once

#include <vector>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm\glm.hpp>

namespace rendering
{
	class RenderObject;
	class Renderer
	{
	private:
		bool m_isInit = false;
		std::vector<RenderObject*> m_renderObjects;

		GLFWwindow* m_glWindow = nullptr;

	public:
		Renderer();
		~Renderer();
		void SetWindow(GLFWwindow* window);
		void Draw();

		void AddRenderObject(RenderObject* object);
		void RemoveRenderObject(RenderObject* object);

		glm::vec4 backGroundColor = {0.f, 0.f, 0.f, 0.f};
	};
}