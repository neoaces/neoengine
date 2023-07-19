#version 150 core
layout (location = 0) in vec3 inPosition;
uniform vec3 uMove;
void main() {
    gl_position = vec4(inPosition + uMove, 1.0);
}
