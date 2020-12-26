#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "obstacle.h"
#include "base.h"

void Obstacle::loadTexture(){
  this->surface = IMG_Load("assets/sprites/pipe-green.png");
}

void Obstacle::computeDstRect(int xOffset){
  this->dstRect.y = (rand() % ((SCREEN_HEIGHT - BASE_HEIGHT) - (BASE_HEIGHT) + 1)) + BASE_HEIGHT;
  this->dstRect.x = OBSTACLE_START_COORD + xOffset;
  this->dstRect.w = OBSTACLE_WIDTH;
  this->dstRect.h = OBSTACLE_HEIGHT;
}

void Obstacle::updateFrame(){
  this->loadTexture();
  this->texture = SDL_CreateTextureFromSurface(this->gameRenderer, this->surface);
  SDL_FreeSurface(this->surface);
}

void Obstacle::updatePosition(){
  this->dstRect.x -= this->speed;
}

void Obstacle::render(){
  this->updateFrame();
  this->updatePosition();
  SDL_RenderCopy(this->gameRenderer, this->texture, NULL, &this->dstRect);
  SDL_DestroyTexture(this->texture);
}
