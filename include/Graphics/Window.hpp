#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <Graphics/Color.hpp>

namespace fta {
    class Window {
    public:
	Window(int width, int height, std::string title);
	void makeCurrent();
	void swapBuffers();
	void pollEvents();
	bool shouldClose();
	void clear(Color color);
    private:
	GLFWwindow* m_glfw_window;
	int m_width;
	int m_height;
    };
}