/* Triangulo
* Se pidió recrear una figura geométrica, en este caso un triángulo: se implementará a partir de dos métodos distintos.
* Natalia Belén Damilano
 * 10/8/2020
 */

#include <iostream>
#include <cassert>     
#include <array>

struct Punto { double x, y; };

struct Triangulo { Punto a; Punto b; Punto c; };

using TrianguloArray = std::array<Punto, 3>;


int main()
{
    /* Defino cada struct de tipo Punto que van a corresponder a cada punto que conforman al triángulo. */
    Punto a{ 0,0 };
    Punto b{ 3,0 };
    Punto c{ 0,3 };


    /* Defino mi struct de tipo Triangulo llamado triangulo, que me servirá para representar esta figura geométrica. */
    Triangulo triangulo{ a, b, c };

    assert(0 == a.x);
    assert(0 == a.y);

    assert(3 == b.x);
    assert(0 == b.y);

    assert(0 == c.x);
    assert(3 == c.y);

    TrianguloArray trianguloArray{ { {-2, 0}, {0, 3}, {2, 0} } };

    assert(-2 == trianguloArray.at(0).x);
    assert(0 == trianguloArray.at(0).y);
    assert(0 == trianguloArray.at(1).x);
    assert(3 == trianguloArray.at(1).y);
    assert(2 == trianguloArray.at(2).x);
    assert(0 == trianguloArray.at(2).y);

}

