#version 330 core

out vec4 FragColor;

in vec4 vColor;
in vec2 vTexCoord;

void main() {
    FragColor = vColor;
}
