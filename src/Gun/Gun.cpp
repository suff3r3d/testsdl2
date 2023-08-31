#include <SDL.h>

#include "Gun.h"

Gun::Gun() {
    shape.h = shape.w = 50;
    shape.x = SCREEN_WIDTH - shape.w / 2;
    shape.y = SCREEN_HEIGHT / 2 - shape.h / 2;

    balls.clear();
    color = Color(15, 24, 211, 150);
}

void Gun::shoot(int x, int y) {
    x -= SCREEN_WIDTH; y -= SCREEN_HEIGHT / 2;

    Ball *newBall = new Ball(SCREEN_WIDTH - 50 / 2, SCREEN_HEIGHT / 2 - 50 / 2);

    double tt = double(newBall->getSpeed()) / sqrt(x*x + y*y);
    newBall->update_velocity(tt * x, tt * y);

    //newBall->update_velocity(5, 8);

    balls.push_back(newBall);
    //printf("%d\n", balls.size());
}

void Gun::update() {
    for (Ball *ball : balls) {
        ball->update();
    }
}

void Gun::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &shape);

    //printf("%d\n", balls.size());
    for (Ball *ball : balls) {
        //printf("h");
        ball->draw(renderer);
    }
}