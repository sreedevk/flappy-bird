#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "game.h"

#define BIRD_WIDTH 32
#define BIRD_HEIGHT 24

class Bird {
  public:
    std::string textureStates[3];
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Renderer *gameRenderer;
    int currentStatus;
    SDL_Rect dstRect;
    bool birdAlive;
    int controlSpeed;
    int fallSpeed;

    void loadDefaults();
    void loadTexture(std::string);
    void updateFrame();
    void updatePosition(int, int);
    void render();
    void kill();
    void jump();
    void fall();

    Bird(SDL_Renderer *renderer){
      this->loadDefaults();
      this->birdAlive = true;
      this->controlSpeed = 12;
      this->fallSpeed = 12;
      this->gameRenderer = renderer;
      this->currentStatus = 0;
      this->updatePosition((SCREEN_WIDTH/2)-(BIRD_WIDTH/2), (SCREEN_HEIGHT/2) - (BIRD_HEIGHT/2));
      this->updateFrame();
    }
};
