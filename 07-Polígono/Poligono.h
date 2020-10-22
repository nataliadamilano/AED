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
};

struct Poligonos {
	unsigned n;
	std::array<Poligono, MAX> poligonos;
};

// Funciones

void AddVertice(Poligono& poligono, const Punto& vertice);

Punto GetVertice(const Poligono& poligono, unsigned pos);

void SetVertice(Poligono& poligono, const Punto& verticeACambiar, const Punto& verticeNuevo);

void RemoveVertice(Poligono& poligono);

unsigned GetCantidadLados(const Poligono& poligono);

float GetPerimetroPoligono(const Poligono& poligono);

float GetDistancia(const Punto& punto1, const Punto& punto2);

bool EscribirArchivo(std::ofstream& archivo, const Poligono& poligono);

void EscribirPuntos(std::ofstream& archivo, const Poligono& poligono);

bool GetPuntos(std::ofstream& archivo, const Punto& punto);

bool EscribirColor(std::ofstream& archivo, const Color& color);

bool ExtraerPoligono(std::ifstream& archivoALeer, Poligono& poligonoACompletar);

bool ExtraerPuntos(std::ifstream& archivoALeer, Poligono& poligonoACompletar);

bool ExtraerColor(std::ifstream& archivoALeer, Poligono& poligonoACompletar);

bool ExtraerLimite(std::ifstream& archivoALeer);

void ExtraerYMostrarPoligonos(std::ifstream& archivoALeer, Poligono& poligonoACompletar, Poligonos& arrayPoligonos);

void EscribirPoligonosAutomatico(std::ofstream& archivoAEscribir, Poligonos& arrayPoligonos);

void EscribirPoligonosManual(std::ofstream& archivoAEscribir, Poligonos& arrayPoligonos);