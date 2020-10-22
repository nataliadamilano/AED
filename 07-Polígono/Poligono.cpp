/* 07-Polígono
 * Se pide realizar un tipo de dato Polígono con ciertas cualidades como el representarlo con un color. Además se pidió desarrollar las funciones AddVértice, GetVértice, SetVértice, RemoveVértice,
 * GetCantidadLados, y GetGetPerímetro.
 *
 * Natalia Belén Damilano
 * 10/09/2020
 */

#include <math.h>
#include "Poligono.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool EscribirArchivo(ofstream& archivo, const Poligono& poligono)

{
    archivo << poligono.n << " ";
    EscribirPuntos(archivo, poligono);
    EscribirColor(archivo, poligono.color);
    archivo << "@" << " ";

    return bool (archivo);
}

void EscribirPuntos(ofstream& archivo, const Poligono& poligono)
{
    for (int i = 0; i <= poligono.n; i++)
    {
        GetPuntos(archivo, poligono.vertices[i]);
    }
}

bool GetPuntos(ofstream& archivo, const Punto& punto)
{
    archivo << punto.x << " " << punto.y << " ";

    return bool (archivo);
}

bool EscribirColor(ofstream& archivo, const Color& color)
{
    archivo << to_string(color.red) << " " << to_string(color.green) << " " << to_string(color.blue) << " ";

    return bool(archivo);
}

bool ExtraerPoligono(std::ifstream& archivoALeer, Poligono& poligonoACompletar)
{
    archivoALeer >> poligonoACompletar.n;
    if (bool(archivoALeer) == false)
    {
        std:cout << "ERROR! No se ha podido leer del archivo." << "\n";
    }
    else
    {
        ExtraerPuntos(archivoALeer, poligonoACompletar);
        ExtraerColor(archivoALeer, poligonoACompletar);
        ExtraerLimite(archivoALeer);
    }

    return bool(archivoALeer);
}

bool ExtraerPuntos(std::ifstream& archivoALeer, Poligono& poligonoACompletar)
{
    for (int i = 0; i <= poligonoACompletar.n; i++)
    {
        archivoALeer >> poligonoACompletar.vertices[i].x;
        archivoALeer >> poligonoACompletar.vertices[i].y;
    }
    
    return bool(archivoALeer);
}

bool ExtraerColor(std::ifstream& archivoALeer, Poligono& poligonoACompletar)
{
    int temp;
    archivoALeer >> temp;
    poligonoACompletar.color.red = temp;
    archivoALeer >> temp;
    poligonoACompletar.color.green = temp;
    archivoALeer >> temp;
    poligonoACompletar.color.blue = temp;

    return bool(archivoALeer);
}

bool ExtraerLimite(std::ifstream& archivoALeer)
{
    char temp;
    archivoALeer >> temp;

    return bool(archivoALeer);
}

void MostrarPoligonos(std::ifstream& archivoALeer, Poligono& poligonoACompletar, Poligonos& arrayPoligonos)
{
    for (int i = 0; i <= arrayPoligonos.n; i++)
    {
        if (ExtraerPoligono(archivoALeer, poligonoACompletar))
        {
            std::cout << "POLIGONO " << i + 1 << ":\n" << "CANT. VERTICES: " << poligonoACompletar.n+1 << "\n" << "VERTICES: ";

            for (int i = 0; i <= poligonoACompletar.n; i++)
            {
                std::cout << "(" << poligonoACompletar.vertices[i].x << "," << poligonoACompletar.vertices[i].y << ") ";
            }

            std::cout << "\nROJO: " << std::to_string(poligonoACompletar.color.red) << "\n";
            std::cout << "VERDE: " << std::to_string(poligonoACompletar.color.green) << "\n";
            std::cout << "AZUL: " << std::to_string(poligonoACompletar.color.blue) << "\n";
            std::cout << "CANTIDAD DE LADOS: " << GetCantidadLados(poligonoACompletar) << "\n" << "\n";
        }
    }
}

void EscribirPoligonosAutomatico(std::ofstream& archivoAEscribir, Poligonos& arrayPoligonos)
{
    for (int i = 0; i <= arrayPoligonos.n; i++)
    {
        EscribirArchivo(archivoAEscribir, arrayPoligonos.poligonos[i]);
    }
}

void EscribirPoligonosManual(std::ofstream& archivoAEscribir, Poligonos& arrayPoligonos)
{
    unsigned respuesta = 1;

    while (respuesta != 0)
    {
        std::cout << "Desea agregar poligonos dentro del archivo? Digite 1 si quiere continuar, de lo contrario digite 0.\n";

        std::cin >> respuesta;

        if (respuesta == 1)
        {
            Poligono poligonoManual;

            std::cin >> poligonoManual.n;

            for (int i = 0; i <= poligonoManual.n; i++)
            {
                std::cin >> poligonoManual.vertices[i].x >> poligonoManual.vertices[i].y;
            }
            int valorColor;

            std::cin >> valorColor;
            poligonoManual.color.red = valorColor;

            std::cin >> valorColor;
            poligonoManual.color.green = valorColor;

            std::cin >> valorColor;
            poligonoManual.color.blue = valorColor;

            arrayPoligonos.n = arrayPoligonos.n + 1;

            arrayPoligonos.poligonos.at(arrayPoligonos.n) = poligonoManual;

            EscribirArchivo(archivoAEscribir, poligonoManual);
        }
        else if (respuesta != 0)
        {
            std::cout << "Respuesta incorrecta.\n";
        }
    }
}

//FUNCIONES ANTERIORES:

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

    float perimetro = 0;

    for (size_t i = 0; i <= poligono.n; i++)
    {
        if (i < poligono.n)
        {
            perimetro += GetDistancia(poligono.vertices[i], poligono.vertices[i + 1]);
            std::cout << "PRIMERO: " << perimetro << "\n";
        }
        else
        {
            perimetro += GetDistancia(poligono.vertices[i], poligono.vertices[0]);
            std::cout << "ULTIMO: " << perimetro << "\n";
        }
    }
    std::cout << perimetro << "\n";
    return perimetro;
}

float GetDistancia(const Punto& punto1, const Punto& punto2)
{
    return sqrt(pow((punto2.x - punto1.x), 2) + pow((punto2.y - punto1.y), 2));
}
