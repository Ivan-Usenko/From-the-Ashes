#include <glad/glad.h>
#include <Graphics/Vertex.hpp>

namespace fta {
    class VAO {
    public:
	VAO();
	void loadVertices(fta::Vertex* vertices, GLuint size, GLenum usage = GL_STATIC_DRAW);
	void loadIndices(GLuint* indices, GLuint size, GLenum usage = GL_STATIC_DRAW);
	void bind();
	void unbind();
	void release();
    private:
	GLuint m_vao;
    };
}
