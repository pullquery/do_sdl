#include <SDL2/SDL.h>

class App {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
    int count;

public:
    App();
    ~App();

    void init(const char* title, int x, int y, int w, int h, bool fullscreen);
    const bool running() { return isRunning; };

    void handleEvent();
    void update();
    void render();
    void clean();
};