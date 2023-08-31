#include <utility>

#include <SDL.h>

class Player {
private:
    SDL_Rect shape;

    int x, y, w, h;
    std::pair<double, double> velocity, acceleration;

    int dir; // left = -1, right = 1

public:
    Player(int w, int h, int x, int y);

    bool onGround();
    void jump();

    void handleOutofScreen();
    void update();
    void run(int dir);
    void stop(int dir);

    void draw(SDL_Renderer *renderer);
};