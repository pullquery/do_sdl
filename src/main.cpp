#define SDL_MAIN_HANDLED
#include "App.hpp"

int main(int argc, char* argv[]) {
    App* app = new App();
    app->init("My App", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (app->running()) {
        app->handleEvent();
        app->update();
        app->render();
    }

    app->clean();

    return 0;
}
