#pragma once
#include <SDL2/SDL.h>

class InitOverlay {
  public:
    SDL_Renderer *gameRenderer;
    SDL_Surface *surface;
    SDL_Texture *texture;

    void loadTexture();
    void updateFrame();
    void render();

    InitOverlay(SDL_Renderer *renderer) {
      this->gameRenderer = renderer;
    }
};
