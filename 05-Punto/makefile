output: PuntoTest.o
	g++ PuntoTest.o -o output
	Punto.o
	g++ Punto.o -o output

PuntoTest.o: PuntoTest.cpp
	g++ -c PuntoTest.cpp

Punto.o: Punto.cpp
	g++ -c Punto.cpp


clean:
	rm *.o output