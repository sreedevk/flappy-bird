#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <sstream>
#include <iostream>
#include "background.h"

void Background::loadTexture(){
  std::stringstream filepath;
  filepath << *ROOT_DIR << "/assets/sprites/";
  filepath << (this->current_mode == DAY ? "background-day.png" : "background-night.png");
  this->surface = IMG_Load(filepath.str().c_str());
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
