#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "base.h"
#include "game.h"

void Base::loadTexture(){
  this->surface = IMG_Load("assets/sprites/base.png");
}

void Base::updateFrame(){
  this->loadTexture();
  this->texture = SDL_CreateTextureFromSurface(this->gameRenderer, this->surface);
  SDL_FreeSurface(this->surface);
}

void Base::computeSrcRect(){
  this->srcRect.h = BASE_HEIGHT;
  this->srcRect.w = BASE_WIDTH - BASE_MOTION_RENDER_OFFSET;
  this->srcRect.x = (this->srcRect.x == 0) ? BASE_MOTION_RENDER_OFFSET : 0;
  this->srcRect.y = 0;
}

void Base::computeDstRect(){
  this->dstRect.h = BASE_HEIGHT;
  this->dstRect.w = this->srcRect.w;
  this->dstRect.x = 0;
  this->dstRect.y = SCREEN_HEIGHT - BASE_HEIGHT;
}

void Base::computeRenderPoints(){
  this->computeSrcRect();
  this->computeDstRect();
}

void Base::render(){
  this->updateFrame();
  this->computeRenderPoints();
  SDL_RenderCopy(this->gameRenderer, this->texture, &this->srcRect, &this->dstRect);
  SDL_DestroyTexture(this->texture);
}
