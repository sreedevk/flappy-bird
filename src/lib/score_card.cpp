#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <sstream>
#include <string>
#include "score_card.h"
#include "game.h"

void ScoreCard::loadTexture(){
  std::stringstream textureFile;
  textureFile << "assets/sprites/" << this->playerScore << ".png";
  this->surface = IMG_Load(textureFile.str().c_str());
}

void ScoreCard::updateFrame(){
  this->texture = SDL_CreateTextureFromSurface(this->gameRenderer, this->surface);
  SDL_FreeSurface(this->surface);
  this->dstRect.x = (SCREEN_WIDTH/2) - (SCORE_WIDTH/2);
  this->dstRect.y = 5;
  this->dstRect.w = SCORE_WIDTH;
  this->dstRect.h = SCORE_HEIGHT;
}

void ScoreCard::render(){
  this->loadTexture();
  this->updateFrame();
  SDL_RenderCopy(this->gameRenderer, this->texture, NULL, &this->dstRect);
  SDL_DestroyTexture(this->texture);
}
