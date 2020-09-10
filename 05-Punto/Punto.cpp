/**/

#include "Punto.h"
#include <cassert>
#include <cmath>
#include <cstring>


using namespace std;

int main()
{
	Punto puntoA{ 3,0 };
	Punto puntoB{ 5,2 };
	Punto puntoC{ 3,0 };
	Punto puntoD{ 5,2 };
	Punto puntoE{ 1.5, 0 };
	Punto puntoF{ 0,0 };
	Punto puntoG{ -3,2 };
	Punto puntoH{ -4,-2 };
	Punto puntoI{ 6, -3 };


	/* ---- Asserts ---- */
	assert(not IsIgual(puntoA, puntoB));
	assert(not IsIgual(puntoB, puntoC));
	assert(not IsIgual(puntoB, puntoE));
	assert(IsIgual(puntoA, puntoC));
	assert(IsIgual(puntoB, puntoD));

	assert(2.82 < GetDistancia(puntoA, puntoB) && 2.83 > GetDistancia(puntoA, puntoB));
	assert(2.82 < GetDistancia(puntoB, puntoC) && 2.83 > GetDistancia(puntoB, puntoC));
	assert(4.03 < GetDistancia(puntoD, puntoE) && 4.04 > GetDistancia(puntoD, puntoE));
	assert(1.5 == GetDistancia(puntoC, puntoE));

	assert(3 == GetDistanciaAlOrigen(puntoA));
	assert(5.38 < GetDistanciaAlOrigen(puntoB) && 5.39 > GetDistanciaAlOrigen(puntoB));
	assert(1.5 == GetDistanciaAlOrigen(puntoE));

	assert(Cuadrante::I == GetCuadrante(puntoA));
	assert(Cuadrante::I == GetCuadrante(puntoE));
	assert(Cuadrante::II == GetCuadrante(puntoG));
	assert(Cuadrante::III == GetCuadrante(puntoH));
	assert(Cuadrante::IV == GetCuadrante(puntoI));
	assert(Cuadrante::Origen == GetCuadrante(puntoF));
	assert(Cuadrante::III != GetCuadrante(puntoA));
	assert(Cuadrante::I != GetCuadrante(puntoH));
	assert(Cuadrante::II != GetCuadrante(puntoB));
	assert(Cuadrante::IV != GetCuadrante(puntoE));

	assert(3 == GetEje(puntoA.x) && 0 == GetEje(puntoA.y));
	assert(1.5 == GetEje(puntoE.x) && 0 == GetEje(puntoE.y));
	assert(-2 != GetEje(puntoG.y) && 2 == GetEje(puntoG.y));
	assert(-2 == GetEje(puntoH.y) && 4 != GetEje(puntoH.x));
	assert(0 == GetEje(puntoF.x) && 0 == GetEje(puntoF.y));

	assert(Eje::X != GetEje2(puntoA, puntoA.y));
	assert(Eje::X == GetEje2(puntoA, puntoA.x));
	assert(Eje::Y == GetEje2(puntoA, puntoA.y));
	assert(Eje::X == GetEje2(puntoF, puntoF.x));
	assert(Eje::X == GetEje2(puntoI, puntoI.x) && Eje::Y == GetEje2(puntoI, puntoI.y));

	assert(4 == Mover(puntoA, { 4,-2 }).x && -2 == Mover(puntoA, { 4,-2 }).y);
	assert(3 != Mover(puntoA, { 7,-4.3 }).x && 0 != Mover(puntoA, { 7,-4.3 }).y);
	assert(0 == Mover(puntoE, { 0,0 }).x && 0 == Mover(puntoE, { 0,0 }).y);
	assert(1.5 != Mover(puntoE, { 0,1.5 }).x && 0 != Mover(puntoE, { 0,1.5 }).y);
	assert(6 == Mover(puntoI, { 6,-3 }).x && -3 == Mover(puntoI, { 6,-3 }).y);
	assert(0 == Mover(puntoF, { 0,0 }).x && 0 == Mover(puntoF, { 0,0 }).y);

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
	return GetDistanciaAlOrigen(punto);
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