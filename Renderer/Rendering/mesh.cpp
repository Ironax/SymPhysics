#include "mesh.h"

static const GLfloat c_quadBufferData[] = {
	-1.0f,  1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f,
	1.0f,  1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
};

static const GLfloat c_cubeBufferData[] = {
	-0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f, 0.5f,
	0.5f,  0.5f, 0.5f,
	0.5f,  0.5f, -0.5f,
	-0.5f,  -0.5f, -0.5f,
	-0.5f,  -0.5f, 0.5f,
	0.5f,  -0.5f, 0.5f,
	0.5f,  -0.5f, -0.5f,
};

static const GLuint c_cubeIndexData[] = {
	0,1,2,
    0,2,3,
    4,7,5,
    4,6,5,
    4,0,3,
    4,3,7,
    7,3,2,
    7,2,6,
    6,2,1,
    6,1,5,
    5,1,0,
    5,0,4
};

rendering::Mesh::Mesh()
{
	
}

void rendering::Mesh::GenBuffers()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
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

void rendering::Mesh::FillCubeData()
{
	m_size = sizeof(c_cubeIndexData);
	m_drawType = GL_LINE_STRIP;

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(c_cubeBufferData), c_cubeBufferData, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(c_cubeIndexData), c_cubeIndexData, GL_STATIC_DRAW);
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

void rendering::Mesh::DrawElements()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glDrawElements(m_drawType, m_size, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}