NAME = app

all: $(NAME)

clean: 
	rm *.o

CC = g++
CFLAGS = -std=c++17 -Wall  -Wextra -pedantic-errors
LINK = -lsfml-graphics -lsfml-window -lsfml-system

app: main.o game.o
	$(CC) $(CFLAGS) main.o game.o -o $(NAME) $(LINK)

main.o: main.cpp game.h
	$(CC) $(CFLAGS) -c main.cpp

game.o: game.cpp game.h
	$(CC) $(CFLAGS) -c game.cpp