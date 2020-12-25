#include "game.h"
#include "bird.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

int Game::computeDelay() {
  if(this->frameTime > this->frameDelay) {
    return 0;
  } else {
    return this->frameDelay - this->frameTime;
  }
}

void Game::computeStatus(void *bird) {
  if(!((Bird *) bird)->birdAlive) {
    this->running = false;
  }
}

void Game::run() {
  Bird *bird = new Bird(this->renderer);
  while(this->running) {
    this->frameStart = SDL_GetTicks();

    SDL_RenderClear(this->renderer);

    /* render entities */
    bird->render();

    SDL_RenderPresent(this->renderer);
    this->computeStatus(bird);

    this->frameTime = SDL_GetTicks() - this->frameStart;
    SDL_Delay(this->computeDelay());
  }
}
