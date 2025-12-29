#Macros

CC = g++
FLAGS = -Wall -std=c++17 
LINKS = -lsfml-graphics -lsfml-window -lsfml-system 
INCLUDE = -I./inludes/
game: obj/main.o obj/game.o obj/welcome.o obj/play.o obj/cherry.o obj/button.o obj/results.o
	$(CC) $(FLAGS) $^ -o $@ $(LINKS)

main.o: src/main.cpp inludes/game.h
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o obj/main.o

game.o: src/game.cpp inludes/game.h inludes/states.h inludes/welcome.h inludes/play.h inludes/results.h
	$(CC) $(FLAGS) $(INCLUDE)$ -c $< -o obg/game.o

welcome.o: src/welcome.cpp inludes/welcome.h inludes/states.h inludes/button.h
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o obg/welcome.o

play.o: src/play.cpp inludes/play.h inludes/states.h inludes/button.h inludes/cherry.h
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o obg/play.o

cherry.o: src/cherry.cpp inludes/cherry.h 
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o obg/cherry.o

button.o: src/button.cpp inludes/button.h
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o obg/button.o

results.o: src/results.cpp inludes/results.h inludes/states.h inludes/button.h
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o obg/results.o

clean:
	rm -f game obj/*.o

