#include "Player.h"

const int jump_velocity = 13;
const int speed = 10;
const int friction = 6;

Player::Player(int w, int h, int x, int y) {
    shape.w = w;
    shape.h = h;
    shape.x = x;
    shape.y = y;

    velocity.first = velocity.second = 0;
    acceleration.first = acceleration.second = 0;
}

bool Player::onGround() {
    return shape.y >= SCREEN_HEIGHT - shape.h;
}

void Player::jump() {
    if (onGround()) {
        velocity.first -= jump_velocity;
    }
}

void Player::update() {
    //printf("ha");
    velocity.first += gravity * delta; 
    shape.y += velocity.first;
    //printf("%d\n", velocity.first);
    if (onGround()) {
        velocity.first = 0;
        shape.y = SCREEN_HEIGHT - shape.h;
    }
    

    bool positive = (bool)(velocity.second > 0);
    velocity.second += acceleration.second * delta;
    shape.x += velocity.second;
    if (positive != (velocity.second > 0)) {
        velocity.second = 0;
        acceleration.second = 0;
    }

    handleOutofScreen();
}

void Player::handleOutofScreen() {
    if (shape.y >= SCREEN_HEIGHT - shape.h) {
        velocity.first = 0;
        shape.y = SCREEN_HEIGHT - shape.h;
    }

    if (shape.y <= 0) shape.y = 0;
    if (shape.x <= 0) shape.x = 0;
    if (shape.x >= SCREEN_WIDTH - shape.w) shape.x = SCREEN_WIDTH - shape.w;
}

void Player::draw(SDL_Renderer *renderer) {
    //printf("he");
    SDL_RenderFillRect(renderer, &shape);
}

void Player::run(int dir) {
    //left :-1, right: 1
    if (dir == 1) {
        velocity.second = speed;
        acceleration.second = 0;
    } else {
        velocity.second = -speed;
        acceleration.second = 0;
    }
}

void Player::stop(int dir) {
    acceleration.second = (dir == 1 ? -friction : friction);
}