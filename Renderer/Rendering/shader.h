#pragma once

#include <GL/glew.h>
#include <glm\glm.hpp>
#include <string>

namespace rendering
{
	class Shader
	{
	private:
		GLuint m_glProgram;

		static void CheckCompileErrors(GLuint shader, std::string type);

	public:
		Shader();
        ~Shader();
		Shader(std::string vs, std::string fs);
		int Compile(std::string vs, std::string fs);
		void Use();

		void SetUniform1f(std::string name, GLfloat value);
		void SetUniform1fv(std::string name, const GLfloat* value, GLsizei count);
		void SetUniform2fv(std::string name, const GLfloat* value, GLsizei count);
		void SetUniform4fv(std::string name, const GLfloat* value, GLsizei count);
		void SetUniformMat4(std::string name, const GLfloat* value, GLsizei count);
	};
}