#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace sys {
    class Window {
    public:
	Window(int width, int height, std::string title);
	void makeCurrent();
	void swapBuffers();
	void pollEvents();
	bool shouldClose();
    private:
	GLFWwindow* m_glfw_window;
	int m_width;
	int m_height;
    };
}
