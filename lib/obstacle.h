#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "base.h"
#include "game.h"

#define OBSTACLE_WIDTH 52
#define OBSTACLE_HEIGHT 320
#define OBSTACLE_START_COORD (SCREEN_WIDTH + OBSTACLE_WIDTH)

class Obstacle {
  public:
    double speed;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Renderer *gameRenderer;
    SDL_Rect srcRect, dstRect;

    void loadTexture();
    void computeDstRect(int xOffset);
    void updateFrame();
    void render();
    void updatePosition();

    Obstacle(SDL_Renderer *renderer, int xOffset){
      this->gameRenderer = renderer;
      this->computeDstRect(xOffset);
      this->speed = 10;
    }
};
