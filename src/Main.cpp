
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//#include <SDL.h>
#include "Player/Player.h"
#include "Cannon/Cannon.h"

/*
IMPORTANT FUNCTIONS IN SDL
int SDL_Init(Uint32 flags)
SDL_Window *SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags)
SDL_Renderer *SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags)
*/

SDL_Window *window;
SDL_Renderer *renderer;

void GameLoop() {
    Player player = Player(50, 50, SCREEN_WIDTH / 2 - 50 / 2, SCREEN_HEIGHT / 2 - 50);
    //Ball ball = Ball(50, 50);
    Cannon cannon = Cannon();

    bool quit = false;

    while (!quit) {
        SDL_Event e;

        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    //printf("Pressed %s\n", SDL_GetKeyName(e.key.keysym.sym));

                    player.handleKeyPressed(e.key.keysym.sym);
                    break;
                case SDL_KEYUP:
                   // printf("Released %s\n", SDL_GetKeyName(e.key.keysym.sym));

                    player.handleKeyReleased(e.key.keysym.sym);
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if (e.button.state == SDL_PRESSED) {
                        //printf("Mouse clicked!\n");
                        printf("%d %d\n", e.button.x, e.button.y);
                        cannon.shoot(e.button.x, e.button.y);
                    }
                
                default:
                    break;
            }
        }

        player.update();
        //ball.update();
        cannon.update();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

        player.draw(renderer);
        //ball.draw(renderer);
        cannon.draw(renderer);

        SDL_RenderPresent(renderer);

        
        #ifdef _WIN32 
            sleep(0.016);
        #else 
            usleep(16000);
        #endif
    }
}

bool init() {
    // Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not be initialized!\n"
               "SDL_Error: %s\n", SDL_GetError());
        return false;
    }

#if defined linux && SDL_VERSION_ATLEAST(2, 0, 8)
    // Disable compositor bypass
    if(!SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0"))
    {
        printf("SDL can not disable compositor bypass!\n");
        return false;
    }
#endif

    // Create window
    window = SDL_CreateWindow(
        "Hello world", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    
    if(!window)
    {
        printf("Window could not be created!\n"
               "SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        printf("Renderer could not be created!\n"
               "SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}
void close() {
    // Quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void loadMedia() {}

int main(int argc, char* argv[])
{
    
    if (!init()) return -1;
    loadMedia();

    GameLoop();

    close();
    

    return 0;
}