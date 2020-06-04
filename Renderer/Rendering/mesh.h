#pragma once

#include <GL/glew.h>

namespace rendering
{
	class Mesh
	{
		GLuint VAO;
		GLuint VBO;
		GLuint m_size;
		GLenum m_drawType;

	public:
		Mesh();

		void GenBuffers();
		void FillQuadData();

		void DrawArray();
		void DrawArrayInstanced(int numberOfInstances);
	};
}