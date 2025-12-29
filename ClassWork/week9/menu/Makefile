NAME = menu

all: $(NAME)

clean: 
	rm -f *.o $(NAME)

CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -pedantic-errors -g  # Added -g for debugging
LINK = -lsfml-graphics -lsfml-window -lsfml-system

menu: main.o mainMenu.o button.o
	$(CC) $(CFLAGS) main.o mainMenu.o button.o -o $(NAME) $(LINK)

main.o: main.cpp mainMenu.h
	$(CC) $(CFLAGS) -c main.cpp

button.o: button.cpp button.h
	$(CC) $(CFLAGS) -c button.cpp

mainMenu.o: mainMenu.cpp mainMenu.h button.h
	$(CC) $(CFLAGS) -c mainMenu.cpp

.PHONY: all clean