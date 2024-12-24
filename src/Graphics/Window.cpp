#include <Graphics/Window.hpp>

namespace fta {
    Window::Window(int width, int height, std::string title) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	m_glfw_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	m_width = width;
	m_height = height;
    }

    void Window::makeCurrent() {
	glfwMakeContextCurrent(m_glfw_window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glViewport(0, 0, m_width, m_height);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void Window::swapBuffers() {
	glfwSwapBuffers(m_glfw_window);
    }

    void Window::pollEvents() {
	glfwPollEvents();
    }

    bool Window::shouldClose() {
	return glfwWindowShouldClose(m_glfw_window);
    }

    void Window::clear(Color color) {
	glClearColor(color.r, color.b, color.g, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
    }
}
