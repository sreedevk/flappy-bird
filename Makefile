CC := g++
LIBS := lib/game.h lib/background.h lib/base.h lib/bird.h lib/background.cpp lib/base.cpp lib/bird.cpp lib/game.cpp
CFLAGS := `sdl2-config --cflags --libs` -lSDL2_image
TARGET := bin/flappyBird

all:
	${CC} main.cpp ${LIBS} -o ${TARGET} ${CFLAGS} -w

clean:
	rm -rf bin/*
