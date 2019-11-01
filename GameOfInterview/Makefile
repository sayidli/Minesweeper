D_OBJ = obj
D_RUN = run
makeDir:
	mkdir build; mkdir obj

buildGame:./build/run

./build/run: ./obj/main.o ./obj/Map.o ./obj/Player.o
	clang++ -Wall -g -std=c++0x -stdlib=libc++ ./obj/main.o ./obj/Map.o ./obj/Player.o -o ./build/run

./obj/main.o:main.cpp
	clang++ -Wall -g -std=c++0x -stdlib=libc++ -c main.cpp -o ./obj/main.o

./obj/Map.o:Map.cpp
	clang++ -Wall -g -std=c++0x -stdlib=libc++ -c Map.cpp -o ./obj/Map.o

./obj/Player.o:Player.cpp
	clang++ -Wall -g -std=c++0x -stdlib=libc++ -c Player.cpp -o ./obj/Player.o


.PHONY: makeDir
