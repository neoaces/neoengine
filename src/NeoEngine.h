#pragma once
#include "GraphicsEngine.h"
#include "backends/imgui_impl_sdl2.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
using neoengine::GraphicsEngine;

namespace neoengine
{
    class NeoEngine {
    public:
        NeoEngine();
        ~NeoEngine();

        int init();
        void exit();

    private:
        int exit_status {0};
        bool running {true};

        std::unique_ptr<GraphicsEngine> m_window{nullptr};

        bool isConfigWindow {true};
    };
}