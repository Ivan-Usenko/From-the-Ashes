#include <Graphics/Window.hpp>

namespace fta {
    void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
    }

    Window::Window(int width, int height, std::string title) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	m_glfw_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	m_width = width;
	m_height = height;
    }

    bool Window::isOpen() {
	return m_glfw_window != NULL;
    }

    bool Window::makeCurrent() {
	glfwMakeContextCurrent(m_glfw_window);
	glfwSetFramebufferSizeCallback(m_glfw_window, Window::framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
	    return false;
	}
	
	// Enable alpha blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
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
