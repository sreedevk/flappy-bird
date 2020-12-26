#pragma once
#include <SDL2/SDL.h>
#include "obstacle.h"
#include <vector>
#define OBSTACLE_OFFSET_DISTANCE 200

class ObstacleManager {
  public:
    std::vector<Obstacle*> obstacles;
    SDL_Renderer *gameRenderer;
    int currentObstacleIndex;
    void updateCurrentObstacleIndex();
    void UpdateObstacles();
    void renderObstacles();
    void initObstacles();

    ObstacleManager(SDL_Renderer *renderer){
      this->currentObstacleIndex = 0;
      this->gameRenderer = renderer;      
      this->initObstacles();
    }
};
