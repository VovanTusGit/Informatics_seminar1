all: main.exe

main.exe: main.o DynamicArray.o
	g++ main.o DynamicArray.o -o main.exe

main.o: src/main.cpp
	g++ -c src/main.cpp -o main.o

DynamicArray.o: src/DynamicArray.cpp
	g++ -c src/DynamicArray.cpp -o DynamicArray.o

clean:
	rm -f *.o main.exe