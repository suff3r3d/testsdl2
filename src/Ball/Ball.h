#include <SDL.h>
#include <tuple>
#include <utility>

#include "../Stuff/Stuff.h"


class Ball {
private:   
    SDL_Rect shape;
    Color color;
    std::pair<double, double> velocity;

    int speed;
public:
    Ball(int x, int y);
    int getSpeed();

    void handleCollisionWithWall();

    void update();
    void update_velocity(int x, int y);
    void draw(SDL_Renderer *renderer);
};