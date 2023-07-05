//
// Created by neoaces on 2023-06-27.
//
#pragma once
#include "backends/imgui_impl_sdl2.h"
#include <SDL2/SDL.h>
#include <string>

namespace neoengine {
    class GraphicsEngine {
    private:
		SDL_Window* gWindow { nullptr }; /// The Window we'll be rendering to
        SDL_Renderer* gRenderer { nullptr };
        //SDL_Surface* screenSurface = NULL; /// The surface contained by the window

	  public:
		struct Settings {
			std::string title;
			const int width{1280};
			const int height{720};
		};
		
        explicit GraphicsEngine(const Settings& settings);
        ~GraphicsEngine();

		[[nodiscard]] SDL_Window* get_native_window() const;
		[[nodiscard]] SDL_Renderer *get_native_renderer() const;

		
    };
} // neoGraphics
