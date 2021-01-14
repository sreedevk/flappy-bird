#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "game.h"
#define BASE_HEIGHT 112
#define BASE_WIDTH  336
#define BASE_MOTION_RENDER_OFFSET 40

class Base {
  public:
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Renderer *gameRenderer;
    SDL_Rect srcRect, dstRect;

    void loadTexture();
    void updateFrame();
    void render();
    void computeSrcRect();
    void computeDstRect();
    void computeRenderPoints();

    Base(SDL_Renderer *renderer){
      this->gameRenderer = renderer;
      this->updateFrame();
    }
};
