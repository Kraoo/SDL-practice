#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create the window
    SDL_Window* window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    // Create the renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Set the background color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Clear the window
    SDL_RenderClear(renderer);

    // Draw a filled rectangle
    SDL_Rect rect = {320, 240, 100, 100};
    SDL_RenderFillRect(renderer, &rect);

    // Present the renderer
    SDL_RenderPresent(renderer);

    // Wait for the user to close the window
    SDL_Event event;
    while (true) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}