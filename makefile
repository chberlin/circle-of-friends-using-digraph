run : program.o circle.o digraph.o
	g++ program.o circle.o digraph.o -o run

program.o : program.cpp circle.cpp
	g++ -c -std=c++11 program.cpp

circle.o : circle.cpp digraph.o
	g++ -c -std=c++11 circle.cpp

digraph.o : digraph.cpp
	g++ -c -std=c++11 digraph.cpp

clean:
	rm*.o*.exe
