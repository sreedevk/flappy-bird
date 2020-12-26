#include "game.h"
#include "bird.h"
#include "background.h"
#include "base.h"
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

void Game::handleEvents() {
  while(SDL_PollEvent(&this->currentEvent)){
    if(currentEvent.type == SDL_QUIT) this->running = false;
  }
}

void Game::run() {
  Bird *bird = new Bird(this->renderer);
  Base *base = new Base(this->renderer);
  Background *background = new Background(this->renderer, DAY);

  while(this->running) {
    this->frameStart = SDL_GetTicks();
    /* handle Keyboard | Quit Events */
    handleEvents();

    /* clear Renderer */
    SDL_RenderClear(this->renderer);

    /* render entities */
    background->render();
    base->render();
    bird->render();

    /* render renderer to display */
    SDL_RenderPresent(this->renderer);
    this->computeStatus(bird);

    /* frameDelay */
    this->frameTime = SDL_GetTicks() - this->frameStart;
    SDL_Delay(this->computeDelay());
  }
}
