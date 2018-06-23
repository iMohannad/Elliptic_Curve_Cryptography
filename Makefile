all: compile

compile: main.o EllipticCurve.o	point.o NAF.o
	g++ -lm main.o EllipticCurve.o point.o NAF.o -o main

main.o: main.cpp
	g++ -c main.cpp

EllipticCurve.o: EllipticCurve.cpp
	g++ -c EllipticCurve.cpp

point.o: point.cpp
	g++ -c point.cpp

NAF.o: NAF.cpp
	g++ -c NAF.cpp

clean:
	rm -rf *o main