#include "shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

rendering::Shader::Shader(std::string vs, std::string fs)
{
	Compile(vs, fs);
}

int rendering::Shader::Compile(std::string vs, std::string fs)
{

	// 1. retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	std::ifstream gShaderFile;
	// ensure ifstream objects can throw exceptions:
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		vShaderFile.open(vs);
		fShaderFile.open(fs);
		std::stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char * fShaderCode = fragmentCode.c_str();
	// 2. compile shaders
	unsigned int vertex, fragment;
	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	CheckCompileErrors(vertex, "VERTEX");
	// fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	CheckCompileErrors(fragment, "FRAGMENT");

	m_glProgram = glCreateProgram();
	glAttachShader(m_glProgram, vertex);
	glAttachShader(m_glProgram, fragment);
	glLinkProgram(m_glProgram);
	CheckCompileErrors(m_glProgram, "PROGRAM");
	// delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return 0;
}

void rendering::Shader::Use()
{
	glUseProgram(m_glProgram);
}

void rendering::Shader::SetUniform1f(std::string name, GLfloat value)
{
	GLint loc = glGetUniformLocation(m_glProgram, name.c_str());
	if (loc != -1)
		glUniform1f(loc, value);
	else
		fprintf(stderr, (name + " location not found.\n").c_str());
}

void rendering::Shader::SetUniform1fv(std::string name, const GLfloat * value, GLsizei count)
{
	GLint loc = glGetUniformLocation(m_glProgram, name.c_str());
	if (loc != -1)
		glUniform1fv(loc, count, value);
	else
		fprintf(stderr, (name + " location not found.\n").c_str());
}

void rendering::Shader::SetUniform2fv(std::string name, const GLfloat * value, GLsizei count)
{
	GLint loc = glGetUniformLocation(m_glProgram, name.c_str());
	if (loc != -1)
		glUniform2fv(loc, count, value);
	else
		fprintf(stderr, (name + " location not found.\n").c_str());
}

void rendering::Shader::SetUniform4fv(std::string name, const GLfloat* value, GLsizei count)
{
	GLint loc = glGetUniformLocation(m_glProgram, name.c_str());
	if (loc != -1)
		glUniform4fv(loc, count, value);
	else
		fprintf(stderr, (name + " location not found.\n").c_str());
}

void rendering::Shader::CheckCompileErrors(GLuint shader, std::string type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}
