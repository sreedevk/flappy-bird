#include "./game_over.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void GameOver::loadTexture(){
  this->surface = IMG_Load("assets/sprites/gameover.png");
}

void GameOver::updateFrame(){
  this->texture = SDL_CreateTextureFromSurface(this->gameRenderer, this->surface);
  SDL_FreeSurface(this->surface);
}

void GameOver::render(){
  this->loadTexture();
  this->updateFrame();
  SDL_Rect game_over_banner;
  game_over_banner.x = 50;
  game_over_banner.y = 75;
  game_over_banner.h = 42;
  game_over_banner.w = 192;

  SDL_RenderCopy(this->gameRenderer, this->texture, NULL, &game_over_banner);
  SDL_DestroyTexture(this->texture);
}
