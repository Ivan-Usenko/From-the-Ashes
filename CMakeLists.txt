cmake_minimum_required(VERSION 3.31)

# Compile settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(From_the_Ashes VERSION 0.1)

add_executable(client 
    "${PROJECT_SOURCE_DIR}/src/client.cpp"
    "${PROJECT_SOURCE_DIR}/src/Graphics/Window.cpp"
    "${PROJECT_SOURCE_DIR}/src/Graphics/Shader.cpp"
    "${PROJECT_SOURCE_DIR}/src/Graphics/VAO.cpp")

# GLFW settings
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)

# GLM settings
set(GLM_BUILD_TESTS OFF)

# Dependencies
add_subdirectory("${PROJECT_SOURCE_DIR}/deps/glfw")
add_subdirectory("${PROJECT_SOURCE_DIR}/deps/glad")
add_subdirectory("${PROJECT_SOURCE_DIR}/deps/glm")
target_link_libraries(client 
    PUBLIC glfw
    PUBLIC glad
    PUBLIC glm::glm
)

configure_file(Config.h.in Config.h)
target_include_directories(client 
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "${PROJECT_SOURCE_DIR}/include")

