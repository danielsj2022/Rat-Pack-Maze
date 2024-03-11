proj3.x: proj3.o 
	g++ -std=c++11 proj3.o -o proj3.x
proj3.o: proj3.cpp Stack.h
	g++ -std=c++11 -c proj3.cpp
