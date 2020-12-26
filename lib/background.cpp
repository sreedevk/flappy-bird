#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "background.h"

void Background::loadTexture(){
  if(this->current_mode == DAY) {
    this->surface = IMG_Load("assets/sprites/background-day.png");
  } else if (this->current_mode == NIGHT) {
    this->surface = IMG_Load("assets/sprites/background-night.png");
  }
}

void Background::render(){
  this->updateFrame();
  SDL_RenderCopy(this->gameRenderer, this->texture, NULL, NULL);
  SDL_DestroyTexture(this->texture);
}

void Background::updateFrame(){
  this->loadTexture(); 
  this->texture = SDL_CreateTextureFromSurface(this->gameRenderer, this->surface);
  SDL_FreeSurface(this->surface);
}
