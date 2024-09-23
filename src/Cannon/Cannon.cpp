#include <SDL.h>
#include "../Defines.h"

#include "Cannon.h"

/*
Balls' lifetime is 4 collisions
*/

Cannon::Cannon() {
    shape.h = shape.w = 50;
    shape.x = SCREEN_WIDTH - shape.w / 2;
    shape.y = SCREEN_HEIGHT / 2 - shape.h / 2;

    //balls = std::vector<*Ball>(MAX_BALLS_ON_SCREEN, NULL);
    balls = new Ball*[MAX_BALLS_ON_SCREEN];
    for (int i = 0; i < MAX_BALLS_ON_SCREEN; i++) balls[i] = NULL;
    color = Color(15, 24, 211, 150);
}

int Cannon::countBalls() const {
    int count = 0;
    for (int i = 0; i < MAX_BALLS_ON_SCREEN; i++) {
        count += balls[i] != NULL;
    }
    return count;
}

void Cannon::shoot(int x, int y) {
    if (countBalls() == MAX_BALLS_ON_SCREEN) return ;
    x -= SCREEN_WIDTH; y -= SCREEN_HEIGHT / 2;

    Ball *newBall = new Ball(SCREEN_WIDTH - 50 / 2, SCREEN_HEIGHT / 2 - 50 / 2);

    double tt = double(newBall->getSpeed()) / sqrt(x*x + y*y);
    newBall->update_velocity(tt * x, tt * y);

    for (int i = 0; i < MAX_BALLS_ON_SCREEN; i++) {
        if (balls[i] == NULL) {
            balls[i] = newBall;
            break;
        }
    }

    //newBall->update_velocity(5, 8);

    // balls.push_back(newBall);
    //printf("%d\n", balls.size());
}

void Cannon::update() {
    for (int i = 0; i < MAX_BALLS_ON_SCREEN; i++) {
        if (balls[i] == 0) continue;
        balls[i]->update();
        //printf("%d\n", balls[i]->touchedWall);
        if (balls[i]->touchedWall == 4) balls[i] = NULL;
    }
}

void Cannon::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &shape);

    //printf("%d\n", balls.size());
    for (int i = 0; i < MAX_BALLS_ON_SCREEN; i++) {
        //printf("h");
        if (balls[i] == NULL) continue;
        balls[i]->draw(renderer);
    }
}