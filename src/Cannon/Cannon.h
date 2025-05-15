#include <SDL.h>
#include "../Ball/Ball.h"
#include "../Defines.h"

#include <vector>
#include <set>
#include <algorithm>

class Cannon {
private:
    SDL_Rect shape;

    Color color;
    std::set<Ball *> balls;
public:
    Cannon();

    void shoot(int x, int y);

    void update();
    void draw(SDL_Renderer *renderer);
};