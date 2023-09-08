#include "Ball.h"
#include <tuple>

#include "../Defines.h"

Ball::Ball(int x, int y) {
    shape.x = x; shape.y = y;
    shape.h = shape.w = 20;

    color = Color(240, 240, 145, 85);
    velocity = std::make_pair(5, 8);

    speed = 8;
    touchedWall = 0;
}

int Ball::getSpeed() {return speed;}

void Ball::draw(SDL_Renderer *renderer) {
    //printf("A ball drawn!\n");
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    //printf("%d %d %d %d\n", color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &shape);
}

void Ball::update() {
    shape.x += velocity.first; shape.y += velocity.second;
    handleCollisionWithWall();
}

void Ball::update_velocity(int x, int y) {
    velocity = std::make_pair(x, y);
}

void Ball::handleCollisionWithWall() {
    if (shape.x <= 0 || shape.x >= SCREEN_WIDTH - shape.w) velocity.first = -velocity.first, touchedWall++;
    if (shape.y <= 0 || shape.y >= SCREEN_HEIGHT - shape.h) velocity.second = -velocity.second, touchedWall++;
}