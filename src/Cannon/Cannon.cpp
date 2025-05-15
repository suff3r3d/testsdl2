#include <SDL.h>
#include "../Defines.h"

#include "Cannon.h"

Cannon::Cannon() {
    shape.h = shape.w = 50;
    shape.x = SCREEN_WIDTH - shape.w / 2;
    shape.y = SCREEN_HEIGHT / 2 - shape.h / 2;

    balls.clear();
    color = Color(15, 24, 211, 150);
}

void Cannon::shoot(int x, int y) {
    if ((int)balls.size() == MAX_ALIVE_BALL) {
      fprintf(stderr, "Maximum number of alive balls reached!\n");
      return ;
    }
    x -= SCREEN_WIDTH; y -= SCREEN_HEIGHT / 2;

    Ball *newBall = new Ball(SCREEN_WIDTH - 50 / 2, SCREEN_HEIGHT / 2 - 50 / 2);

    double tt = double(newBall->getSpeed()) / sqrt(x*x + y*y);
    newBall->update_velocity(tt * x, tt * y);

    //newBall->update_velocity(5, 8);

    balls.insert(newBall);
    //printf("%d\n", balls.size());
}

void Cannon::update() {
    for (Ball * ball : balls) {
        ball->update();
    }
    for (std::set<Ball *>::iterator it = balls.begin(); it != balls.end(); ) {
      if ((*it)->touchedWall >= MAX_WALL_TOUCH) it = balls.erase(it);
      else it++;
    }
}

void Cannon::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &shape);

    for (Ball *ball : balls) {
        ball->draw(renderer);
    }
}