#include <iostream>
#include <string>
#include "App.hpp"

App::App() {}

App::~App() {}

void App::init(const char* title, int x, int y, int w, int h, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        isRunning = false;
        return;
    }

    window = SDL_CreateWindow(title, x, y, w, h, flags);
    if (!window) {
        isRunning = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        isRunning = false;
        return;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    isRunning = true;
}

void App::handleEvent() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_MOUSEBUTTONDOWN:
        isClicking = true;
        break;

    case SDL_MOUSEBUTTONUP:
        isClicking = false;
        break;


    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_1:
        case SDLK_KP_1:
            color = 1;
            break;

        case SDLK_2:
        case SDLK_KP_2:
            color = 2;
            break;

        case SDLK_3:
        case SDLK_KP_3:
            color = 3;
            break;

        default:
            color = 0;
            break;
        }
        break;

    default:
        break;
    }
}

void App::update() {
    SDL_GetMouseState(&mouseX, &mouseY);
}

void App::render() {
    if (!isClicking) return;

    switch (color) {
    case 1:
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        break;

    case 2:
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        break;

    case 3:
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        break;

    default:
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        break;
    }

    SDL_RenderFillRect(renderer, new SDL_Rect{ mouseX, mouseY, 5, 5 });

    SDL_RenderPresent(renderer);
}

void App::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}