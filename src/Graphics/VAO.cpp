#include <Graphics/VAO.hpp>

namespace fta {
    VAO::VAO() {
	glGenVertexArrays(1, &m_vao);
    }

    void VAO::loadVertices(fta::Vertex* vertices, GLuint size, GLenum usage) {
	this->bind();

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, usage);
	
	// Specifying vertex attributes
	// Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(fta::Vertex), (void*)0);
	glEnableVertexAttribArray(0);
	// Color
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(fta::Vertex), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// Texture coord
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(fta::Vertex), (void*)(7 * sizeof(float)));
	glEnableVertexAttribArray(2);
	
	// Cleanup
	this->unbind();
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &vbo);
    }

    void VAO::loadIndices(GLuint* indices, GLuint size, GLenum usage) {
	this->bind();

	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, usage);
	
	// Cleanup
	this->unbind();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &ebo);
    }

    void VAO::bind() {
	glBindVertexArray(m_vao);
    }

    void VAO::unbind() {
	glBindVertexArray(0);
    }

    void VAO::release() {
	glDeleteVertexArrays(1, &m_vao);
    }
}
