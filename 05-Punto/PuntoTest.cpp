#include "Punto.h"
#include <cassert>



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

	assert(3 == GetRho(puntoA));
	assert(0 == GetPhi(puntoA));

	assert(5.38 < GetRho(puntoB) && 5.39 > GetRho(puntoB));
	assert(0.38 < GetPhi(puntoB) && 0.39 > GetPhi(puntoB));

	assert(3.60 < GetRho(puntoG) && 3.61 > GetPhi(puntoG));
	assert(2.55 < GetPhi(puntoG) && 2.56 > GetPhi(puntoG));

	assert(4.47 < GetRho(puntoH) && 4.48 > GetRho(puntoH));
	assert(-2.67 > GetPhi(puntoH) && -2.68 < GetPhi(puntoH));


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

	assert(!IsIgual({ 4,-2 }, Mover(puntoA, { 4, -2 })));
	assert(!IsIgual({ 3,0 }, Mover(puntoA, { 7, -4.3 })));
	assert(IsIgual({ 0,0 }, Mover(puntoE, { 0, 0 })));
	assert(!IsIgual({ 1.5,0 }, Mover(puntoE, { 0, 1.5 })));
	assert(IsIgual({ 6,-3 }, Mover(puntoI, { 6, -3 })));
	assert(IsIgual({ 0,0 }, Mover(puntoF, { 0, 0 })));

}