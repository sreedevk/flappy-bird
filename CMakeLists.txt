cmake_minimum_required(VERSION "3.19.1")
project(flappyBird)

set(LIBRARY_PATHS /usr/include /usr/lib/ usr/local/lib)

find_library(SDL2_LIBRARY
  NAMES SDL2
  PATHS ${LIBRARY_PATHS}
)

find_library(SDL2_IMAGE_LIBRARY
  NAMES SDL2_image
  PATHS ${LIBRARY_PATHS}
)

add_library(bird SHARED lib/bird.cpp lib/bird.h)
add_library(game SHARED lib/game.cpp lib/game.h)
add_library(background SHARED lib/background.cpp lib/background.h)
add_library(base SHARED lib/base.cpp lib/base.h)
add_library(init_overlay SHARED lib/init_overlay.cpp lib/init_overlay.h)
add_library(obstacle SHARED lib/obstacle.cpp lib/obstacle.h)
add_library(obstacle_manager SHARED lib/obstacle_manager.cpp lib/obstacle_manager.h)
add_library(score_card SHARED lib/score_card.cpp lib/score_card.h)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} bird game background base init_overlay obstacle obstacle_manager score_card)
