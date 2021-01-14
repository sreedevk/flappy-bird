#pragma once
#include <SDL2/SDL.h>

class GameOver {
  public:
    SDL_Renderer *gameRenderer;
    SDL_Surface *surface;
    SDL_Texture *texture;

    void loadTexture();
    void updateFrame();
    void render();

    GameOver(SDL_Renderer *renderer) {
      this->gameRenderer = renderer;
    }
};
