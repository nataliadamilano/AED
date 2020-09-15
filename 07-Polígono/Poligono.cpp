/* 07-Polígono
 * Se pide realizar un tipo de dato Polígono con ciertas cualidades como el representarlo con un color. Además se pidió desarrollar las funciones AddVértice, GetVértice, SetVértice, RemoveVértice,
 * GetCantidadLados, y GetGetPerímetro.
 *
 * Natalia Belén Damilano
 * 10/09/2020
 */

#include <math.h>
#include "Poligono.h"

using namespace std;


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
