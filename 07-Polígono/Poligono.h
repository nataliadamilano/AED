#include <stdio.h>
#include <array>
#include <string>
#include <iostream>
#include <fstream>

const unsigned MAX = 10;

// Prototipos

struct Punto { double x, y; };

struct Color { uint8_t red, green, blue; };

struct Poligono {
    unsigned n;
    std::array<Punto, MAX> vertices;
    Color color;
    //struct Nodo* first{ nullptr };
    //Color color;
};

struct Poligonos {
    unsigned n;
    std::array<Poligono, MAX> poligonos;
    //struct NodoPoligonos* first{ nullptr };
};

// Funciones

void AddVertice(Poligono&, const Punto&);

Punto GetVertice(const Poligono&, unsigned);

Poligono GetPoligonoFromPoligonos(const Poligonos&, unsigned);

void SetVertice(Poligono&, const Punto&, const Punto&);

void RemoveVertice(Poligono&);

unsigned GetCantidadLados(const Poligono&);

float GetPerimetroPoligono(const Poligono&);

float GetDistancia(const Punto&, const Punto&);

bool EscribirArchivo(std::ofstream&, const Poligono&);

void EscribirPuntos(std::ofstream&, const Poligono&);

bool GetPuntos(std::ofstream&, const Punto&);

bool EscribirColor(std::ofstream&, const Color&);

bool ExtraerPoligono(std::ifstream&, Poligono&);

bool ExtraerPuntos(std::ifstream&, Poligono&);

bool ExtraerColor(std::ifstream&, Poligono&);

bool ExtraerLimite(std::ifstream&);

void ExtraerYMostrarListaContiguaPoligonos(std::ifstream&, const Poligonos&);

void EscribirPoligonosAutomatico(std::ofstream&, Poligonos&);

void EscribirPoligonosManual(std::ofstream&, Poligonos&);

bool IsPerimetroPolMayorAX(const Poligono&);

Poligonos GetPoligonosPerimetroMayorAX(const Poligonos&);


//VERS PUNTEROS

void MostrarListaPoligono(const Poligono&);

void AddPoligono(Poligonos&, const Poligono&);

void MostrarListaPoligonos(const Poligonos&);

void RemovePoligonoListaPoligonos(Poligonos&);

void FreeHeapListaPoligonos(Poligonos&);

void RemovePoligono(Poligono&);

void FreeHeapListaPoligono(Poligono&);

void ExtraerYMostrarListaEnlazadaPoligonos(std::ifstream&, Poligonos&);

bool IsListaPoligonosEmpty(const Poligonos&);

bool IsListaPoligonoEmpty(const Poligono&);
