#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "init_overlay.h"

void InitOverlay::loadTexture(){
  this->surface = IMG_Load("assets/sprites/message.png");
}

void InitOverlay::updateFrame(){
  this->texture = SDL_CreateTextureFromSurface(this->gameRenderer, this->surface);
  SDL_FreeSurface(this->surface);
}

void InitOverlay::render(){
  this->loadTexture();
  this->updateFrame();
  SDL_RenderCopy(this->gameRenderer, this->texture, NULL, NULL);
  SDL_DestroyTexture(this->texture);
}
