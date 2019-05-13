all: bin_tree

bin_tree: main.o bin_tree.o
	g++ main.o bin_tree.o -o main

main.o: main.cpp
	g++ -c main.cpp

bin_tree.o: bin_tree.cpp
	g++ -c bin_tree.cpp

clean:
	rm *.o main 
