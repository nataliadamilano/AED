/* 07-Polígono
 * Se pide realizar un tipo de dato Polígono con ciertas cualidades como el representarlo con un color. Además se pidió desarrollar las funciones AddVértice, GetVértice, SetVértice, RemoveVértice,
 * GetCantidadLados, y GetPerímetro.
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

const std::string ERROR_POLIGONO = "ERROR! No se ha podido leer del archivo.";
const std::string ESPACIO = " ";
const std::string POLIGONO_N = "POLIGONO ";
const std::string POLIGONO = "POLIGONO: ";
const std::string CANTIDAD_VERTICES = "CANT. DE VERTICES: ";
const std::string CANTIDAD_LADOS = "CANT. DE LADOS: ";
const std::string VERTICES = "VERTICES: ";
const std::string AGREGAR_POLIGONOS = "Desea agregar poligonos dentro del archivo? Digite 1 si quiere continuar, de lo contrario digite 0.";
const std::string RESPUESTA_INCORRECTA = "Respuesta incorrecta.";
const std::string ROJO = "ROJO: ";
const std::string VERDE = "VERDE: ";
const std::string AZUL = "AZUL: ";
const unsigned VALOR_COND_PERIMETRO = 14;
const unsigned VALOR_INICIAL_RESPUESTA = 1;
const unsigned VALOR_FINAL_RESPUESTA = 0;

bool EscribirArchivo(ofstream& archivo, const Poligono& poligono)

{
    archivo << poligono.n << ESPACIO;
    EscribirPuntos(archivo, poligono);
    EscribirColor(archivo, poligono.color);

    return bool (archivo);
}

void EscribirPuntos(ofstream& archivo, const Poligono& poligono)
{
    for (size_t i = 0; i < poligono.n; ++i)
        GetPuntos(archivo, GetVertice(poligono,i));
}

bool GetPuntos(ofstream& archivo, const Punto& punto)
{
    archivo << punto.x << ESPACIO << punto.y << ESPACIO;

    return bool (archivo);
}

bool EscribirColor(ofstream& archivo, const Color& color)
{
    archivo << to_string(color.red) << ESPACIO << to_string(color.green) << ESPACIO << to_string(color.blue) << ESPACIO;

    return bool(archivo);
}

bool ExtraerPoligono(std::ifstream& archivoALeer, Poligono& poligonoACompletar)
{

    if (archivoALeer.fail())
    {
        std:cout << ERROR_POLIGONO << "\n";
    }
    else
    {
        archivoALeer >> poligonoACompletar.n;
        ExtraerPuntos(archivoALeer, poligonoACompletar);
        ExtraerColor(archivoALeer, poligonoACompletar);
    }

    return bool(archivoALeer);
}

bool ExtraerPuntos(std::ifstream& archivoALeer, Poligono& poligonoACompletar)
{
    for (size_t i = 0; i < poligonoACompletar.n; ++i)
    {
        archivoALeer >> poligonoACompletar.vertices.at(i).x;

        archivoALeer >> poligonoACompletar.vertices.at(i).y;
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

void ExtraerYMostrarListaContiguaPoligonos(std::ifstream& archivoALeer, const Poligonos& arrayPoligonos)
{
    for (size_t i = 0; i < arrayPoligonos.n; ++i)
    {
        Poligono poligonoACompletar;

        if (ExtraerPoligono(archivoALeer, poligonoACompletar))
        {
            std::cout << POLIGONO << i + 1 << ":\n" << CANTIDAD_VERTICES << poligonoACompletar.n << "\n" << VERTICES;

            for (size_t i = 0; i < poligonoACompletar.n; ++i)
            {
                std::cout << "(" << GetVertice(poligonoACompletar, i).x << "," << GetVertice(poligonoACompletar, i).y << ") ";
            }

            std::cout << "\n" << ROJO << std::to_string(poligonoACompletar.color.red) << "\n";
            std::cout << VERDE << std::to_string(poligonoACompletar.color.green) << "\n";
            std::cout << AZUL << std::to_string(poligonoACompletar.color.blue) << "\n";
            std::cout << CANTIDAD_LADOS << GetCantidadLados(poligonoACompletar) << "\n" << "\n";
        }
    }
}

void EscribirPoligonosAutomatico(std::ofstream& archivoAEscribir, Poligonos& arrayPoligonos)
{
    for (size_t i = 0; i < arrayPoligonos.n; ++i)
    {
        if (IsPerimetroPolMayorAX(GetPoligonoFromPoligonos(arrayPoligonos, i)))
            EscribirArchivo(archivoAEscribir, GetPoligonoFromPoligonos(arrayPoligonos, i));
    }
}

void EscribirPoligonosManual(std::ofstream& archivoAEscribir, Poligonos& arrayPoligonos)
{
    unsigned respuesta = VALOR_INICIAL_RESPUESTA;

    while (respuesta != VALOR_FINAL_RESPUESTA)
    {
        std::cout << AGREGAR_POLIGONOS << "\n";

        std::cin >> respuesta;

        if (respuesta == VALOR_INICIAL_RESPUESTA)
        {
            Poligono poligonoManual;

            std::cout << CANTIDAD_VERTICES;
            std::cin >> poligonoManual.n;

            std::cout << "\n" << VERTICES;

            for (size_t i = 0; i < poligonoManual.n; ++i)
            {
                std::cin >> poligonoManual.vertices.at(i).x >> poligonoManual.vertices.at(i).y;
            }

            std::cout << ROJO;

            int valorColor;

            std::cin >> valorColor;
            poligonoManual.color.red = valorColor;

            std::cout << VERDE;

            std::cin >> valorColor;
            poligonoManual.color.green = valorColor;

            std::cout << AZUL;

            std::cin >> valorColor;
            poligonoManual.color.blue = valorColor;

            if (IsPerimetroPolMayorAX(poligonoManual))
            {
                arrayPoligonos.n = ++arrayPoligonos.n;

                arrayPoligonos.poligonos.at(arrayPoligonos.n) = poligonoManual;
                
                EscribirArchivo(archivoAEscribir, poligonoManual);
            }
        }
        else if (respuesta != VALOR_FINAL_RESPUESTA)
        {
            std::cout << RESPUESTA_INCORRECTA << "\n";
        }
    }
}

bool IsPerimetroPolMayorAX(const Poligono& poligono)
{
    return (GetPerimetroPoligono(poligono) > VALOR_COND_PERIMETRO);
}

Poligonos GetPoligonosPerimetroMayorAX(const Poligonos& arrayPoligonos)
{
    Poligonos poligonosPerimetroMayorAX;

    int j = 0;

    for (size_t i = 0; i < arrayPoligonos.n + 1; ++i)
    {

        if (IsPerimetroPolMayorAX(GetPoligonoFromPoligonos(arrayPoligonos, i)))
        {
            poligonosPerimetroMayorAX.n = j + 1;

            GetPoligonoFromPoligonos(poligonosPerimetroMayorAX, j) = GetPoligonoFromPoligonos(arrayPoligonos, i);

            ++j;
        }
    }

    return poligonosPerimetroMayorAX;
}

Poligono GetPoligonoFromPoligonos(const Poligonos& arrayPoligonos, unsigned pos)
{
    return arrayPoligonos.poligonos.at(pos);
}

//FUNCIONES ANTERIORES:

void AddVertice(Poligono& poligono, const Punto& vertice)
{
    if (poligono.n < MAX) {
        poligono.n += 1;
        poligono.vertices.at(poligono.n) = vertice;
    }
}

Punto GetVertice(const Poligono& poligono, unsigned pos)
{
    return poligono.vertices.at(pos);
}

void SetVertice(Poligono& poligono, const Punto& verticeACambiar, const Punto& verticeNuevo)
{
    for (size_t i = 0; i < poligono.n; ++i)
    {
        if (GetVertice(poligono, i).x == verticeACambiar.x && GetVertice(poligono, i).y == verticeACambiar.y)
        {
            poligono.vertices.at(i) = verticeNuevo;
        }

    }
}

void RemoveVertice(Poligono& poligono)
{
    if (poligono.n > 3)
    {
        --poligono.n;
    }
}

unsigned GetCantidadLados(const Poligono& poligono)
{
    return poligono.n;
}

float GetPerimetroPoligono(const Poligono& poligono)
{

    float perimetro = 0;

    for (size_t i = 0; i < poligono.n; ++i)
    {
        if (i < poligono.n - 1)
        {
            perimetro += GetDistancia(GetVertice(poligono, i), GetVertice(poligono, i+1));
        }
        else
        {
            perimetro += GetDistancia(GetVertice(poligono, i), GetVertice(poligono, 0));
        }
    }
    return perimetro;
}

float GetDistancia(const Punto& punto1, const Punto& punto2)
{
    return sqrt(pow((punto2.x - punto1.x), 2) + pow((punto2.y - punto1.y), 2));
}