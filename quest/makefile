program: main.o event.o item.o room.o
	g++ -o program main.o event.o item.o room.o

main.o: main.cpp
	g++ -c main.cpp

event.o: event.cpp
	g++ -c event.cpp

item.o: item.cpp
	g++ -c item.cpp

room.o: room.cpp
        g++ -c room.cpp

clean:
	rm -f *.o program
