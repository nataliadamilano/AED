/* 05-Punto
 * Se pide realizar un tipo de dato Punto que representa un punto en plano como coordenadas cartesianas. Además, se deberán desarrollar las funciones IsIgual, GetDistancia, y
 * GetDistanciaAlOrigen.
 *
 * Natalia Belén Damilano
 * 10/09/2020
 */

#include "Punto.h"
#include <cmath>

using namespace std;

int main()
{
}

bool IsIgual(Punto punto1, Punto punto2)
{
	return (punto1.x == punto2.x) && (punto1.y == punto2.y);
}

double GetDistancia(Punto punto1, Punto punto2)
{
	return sqrt((punto2.x - punto1.x) * (punto2.x - punto1.x) + (punto2.y - punto1.y) * (punto2.y - punto1.y));
}

double GetDistanciaAlOrigen(Punto punto)
{
	return sqrt((punto.x) * (punto.x) + (punto.y) * (punto.y));
}

double GetRho(Punto punto)
{
	return sqrt((punto.x * punto.x) + (punto.y * punto.y));
}

double GetPhi(Punto punto)
{
	return atan2(punto.y, punto.x);
}

Cuadrante GetCuadrante(Punto punto)
{
	return (punto.x >= 0 && punto.y > 0) || (punto.x > 0 && punto.y >= 0) ? Cuadrante::I :
		(punto.x <= 0 && punto.y > 0) || (punto.x < 0 && punto.y >= 0) ? Cuadrante::II :
		(punto.x <= 0 && punto.y < 0) || (punto.x < 0 && punto.y <= 0) ? Cuadrante::III :
		(punto.x >= 0 && punto.y < 0) || (punto.x > 0 && punto.y <= 0) ? Cuadrante::IV :
		Cuadrante::Origen;
}

double GetEje(double ejePunto)
{
	return ejePunto;
}

Eje GetEje2(Punto punto, double ejePunto)
{
	return ejePunto == punto.x ? Eje::X :
		Eje::Y;
}

Punto Mover(Punto& puntoAMover, Punto nuevoPunto)
{
	return nuevoPunto.x != puntoAMover.x || nuevoPunto.y != puntoAMover.y ? puntoAMover = nuevoPunto :
		puntoAMover;
}
