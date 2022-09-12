# Starter Makefile
# add .cpp and .h files as specified in each task. 

main: main.o reservoir.o reserveorder.o
	g++ -o main main.o reservoir.o reserveorder.o

main.o: main.cpp reservoir.h
	g++ -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	g++ -c reservoir.cpp

reserveorder.o: reserveorder.cpp reserveorder.h
	g++ -c reserveorder.cpp

clean:
	rm -f main.o reservoir.o reserveorder.o

