#include <iostream>
#include <sstream>

#include <Config.h>
#include <Graphics/Window.hpp>

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
	-0.5f, -0.5f, 0.f,
	0.5f, -0.5f, 0.f,
	0.f, 0.5f, 0.f
    };

    while (!window.shouldClose()) {
	window.clear(fta::Color(0.f, 0.f, 0.f, 1.f));


	window.swapBuffers();
	window.pollEvents();
    }
    
    glfwTerminate();
    return 0;
}
