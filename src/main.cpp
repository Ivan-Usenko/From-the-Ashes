#include <cstdlib>
#include <iostream>
#include <sstream>

#include <Config.h>
#include <System/Window.hpp>

void handle_error(int err_code, const char* err_desc) {
    std::cout << "Error has occured (0x" << std::hex << err_code << "): " << err_desc << std::endl;
    glfwTerminate();
    exit(1);
}

int main() {
    glfwSetErrorCallback(handle_error);
    glfwInit();
    
    std::stringstream title;
    title << "Game v" << GAME_VERSION_MAJOR <<  "." << GAME_VERSION_MINOR;
    sys::Window window(800, 600, title.str());

    window.makeCurrent();
    while (!window.shouldClose()) {
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	window.swapBuffers();
	window.pollEvents();
    }

    glfwTerminate();
    return 0;
}
