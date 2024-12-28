#include <glad/glad.h>
#include <string>
#include <sstream>

namespace fta {
    class Shader {
    public:
	Shader(std::string vertex_path, std::string fragment_path);
	bool isLoaded();
	std::string getErrorLog();
	void loadFromFile(std::string vertex_path, std::string fragment_path);
	void bind();
	void unbind();
	void release();
    private:
	GLuint m_program;
	bool m_loaded;
	std::stringstream m_error_log;
    };
}
