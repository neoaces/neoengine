//
// Created by neoaces on 2023-06-27.
//

#include "GraphicsEngine.h"
#include "backends/imgui_impl_sdl2.h"

#if __APPLE__
#define ARCH_MAC true
#endif

namespace neoengine {
GraphicsEngine::GraphicsEngine(const Settings& settings) {
	auto winflags {
		static_cast<SDL_WindowFlags>(SDL_WINDOW_RESIZABLE |
                                     SDL_WINDOW_ALWAYS_ON_TOP)};

	constexpr int center_window{SDL_WINDOWPOS_CENTERED};

	auto renderflags {
		static_cast<SDL_RendererFlags>(SDL_RENDERER_PRESENTVSYNC |
									   SDL_RENDERER_ACCELERATED)};

	gWindow = SDL_CreateWindow(settings.title.c_str(), center_window, center_window, settings.width, settings.height, winflags);
    gRenderer = SDL_CreateRenderer(gWindow, -1, renderflags);
	
    // if (ARCH_MAC) {
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "metal"); /// Needed on macos; will crash if not present
	// }
}

GraphicsEngine::~GraphicsEngine() {
    //Destroy gWindow and quit SDL subsystems
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
}

SDL_Renderer* GraphicsEngine::get_native_renderer() const {
    return gRenderer;
}

SDL_Window* GraphicsEngine::get_native_window() const {
    return gWindow;
}
} // neoGraphics