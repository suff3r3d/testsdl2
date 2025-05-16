#include <utility>

#include <SDL.h>

class Player {
private:
    SDL_Rect shape;

    int x, y, w, h;
    std::pair<double, double> velocity, acceleration;

    double speed; // left = -1, right = 1

    SDL_mutex * lock;

    Player(int w, int h, int x, int y);
public:
    static Player * instance;
    static Player * getInstance();

    void handleOutofScreen();
    void update();

    void handleKeyPressed(SDL_Keycode key);
    void handleKeyReleased(SDL_Keycode key);

    void draw(SDL_Renderer *renderer);

    void mutex_lock();
    void mutex_unlock();
};