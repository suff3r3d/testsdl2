#include <SDL.h>
#include "../Ball/Ball.h"

#include <vector>

class Gun {
private:
    SDL_Rect shape;

    Color color;
    std::vector<Ball *> balls;
public:
    Gun();

    void shoot(int x, int y);

    void update();
    void draw(SDL_Renderer *renderer);
};