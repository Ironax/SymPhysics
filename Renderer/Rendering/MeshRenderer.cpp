#include "MeshRenderer.h"
#include "shader.h"
#include "mesh.h"
#include <glm\gtx/transform.hpp>

void rendering::MeshRenderer::SetMesh(Mesh* mesh)
{
	m_mesh = mesh;
}


void rendering::MeshRenderer::Draw()
{
	if (shader)
	{
		m_transform = glm::translate(glm::identity<glm::mat4>(), m_position) *toMat4(m_rotation) * glm::scale(m_scale);
		shader->Use();
		shader->SetUniformMat4("transform", &m_transform[0][0], 1);
	}

	if (m_mesh)
		m_mesh->DrawElements();
}

void rendering::MeshRenderer::InitRender()
{
    
}
