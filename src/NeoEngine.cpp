#include "NeoEngine.h"
#include "GraphicsEngine.h"
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer2.h>
#include <imgui.h>

namespace neoengine {
    NeoEngine::NeoEngine() {
        unsigned int INIT_FLAGS = SDL_INIT_VIDEO | SDL_INIT_TIMER;
        if (INIT_FLAGS == 0) {
            std::cout << "SDL failed to initialize...";
            exit_status = 1;
        }
        m_window = std::make_unique<GraphicsEngine>
            (GraphicsEngine::Settings{ "Application" });
    }

    NeoEngine::~NeoEngine() {
        ImGui_ImplSDLRenderer2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
        SDL_Quit();
    };

    int NeoEngine::init() {
        if (exit_status == 1) {
            return exit_status;
        }
	
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io{ ImGui::GetIO() };

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        const float font_scaling{ m_window->get_scale() };
        const float font_size{ (32.0f * font_scaling) / 2 };

        io.Fonts->AddFontFromFileTTF("Inter.ttf", font_size);
        io.FontDefault = io.Fonts->AddFontFromFileTTF("Inter.ttf", font_size);

        ImGui_ImplSDL2_InitForSDLRenderer(
            m_window->get_native_window(),
            m_window->get_native_renderer());

        ImGui_ImplSDLRenderer2_Init(
            m_window->get_native_renderer()
        );

        running = true;

        while (running) {
            // Poll SDL events
            SDL_Event event{};
            while (SDL_PollEvent(&event) == 1) {
                ImGui_ImplSDL2_ProcessEvent(&event);
                // Listen for the quit event to stop the application
                if (event.type == SDL_QUIT) {
                    exit();
                }
            }

            ImGui_ImplSDLRenderer2_NewFrame();
            ImGui_ImplSDL2_NewFrame();
            ImGui::NewFrame();

            ImGui::DockSpaceOverViewport();

            // ImGui::DockSpace(ImGui::GetID("DockSpace"));

            if (ImGui::BeginMainMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("Exit")) { exit(); }
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("View")) {
                    ImGui::MenuItem(
                        "Show Config Window", nullptr, &isConfigWindow
                    );
                    ImGui::EndMenu();
                }

                ImGui::EndMainMenuBar();
            }

            if (isConfigWindow) {
                ImGui::Begin("Config", &isConfigWindow);
                ImGui::Text("Place the configuration files here:");
                ImGui::End();
            }

            ImGui::Render();

            // Clear window
            SDL_SetRenderDrawColor(m_window->get_native_renderer(), 100,
                100, 100, 255);

            SDL_RenderClear(m_window->get_native_renderer());

            // Render current frame
            ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
            SDL_RenderPresent(m_window->get_native_renderer());
        }

        return exit_status;
    };

    void NeoEngine::exit() {
        running = false;
    };
}
