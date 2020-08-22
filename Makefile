CC = g++ -std=c++11

all: main.o Block.o Blockchain.o sha256.o
	$(CC) main.o Block.o Blockchain.o sha256.o
main.o: main.cpp Blockchain.o
	$(CC) -c main.cpp
Block.o: Block.cpp sha256.cpp
	$(CC) -c Block.cpp
Blockchain.o: Blockchain.cpp 
	$(CC) -c Blockchain.cpp
sha256.o: sha256.cpp 
	$(CC) -c sha256.cpp					
clean:
	rm *.o
	rm a.out