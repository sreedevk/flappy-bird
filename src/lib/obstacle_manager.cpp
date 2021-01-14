#include <SDL2/SDL.h>
#include "obstacle_manager.h"
#include "obstacle.h"

void ObstacleManager::initObstacles(){
  for(int i=0; i<3; i++) {
    Obstacle *newObstacle = new Obstacle(this->gameRenderer, (i + 1) * OBSTACLE_OFFSET_DISTANCE);
    this->obstacles.push_back(newObstacle);
  }
}

void ObstacleManager::UpdateObstacles(){
  for(int i=0; i<3; i++) {
    Obstacle *obs = this->obstacles[i];
    if(obs->dstRect.x < (0-(OBSTACLE_WIDTH + OBSTACLE_OFFSET_DISTANCE))) {
      obs->computeDstRect((i + 1) * OBSTACLE_OFFSET_DISTANCE);
    } 
  }
}

void ObstacleManager::renderObstacles(){
  this->UpdateObstacles();
  for(int i=0; i<3; i++) {
    this->obstacles[i]->render();
  }
}
