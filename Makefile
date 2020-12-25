all:
	g++ main.cpp game.cpp game.h bird.cpp bird.h -o flappyBird `sdl2-config --cflags --libs` -lSDL2_image -w
