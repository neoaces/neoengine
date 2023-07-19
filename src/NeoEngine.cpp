#include "NeoEngine.h"
#include "GraphicsEngine.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "glad.h"
#include "glfw3.h"
#include <imgui.h>

namespace neoengine {
    static void glfw_error_callback(int error, const char* description) {
        fprintf(stderr, "GLFW Error %d: %s\n", error, description);
    }

    NeoEngine::NeoEngine() {
        m_window = std::make_unique<GraphicsEngine>
            (GraphicsEngine::Settings());
    }

    NeoEngine::~NeoEngine() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(m_window->get_native_window());
        glfwTerminate();
    };

    int NeoEngine::run() {
        if (exit_status == 1) {
            return exit_status;
        }
	
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io{ImGui::GetIO()};

        io.Fonts->AddFontFromFileTTF("Inter.ttf", 16.0f);
        io.FontDefault = io.Fonts->AddFontFromFileTTF("Inter.ttf", 16.0f);

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        ImGui_ImplGlfw_InitForOpenGL(m_window->get_native_window(), true);
        ImGui_ImplOpenGL3_Init();

        while (running && !glfwWindowShouldClose(m_window->get_native_window())) {
            glfwPollEvents();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGui::DockSpaceOverViewport();

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

            if (isMainScene) {
                ImGui::Begin("Scene", &isConfigWindow);
                ImGui::BeginChild("SceneRender");

                
                // ImGui::Text("Scene here:");

                ImGui::EndChild();
                ImGui::End();
            }

            // Rendering
            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(m_window->get_native_window(), &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            // Update and Render additional Platform Windows
            // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
            //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
                GLFWwindow* backup_current_context = glfwGetCurrentContext();
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
                glfwMakeContextCurrent(backup_current_context);
            }

            glfwSwapBuffers(m_window->get_native_window());
        }

        return exit_status;
    };

    void NeoEngine::exit() {
        running = false;
    };
}
