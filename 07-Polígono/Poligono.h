using namespace std;

const unsigned MAX = 10;

// Prototipos

struct Punto { double x, y; };

enum struct Color { azul, rojo, verde, amarillo };

struct Poligono {
    unsigned n;
    array<Punto, MAX> vertices;
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
