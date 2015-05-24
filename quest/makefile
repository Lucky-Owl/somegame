
program: main.o event.o item.o room.o player.o
	g++ -o program main.o event.o item.o room.o player.o

main.o: main.cpp
	g++ -c main.cpp

event.o: event.cpp
	g++ -c event.cpp

room.o: room.cpp
	g++ -c room.cpp

item.o: item.cpp
	g++ -c item.cpp

player.o: player.cpp
	g++ -c player.cpp

clean:
	rm -f *.o program *~
