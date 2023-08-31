#include <utility>

#include <SDL.h>

class Player {
private:
    SDL_Rect shape;

    int x, y, w, h;
    std::pair<double, double> velocity, acceleration;

    double speed; // left = -1, right = 1

public:
    Player(int w, int h, int x, int y);

    void handleOutofScreen();
    void update();

    void handleKeyPressed(SDL_Keycode key);
    void handleKeyReleased(SDL_Keycode key);

    void draw(SDL_Renderer *renderer);
};