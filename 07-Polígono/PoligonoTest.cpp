#include <cassert>
#include "Poligono.h"
#include <iostream>


int main()
{
	Poligono poligono{ 2, {{{0,0}, {3,0}, {0,3}}}, {255,0,0} };
	Poligono poligono2{ 4, {{{0,0}, {0,3}, {4,2}, {2,3}, {-1,1}}}, {0,255,0} };
	Poligono poligono3{ 3, {{{0,0}, {3,0}, {0,3}, {5,5}}}, {0,0,255} };

	Poligonos poligonos{ 2, {{poligono, poligono2, poligono3}} };

	std::ofstream archivo;

	archivo.open("poligonos.txt");

	EscribirPoligonosAutomatico(archivo, poligonos);

	EscribirPoligonosManual(archivo, poligonos);

	archivo.close();

	std::ifstream archivoALeer;

	archivoALeer.open("poligonos.txt");

	Poligono poligonoACompletar;

	ExtraerYMostrarPoligonos(archivoALeer, poligonoACompletar, poligonos);

	archivoALeer.close();

	//Pruebas con archivo

	archivoALeer.open("poligonos.txt");

	Poligono poligonoPrueba;

	ExtraerPoligono(archivoALeer, poligonoPrueba);

	assert(poligonoPrueba.vertices[0].x == poligono.vertices[0].x);
	assert(poligonoPrueba.vertices[0].y == poligono.vertices[0].y);

	assert(poligonoPrueba.vertices[1].x == poligono.vertices[1].x);
	assert(poligonoPrueba.vertices[1].y == poligono.vertices[1].y);

	assert(poligonoPrueba.vertices[2].x == poligono.vertices[2].x);
	assert(poligonoPrueba.vertices[2].y == poligono.vertices[2].y);

	archivoALeer.close();

	//Pruebas

	assert(0 == GetVertice(poligono, 0).x && 0 == GetVertice(poligono, 0).y);
	assert(3 == GetVertice(poligono, 1).x && 0 == GetVertice(poligono, 0).y);
	assert(0 == GetVertice(poligono, 2).x && 3 == GetVertice(poligono, 2).y);
	assert(0 != GetVertice(poligono, 1).x && 3 != GetVertice(poligono, 0).y);
	assert(5 != GetVertice(poligono, 2).x && 3 == GetVertice(poligono, 2).y);

	assert(3 == GetCantidadLados(poligono));
	assert(5 == GetCantidadLados(poligono2));
	assert(4 == GetCantidadLados(poligono3));
	assert(5 != GetCantidadLados(poligono));
	assert(3 != GetCantidadLados(poligono3));

	float perimPoligono = GetPerimetroPoligono(poligono);

	assert(10.24 < perimPoligono && 10.25 > perimPoligono);
	assert(10.25 > perimPoligono && 10.26 > perimPoligono);

	perimPoligono = GetPerimetroPoligono(poligono2);

	assert(14.37 < perimPoligono && 14.38 > perimPoligono);
	assert(14.3790 > perimPoligono && 14.37 < perimPoligono);

	perimPoligono = GetPerimetroPoligono(poligono3);

	assert(19.69 < perimPoligono && 19.70 > perimPoligono);
	assert(19.6990 > perimPoligono && 19.6980 < perimPoligono);

	AddVertice(poligono, { 6,3.5 });

	assert(6 == poligono.vertices[poligono.n].x && 3.5 == poligono.vertices[poligono.n].y);
	assert(0 != poligono.vertices[poligono.n].x && 3 != poligono.vertices[poligono.n].y);

	AddVertice(poligono2, { 3.4,6 });

	assert(3.4 == poligono2.vertices[poligono2.n].x && 6 == poligono2.vertices[poligono2.n].y);
	assert(6 != poligono2.vertices[poligono2.n].x && 2 != poligono2.vertices[poligono2.n].y);

	AddVertice(poligono3, { 2,4 });

	assert(2 == poligono3.vertices[poligono3.n].x && 4 == poligono3.vertices[poligono3.n].y);
	assert(5 != poligono3.vertices[poligono3.n].x && 5 != poligono3.vertices[poligono3.n].y);

	SetVertice(poligono, { 3,0 }, { 6,6 });

	assert(6 == poligono.vertices[1].x && 6 == poligono.vertices[1].y);
	assert(3 != poligono.vertices[1].x && 0 != poligono.vertices[1].y);

	SetVertice(poligono2, { 0,0 }, { 1,3 });

	assert(1 == poligono2.vertices[0].x && 3 == poligono2.vertices[0].y);
	assert(0 != poligono2.vertices[0].x && 0 != poligono2.vertices[0].y);

	SetVertice(poligono3, { 5,5 }, { 4,3 });

	assert(4 == poligono3.vertices[3].x && 3 == poligono3.vertices[3].y);
	assert(5 != poligono3.vertices[3].x && 5 != poligono3.vertices[3].y);

	RemoveVertice(poligono2);

	assert(4 == poligono2.n);

	RemoveVertice(poligono2);

	assert(3 == poligono2.n);

	RemoveVertice(poligono3);

	assert(3 == poligono3.n);

	assert(3 == GetDistancia({ 0,0 }, { 3,0 }));
	assert(6.40 < GetDistancia({ 5,8 }, { 10,4 }) && 6.41 > GetDistancia({ 5,8 }, { 10,4 }));
	assert(9 != GetDistancia({ 0,0 }, { 3,0 }));
	assert(1 == GetDistancia({ 2,0 }, { 3,0 }));
	assert(0 == GetDistancia({ 0,3 }, { 0,3 }));

	std::string stop;
	std::cin >> stop;
}
