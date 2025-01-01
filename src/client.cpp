#include <iostream>
#include <sstream>

#include <Config.h>
#include <Graphics/Window.hpp>
#include <Graphics/Shader.hpp>
#include <Graphics/VAO.hpp>

int main() {
    if (!glfwInit()) {
	std::cerr << "Failed to initialize GLFW" << std::endl;
	return 1;
    }
    
    std::stringstream title;
    title << "From the Ashes (" << GAME_VERSION_MAJOR << "." << GAME_VERSION_MINOR << ")";
    fta::Window window(800, 600, title.str());
    if (!window.isOpen()) {
	std::cerr << "Failed to create window" << std::endl;
	glfwTerminate();
	return 1;
    }

    if (!window.makeCurrent()) {
	std::cerr << "Failed to load GLAD" << std::endl;
	glfwTerminate();
	return 1;
    }
    
    fta::Vertex vertices[] = {
	fta::Vertex(glm::vec3(-0.5f, -0.5f, 0.f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2()),
	fta::Vertex(glm::vec3(0.5f, -0.5f, 0.f), glm::vec4(0.f, 1.f, 0.f, 1.f), glm::vec2()),
	fta::Vertex(glm::vec3(0.f, 0.5f, 0.f), glm::vec4(0.f, 0.f, 1.f, 1.f), glm::vec2())
    };

    GLuint indices[] = {
	0, 1, 2
    };

    fta::VAO vao;
    vao.loadVertices(vertices, sizeof(vertices));
    vao.loadIndices(indices, sizeof(indices));
    
    fta::Shader shader("resources/shaders/default.vert", "resources/shaders/default.frag");
    if (!shader.isLoaded()) {
	std::cerr << shader.getErrorLog() << std::endl;
	glfwTerminate();
	return 1;
    }

    while (!window.shouldClose()) {
	window.clear(fta::Color(0.f, 0.f, 0.f, 1.f));

	shader.bind();
	vao.bind();
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

	window.swapBuffers();
	window.pollEvents();
    }
    
    glfwTerminate();
    return 0;
}
