#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "bird.h"
#include "game.h"

void Bird::loadTexture(std::string flap_status){
  if(flap_status == "up") {
    this->surface = IMG_Load("assets/sprites/yellowbird-upflap.png");
  } else if(flap_status == "down") {
    this->surface = IMG_Load("assets/sprites/yellowbird-downflap.png");
  } else if(flap_status == "mid") {
    this->surface = IMG_Load("assets/sprites/yellowbird-midflap.png");
  }
}

void Bird::loadDefaults(){
  this->textureStates[0] = "up";
  this->textureStates[1] = "mid";
  this->textureStates[2] = "down";
}

void Bird::updateFrame(){
  this->currentStatus = (this->currentStatus + 1) % 3;
  this->loadTexture(this->textureStates[this->currentStatus]); 
  this->texture = SDL_CreateTextureFromSurface(this->gameRenderer, this->surface);
  SDL_FreeSurface(this->surface);
}

void Bird::updatePosition(int x, int y) {
  this->dstRect.x = x;
  this->dstRect.y = y;
  this->dstRect.h = BIRD_HEIGHT;
  this->dstRect.w = BIRD_WIDTH;
}

void Bird::render(){
  this->updateFrame();
  SDL_RenderCopy(this->gameRenderer, this->texture, NULL, &this->dstRect);
  SDL_DestroyTexture(this->texture);
}

void Bird::jump(){
  this->dstRect.y -= this->controlSpeed; 
}

void Bird::fall(){
  this->dstRect.y += this->fallSpeed;
}
