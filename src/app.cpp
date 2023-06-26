#include <iostream>
#include <queue>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Body.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1350;
const int SCREEN_HEIGHT = 900;
bool p_open = false;

SDL_Renderer* gRenderer = NULL;
//The window we'll be rendering to
//SDL_Window* gWindow = NULL;
SDL_Window* window = NULL;

//The surface contained by the window
SDL_Surface* screenSurface = NULL;

bool success = true;
int main() {
    Vector v(1, 3);
    v.printVec();
    std::queue<Force> forces = v.forces;

    for (int i = 1; i < 6; i++) {
        Force temp = forces.front();
        forces.pop();

        v.apply(&temp, 1.0f);

        v.printVec();
        forces.push(temp);
    }

    //Initialize SDL, returns negative error values
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    else
    {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Object that represents the screen's state
            screenSurface = SDL_GetWindowSurface(window);

            //Fill the surface white
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window); /// Update the surface

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
            //            }
            //            else
            //            {
            //                while( !p_open )
            //                {
            //                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            //                    SDL_RenderClear( gRenderer );
            //
            //                    //Render red filled quad
            //                    SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
            //                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
            //                    SDL_RenderFillRect( gRenderer, &fillRect );
            //
            //                    SDL_RenderPresent( gRenderer );
            //                }
            //            }
        }
    }


    //Destroy window and quit SDL subsystems
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
