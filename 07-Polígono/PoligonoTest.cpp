#include <cassert>
#include "Poligono.h"
#include <iostream>
#include <iomanip>


struct Nodo {
	Punto value;
	Nodo* next;
};

const std::string ARCHIVO = "poligonos.txt";

int main()
{

#pragma region VersListaEnlazada
	////Inicialización poligono vers. punteros:

	//Poligono poligono{ nullptr,{255,0,0} };

	//Punto vertice{ 0,0 };

	//AddVertice(poligono, vertice);

	//vertice = { 3,0 };

	//AddVertice(poligono, vertice);

	//vertice = { 0,3 };

	//AddVertice(poligono, vertice);

	////Inicialización poligono2 vers. punteros:

	//Poligono poligono2{ nullptr,{0,255,0} };

	//Punto vertice2{ 0,0 };

	//AddVertice(poligono2, vertice2);

	//vertice2 = { 0,3 };

	//AddVertice(poligono2, vertice2);

	//vertice2 = { 4,2 };

	//AddVertice(poligono2, vertice2);

	//vertice2 = { 2,3 };

	//AddVertice(poligono2, vertice2);

	//vertice2 = { -1,1 };

	//AddVertice(poligono2, vertice2);

	////Inicialización poligono3 vers. punteros:

	//Poligono poligono3{ nullptr,{0,0,255} };

	//Punto vertice3{ 0,0 };

	//AddVertice(poligono3, vertice3);

	//vertice3 = { 3,0 };

	//AddVertice(poligono3, vertice3);

	//vertice3 = { 0,3 };

	//AddVertice(poligono3, vertice3);

	//vertice3 = { 5,5 };

	//AddVertice(poligono3, vertice3);

	//Poligonos listaPoligonos{ nullptr };

	//AddPoligono(listaPoligonos, poligono);
	//AddPoligono(listaPoligonos, poligono2);
	//AddPoligono(listaPoligonos, poligono3);

	////Nodo* aux = GetPoligonoFromPoligonos(arrayPoligonos, 2).first;

	////std::cout << "(" << aux->next->value.x << "," << aux->next->value.y << ")";

	//std::ofstream archivo;

	//archivo.open(ARCHIVO);

	//if (archivo.is_open())
	//{
	//	EscribirPoligonosAutomatico(archivo, listaPoligonos);
	//	EscribirPoligonosManual(archivo, listaPoligonos);
	//}

	//archivo.close();

	//std::ifstream archivoALeer;

	//archivoALeer.open(ARCHIVO);

	//if (archivoALeer.is_open())
	//{
	//	Poligonos poligonoslista = GetPoligonosPerimetroMayorAX(listaPoligonos);

	//	ExtraerYMostrarListaEnlazadaPoligonos(archivoALeer, poligonoslista);

	//	FreeHeapListaPoligonos(poligonoslista);
	//}

	//archivoALeer.close();

#pragma endregion VersListaEnlazada


#pragma region VersListaContigua

	Poligono poligono{ 3, {{{0,0}, {3,0}, {0,3}}}, {255,0,0} };
	Poligono poligono2{ 5, {{{0,0}, {0,3}, {4,2}, {2,3}, {-1,1}}}, {0,255,0} };
	Poligono poligono3{ 4, {{{0,0}, {3,0}, {0,3}, {5,5}}}, {0,0,255} };

	Poligonos listaPoligonos{ 3, {{poligono, poligono2, poligono3}} };

	std::ofstream archivo;

	archivo.open(ARCHIVO);

	if (archivo.is_open())
	{
		EscribirPoligonosAutomatico(archivo, listaPoligonos);
		EscribirPoligonosManual(archivo, listaPoligonos);
	}

	archivo.close();

	std::ifstream archivoALeer;

	archivoALeer.open(ARCHIVO);

	if (archivoALeer.is_open())
	{
		ExtraerYMostrarListaContiguaPoligonos(archivoALeer, GetPoligonosPerimetroMayorAX(listaPoligonos));
	}

	archivoALeer.close();

#pragma endregion VersListaContigua

	//Pruebas con archivo

	archivoALeer.open(ARCHIVO);

	Poligono poligonoPruebaExtraccion;

	ExtraerPoligono(archivoALeer, poligonoPruebaExtraccion);

	Punto punto1{ GetVertice(poligonoPruebaExtraccion, 0) };

	assert(punto1.x == GetVertice(poligono2, 0).x);
	assert(punto1.y == GetVertice(poligono2, 0).y);

	Punto punto2{ GetVertice(poligonoPruebaExtraccion, 1) };

	assert(punto2.x == GetVertice(poligono2, 1).x);
	assert(punto2.y == GetVertice(poligono2, 1).y);

	Punto punto3{ GetVertice(poligonoPruebaExtraccion, 2) };

	assert(punto3.x == GetVertice(poligono2, 2).x);
	assert(punto3.y == GetVertice(poligono2, 2).y);

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

	assert(0 == GetVertice(poligono, 2).x && 3 == GetVertice(poligono, 2).y);
	assert(6 != GetVertice(poligono, 2).x && 3.5 != GetVertice(poligono, 2).y);

	AddVertice(poligono2, { 3.4,6 });

	assert(3.4 == GetVertice(poligono2, 6).x && 6 == GetVertice(poligono2, 6).y);
	assert(6 != GetVertice(poligono2, 6).x && 2 != GetVertice(poligono2, 6).y);

	AddVertice(poligono3, { 2,4 });

	assert(2 == GetVertice(poligono3, 5).x && 4 == GetVertice(poligono3, 5).y);
	assert(5 != GetVertice(poligono3, 5).x && 5 != GetVertice(poligono3, 5).y);

	SetVertice(poligono, { 3,0 }, { 6,6 });

	assert(6 == GetVertice(poligono, 1).x && 6 == GetVertice(poligono, 1).y);
	assert(3 != GetVertice(poligono, 1).x && 0 != GetVertice(poligono, 1).y);

	SetVertice(poligono2, { 0,0 }, { 1,3 });

	assert(1 == GetVertice(poligono2, 0).x && 3 == GetVertice(poligono2, 0).y);
	assert(0 != GetVertice(poligono2, 0).x && 0 != GetVertice(poligono2, 0).y);

	SetVertice(poligono3, { 5,5 }, { 4,3 });

	assert(4 == GetVertice(poligono3, 3).x && 3 == GetVertice(poligono3, 3).y);
	assert(5 != GetVertice(poligono3, 3).x && 5 != GetVertice(poligono3, 3).y);

	RemoveVertice(poligono2);

	assert(5 == GetCantidadLados(poligono2));

	RemoveVertice(poligono2);

	assert(4 == GetCantidadLados(poligono2));

	RemoveVertice(poligono3);

	assert(4 == GetCantidadLados(poligono3));

	assert(3 == GetDistancia({ 0,0 }, { 3,0 }));
	assert(6.40 < GetDistancia({ 5,8 }, { 10,4 }) && 6.41 > GetDistancia({ 5,8 }, { 10,4 }));
	assert(9 != GetDistancia({ 0,0 }, { 3,0 }));
	assert(1 == GetDistancia({ 2,0 }, { 3,0 }));
	assert(0 == GetDistancia({ 0,3 }, { 0,3 }));

	//FreeHeapListaPoligonos(listaPoligonos);
	//FreeHeapListaPoligono(poligono);
	//FreeHeapListaPoligono(poligono2);
	//FreeHeapListaPoligono(poligono3);

	//assert(IsListaPoligonoEmpty(poligono));
	//assert(IsListaPoligonoEmpty(poligono2));
	//assert(IsListaPoligonoEmpty(poligono3));
	//assert(IsListaPoligonosEmpty(listaPoligonos));

	std::string exit;
	std::cin >> exit;
}
