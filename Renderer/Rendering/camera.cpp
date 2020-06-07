#include "camera.h"
#include "shader.h"
#include <glm/gtx/transform.hpp>

rendering::Camera::Camera()
{
	m_fov = 90;
	m_aspect = 1.77f;
	m_near = 0.1f;
	m_far = 1000.0f;
	OnTransformChange();
	OnProjectionChange();
}
rendering::Camera::~Camera()
{}

void rendering::Camera::UpdateShader(Shader * shader)
{
	if (shader)
	{
	    shader->Use();
		shader->SetUniformMat4("projection", &m_projection[0][0], 1);
		shader->SetUniformMat4("camera", &m_transform[0][0], 1);
	}
}

void rendering::Camera::OnTransformChange()
{
	m_transform = glm::inverse(glm::translate(glm::identity<glm::mat4>(), m_position) * toMat4(m_rotation));
}
void rendering::Camera::OnProjectionChange()
{
	m_projection = glm::perspective(m_fov, m_aspect, m_near, m_far);
}

void rendering::Camera::SetProjection(float fov, float aspect, float near, float far)
{
	m_fov = fov;
	m_aspect = aspect;
	m_near = near;
	m_far = far;
	OnProjectionChange();
}

void rendering::Camera::SetTransform(const glm::vec3& v, const glm::quat& q)
{
	m_position = v;
	m_rotation = q;
	OnTransformChange();
}
