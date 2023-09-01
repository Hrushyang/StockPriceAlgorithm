output: main.o problem1.o problem2.o problem3.o
	g++ main.o problem1.o problem2.o problem3.o -o Stocks

main.o: main.cpp
	g++ -c main.cpp

problem1.o: problem1.cpp algorithms.h
	g++ -c problem1.cpp

problem2.o: problem2.cpp algorithms.h
	g++ -c problem2.cpp
	
problem3.o: problem3.cpp algorithms.h
	g++ -c problem3.cpp
	
clean:
	rm *.o Stocks