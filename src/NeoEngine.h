#pragma once
#define GLFW_INCLUDE_NONE
#include "GraphicsEngine.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <iostream>
#include <memory>
using neoengine::GraphicsEngine;

namespace neoengine
{
    class NeoEngine {
    public:
        NeoEngine();
        ~NeoEngine();

        static void glfw_error_callback(int error, const char* description);
        
        int run();
        void exit();

    private:
        int exit_status {0};

        std::unique_ptr<GraphicsEngine> m_window{nullptr};

        bool isConfigWindow{true};
        bool isMainScene{true};
        bool running{true};
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    };
}