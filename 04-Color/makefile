output: ColorTest.o Color.o
	g++ ColorTest.o Color.o -o output

ColorTest.o: ColorTest.cpp
	g++ -c ColorTest.cpp

Color.o: Color.cpp
	g++ -c Color.cpp

clean:
	rm *.o output