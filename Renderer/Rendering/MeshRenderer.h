#pragma once

#include <glm\glm.hpp>
#include <glm\gtx/quaternion.hpp>
#include <glm\gtx/quaternion.hpp>
#include "render_object.h"

namespace rendering
{
	class Mesh;
	class MeshRenderer : public RenderObject
	{
	public:
		glm::vec3 m_position;
		glm::quat m_rotation = glm::identity<glm::quat>();
		glm::vec3 m_scale = glm::vec3(1,1,1);

		glm::mat4 m_transform;

	    Mesh* m_mesh;

			virtual void InitRender() override;
			virtual void Draw() override;
			virtual void SetMesh(Mesh* mesh);
    };
}