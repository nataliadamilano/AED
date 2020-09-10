#include <stdio.h>

const unsigned MAX = 10;

// Prototipos

struct Punto { double x, y; };

struct Color { uint8_t red, green, blue; };

struct Poligono {
    unsigned n;
    std::array<Punto, MAX> vertices;
    Color color;
};

// Funciones

void AddVertice(Poligono& poligono, const Punto& vertice);

Punto GetVertice(const Poligono& poligono, unsigned pos);

void SetVertice(Poligono& poligono, const Punto& verticeACambiar, const Punto& verticeNuevo);

void RemoveVertice(Poligono& poligono);

unsigned GetCantidadLados(const Poligono& poligono);

float GetPerimetroPoligono(const Poligono& poligono);

float GetDistancia(const Punto& punto1, const Punto& punto2);
