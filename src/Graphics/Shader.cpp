#include <Graphics/Shader.hpp>
#include <fstream>

namespace fta {
    std::string ReadFileContent(std::string path) {
	std::ifstream file(path);
	std::stringstream ss;
	ss << file.rdbuf();
	file.close();
	return ss.str();
    }

    std::string Shader::getErrorLog() {
	return m_error_log.str();
    }

    bool Shader::isLoaded() {
	return m_loaded;
    }

    void Shader::loadFromFile(std::string vertex_path, std::string fragment_path) {
	GLint success;
	char info_log[512];
	m_loaded = true;
	m_error_log.str("");

	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	std::string vertex_str = ReadFileContent(vertex_path);
	const char* vertex_source = vertex_str.c_str();
	glShaderSource(vertex_shader, 1, &vertex_source, NULL);
	glCompileShader(vertex_shader);
	
	// Check for vertex shader compile errors
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
	    m_loaded = false;
	    glGetShaderInfoLog(vertex_shader, sizeof(info_log), NULL, info_log);
	    m_error_log << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info_log << std::endl;
	}
	

	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	std::string fragment_str = ReadFileContent(fragment_path);
	const char* fragment_source = fragment_str.c_str();
	glShaderSource(fragment_shader, 1, &fragment_source, NULL);
	glCompileShader(fragment_shader);

	// Check for fragment shader compile errors
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
	    m_loaded = false;
	    glGetShaderInfoLog(fragment_shader, sizeof(info_log), NULL, info_log);
	    m_error_log << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << info_log << std::endl;
	}

	m_program = glCreateProgram();
	glAttachShader(m_program, vertex_shader);
	glAttachShader(m_program, fragment_shader);
	glLinkProgram(m_program);

	glGetProgramiv(m_program, GL_LINK_STATUS, &success);
	if (!success) {
	    m_loaded = false;
	    glGetProgramInfoLog(m_program, sizeof(info_log), NULL, info_log);
	    m_error_log << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << info_log << std::endl;
	    this->release();
	}

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

    }


    Shader::Shader(std::string vertex_path, std::string fragment_path) {
	loadFromFile(vertex_path, fragment_path);
    }

    void Shader::bind() {
	glUseProgram(m_program);
    }

    void Shader::unbind() {
	glUseProgram(0);
    }

    void Shader::release() {
	glDeleteProgram(m_program);
    }
}
