#pragma once
#include <glm/gtx/quaternion.hpp>

namespace rendering
{
    class Shader;
    class Camera
    {
        public:
		Camera();
		~Camera();

		void UpdateShader(Shader* shader);
		void SetTransform(const glm::vec3& v, const glm::quat& q);
		void SetProjection(float fov, float aspect, float near, float far);

        private:
			void OnTransformChange();
			void OnProjectionChange();

		glm::vec3 m_position;
		glm::quat m_rotation;
		glm::mat4 m_projection;
		glm::mat4 m_transform;

		float m_fov = 90;
		float m_aspect = 1.77f;
		float m_near = 0.1f;
		float m_far = 1000.0f;

    };
}
