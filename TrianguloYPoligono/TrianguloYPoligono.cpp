/*

*/

#include <string>
#include <array>
#include <iostream>
#include <cassert>
#include <math.h>

using namespace std;

const unsigned MAX = 10;

// Prototipos

struct Punto { double x, y; };

enum struct Colores { azul, rojo, verde, amarillo };

struct Poligono {
    unsigned n;
    array<Punto, MAX> puntos;
    Colores color;
};

struct Triangulo { array<Punto, 3> puntos; Colores color; };

// Fin Prototipos.

// Funciones Polígono

void AgregarPuntoAlFinal(Poligono& poligono, const Punto& punto);

void QuitarPuntoDelFinal(Poligono& poligono);

void SetColorPoligono(Poligono& poligono, const Colores& color);

void SetPuntoPoligono(Poligono& poligono, const Punto& puntoAModificar, const Punto& punto);

Colores GetColorPoligono(const Poligono& poligono);

Punto GetPuntoPoligono(const Poligono& poligono, unsigned pos);

// Fin Funciones Polígono.

// Funciones Triángulo

void SetColorTriangulo(Triangulo& triangulo, const Colores& color);

void SetPuntoTriangulo(Triangulo& triangulo, const Punto& puntoAModificar, const Punto& punto);

Colores GetColorTriangulo(const Triangulo& triangulo);

double GetPerimetroTriangulo(const Triangulo& triangulo);

string GetTipoDeTriangulo(const Triangulo& triangulo); // No desarrollada.

unsigned GetAreaTriangulo(const Triangulo& triangulo); // No desarrollada. Hay que tener en cuenta si el triángulo es equilátero, isósceles o si se conoce la altura del mismo.

double GetDistancia(const Punto& punto1, const Punto& punto2);

// Fin Funciones Triángulo.

int main()
{
    /* Declaro polígono. */
    Poligono poligono{ 3, {{{0,0}, {3,0}, {0,3}}}, Colores::azul };

    AgregarPuntoAlFinal(poligono, { 3,2 });

    SetColorPoligono(poligono, Colores::verde);

    // cout << static_cast<int>(GetColorPoligono(poligono1)) << endl;

    SetPuntoPoligono(poligono, { 0,0 }, { -3,-2 });

    // cout << "(" << GetPuntoPoligono(poligono1, 2).x << ", " << GetPuntoPoligono(poligono1, 2).y << ")" << endl;

    /* Bucle que recorre todos los puntos que pertenecen a poligono1 y los imprime por pantalla. */
     for (int i = 0; i < poligono.n; i++)
     {
         cout << "(" << poligono.puntos[i].x << ", " << poligono.puntos[i].y << ")";
     }


    /* Defino mi struct de tipo Triangulo llamado triangulo, que me servirá para representar esta figura geométrica. */
    Triangulo triangulo{ {{{0,0}, {3,0}, {0,3}}}, Colores::amarillo };

    // SetPuntoTriangulo(triangulo, { 3,0 }, { 2,3 });

    for (int i = 0; i < triangulo.puntos.size(); i++)
    {
        cout << "(" << triangulo.puntos[i].x << ", " << triangulo.puntos[i].y << ")";
    }

    cout << endl << "Su perímetro es: " << GetPerimetroTriangulo(triangulo);

}

void AgregarPuntoAlFinal(Poligono& poligono, const Punto& punto)
{
    if (poligono.n < MAX) {
        poligono.puntos[poligono.n++] = punto;
    }
}

void SetColorPoligono(Poligono& poligono, const Colores& color)
{
    poligono.color = color;
}

Colores GetColorPoligono(const Poligono& poligono)
{
    return poligono.color;
}

void SetPuntoPoligono(Poligono& poligono, const Punto& puntoAModificar, const Punto& punto)
{
    for (size_t i = 0; i < poligono.n; i++)
    {
        if (poligono.puntos[i].x == puntoAModificar.x && poligono.puntos[i].y == puntoAModificar.y)
        {
            poligono.puntos[i] = punto;
        }
    }
}

Punto GetPuntoPoligono(const Poligono& poligono, unsigned pos)
{
    return poligono.puntos.at(pos);
}

void SetColorTriangulo(Triangulo& triangulo, const Colores& color)
{
    triangulo.color = color;
}

void SetPuntoTriangulo(Triangulo& triangulo, const Punto& puntoAModificar, const Punto& punto)
{
    for (size_t i = 0; i < triangulo.puntos.size(); i++)
    {
        if (triangulo.puntos[i].x == puntoAModificar.x && triangulo.puntos[i].y == puntoAModificar.y)
        {
            triangulo.puntos[i] = punto;
        }
    }
}

Colores GetColorTriangulo(const Triangulo& triangulo)
{
    return triangulo.color;
}

double GetPerimetroTriangulo(const Triangulo& triangulo)
{
    double ladoA = GetDistancia(triangulo.puntos.at(0), triangulo.puntos.at(1));

    double ladoB = GetDistancia(triangulo.puntos.at(1), triangulo.puntos.at(2));

    double ladoC = GetDistancia(triangulo.puntos.at(2), triangulo.puntos.at(0));

    return ladoA + ladoB + ladoC;
}

double GetDistancia(const Punto& punto1, const Punto& punto2)
{
    return sqrt(pow((punto2.x - punto1.x), 2) + pow((punto2.y - punto1.y), 2));
}
