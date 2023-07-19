//
// Created by neoaces on 2023-06-27.
//
#pragma once
// asserts that GLFW doesn't import OpenGL twice
#define GLFW_INCLUDE_NONE
#define GL_SILENCE_DEPRECATION

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <string>
#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include <cstdio>
#include "ShaderProg.h"
#include "SquareBody.h"

namespace neoengine {
    class GraphicsEngine {
    private:
		GLFWwindow* gWindow { nullptr }; /// The Window we'll be rendering to
		bool error{false};

       public:
        
		struct Settings {
			std::string title;
			const int width{1920};
			const int height{1080};
        };

        /**
         * @brief Callback for OpenGL errors.
         * 
         * @param id 
         * @param description Description of the errors 
         */
        static void glfwError(int id, const char* description) {
			std::cout << description << std::endl;
		}

        /**
         * @brief Construct a new Graphics Engine object. Uses the settings struct to hold various traits that can be changed at runtime.
         * 
         * @param settings Struct that holds name, width, height
         */
        explicit GraphicsEngine(const Settings& settings);

        /**
         * @brief Get the native window object constructed by GLFW.
         * 
         * @return GLFWwindow* Window returned by GLFW.
         */
		[[nodiscard]] GLFWwindow* get_native_window() const;
        const char* glsl_version;

		// Object ID variables
		unsigned int vertexBuffer;
		unsigned int vertexArray;
    };
} // neoGraphics
