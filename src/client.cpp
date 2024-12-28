#include <iostream>
#include <sstream>

#include <Config.h>
#include <Graphics/Window.hpp>
#include <Graphics/Shader.hpp>

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

    float vertices[] = {
	-0.5f, -0.5f, 0.0f,	1.f, 0.f, 0.f, 1.f,
	 0.5f, -0.5f, 0.0f,	0.f, 1.f, 0.f, 1.f,
	 0.0f,  0.5f, 0.0f,	0.f, 0.f, 1.f, 1.f
    };

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    fta::Shader shader("resources/shaders/default.vert", "resources/shaders/default.frag");
    if (!shader.isLoaded()) {
	std::cerr << shader.getErrorLog() << std::endl;
	glfwTerminate();
	return 1;
    }

    while (!window.shouldClose()) {
	window.clear(fta::Color(0.f, 0.f, 0.f, 1.f));

	shader.bind();
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	window.swapBuffers();
	window.pollEvents();
    }
    
    glfwTerminate();
    return 0;
}
