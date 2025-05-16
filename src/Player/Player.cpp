#include "Player.h"

#include "../Defines.h"

Player * Player::instance = NULL;

Player::Player(int w, int h, int x, int y) {
    shape.w = w;
    shape.h = h;
    shape.x = x;
    shape.y = y;

    velocity.first = velocity.second = 0;
    acceleration.first = acceleration.second = 0;

    speed = PLAYER_SPEED;
    
    lock = SDL_CreateMutex();
}

void Player::mutex_lock() {
  SDL_LockMutex(lock);
}

void Player::mutex_unlock() {
  SDL_UnlockMutex(lock);
}

Player * Player::getInstance() {
  if (instance == NULL) {
    instance = new Player(50, 50, SCREEN_WIDTH / 2 - 50 / 2, SCREEN_HEIGHT / 2 - 50); 
  }
  return instance;
}

void Player::update() {
    shape.x += velocity.first, shape.y += velocity.second;
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

void Player::handleKeyPressed(SDL_Keycode key) {
    //printf("Key pressed\n");
    switch (key) {
        case SDLK_w:
            velocity.second = -speed;
            break;
        case SDLK_s:
            velocity.second = speed;
            break;
        case SDLK_a:
            velocity.first = -speed;
            break;
        case SDLK_d:
            velocity.first = speed;
            break;
    }
}

void Player::handleKeyReleased(SDL_Keycode key) {
    if (key == SDLK_w || key == SDLK_s) velocity.second = 0;
    if (key == SDLK_a || key == SDLK_d) velocity.first = 0;
}