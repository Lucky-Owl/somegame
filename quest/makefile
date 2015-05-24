program: main.o list.o event.o item.o room.o
	g++ -o program main.o list.o event.o item.o room.o

main.o: main.cpp
	g++ -c main.cpp

event.o: event.cpp
	g++ -c event.cpp

item.o: item.cpp
	g++ -c item.cpp

room.o: room.cpp list.o
	g++ -c room.cpp

list.o: list.cpp 
	g++ -c list.cpp

player.o: player.cpp
	g++ -c player.cpp

clean:
	rm -f *.o program *~
