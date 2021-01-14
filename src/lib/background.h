#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#define DAY "day"
#define NIGHT "night"
#define ROOT_DIR "./"

class Background {
  public:
    std::string img;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Renderer *gameRenderer;
    std::string current_mode;

    void render();
    void updateFrame();
    void loadTexture();

    Background(SDL_Renderer *renderer, std::string mode){
      this->current_mode = mode;
      this->gameRenderer = renderer;
      this->updateFrame();
    }
};
