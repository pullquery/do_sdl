#include <iostream>
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

    isRunning = true;
}

void App::handleEvent() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_MOUSEBUTTONUP:
        std::cout << "Mouse Button Up" << std::endl;
        break;

    case SDL_MOUSEBUTTONDOWN:
        std::cout << "Mouse Button Down" << std::endl;
        break;

    case SDL_MOUSEWHEEL:
        std::cout << "Mouse Wheel" << std::endl;
        break;

    case SDL_KEYUP:
        std::cout
            << "Key Up: "
            << SDL_GetScancodeName(event.key.keysym.scancode)
            << "("
            << SDL_GetKeyName(event.key.keysym.sym)
            << ")"
            << std::endl;
        break;

    case SDL_KEYDOWN:
        std::cout
            << "Key Up: "
            << SDL_GetScancodeName(event.key.keysym.scancode)
            << "("
            << SDL_GetKeyName(event.key.keysym.sym)
            << ")"
            << std::endl;
        break;

    default:
        break;
    }
}

void App::update() {
    count++;
    // std::cout << "Count: " << count << std::endl;
}

void App::render() {
    SDL_RenderClear(renderer);


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 100, 300, 700, 300);
    SDL_RenderDrawLine(renderer, 400, 100, 400, 500);
    SDL_RenderDrawLine(renderer, 100, 100, 700, 500);
    SDL_RenderDrawLine(renderer, 100, 500, 700, 100);


    SDL_SetRenderDrawColor(renderer, 0xFF, 0xCC, 0x00, 255);
    SDL_RenderPresent(renderer);
}

void App::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}