field: Field.cpp Field.h
	g++ -c -std=c++14 -Wall -o field.o Field.cpp
game: Game.cpp Game.h
	g++ -std=c++14 -Wall -o game.o Game.cpp

clean:
	rm *.o
