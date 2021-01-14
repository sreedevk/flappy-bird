#include <SDL2/SDL.h>
#define SCORE_WIDTH 24
#define SCORE_HEIGHT 36

class ScoreCard {
  public:
    int playerScore;
    SDL_Renderer *gameRenderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect dstRect;

    void loadTexture();
    void updateFrame();
    void render();

    ScoreCard(SDL_Renderer *renderer){
      this->gameRenderer = renderer;
      this->playerScore = 0;
    }
};
