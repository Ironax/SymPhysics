#include "mesh.h"

static const GLfloat c_quadBufferData[] = {
	-1.0f,  1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f,
	1.0f,  1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
};

rendering::Mesh::Mesh()
{
	
}

void rendering::Mesh::GenBuffers()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
}

void rendering::Mesh::FillQuadData()
{
	m_size = 4;
	m_drawType = GL_TRIANGLE_STRIP;

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(c_quadBufferData), c_quadBufferData, GL_STATIC_DRAW);
}

void rendering::Mesh::DrawArray()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glDrawArrays(m_drawType, 0, m_size);
	glBindVertexArray(0);
}

void rendering::Mesh::DrawArrayInstanced(int numberOfInstances)
{
	glBindVertexArray(VAO);
	glDrawArraysInstanced(m_drawType, 0, m_size, numberOfInstances);
	glBindVertexArray(0);
}


