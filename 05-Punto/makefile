output: PuntoTest.o Punto.o
	g++ PuntoTest.o Punto.o -o output

PuntoTest.o: PuntoTest.cpp
	g++ -c PuntoTest.cpp

Punto.o: Punto.cpp
	g++ -c Punto.cpp

clean:
	rm *.o output