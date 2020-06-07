#include <iostream>
#include <World.h>

#include "Rendering/display.h"
#include "Rendering/shader.h"
#include "Rendering/renderer.h"
#include "Rendering/camera.h"
#include "Rendering/mesh.h"
#include "Rendering/MeshRenderer.h"

Display display;

rendering::Mesh mesh;
rendering::Camera camera;
rendering::Shader shader;
rendering::MeshRenderer cube;

void Init()
{
	display.CreateWindow("Sym", 900, 500);
	display.Init();

	Sym::World world;
	world.Init();

	shader.Compile("Rendering/Basic.vs", "Rendering/Basic.fs");

	mesh.GenBuffers();
	mesh.FillCubeData();

	cube.shader = &shader;
	cube.SetMesh(&mesh);
	cube.m_position = glm::vec3(0, 0, -10);

	display.Renderer().AddRenderObject(&cube);

	camera.SetTransform(glm::vec3(1, 0, -5), glm::identity<glm::quat>());
	camera.UpdateShader(&shader);
}

int main()
{
	Init();

	bool m_running = true;
	while (m_running)
	{
		display.Render();
		if (glfwGetKey(display.GlWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
			m_running = false;
		//cube.m_position += glm::vec3(0, 0, -0.001f);
		cube.m_rotation *= glm::angleAxis(0.01f, glm::vec3(0, 1.f, 0));
	}
	return 0;
}

