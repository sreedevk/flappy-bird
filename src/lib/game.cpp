#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>
#include <string>
#include "game.h"
#include "bird.h"
#include "background.h"
#include "base.h"
#include <array>
#include "obstacle_manager.h"
#include "init_overlay.h"
#include "score_card.h"
#include "game_over.h"
#include <iostream>

int Game::computeDelay() {
  if(this->frameTime > this->frameDelay) {
    return 0;
  } else {
    return this->frameDelay - this->frameTime;
  }
}

void Game::computeStatus(void *bird) {
  Bird *bird_obj = (Bird *) bird;
  if(!bird_obj->birdAlive) {
    this->gameOver = true;
  }
}

void Game::handleEvents() {
  while(SDL_PollEvent(&this->currentEvent)){
    switch(currentEvent.type) {
      case SDL_QUIT:
        this->running = false;
        break;
      case SDL_KEYDOWN:
        switch(currentEvent.key.keysym.sym) {
          case SDLK_ESCAPE:
            this->running = false;
            break;
          case SDLK_SPACE:
            this->gameStarted = true;
            break;
        }
        break;
      default:
        break;
    }
  }
}

void Game::run() {
  Bird *bird = new Bird(this->renderer);
  Base *base = new Base(this->renderer);
  Background *background = new Background(this->renderer, DAY);
  ScoreCard *score_card = new ScoreCard(this->renderer);
  InitOverlay *init_overlay = new InitOverlay(this->renderer);
  ObstacleManager *obstacle_man = new ObstacleManager(this->renderer);
  GameOver *g_over = new GameOver(this->renderer);
  const Uint8 *state = SDL_GetKeyboardState(NULL);

  while(this->running) {
    this->frameStart = SDL_GetTicks();
    /* handle Keyboard | Quit Events */
    handleEvents();
    SDL_PumpEvents();
    if(!this->gameOver) {
      /* clear Renderer */
      SDL_RenderClear(this->renderer);

      /* render entities */
      background->render();
      if(this->gameStarted) {
        score_card->render();
        obstacle_man->renderObstacles();
        state[SDL_SCANCODE_SPACE] ? bird->jump() : bird->fall();
      } else {
        init_overlay->render();
      }
      base->render();
      bird->render();
      bird->updateBirdLife();
    } else {
      g_over->render();
    }

    /* render renderer to display */
    SDL_RenderPresent(this->renderer);
    this->computeStatus(bird);

    /* frameDelay */
    this->frameTime = SDL_GetTicks() - this->frameStart;
    SDL_Delay(this->computeDelay());
  }
}
