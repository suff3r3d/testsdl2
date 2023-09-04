#include <SDL.h>
#include "../Ball/Ball.h"

#include <vector>

class Cannon {
private:
    SDL_Rect shape;

    Color color;
    std::vector<Ball *> balls;
public:
    Cannon();

    void shoot(int x, int y);

    void update();
    void draw(SDL_Renderer *renderer);
};