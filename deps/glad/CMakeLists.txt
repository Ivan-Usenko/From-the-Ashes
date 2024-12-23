cmake_minimum_required(VERSION 3.31)

project(glad VERSION 3.3)

add_library(${PROJECT_NAME} STATIC src/glad.c)
target_include_directories(${PROJECT_NAME} PUBLIC "include")
