#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#define FRAMERATE 12
#define SCREEN_HEIGHT 512
#define SCREEN_WIDTH 288

class Game {
  public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Event currentEvent;
    int frameDelay;
    Uint32 frameStart;
    int frameTime; 
    bool running;
    bool gameStarted;
    bool gameOver;
    int flags;

    SDL_Texture *loadTexture(std::string file);
    void         run();
    void         handleEvents();
    void         computeStatus(void *);
    int          computeDelay();

    Game() {
      SDL_Init(SDL_INIT_EVERYTHING);
      this->flags = 0;
      this->window   = SDL_CreateWindow("FlappyBird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, this->flags);
      this->renderer = SDL_CreateRenderer(this->window, -1, 0);
      this->running = true;
      this->gameStarted = false;
      this->gameOver = false;
      this->frameDelay = 1000/FRAMERATE;
    }

    ~Game() {
      SDL_Quit();
    }
};
