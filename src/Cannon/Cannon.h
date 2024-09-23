#include <SDL.h>
#include "../Ball/Ball.h"

#include <vector>

#ifndef CANNON
#define CANNON

class Cannon {
private:
    SDL_Rect shape;

    Color color;
    Ball **balls;
public:
    Cannon();

    int countBalls() const;
    void shoot(int x, int y);

    void update();
    void draw(SDL_Renderer *renderer);
};

#endif