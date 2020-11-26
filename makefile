UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
		HEAD := \"sdlheaders/mac.hpp\"
  	CCFLAGS= -framework SDL2 -framework SDL2_image -framework SDL2_ttf
else
		HEAD := \"sdlheaders/linux.hpp\"
		CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf
endif

all: test rsdl.o head

test: game.o myString.o rsdl.o Brick.o Database.o
		g++ example/main.cpp src/rsdl.o example/game.o example/myString.o example/Database.cpp example/Brick.cpp $(CCFLAGS) -o test

Database.o: example/Database.cpp myString.o rsdl.o
	g++ -c example/Database.cpp -o example/Database.o

Ball.o: example/Database.cpp myString.o rsdl.o
	g++ -c example/Database.cpp -o example/Database.o

Brick.o: example/Brick.cpp myString.o rsdl.o
	g++ -c example/Brick.cpp -o example/Brick.o

game.o: example/game.cpp myString.o rsdl.o
	g++ -c example/game.cpp -o example/game.o

myString.o: example/myString.cpp rsdl.o
	g++ -c example/myString.cpp -o example/myString.o

rsdl.o: src/rsdl.hpp src/rsdl.cpp
		g++ -c src/rsdl.cpp -o src/rsdl.o

head:
		echo "#include "$(HEAD) > ./src/sdlHeaders.hpp
clean:
	rm -r *.o
