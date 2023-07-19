#include "GraphicsEngine.h"
#include "ShaderProg.h"

#if __APPLE__
#define ARCH_MAC true
#endif

namespace neoengine
{
GraphicsEngine::GraphicsEngine(const Settings& settings) {
    glfwSetErrorCallback(&glfwError); // Prints out any errors in OpenGL
    glfwInit();

    // Decide GL+GLSL versions
    #if defined(IMGUI_IMPL_OPENGL_ES2)
        // GL ES 2.0 + GLSL 100
        glsl_version = "#version 100";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    #elif defined(__APPLE__)
        // GL 3.2 + GLSL 150
        glsl_version = "#version 150";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
    #else
        // GL 3.0 + GLSL 130
        glsl_version = "#version 130";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
    #endif

	gWindow = glfwCreateWindow(settings.width, settings.height, settings.title.c_str(), nullptr, nullptr);
    if (gWindow == nullptr) {
        error = true;
    }
    
    glfwMakeContextCurrent(gWindow);
    glfwSwapInterval(1);  // Enables vsync

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("FAILED!");
        exit(1);
    };

    ShaderProg myProgram;

    myProgram.attach("./vs.glsl", GL_VERTEX_SHADER);
    myProgram.attach("./fs.glsl", GL_FRAGMENT_SHADER);
    myProgram.link();

        glGenVertexArrays(1, &vertexArray);
    glGenBuffers(1, &vertexBuffer);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    glEnableVertexAttribArray(0);
}

GLFWwindow* GraphicsEngine::get_native_window() const {
    return gWindow;
}
} // neoGraphics