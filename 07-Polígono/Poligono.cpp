/* 07-Polígono
 * Se pide realizar un tipo de dato Polígono con ciertas cualidades como el representarlo con un color. Además se pidió desarrollar las funciones AddVértice, GetVértice, SetVértice, RemoveVértice,
 * GetCantidadLados, y GetGetPerímetro.
 *
 * Natalia Belén Damilano
 * 10/09/2020
 */

#include <array>
#include <cassert>
#include <math.h>
#include "Poligono.h"

using namespace std;


int main()
{
    Poligono poligono{ 2, {{{0,0}, {3,0}, {0,3}}}, {255,0,0} };
    Poligono poligono2{ 4, {{{0,0}, {3,0}, {0,3}, {4,1}, {6,2}}}, {0,255,0} };
    Poligono poligono3{ 3, {{{0,0}, {3,0}, {0,3}, {5,5}}}, {0,0,255} };

    // Pruebas
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

    assert(30.51 < perimPoligono && 30.52 > perimPoligono);
    assert(30.52 > perimPoligono && 30.51 < perimPoligono);

    perimPoligono = GetPerimetroPoligono(poligono3);

    assert(50.21 < perimPoligono && 50.22 > perimPoligono);
    assert(50.22 > perimPoligono && 50.21 < perimPoligono);


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
}





void AddVertice(Poligono& poligono, const Punto& vertice)
{
    if (poligono.n < MAX) {
        poligono.n += 1;
        poligono.vertices[poligono.n] = vertice;
    }
}

Punto GetVertice(const Poligono& poligono, unsigned pos)
{
    return poligono.vertices.at(pos);
}

void SetVertice(Poligono& poligono, const Punto& verticeACambiar, const Punto& verticeNuevo)
{
    for (size_t i = 0; i < poligono.n; i++)
    {
        if (poligono.vertices[i].x == verticeACambiar.x && poligono.vertices[i].y == verticeACambiar.y)
        {
            poligono.vertices[i] = verticeNuevo;
        }
    }
}

void RemoveVertice(Poligono& poligono)
{
    if (poligono.n > 3)
    {
        poligono.n--;
        poligono.vertices[poligono.n];
    }
}

unsigned GetCantidadLados(const Poligono& poligono)
{
    return poligono.n + 1;
}

float GetPerimetroPoligono(const Poligono& poligono)
{

    float perimetro;

    for (size_t i = 0; i <= poligono.n; i++)
    {
        if (i < poligono.n)
        {
            perimetro += GetDistancia(poligono.vertices[i], poligono.vertices[i + 1]);
        }
        else
            perimetro += GetDistancia(poligono.vertices[i], poligono.vertices[0]);
    }

    return perimetro;
}

float GetDistancia(const Punto& punto1, const Punto& punto2)
{
    return sqrt(pow((punto2.x - punto1.x), 2) + pow((punto2.y - punto1.y), 2));
}
