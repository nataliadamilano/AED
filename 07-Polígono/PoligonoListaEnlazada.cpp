/* 07-Polígono
 * Se pide realizar un tipo de dato Polígono (siendo Polígono una lista enlazada) con ciertas cualidades como el representarlo con un color. Además se pidió desarrollar las funciones AddVértice, GetVértice, SetVértice, RemoveVértice,
 * GetCantidadLados, y GetPerímetro.
 *
 * Natalia Belén Damilano
 * 20/11/2020
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

struct Nodo {
    Punto value;
    Nodo* next;
};

struct NodoPoligonos {
    Poligono value;
    NodoPoligonos* next;
};

bool EscribirArchivo(ofstream& archivo, const Poligono& listaPoligono)

{
    archivo << GetCantidadLados(listaPoligono) << ESPACIO;
    EscribirPuntos(archivo, listaPoligono);
    EscribirColor(archivo, listaPoligono.color);

    return bool(archivo);
}

void EscribirPuntos(ofstream& archivo, const Poligono& listaPoligono)
{
    for (size_t i = 0; i < GetCantidadLados(listaPoligono); ++i)
        GetPuntos(archivo, GetVertice(listaPoligono, i));
}

bool GetPuntos(ofstream& archivo, const Punto& punto)
{
    archivo << punto.x << ESPACIO << punto.y << ESPACIO;

    return bool(archivo);
}

bool EscribirColor(ofstream& archivo, const Color& color)
{
    archivo << to_string(color.red) << ESPACIO << to_string(color.green) << ESPACIO << to_string(color.blue) << ESPACIO;

    return bool(archivo);
}

void EscribirPoligonosManual(std::ofstream& archivoAEscribir, Poligonos& listaPoligonos)
{
    unsigned respuesta = VALOR_INICIAL_RESPUESTA;

    while (respuesta != VALOR_FINAL_RESPUESTA)
    {
        std::cout << AGREGAR_POLIGONOS << "\n";

        std::cin >> respuesta;

        if (respuesta == VALOR_INICIAL_RESPUESTA)
        {
            Poligono listaPoligonoManual;

            std::cout << CANTIDAD_VERTICES;

            unsigned cantidad;
            std::cin >> cantidad;

            std::cout << "\n" << VERTICES;

            for (size_t i = 0; i < cantidad; i++)
            {
                Punto vertice;
                std::cin >> vertice.x >> vertice.y;
                AddVertice(listaPoligonoManual, vertice);
            }

            std::cout << ROJO;

            int valorColor;

            std::cin >> valorColor;
            listaPoligonoManual.color.red = valorColor;

            std::cout << VERDE;

            std::cin >> valorColor;
            listaPoligonoManual.color.green = valorColor;

            std::cout << AZUL;

            std::cin >> valorColor;
            listaPoligonoManual.color.blue = valorColor;

            if (IsPerimetroPolMayorAX(listaPoligonoManual))
            {
                AddPoligono(listaPoligonos, listaPoligonoManual);
                EscribirArchivo(archivoAEscribir, listaPoligonoManual);
            }

        }
        else if (respuesta != VALOR_FINAL_RESPUESTA)
        {
            std::cout << RESPUESTA_INCORRECTA << "\n";
        }

    }
}

void EscribirPoligonosAutomatico(std::ofstream& archivoAEscribir, Poligonos& listaPoligonos)
{
    for (auto n = listaPoligonos.first; n; n = n->next)
    {
        if (IsPerimetroPolMayorAX(n->value))
            EscribirArchivo(archivoAEscribir, n->value);
    }
}

bool IsPerimetroPolMayorAX(const Poligono& listaPoligono)
{
    return (GetPerimetroPoligono(listaPoligono) > VALOR_COND_PERIMETRO);
}

Poligonos GetPoligonosPerimetroMayorAX(const Poligonos& listaPoligonos)
{
    Poligonos listaPoligonosPerimetroMayorAX{ nullptr };

    for (auto n = listaPoligonos.first; n; n = n->next)
    {
        if (IsPerimetroPolMayorAX(n->value))
            AddPoligono(listaPoligonosPerimetroMayorAX, n->value);
    }

    return listaPoligonosPerimetroMayorAX;
}

Poligono GetPoligonoFromPoligonos(const Poligonos& listaPoligonos, unsigned pos)
{
    NodoPoligonos* aux = listaPoligonos.first;

    unsigned contador = 0;

    while (aux != nullptr)
    {
        if (contador == pos)
            return(aux->value);
        ++contador;

        aux = aux->next;
    }
    return aux->value;
}

bool ExtraerPoligono(std::ifstream& archivoALeer, Poligono& listaPoligonoACompletar)
{

    if (archivoALeer.fail())
    {
    std:cout << ERROR_POLIGONO << "\n";
    }
    else
    {
        unsigned cantVertices;

        archivoALeer >> cantVertices;

        for (size_t i = 0; i < cantVertices; ++i)
        {
            ExtraerPuntos(archivoALeer, listaPoligonoACompletar);
        }
        ExtraerColor(archivoALeer, listaPoligonoACompletar);
    }

    return bool(archivoALeer);
}

bool ExtraerPuntos(std::ifstream& archivoALeer, Poligono& listaPoligonoACompletar)
{
    Nodo* n = new Nodo; // Inicializo una variable de tipo "puntero a nodo" que va a apuntar a una nueva reserva de memoria del heap.


    archivoALeer >> n->value.x; // Extraigo los puntos del archivo y se los asigno al nodo dentro de su atributo "value" que en este caso será un valor de tipo Punto.
    archivoALeer >> n->value.y;

    n->next = nullptr; // El siguiente nodo al cual va a apuntar n va a ser nullptr, o sea, que por el momento no apunta a nada.

    if (listaPoligonoACompletar.first == nullptr) // Condición: si el puntero al primer nodo de mi lista no apunta a nada, le asigno la dirección de memoria a la cual apunta n junto con el valor que almacené ahí.
    {
        listaPoligonoACompletar.first = n;
    }
    else // Caso contrario, creo una variable auxiliar que va a ser un nuevo puntero a un nodo en donde voy a guardar la dirección de memoria a la que apunta el primer puntero al nodo de la lista.
    {
        Nodo* aux = listaPoligonoACompletar.first;

        while (aux->next != nullptr) //Voy a hacer un recorrido por la lista de vértices, hasta que el puntero al siguiente nodo de la lista sea nullptr y me habilite a extraer el siguiente punto.
        {
            aux = aux->next;
        }

        if (aux->next == nullptr) // Me fijo si efectivamente estoy en el puntero que no apunta a ningún nodo siguiente, y lo que hago es asignarle a ese puntero la dirección de memoria en donde está alojado el vértice.
        {
            aux->next = n;
        }

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

void ExtraerYMostrarListaEnlazadaPoligonos(std::ifstream& archivoALeer, Poligonos& listaPoligonos)
{

    int counter = 1;

    for (auto i = listaPoligonos.first; i; i = i->next)
    {
        Poligono poligonoACompletar{ nullptr };

        if (ExtraerPoligono(archivoALeer, poligonoACompletar))
        {
            std::cout << POLIGONO_N << counter << ":\n" << CANTIDAD_VERTICES << GetCantidadLados(poligonoACompletar) << "\n" << VERTICES;

            for (auto j = poligonoACompletar.first; j; j = j->next)
            {
                std::cout << "(" << j->value.x << "," << j->value.y << ") ";
            }

            std::cout << "\n" << ROJO << std::to_string(poligonoACompletar.color.red) << "\n";
            std::cout << VERDE << std::to_string(poligonoACompletar.color.green) << "\n";
            std::cout << AZUL << std::to_string(poligonoACompletar.color.blue) << "\n";
            std::cout << CANTIDAD_LADOS << GetCantidadLados(poligonoACompletar) << "\n" << "\n";

            counter = counter + 1;

        }

    }
}

void RemovePoligonoListaPoligonos(Poligonos& listaPoligonos) {

    NodoPoligonos* aux = listaPoligonos.first;

    listaPoligonos.first = listaPoligonos.first->next;

    delete aux;

}

void FreeHeapListaPoligonos(Poligonos& listaPoligonos)
{
    while (listaPoligonos.first != nullptr)
    {
        RemovePoligonoListaPoligonos(listaPoligonos);
    }
}

void RemovePoligono(Poligono& listaPoligono) {

    Nodo* aux = listaPoligono.first;

    listaPoligono.first = listaPoligono.first->next;

    delete aux;

}

void FreeHeapListaPoligono(Poligono& listaPoligono)
{
    while (listaPoligono.first != nullptr)
    {
        RemovePoligono(listaPoligono);
    }
}

void AddVertice(Poligono& lista, const Punto& vertice)
{
    Nodo* n = new Nodo;

    n->value = vertice; 

    n->next = nullptr;

    if (lista.first == nullptr) 
    {
        lista.first = n;
    }
    else 
    {
        Nodo* aux = lista.first;

        while (aux->next != nullptr) 
        {
            aux = aux->next;
        }

        if (aux->next == nullptr) 
        {
            aux->next = n;
        }
    }

}

void MostrarListaPoligono(const Poligono& listaPoligono)
{
    cout << POLIGONO;

    for (auto i = listaPoligono.first; i; i = i->next)
    {
        cout << "(" << i->value.x << "," << i->value.y << ") ";
    }
}

void MostrarListaPoligonos(const Poligonos& listaPoligonos)
{
    for (auto i = listaPoligonos.first; i; i = i->next)
    {
        cout << POLIGONO;

        for (Nodo* j = i->value.first; j; j = j->next)
        {
            cout << "(" << j->value.x << ", " << j->value.y << ") ";
        }
        cout << "\n";
    }
}

Punto GetVertice(const Poligono& listaPoligono, unsigned pos)
{
    Nodo* aux = listaPoligono.first;

    unsigned contador = 0;

    while (aux != nullptr)
    {
        if (contador == pos+1)
            return(aux->value);
        ++contador;
        aux = aux->next;
    }

    return aux->value;
}

void SetVertice(Poligono& listaPoligono, const Punto& verticeACambiar, const Punto& verticeNuevo)
{
    for (Nodo* aux = listaPoligono.first; aux != nullptr; aux = aux->next)
    {
        if (aux->value.x == verticeACambiar.x && aux->value.y == verticeACambiar.y)
        {
            aux->value = verticeNuevo;
        }
    }
}

void RemoveVertice(Poligono& listaPoligono)
{
    if (GetCantidadLados(listaPoligono) > 3)
    {
        Nodo* aux = listaPoligono.first;

        while (aux->next->next != nullptr)
        {
            aux = aux->next;
        }

        delete aux->next;

        aux->next = nullptr;
    }

}

unsigned GetCantidadLados(const Poligono& listaPoligono)
{
    Nodo* aux = listaPoligono.first;

    unsigned counter = 0;

    while (aux != nullptr)
    {
        aux = aux->next;
        ++counter;
    }

    return counter;
}

float GetPerimetroPoligono(const Poligono& listaPoligono)
{

    float perimetro = 0;

    for (size_t i = 0; i < GetCantidadLados(listaPoligono); i++)
    {
        if (i < GetCantidadLados(listaPoligono) - 1)
        {
            perimetro += GetDistancia(GetVertice(listaPoligono, i), GetVertice(listaPoligono, i + 1));
        }
        else
        {
            perimetro += GetDistancia(GetVertice(listaPoligono, i), GetVertice(listaPoligono, 0));
        }
    }
    return perimetro;
}

float GetDistancia(const Punto& punto1, const Punto& punto2)
{
    return sqrt(pow((punto2.x - punto1.x), 2) + pow((punto2.y - punto1.y), 2));
}

void AddPoligono(Poligonos& arrayPoligonos, const Poligono& poligono)
{
    NodoPoligonos* n = new NodoPoligonos; 

    n->value = poligono; 
    n->next = nullptr; 

    if (arrayPoligonos.first == nullptr) 
    {
        arrayPoligonos.first = n;
    }
    else 
    {
        NodoPoligonos* aux = arrayPoligonos.first;

        while (aux->next != nullptr) 
        {
            aux = aux->next;
        }

        if (aux->next == nullptr) 
        {
            aux->next = n;
        }

    }
}

bool IsListaPoligonosEmpty(const Poligonos& listaPoligonos)
{
    return listaPoligonos.first == nullptr;
}

bool IsListaPoligonoEmpty(const Poligono& listaPoligono) {
    return listaPoligono.first == nullptr;
}


