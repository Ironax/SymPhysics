#pragma once

namespace rendering
{
	class Renderer;
	class Shader;
	class RenderObject
	{
	protected:
	public:
		virtual void InitRender() = 0;
		virtual void Draw() = 0;
		Shader* m_shader;
	};
}