
program: main.o event.o item.o room.o game_instance.o
	g++ -o program main.o event.o item.o room.o game_instance.o

main.o: main.cpp
	g++ -c main.cpp

event.o: event.cpp
	g++ -c event.cpp

room.o: room.cpp
	g++ -c room.cpp

item.o: item.cpp
	g++ -c item.cpp

game_instance.o: game_instance.cpp
	g++ -c game_instance.cpp

clean:
	rm -f *.o program *~
