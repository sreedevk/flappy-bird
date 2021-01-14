#include <iostream>
#include <cmath>
#include <vector>
#include <SDL2/SDL.h>
#include "lib/game.h"

using namespace std;

Game *game;

int main(){
  game = new Game;
  game->run();

  return EXIT_SUCCESS;
}
