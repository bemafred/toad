toad: ./source/main.cpp
	c++ ./source/main.cpp -lncurses -o toad

run: toad
	./toad
